#include <iostream>
#include <bsppp/bsppp.hpp>


using namespace std;
//using namespace bsp;

namespace bl = boost::lambda;

int sender2( int ind, par<int> const& v )
{
  return *v;
}

int bsp_main(int argc, char** argv)
{
    
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

