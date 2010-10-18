/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_DETAILS_PRIMITIVES_SYNC_MPI_HPP_INCLUDED
#define BSPPP_DETAILS_PRIMITIVES_SYNC_MPI_HPP_INCLUDED

/******************************************************************************
 * BSP sync for MPI
 ******************************************************************************/

#include <bsppp/details/environment.hpp>

namespace MPI
{
namespace bsp
{
  void inline synchronize()
  {
    details::runtime::world.barrier();
  }
}

}

#endif
