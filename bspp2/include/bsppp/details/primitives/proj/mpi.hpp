/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_DETAILS_PRIMITIVES_PROJ_MPI_HPP_INCLUDED
#define BSPPP_DETAILS_PRIMITIVES_PROJ_MPI_HPP_INCLUDED

/******************************************************************************
 * BSP proj for MPI
 ******************************************************************************/

#include <algorithm>
#include <boost/mpi/collectives.hpp>
#include <bsppp/details/memory/buffer.hpp>
namespace MPI
{
namespace bsp
{
  namespace details
  {
    template<class T>
    inline void proj_impl(details::buffer<T>& data,int i,T const& v)
    {

      std::fill(&data[0],&data[0]+size(),v);
      bmpi::all_gather( runtime::world, &data[pid()], 1, &data[0] );
    }
  }
}
}

#endif
