/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#include <iostream>
//#include <boost/lambda/lambda.hpp>
//#include <boost/spirit/home/phoenix.hpp>
#include <bsppp/bsppp.hpp>
//#include <bsppp/core/replicate.hpp>

using namespace std;
using namespace bsp;

//using namespace boost::phoenix;
//using namespace boost::phoenix::arg_names;

//template<class T> T iota(int i) { return T(1+(int)(i)); }
//
//struct sender
//{
//  sender() {}
//  sender( par<int> const& v) : value(v) {}
//
//  template<class Sig> struct result;
//  template<class This,class T> struct result<This(T)>
//  {
//    typedef int type;
//  };
//
//  int operator()(int to)
//  {
//    return (*pid_ == to) ? -1 : (*pid_+1)*10+*value;
//  }
//  par<int> value;
//};

int main(int argc,char** argv)
{
  BSP_FUNCTION(argc,argv)
  {
//    int tab[] = {10,20,30,40,50,60,70,80};
//    par<int> dec  = (boost::lambda::_1+1)*10;
//    par<int> dec1 = &iota<int>;
//    par<int> dec2 = tab;
//
//    result_of::proj<int>::type fw;
//    int k = 0;
//
//    for(int i =0; i<100;++i)
//    {
//      // Super-step 1
//      fw = proj(pid_);
//
//      //Super step 2
//      for(int i=0;i<bsp::size();++i) k+= fw(i);
//    }
//
//    printf("[%d] = %d\n",*pid_,k);
//    synchronize();
//
//    par<int> dec  = (boost::lambda::_1+1)*10;
//
//    par< sender > p = sender(dec);
//    result_of::put<sender>::type recv;
//
//    for(int i=0;i<10;++i)
//    {
//      // Super-step 3+
//      recv = put( p );
//
//      // Super-step 4+
//      printf("[%d] : %d %d %d %d \n",*pid_,(*recv)(0),(*recv)(1)
//                                          ,(*recv)(2),(*recv)(3)
//            );
//      synchronize();
//
//      // Super-step 5+
//      if(!*pid_) puts("");
//    }
  }
  return 0;
}
