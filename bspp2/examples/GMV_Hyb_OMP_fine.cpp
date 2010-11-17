/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#include <iostream>
#include <bsppp/bsppp.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>

#include "omp.h"

#include "data.hpp"

using namespace bsp;
using namespace std;
namespace bl = boost::lambda;






void bsp_GMV_OMP_fine_1(int argc, char** argv,int const& M,int const &N,int const &n,
           std::vector<double> & U,data<double> & A, std::vector<double> & ParV,double& Tcomp, double & Tcomm)
           {





    int i,j,a,b;
   double T1,T2;


a=n/(N);
b=n/(M);
T1=bsp::time();
#pragma omp parallel for //private(i,j)
    for( i=0;i<n/N;i++)
     {


       for(j=0;j<n/M;j++)
        {
          ParV[i]+= A(i,j)*U[j];

          }
      }

T2=bsp::time();
Tcomp+=T2-T1;
printf("time == %f\n",Tcomp);



}


void  bsp_GMV_OMP_fine_2(int argc, char** argv,int const &N,int const &n,
           std::vector<double> & ParV, std::vector<double> const& recv)
           {



  int k,a;

a=n/(N);
#pragma omp parallel for private(k,a)
    for( k=0;k<a;k++)
         ParV[k]+= recv[k];



}











