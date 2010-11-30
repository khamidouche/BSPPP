/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_CORE_TRAITS_BSP_RESULT_HPP_INCLUDED
#define BSPPP_CORE_TRAITS_BSP_RESULT_HPP_INCLUDED

#include <boost/lambda/lambda.hpp>
#include <boost/utility/result_of.hpp>
#include <boost/function_types/result_type.hpp>
#include <bsppp/details/traits/is_function_type.hpp>

namespace MPI
{
namespace bsp
{
  namespace details
  {
    namespace bm = boost::mpl;
    namespace bf = boost::function_types;

    ////////////////////////////////////////////////////////////////////////////
    // BSP Callable entity returns type either
    // - as a real function
    // - as a PFO
    ////////////////////////////////////////////////////////////////////////////
    template<class T, bool EnableIf = details::is_function_type<T>::value>
    struct bsp_result_impl : boost::result_of<T(int)> {};

    template<class T>
    struct bsp_result_impl<T,true> : bf::result_type<T> {};
   }

  namespace traits
  {
    ////////////////////////////////////////////////////////////////////////////
    // Return the result type of a call to a BSP Callable Entity
    ////////////////////////////////////////////////////////////////////////////
    template<class T>
    struct bsp_result : details::bsp_result_impl<T> {};

    ////////////////////////////////////////////////////////////////////////////
    // Overload for boost::lambda
    ////////////////////////////////////////////////////////////////////////////
    template<class T>
    struct bsp_result<boost::lambda::lambda_functor<T> >
    {
      typedef typename T::template sig< boost::tuple<int> >::type type;
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
    namespace bm = boost::mpl;
    namespace bf = boost::function_types;

    ////////////////////////////////////////////////////////////////////////////
    // BSP Callable entity returns type either
    // - as a real function
    // - as a PFO
    ////////////////////////////////////////////////////////////////////////////
    template<class T, bool EnableIf = details::is_function_type<T>::value>
    struct bsp_result_impl : boost::result_of<T(int)> {};

    template<class T>
    struct bsp_result_impl<T,true> : bf::result_type<T> {};
   }

  namespace traits
  {
    ////////////////////////////////////////////////////////////////////////////
    // Return the result type of a call to a BSP Callable Entity
    ////////////////////////////////////////////////////////////////////////////
    template<class T>
    struct bsp_result : details::bsp_result_impl<T> {};

    ////////////////////////////////////////////////////////////////////////////
    // Overload for boost::lambda
    ////////////////////////////////////////////////////////////////////////////
    template<class T>
    struct bsp_result<boost::lambda::lambda_functor<T> >
    {
      typedef typename T::template sig< boost::tuple<int> >::type type;
    };
  }
}
}


#endif
