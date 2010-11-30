/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_CORE_ENVIRONNEMENT_HPP_INCLUDED
#define BSPPP_CORE_ENVIRONNEMENT_HPP_INCLUDED

#include <cstdio>
#include <bsppp/details/environment.hpp>

////////////////////////////////////////////////////////////////////////////////
// BSP Environnement start-up.
// Runtime calls to start a new BSP.
////////////////////////////////////////////////////////////////////////////////
#define BSP_FUNCTION(argc,argv)                                     \
bsp::details::environment BOOST_PP_CAT(env,__COUNTER__)(argc,argv); \
if (bool stop_ = false) {} else                                     \
for(; !stop_; stop_ = true)                                         \
 BSP_STARTUP()                                                      \



#define BSP_HYB_START(argc,argv)                                     \
OMP::bsp::details::environment BOOST_PP_CAT(env,__COUNTER__)(argc,argv); \
if (bool stop_ = false) {} else                                     \
for(; !stop_; stop_ = true)                                         \
 BSP_STARTUP()




namespace MPI
{
namespace bsp
{
  //////////////////////////////////////////////////////////////////////////////
  // BSP machine PID
  // Returns the local PID on a BSP machine processor
  //////////////////////////////////////////////////////////////////////////////
  int inline pid() {return details::runtime::pid(); }
  double inline time() { return details::runtime::time(); }
}
}

namespace OMP
{
namespace bsp
{
  //////////////////////////////////////////////////////////////////////////////
  // BSP machine PID
  // Returns the local PID on a BSP machine processor
  //////////////////////////////////////////////////////////////////////////////
  int inline pid() {return details::runtime::pid(); }
  double inline time() { return details::runtime::time(); }
}
}                                                     \



#endif
