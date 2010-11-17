/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_BSPPP_HPP_INCLUDED
#define BSPPP_BSPPP_HPP_INCLUDED

#include <bsppp/core/environment.hpp>
#include <bsppp/core/par.hpp>
#include <bsppp/core/pid.hpp>
#include <bsppp/core/primitives.hpp>


#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>


#if defined(BSP_MPI_TARGET) || defined(BSP_HYB_TARGET)
 using MPI::bsp::pid;
 using MPI::bsp::time;
 using MPI::bsp::size;
 using MPI::bsp::par;
 using MPI::bsp::put;
 using MPI::bsp::proj;
 using MPI::bsp::synchronize;
 using MPI::bsp::result_of_proj;
 using MPI::bsp::result_of_put;
#elif defined(BSP_OMP_TARGET)
 using OMP::bsp::pid;
 using OMP::bsp::time;
 using OMP::bsp::size;
 using OMP::bsp::par;
 using OMP::bsp::put;
 using OMP::bsp::proj;
 using OMP::bsp::split;
 using OMP::bsp::synchronize;
 using OMP::bsp::result_of_proj;
 using OMP::bsp::result_of_put;
 using OMP::bsp::result_of_split;
#endif

#endif
