#include <iostream>
#include <bsppp/bsppp.hpp>
//#include <boost/lambda/lambda.hpp>
//#include <boost/lambda/bind.hpp>



//#include <boost/range.hpp>
//#include "inprod.hpp"
//#include "test_GMV.hpp"
//#include "test_GMM.hpp"
//#include "test_GMV_ligne.hpp"
//#include "test_GMM_fine.hpp"
//#include "test_GMV_fine.hpp"
//
//#include "data.hpp"

//#include "boost/multi_array.hpp"
//#include <cassert>



//#include "test_data.hpp"

//#include "test.hpp"

using namespace std;
//using namespace bsp;

namespace bl = boost::lambda;

int sender2( int ind, par<int> const& v )
{
  return *v;
}

int bsp_main(int argc, char** argv)
{
    //std::cout<<"pid = "<<pid()<<std::endl;
    par<int> a;
    *a=pid()*2;
std::cout<<"a== "<<*a<<std::endl;

   result_of_proj<int>::type fw;
    fw = proj(a);
for(int i=0;i<size();i++)
std::cout<<"pid== "<<pid()<<" proj = "<<fw(i)<<std::endl;


par< boost::function<int (int)> > s = bl::bind(sender2,bl::_1,a);
    result_of_put< boost::function<int(int)> >::type recv;

    recv = put( s );
int sum=0;
for(int i=0;i<size();i++) sum+=(*recv)(i);
std::cout<<"*** pid== "<<pid()<<"  put  = "<<sum<<std::endl;


     BSP_HYB_START(argc,argv)
     {
         std::cout<<"Hyb "<<pid()<<std::endl;
         std::cout<<"Hyb *** "<<size()<<std::endl;

         par<int> b;

         *b=pid()*8 ;
         std::cout<<"B== "<<*b<<std::endl;

    result_of_proj<int>::type fH;
    fH =proj(b);

for(int i=0;i<size();i++)
std::cout<<" Hyb pid== "<<pid()<<" HYB proj = "<<fH(i)<<std::endl;


  par< boost::function<int (int)> > s1 = bl::bind(sender2,bl::_1,b);

  result_of_put< boost::function<int(int)> >::type recv2;


    recv2 = put( s1 );

int sum=0;
for(int i=0;i<size();i++) sum+=(*recv2)(i);
std::cout<<"*** pid== "<<pid()<<"  put  = "<<sum<<std::endl;


     }
     BSP_HYB_END()



    return 0;
}

/*
struct sender
{
  sender() {}
  sender( par<float> const& v) : value(v) {}

  template<class Sig> struct result;
  template<class This,class T> struct result<This(T)>
  {
    typedef float type;
  };

  float operator()(int dest)
  {
    switch(*pid_)
    {
      case 0: return (dest==1 || dest==2) ? *value : 0;
      default: return 0;
    }
  }

  par<float> value;
};
*/
//float sender2( int to, par<float> const& p )
//{
//  return (*pid_ == to) ? -1 :    (*pid_+1)*10+*p;
//}

/*
vector<int>const & sender2( int to, par<vector<int> > const& p,int a, int b )
{

  return  *p;
}


vector<double> inline  fun_ligne1 ( int ind, par<vector<double> > const& v, int s, int t, int N, int M)
  {
      if(ind==(s+(((t+1)%M)*N)))
                      return *v;
          else return  vector<double> ();

  }

void inline test_MA(int const &N,int const& P,
           std::vector<int> & U,boost::multi_array<int, 2>& AM,vector<int> &V)
           {


int i,j;


    for( i=0;i<N/P;i++)
     {

       for( j=0;j<N/P;j++)
        {
          V[i]+= AM[i][j]*U[j];

          }
     }
}


void inline test_mat(int const &N,int const& P,
           std::vector<int> & U,data<int> & M,vector<int> &V)
           {


int i,j;


    for( i=0;i<N/P;i++)
     {

       for( j=0;j<N/P;j++)
        {
          V[i]+= M(i,j)*U[j];

          }
     }
}

void inline test_vect(int const &N,int const& P,
           std::vector<int> & U,std::vector<int> & C,vector<int> &V)
           {


int j;


//    for( i=0;i<N/P;i++)
//     {

       for( j=0;j<N/P;j++)
        {
          V[j]+= C[j]*U[j];

          }
     // }
}


// implanter les collectives MPI en BSP++
void hello(int argc, char** argv)
{
//    vector<double> D(100);
//std::vector<int> v(10);
  BSP_FUNCTION(argc,argv)
  {
    // Super-step 1
    double t1,t2;


//    par<boost::iterator_range< std::vector<int>::iterator > >r;
//
//    for(int i=0;i<10;i++) v[i]=i;
//    //boost::iterator_range< std::vector<int>::iterator > r;
//
//     r = split(v);
//
//     std::cout <<"rank = "<<bsp::pid()<<"  size= "<<&(*r)[0]<<std::endl;
//
//     (*r)[0]=20;
////     synchronize();
//     synchronize();
//
//     std::cout <<"rank = "<<bsp::pid()<<" val "<<v[0]<<"  val2 = "<<v[5]<<std::endl;
//

    /*
    par<float> p;
    p = f(*pid_);

    cout << *pid_ << " = " << *p << endl;
    sync();

    // Super-step 2

    result_of::proj<float>::type fw;
    fw = proj(p);

    // Super-step
    for(int i=0;i< bsp::size();++i)
      printf("%d received %f from %d\n",*pid_,fw(i),i);
       t1=bsp::time();
    bsp::synchronize();
 t2=bsp::time();
 cout<<"temps == "<<t2-t1<<endl;
    puts("");
    // Super-step

//    par< sender > s = sender(p);
//    result_of::put<sender>::type recv;
//    recv = put( s );

    par< boost::function<float(int)> > s = bl::bind(sender2,bl::_1,p);
    result_of::put< boost::function<float(int)> >::type recv;
    recv = put( s );

   // Super-step
    for(int i=0;i< bsp::size();++i)
      printf("%d received %f from %d\n",*pid_,(*recv)(i),i);
    bsp::synchronize();
    */

////
/*
    int N,P=bsp::size();
    N=atoi(argv[1]);

    par<vector<int> > p;
    p=vector<int> (N/P);

    vector<int> A(N/P);
    vector<int> B(N/P);
    vector<int> C(N/P);


    data<int> M(N/P,N/P);


    typedef boost::multi_array<int, 2> array_type;
    typedef array_type::index index;
    array_type AM(boost::extents[N/P][N/P]);



 for(index ii=0;ii<N/P;ii++){
    for(index jj=0;jj<N/P;jj++)
      {
       AM[ii][jj]=1;
       }
  }



 for(int i=0;i<N/P;i++){
    for(int j=0;j<N/P;j++)
      {
       M(i,j)=1;
       }
  }
  for(int j=0;j<N/P;j++)
      {
       A[j]=0;
       B[j]=1;
       C[j]=1;
       }


  for(int i=0;i<N/P;i++)
      (*p)[i]=0;



   par< boost::function<vector<int>(int)> > s = bl::bind(sender2,bl::_1,p,2,3);
    result_of::put< boost::function<vector<int>(int)> >::type recv;

    recv = put( s );




t1=bsp::time();
//for(int k=0;k<100;k++) test_vect(N,P,B,C,A);
//for(int k=0;k<100;k++) test_mat(N,P,B,M,A);
for(int k=0;k<100;k++) test_MA(N,P,B,AM,A);


 t2=bsp::time();
cout<<" temps *  =  "<<(t2-t1)/100<<endl;

cout << A[0] << "\n";








}
}
*/

//int main(int argc, char** argv)
//{
//  //hello(argc,argv);
// // bspinprod<double>(argc,argv);
//  //test_gmv<double>(argc,argv);
//
//  //test_gmm<double>(argc,argv);
//  //test_data<double>(argc,argv);
//  //test_gmv_ligne<double>(argc,argv);
//  //test_gmm_fine<double>(argc,argv);
//  test_gmv_fine<double>(argc,argv);
//  return 0;
//}
