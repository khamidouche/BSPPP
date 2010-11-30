/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_DETAILS_MACROS_HPP_INCLUDED
#define BSPPP_DETAILS_MACROS_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Macro for generating #pragma into other macros. See :
//
// http://www.delorie.com/gnu/docs/gcc/cpp_45.html
// http://msdn.microsoft.com/en-us/library/d9x1s805.aspx
//
// for details. This is mainly needed for the OpenMP target
////////////////////////////////////////////////////////////////////////////////
#if defined(__GNUC__)
#define BSP_PRAGMA(x) _Pragma (#x)
#elif defined(BOOST_MSVC)
#define BSP_PRAGMA(x) __pragma (#x)
#endif

////////////////////////////////////////////////////////////////////////////////
// Remove warning for enable_if on constructor and other generic functions.
////////////////////////////////////////////////////////////////////////////////
namespace MPI
{
namespace bsp
{
  template<class T> void ignore_unused_param(T const&) {}
}
}
namespace OMP
{
namespace bsp
{
  template<class T> void ignore_unused_param(T const&) {}
}
}

#endif
