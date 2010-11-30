
#include <iostream>
#include <bsppp/bsppp.hpp>
#include "data.hpp"


#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>


using namespace std;


namespace bl = boost::lambda;








int sender0( int ind, par<int > const& v, int const& rank_ )
{
  if(rank_==0)  return *v;
  else return int();
}


data<int> sender1( int ind, par<data<int> > const& v, int s, int N )
{
  if(ind %N==s)  return *v;
  else return data<int>(1,1);
}
data<int> sender2( int ind, par<data<int> > const& v, int t, int N)
{
  if(ind/N==t)  return *v;
  else return data<int>(1,1);
}

void inline compute_GMM(data<int>const & A, data<int>const &B, data<int>& C, int n)
{
    for(int i=0;i<n;i++ )
      for(int k=0;k<n;k++ )
       for(int j=0;j<n;j++ )
        C(i,j)=A(i,k)*B(k,j);
}



//void GMV_Hyb(int argc, char** argv, )
//{
//    #if defined (BSP_HYB_TARGET)
//
//    BSP_HYB_START(argc,argv)
//    {
//         int sh,th, rank_Hyb, nbproc_Hyb;
//
//    double T1_,T2_,;
//
//
//    rank_Hyb=pid();
//    nbproc_Hyb= size();
//
//
//
//
//    sh=rank_Hyb%2;
//    th=rank_Hyb/2;
//
//    /// communication of the data size ///
//
//    /// ****************** ///
//
//    //cout<<"ok  "<<rank_<<"  "<<nbproc<<"   n= "<<n<<endl;
//
//         typedef result_of_split<vector<int>,linear>::type sliced_type;
//         sliced_type Gvect_hyb = split(in,linear());
//
//
//
//
//
//
//    T1=time();
//
//    par< boost::function<data<int> (int)> > s1 = bl::bind(sender1,bl::_1,matA,s,M);
//    result_of_put< boost::function<data<int> (int)> >::type recv1;
//    recv1 = put( s1 );
//
//    /// step 2 //////
//    par< boost::function<data<int> (int)> > s2 = bl::bind(sender2,bl::_1,matB,t,M);
//    result_of_put< boost::function<data<int> (int)> >::type recv2;
//    recv2 = put( s2 );
//
//    T2=time();
//    Tcomm+=T2-T1;
//    synchronize();
//
//    /// step 3 //////
//
//
//    //compute_GMM(data<int>const & A, data<int>const &B, data<int>& C)
//    T1=time();
//    for(int i=0;i<nbproc;i++)
////     if(i==rank_)
////      compute_GMM( *matA,*matB, *matC, n/sqrt(nbproc));
////    else
//      if((i%M==s)&&(i/M==t))
//      compute_GMM( (*recv1)(i),(*recv2)(i), *matC, n/sqrt(nbproc));
//
//
//
//    T2=time();
//    Tcomp+=T2-T1;
//
//
//
//
//    }
//    BSP_HYB_END()
//
//
//    #endif
//
//}




int bsp_main(int argc, char** argv)
{


    /// BSP PSRS ///


    int rank_, nbproc,n, s,t,M;

    double T1,T2,Tcomp,Tcomm;


    rank_=pid();
    nbproc= size();

    M=sqrt(nbproc);



    s=rank_%M;
    t=rank_/M;

    /// communication of the data size ///

    par<int> N;
    if(rank_==0) *N=atoi(argv[1]);

    par< boost::function<int (int)> > s0 = bl::bind(sender0,bl::_1,N, rank_);
    result_of_put< boost::function<int (int)> >::type recv0;
    recv0 = put( s0 );

    n=(*recv0)(0);
    /// ****************** ///

    //cout<<"ok  "<<rank_<<"  "<<nbproc<<"   n= "<<n<<endl;

    par<data<int> > matA;
    matA=data<int> (n/M,n/M);

    par<data<int> > matB;
    matB=data<int> (n/M,n/M);

    par<data<int> > matC;
    matC=data<int> (n/M,n/M);


    for(int i=0;i<n/M;i++)
      for(int j=0;j<n/M;j++)
      {(*matA)(i,j)=1;
       (*matB)(i,j)=1;
       (*matC)(i,j)=0;
      }
   // generate (Gvect->begin(), Gvect->end(), RandomNumber);

    T1=time();

    par< boost::function<data<int> (int)> > s1 = bl::bind(sender1,bl::_1,matA,s,M);
    result_of_put< boost::function<data<int> (int)> >::type recv1;
    recv1 = put( s1 );

    /// step 2 //////
    par< boost::function<data<int> (int)> > s2 = bl::bind(sender2,bl::_1,matB,t,M);
    result_of_put< boost::function<data<int> (int)> >::type recv2;
    recv2 = put( s2 );

    T2=time();
    Tcomm+=T2-T1;
  synchronize();

    /// step 3 //////


    //compute_GMM(data<int>const & A, data<int>const &B, data<int>& C)
    T1=time();
    for(int i=0;i<nbproc;i++)
//     if(i==rank_)
//      compute_GMM( *matA,*matB, *matC, n/sqrt(nbproc));
//    else
      if((i%M==s)&&(i/M==t))
      compute_GMM( (*recv1)(i),(*recv2)(i), *matC, n/sqrt(nbproc));



    T2=time();
    Tcomp+=T2-T1;


   if(rank_==0)
     cout<<"Tcomp "<<Tcomp<<" Tcomm "<<Tcomm<<endl;



return 0;
}

