/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_DETAILS_MEMORY_OMP_HPP_INCLUDED
#define BSPPP_DETAILS_MEMORY_OMP_HPP_INCLUDED

namespace OMP
{
namespace bsp
{
  namespace details
  {
    ////////////////////////////////////////////////////////////////////////////
    // OpenMP BSP Machine memory allocation
    ////////////////////////////////////////////////////////////////////////////
    template<class T> inline void alloc(T*& data,int size)
    {
      static T* tmp;

      #pragma omp single
      tmp =  new T[size];

      data = tmp;
    }

    ////////////////////////////////////////////////////////////////////////////
    // OpenMP BSP Machine memory desallocation
    ////////////////////////////////////////////////////////////////////////////
    template<class T> inline void release(T*& data)
    {
      #pragma omp single
      if(!data) delete[] data;

      data = 0;
    }
  }
}

}

#endif
