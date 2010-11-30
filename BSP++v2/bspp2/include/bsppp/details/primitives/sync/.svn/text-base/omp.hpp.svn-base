/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_DETAILS_PRIMITIVES_SYNC_OMP_HPP_INCLUDED
#define BSPPP_DETAILS_PRIMITIVES_SYNC_OMP_HPP_INCLUDED

/******************************************************************************
 * BSP sync for OpenMP
 ******************************************************************************/
#if defined(BSP_OMP_TARGET)

#include <bsppp/details/environment.hpp>

namespace bsp
{
  void inline synchronize()
  {
    #pragma omp barrier
  }
}

#endif

#endif
