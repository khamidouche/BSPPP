
#include <iostream>
#include <bsppp/bsppp.hpp>

#include <functional>
#include <numeric>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>


using namespace std;


namespace bl = boost::lambda;







int RandomNumber () { return (rand()%100); }

int sender0( int ind, par<int > const& v, int const& rank_ )
{
  if(rank_==0)  return *v;
  else return int();
}

int inprod_hyb(int argc, char** argv, int n, double& Tcomp, double & Tcomm)
{
    int result;
    #if defined (BSP_HYB_TARGET)
    BSP_HYB_START(argc,argv)
    {
        int nbproc_hyb=size();
        int rank_hyb=pid();
        double T1,T2;

        par<vector<int> > Gvect_Hyb;
        Gvect_Hyb=vector<int> (n/nbproc_hyb);

        par<int> Alpha_Hyb;
        *Alpha_Hyb=0;

        generate (Gvect_Hyb->begin(), Gvect_Hyb->end(), RandomNumber);
        T1=time();
        *Alpha_Hyb=inner_product(Gvect_Hyb->begin(), Gvect_Hyb->end(),Gvect_Hyb->begin(),0);
        T2=time();
        if(rank_hyb==0) Tcomp+=T2-T1;

        T1=time();
        result_of_proj<int>::type fw_Hyb;
        fw_Hyb = proj(Alpha_Hyb);
        T2=time();
        if(rank_hyb==0) Tcomm+=T2-T1;

        T1=time();
        *Alpha_Hyb= accumulate(fw_Hyb.begin(),fw_Hyb.end(),0);
        synchronize();
        T2=time();
        if(rank_hyb==0) Tcomp+=T2-T1;

        if(rank_hyb==0)result=*Alpha_Hyb;
    }
    BSP_HYB_END()
    #endif
    return result;
}
int bsp_main(int argc, char** argv)
{

    ///*****  inprod  **** ///

    int rank_, nbproc,n;
    double T1,T2,Tcomp=0.0,Tcomm=0.0;
    rank_=pid();
    nbproc= size();


    srand ( unsigned ( time(NULL) )*rank_ );

    /// communication of the data size ///

    par<int> N;
    if(rank_==0) *N=atoi(argv[1]);

    par< boost::function<int (int)> > s0 = bl::bind(sender0,bl::_1,N, rank_);
    result_of_put< boost::function<int (int)> >::type recv0;
    recv0 = put( s0 );


    n=(*recv0)(0);
    /// ****************** ///


    par<int> Alpha;
    *Alpha=0;

    #if !defined (BSP_HYB_TARGET)
    par<vector<int> > Gvect;
    Gvect=vector<int> (n/nbproc);



    generate (Gvect->begin(), Gvect->end(), RandomNumber);

    T1=time();

    *Alpha=inner_product(Gvect->begin(), Gvect->end(),Gvect->begin(),0);

    T2=time();
    Tcomp+=T2-T1;

    T1=time();

    result_of_proj<int>::type fw;
    fw = proj(Alpha);

    T2=time();
    Tcomm+=T2-T1;

    T1=time();

    *Alpha= accumulate(fw.begin(),fw.end(),0);
    synchronize();

     T2=time();
    Tcomp+=T2-T1;

    #else
    *Alpha=inprod_hyb(argc, argv, n/nbproc, Tcomp, Tcomm);
    T1=time();

    result_of_proj<int>::type fw;
    fw = proj(Alpha);

    T2=time();
    Tcomm+=T2-T1;

    T1=time();
    *Alpha= accumulate(fw.begin(),fw.end(),0);
    synchronize();
    T2=time();
    Tcomp+=T2-T1;
    #endif

    if(rank_==0)
    cout<<"pid = "<<rank_<<" inprod == "<<*Alpha<<" Tcomp "<<Tcomp<<" Tcomm "<<Tcomm<<endl;



return 0;
}
