/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_DETAILS_PRIMITIVES_SIZE_HPP_INCLUDED
#define BSPPP_DETAILS_PRIMITIVES_SIZE_HPP_INCLUDED

namespace MPI
{
namespace bsp
{
  //////////////////////////////////////////////////////////////////////////////
  // BSP Machine number of processor
  //////////////////////////////////////////////////////////////////////////////
  int inline size() { return details::runtime::size(); }
}
}
namespace OMP
{
namespace bsp
{
  //////////////////////////////////////////////////////////////////////////////
  // BSP Machine number of processor
  //////////////////////////////////////////////////////////////////////////////
  int inline size() { return details::runtime::size(); }
}
}
#endif
