/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_DETAILS_TRAITS_ENABLE_IF_TYPE_HPP_INCLUDED
#define BSPPP_DETAILS_TRAITS_ENABLE_IF_TYPE_HPP_INCLUDED

namespace MPI
{
namespace bsp
{
  namespace details
  {
    ////////////////////////////////////////////////////////////////////////////
    /// SFINAE check on type existence
    /// If type T is a valid type, then enable_if<T,R>::type evaluates to R
    ////////////////////////////////////////////////////////////////////////////
    template<class T, class Result=void> struct enable_if_type
    {
      typedef Result type;
    };
  }
}
}

namespace OMP
{
namespace bsp
{
  namespace details
  {
    ////////////////////////////////////////////////////////////////////////////
    /// SFINAE check on type existence
    /// If type T is a valid type, then enable_if<T,R>::type evaluates to R
    ////////////////////////////////////////////////////////////////////////////
    template<class T, class Result=void> struct enable_if_type
    {
      typedef Result type;
    };
  }
}
}
#endif
