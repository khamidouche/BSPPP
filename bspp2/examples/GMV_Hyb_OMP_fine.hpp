/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/

#ifndef  GMV_HYB_OMP_FINE_HPP__INCLUDED__
#define  GMV_HYB_OMP_FINE_HPP__INCLUDED__

#include "data.hpp"

void bsp_GMV_OMP_fine_1(int argc, char** argv,int const& M,int const &N,int const &n,
           std::vector<double> & U,data<double> & A, std::vector<double> & ParV,double& Tcomp, double & Tcomm);

void  bsp_GMV_OMP_fine_2(int argc, char** argv,int const &N,int const &n,
           std::vector<double> & ParV, std::vector<double> const & recv);


#endif



