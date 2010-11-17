/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/

#include "data.hpp"

#include <bsppp/bsppp.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>


using namespace std;
using namespace bsp;
namespace bl = boost::lambda;



void gmv_omp_L(int argc, char ** argv, std::vector<double>& V, data<double>& A, std::vector<double>& U, double & Tcomp, double & Tcomm){


       BSP_FUNCTION(argc,argv)
    {
        double T1,T2;
        int p=bsp::size();
        int pid=bsp::pid();
        int indx =((V.size()/p)*pid);

          std::vector<double> Uomp= U;
         // std::cout<<"rank = "<<pid<<"  & Uomp = "<<&Uomp[0]<<std::endl;

          T1=bsp::time();
         for(int i=0;i<V.size()/p;i++)
          {

           for(int j=0;j<U.size();j++)
          {
          V[i+indx]+= A(i+indx,j)*Uomp[j];


          }
      }
      T2=bsp::time();
      if (pid==0)Tcomp+=T2-T1;
    }
}







