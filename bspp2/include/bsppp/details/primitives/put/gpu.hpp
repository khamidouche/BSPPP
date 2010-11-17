/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_DETAILS_PRIMITIVES_PUT_GPU_HPP_INCLUDED
#define BSPPP_DETAILS_PRIMITIVES_PUT_GPU_HPP_INCLUDED

/******************************************************************************
 * BSP put for GPU
 ******************************************************************************/
#if defined(BSP_GPU_TARGET)
#include <bsppp/details/memory/buffer.hpp>

namespace bsp
{
  namespace details
  {
    template<class T> struct put_impl
    {
      static inline int extent()   { return 1; }

      static inline void init(buffer<T>& data,boost::function<T(int)> const& f)
      {
      }

      static inline T const& at(buffer<T> const& data,int i) { return data[i]; }
    };
  }
}
#endif

#endif
