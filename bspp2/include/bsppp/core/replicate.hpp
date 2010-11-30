/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_CORE_REPLICATE_HPP_INCLUDED
#define BSPPP_CORE_REPLICATE_HPP_INCLUDED

#include <boost/utility/result_of.hpp>
#include <bsppp/core/par.hpp>

namespace MPI
{
namespace bsp
{
  namespace result_of
  {
    struct replicate
    {
      template<class Sig> struct result;
      template<class This,class T> struct result<This(T)>
      {
        typedef par<T> type;
      };
    };
  }

  template<class T> inline
  typename boost::result_of<result_of::replicate(T)>::type
  replicate( T const& v )
  {
    typename boost::result_of<result_of::replicate(T)>::type that = v;
    return that;
  }
}
}

namespace OMP
{
namespace bsp
{
  namespace result_of
  {
    struct replicate
    {
      template<class Sig> struct result;
      template<class This,class T> struct result<This(T)>
      {
        typedef par<T> type;
      };
    };
  }

  template<class T> inline
  typename boost::result_of<result_of::replicate(T)>::type
  replicate( T const& v )
  {
    typename boost::result_of<result_of::replicate(T)>::type that = v;
    return that;
  }
}
}

#endif
