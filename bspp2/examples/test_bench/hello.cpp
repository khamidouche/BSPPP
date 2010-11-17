#include <iostream>
#include <bsppp/bsppp.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>



#include <boost/range.hpp>
//#include "inprod.hpp"
//#include "test_GMV.hpp"
//#include "test_GMM.hpp"
//#include "test_GMM1.hpp"
#include "test_GMV_ligne.hpp"

#include "data.hpp"
//#include "test.hpp"

using namespace std;
using namespace bsp;

namespace bl = boost::lambda;


//namespace boost
//{
//  void throw_exception (std::exception const & ) {}
//}

float f(int i)
{
  return 1.f/(1+i);
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

// implanter les collectives MPI en BSP++
void hello(int argc, char** argv)
{
    vector<double> D(100);
std::vector<int> v(10);
  BSP_FUNCTION(argc,argv)
  {
    // Super-step 1
    double t1,t2;


  //  par<boost::iterator_range< std::vector<int>::iterator > >r;

   // for(int i=0;i<10;i++) v[i]=i;
    //boost::iterator_range< std::vector<int>::iterator > r;

    // r = split(v);

    // std::cout <<"rank = "<<bsp::pid()<<"  size= "<<&(*r)[0]<<std::endl;

    // (*r)[0]=20;
//     synchronize();
    // synchronize();

    // std::cout <<"rank = "<<bsp::pid()<<" val "<<v[0]<<"  val2 = "<<v[5]<<std::endl;


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
    int N,P=bsp::size();
    N=atoi(argv[1]);

    par<vector<int> > p;
    p=vector<int> (N/P);

    vector<int> A(N/P);
    vector<int> B(N/P);
    vector<int> C(N/P);
    //vector<double> p(N/P);

    data<int> M(N/P,N/P);


 //

//     result_of::proj<vector<double> >::type fw;
//    fw = proj(p);
//


 for(int i=0;i<N/P;i++){
    for(int j=0;j<N/P;j++)
      {
       M(i,j)=1;
       }
  }
  for(int j=0;j<N/P;j++)
      {
       A[j]=1;
       }


  for(int i=0;i<N/P;i++)
      (*p)[i]=0;
      //p[i]=0.0;

 double Tcomp,Tcomm;
/*
   par< boost::function<vector<int>(int)> > s = bl::bind(sender2,bl::_1,boost::cref(p),2,3);
    result_of::put< boost::function<vector<int>(int)> >::type recv;

    recv = put( s );*/
//
//

    //boost::function<vector<double>(int)> s = bl::bind(sender2,bl::_1,boost::cref(p),2,3);
 //  cout << (*s)(0)[0] << endl;/

 {
t1=bsp::time();
//for(int k=0;k<100;k++) test(N,P,A,M,B,p,Tcomp,Tcomm);
//{

//    for(int i=0;i<N;i++)
//     for(int j=0;j<N;j++)
//         {
//              (*p)[i] =A[i]*M(i,j);
//
//
//           }


 t2=bsp::time();
cout<<" temps *  =  "<<(t2-t1)/100<<endl;

//cout << p[0] << "\n";


}



// par< boost::function< vector<double>(int)> > s2 = bl::bind(fun_ligne1,bl::_1,p,1,1,1,1);
//        result_of::put< boost::function<vector<double> (int)> >::type recv1;

}
}


int main(int argc, char** argv)
{
 // hello(argc,argv);
 // bspinprod<double>(argc,argv);
 // test_gmv<double>(argc,argv);

 // test_gmm<double>(argc,argv);
 //   test_gmm1<double>(argc,argv);
    test_gmv_ligne<double>(argc,argv);
  return 0;
}
