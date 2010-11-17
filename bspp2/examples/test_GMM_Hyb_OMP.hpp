/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/

#ifndef  TEST_GMM_HYB_OMP_HPP__INCLUDED__
#define  TEST_GMM_HYB_OMP_HPP__INCLUDED__

#include "data.hpp"

void gmm_hyb_omp(int argc, char** argv, int const& nlr, int const& nlc, int const& b,
           data<double> const& A,data<double> const& B, data<double> & C, double & Tcomp, double & Tcomm);



#endif

