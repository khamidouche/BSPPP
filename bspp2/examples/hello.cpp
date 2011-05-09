
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
//
int sender2( int ind, par<int> const& v )
{
  return *v;
}

//#include <boost/range/adaptor/sliced.hpp>

//struct linear
//{
//  template<class Sig> struct result;
//  template<class This,class Value>
//  struct result<This(Value,std::size_t,std::size_t)>
//  {
//    typedef boost::iterator_range< typename boost::range_iterator<Value const>::type > type;
//  };
//
//  template<class Value> inline
//  typename result<linear(Value,std::size_t,std::size_t)>::type
//  operator()(Value const& v, std::size_t pid,std::size_t sz) const
//  {
//    std::size_t rs = boost::size(v)/sz;
//    return boost::adaptors::slice(v,pid*rs,(pid+1)*rs);
//  }
//};

int bsp_main(int argc, char** argv)
{
    //std::cout<<"pid = "<<pid()<<std::endl;
    par<vector<int> > a;
    a=vector<int> (20);

for(int i=0;i<20;i++)
     (*a)[i]=i;

//par< boost::function<int (int)> > s = bl::bind(sender2,bl::_1,a);
//    result_of_put< boost::function<int(int)> >::type recv;
//
//    recv = put( s );
//int sum=0;
//for(int i=0;i<size();i++) sum+=(*recv)(i);
//std::cout<<"*** pid== "<<pid()<<"  put  = "<<sum<<std::endl;


     BSP_HYB_START(argc,argv)
     {

       typedef result_of_split<vector<int>,linear>::type sliced_type;
       sliced_type b = split(*a,linear());

       result_of_proj<sliced_type::value_type>::type pb = proj(b);

       for(int i=0;i<size();i++)
         for(int j=0;j<boost::size(pb(i));j++)
        printf("pid %d = %d\n",pid(),(pb(i))[j]);

     }
     BSP_HYB_END()



    return 0;
}

