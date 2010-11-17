/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/

#ifndef  TEST_HPP__INCLUDED__
#define  TEST_HPP__INCLUDED__


#include "data.hpp"
#include <boost/typeof/typeof.hpp>

using namespace bsp;
using namespace std;
namespace bl = boost::lambda;

std::vector<int> inline  fun_ligne ( int ind, par<std::vector<int> > const& v, int s, int t, int N, int M)
  {
      if(ind==(s+(((t+1)%M)*N)))
                      return *v;
          else return  std::vector<int> ();

  }
//
//std::vector<double>  fun_colone ( int ind, par<std::vector<double> > const& v, int t, int N)
//  {
//      if((ind/N)==t)
//                      return *v;
//          else return  std::vector<double> ();
//
//  }
//
//
//std::vector<double>  fun_all ( int ind, par<std::vector<double> > const& v)
//  {
//       return *v;
//  }

void inline test(int const &N,int const& P,
           std::vector<int> & U,data<int> & A,vector<int> &V, par<std::vector<int> >& ParV,double& Tcomp, double & Tcomm)
           {

//void inline test(int const &N,int const& P,
//           std::vector<double> & U,data<double> & A,vector<double> &V, std::vector<double> & ParV,double& Tcomp, double & Tcomm)
//           {


     double t1,t2;

int i,j;






     //t1=bsp::time();
    for( i=0;i<N/P;i++)
     {

       for( j=0;j<N/P;j++)
        {
          //(*ParV)[i]+= A(i,j)*U[j];
          //ParV[i]+= A(i,j)*U[j];
          V[i]+= A(i,j)*U[j];

          }
      }

      //t2=bsp::time();
      //Tcomp+=t2-t1;
//printf("le temps == %f\n",t2-t1);
  //synchronize();


//        typedef BOOST_TYPEOF(bl::bind(fun_ligne,bl::_1,boost::cref(ParV),1,1,1,1)) foo;
//        par<foo> s2 = bl::bind(fun_ligne,bl::_1,boost::cref(ParV),1,1,1,1);
//        result_of::put< boost::function<vector<int> (int)> >::type recv1;
//
//        recv1 =put(s2);
//

//        par< boost::function< vector<int>(int)> > s3 = bl::bind(fun_ligne,bl::_1,ParV,1,1,1,1);
//        result_of::put< boost::function<vector<int> (int)> >::type recv2;
//
//
//        recv2 =put(s3);



//
//
//
//    t2=bsp::time();
//    Tcomm+=t2-t1;
//
//
//

        V=(*ParV);








} /* end bspmv */



#endif


