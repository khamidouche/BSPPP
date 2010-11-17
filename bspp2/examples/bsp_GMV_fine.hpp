/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/

#ifndef  BSP_GMV_FINE_HPP__INCLUDED__
#define  BSP_GMV_FINE_HPP__INCLUDED__


#include "data.hpp"
#include "omp.h"

using namespace bsp;
using namespace std;
namespace bl = boost::lambda;





template<class T>
void inline bsp_GMV_fine(int const &n,
           std::vector<T> & U,data<double> & A,vector<double> &V, double& Tcomp, double & Tcomm)
           {





    double t1,t2;

int i,j;






     t1=bsp::time();
#pragma omp parallel for private (i,j)
    for( i=0;i<n;i++)
     {

       for( j=0;j<n;j++)
        {
          V[i]+= A(i,j)*U[j];
          //V[i]+= A(i,j)*U[j];

          }
      }

      t2=bsp::time();
      Tcomp+=t2-t1;
printf("le temps == %f\n",t2-t1);







} /* end bspmv */



#endif


