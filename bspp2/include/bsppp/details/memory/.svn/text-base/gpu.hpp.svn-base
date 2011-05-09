/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_DETAILS_MEMORY_GPU_HPP_INCLUDED
#define BSPPP_DETAILS_MEMORY_GPU_HPP_INCLUDED

#if defined(BSP_GPU_TARGET)
namespace bsp
{
  namespace details
  {
    ////////////////////////////////////////////////////////////////////////////
    // GPU BSP Machine memory allocation
    ////////////////////////////////////////////////////////////////////////////
    template<class T> inline void alloc(T*& data,int size)
    {
      data = new T[size]; // CUDAMallocHost ???
    }

    ////////////////////////////////////////////////////////////////////////////
    // GPU BSP Machine memory desallocation
    ////////////////////////////////////////////////////////////////////////////
    template<class T> inline void release(T*& data)
    {
      if(!data) delete[] data;
      data = 0;
    }
  }
}

#endif

#endif

