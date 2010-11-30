/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_DETAILS_PRIMITIVES_PUT_OMP_HPP_INCLUDED
#define BSPPP_DETAILS_PRIMITIVES_PUT_OMP_HPP_INCLUDED

/******************************************************************************
 * BSP put for OpenMP
 ******************************************************************************/

#include <bsppp/details/memory/buffer.hpp>

namespace OMP
{
namespace bsp
{
  namespace details
  {
    template<class T> struct put_impl
    {
      static inline int extent()   { return size()*size(); }

      static inline void init(buffer<T>& data,boost::function<T(int)> const& f,int const& pid1,int const& size1)
      {

        int offset = pid1*size1;
        for(int i=0;i<size1;++i) data[i+offset] = f(i);
        synchronize();
      }

      static inline T const& at(buffer<T> const& data,int i,int const& pid1,int const& size1) { return data[i*size1+pid1]; }
    };
  }
}
}

#endif

