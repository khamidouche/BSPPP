/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_DETAILS_PRIMITIVES_PUT_MPI_HPP_INCLUDED
#define BSPPP_DETAILS_PRIMITIVES_PUT_MPI_HPP_INCLUDED

/******************************************************************************
 * BSP put for MPI
 ******************************************************************************/

#include <bsppp/details/memory/buffer.hpp>

namespace MPI
{
namespace bsp
{
  namespace details
  {
    template<class T> struct put_impl
    {
      static inline int extent()   { return size(); }

      static inline void init(buffer<T>& data,boost::function<T(int)> const& f,int const& pid1,int const& size1)
      {
        for(int i=0;i<size1;++i) data[i] = f(i);
        bmpi::all_to_all( runtime::world, &data[0], 1, &data[0] );
      }

      static inline T const& at(buffer<T> const& data,int i,int const& pid1,int const& size1) { return data[i]; }
    };
  }
}
}

#endif
