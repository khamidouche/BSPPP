/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/

#ifndef  BSP_GMV_LIGNE_HPP__INCLUDED__
#define  BSP_GMV_LIGNE_HPP__INCLUDED__


#include "data.hpp"

using namespace bsp;
using namespace std;
namespace bl = boost::lambda;




template<class T>
void inline bsp_GMV_ligne(int const &n,int const& p,
           std::vector<T> & U,data<double> & A,vector<double> &V, par<std::vector<T> >& ParV,double& Tcomp, double & Tcomm)
           {





    double t1,t2;

int i,j;






     t1=bsp::time();
    for( i=0;i<n/p;i++)
     {

       for( j=0;j<n;j++)
        {
          (*ParV)[i]+= A(i,j)*U[j];
          //V[i]+= A(i,j)*U[j];

          }
      }

      t2=bsp::time();
      Tcomp+=t2-t1;
//printf("le temps == %f\n",t2-t1);
  //synchronize();
        t1=bsp::time();

     result_of::proj<std::vector<double> >::type fw;
      fw = proj(ParV);


    t2=bsp::time();
    Tcomm+=t2-t1;




        V=fw(0);








} /* end bspmv */



#endif


