/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/

#ifndef  GMV_OMP_L_HPP__INCLUDED__
#define  GMV_OMP_L_HPP__INCLUDED__

#include "data.hpp"

void gmv_omp_L(int argc, char** argv,
           std::vector<double> & V,data<double> & A, std::vector<double> & U, double & Tcomp, double & Tcomm);



#endif
