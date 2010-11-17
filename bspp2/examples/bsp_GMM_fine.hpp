/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/

#ifndef  BSP_GMM_FINE_HPP__INCLUDED__
#define  BSP_GMM_FINE_HPP__INCLUDED__

#include "omp.h"


#include "data.hpp"
using namespace std;
using namespace bsp;
namespace bl = boost::lambda;






template<class T>
void inline bsp_GMM_fine(int const &nm,int b,
                      data<double> const& A, data<double> const& B, data<double> & C, double & Tcomp, double & Tcomm)
                      {



    double t1,t2;
int i,j,k;

for(int kl=0;kl<nm/b;kl++)
 for(int kc=0;kc<nm/b;kc++){

           t1=bsp::time();
#pragma omp parallel for private (i,j,k)
              for( i=0;i<b;i++)
               for( k=0;k<nm;k++)
                for( j=0;j<b;j++)
               C(i+(kl*b),j+(kc*b))+= A(i+(kl*b),k)*B(k,j+(kc*b));



            t2=bsp::time();
            Tcomp+=t2-t1;

         }
     }



#endif





