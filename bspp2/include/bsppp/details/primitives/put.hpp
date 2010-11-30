/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_DETAILS_PRIMITIVES_PUT_HPP_INCLUDED
#define BSPPP_DETAILS_PRIMITIVES_PUT_HPP_INCLUDED

#include <boost/function.hpp>
#include <bsppp/details/memory/buffer.hpp>
#include <bsppp/details/primitives/put/par.hpp>
#include <bsppp/core/traits/is_bsp_callable.hpp>

namespace MPI
{
namespace bsp
{
  namespace result_of
  {
    template<class T> struct put { typedef par< details::put_data<T> > type; };
  }

  template<class T> struct result_of_put : result_of::put<T> {};

  //////////////////////////////////////////////////////////////////////////////
  // PUT primitive
  //////////////////////////////////////////////////////////////////////////////
  template<class Func> inline
  typename boost::enable_if< traits::is_bsp_callable<Func>
                           , MPI::bsp::details::put_data<Func>
                           >::type
   put(par< Func > const& f)
  {
    return details::put_data<Func>(f);
  }
}
}

namespace OMP
{
namespace bsp
{
  namespace result_of
  {
    template<class T> struct put { typedef par< details::put_data<T> > type; };
  }

  template<class T> struct result_of_put : result_of::put<T> {};

  //////////////////////////////////////////////////////////////////////////////
  // PUT primitive
  //////////////////////////////////////////////////////////////////////////////
  template<class Func> inline
  typename boost::enable_if< traits::is_bsp_callable<Func>
                           , OMP::bsp::details::put_data<Func>
                           >::type
   put(par< Func > const& f)
   {
    return details::put_data<Func>(f);
   }
}
}

#endif
