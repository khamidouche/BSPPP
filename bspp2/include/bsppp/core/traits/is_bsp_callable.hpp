/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_CORE_TRAITS_IS_BSP_CALLABLE_HPP_INCLUDED
#define BSPPP_CORE_TRAITS_IS_BSP_CALLABLE_HPP_INCLUDED

#include <boost/lambda/lambda.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/equal.hpp>
#include <bsppp/details/traits/is_function_type.hpp>
#include <bsppp/details/traits/is_result_of_supported.hpp>
#include <boost/type_traits/is_void.hpp>
#include <boost/type_traits/is_integral.hpp>
#include <boost/function_types/function_arity.hpp>
#include <boost/function_types/parameter_types.hpp>
#include <boost/function_types/result_type.hpp>

namespace MPI
{
namespace bsp
{
  namespace details
  {
    namespace bm = boost::mpl;
    namespace bf = boost::function_types;

    ////////////////////////////////////////////////////////////////////////////
    // Types are BSP compatible if :
    // - they're a PFO that support a T(int) call
    // - they're an unary function which :
    //        - as only one arguments
    //        - this one argument is integral
    //        - returns non-void type
    ////////////////////////////////////////////////////////////////////////////
    template<class T, bool EnableIf = details::is_function_type<T>::value>
    struct is_bsp_callable_impl
         : details::is_result_of_supported<T(int)>
    {};

    template<class T>
    struct is_bsp_callable_impl<T,true>
         : bm::and_< bm::bool_< bf::function_arity<T>::value == 1 >
                   , boost::is_integral<typename bm::at_c<typename bf::parameter_types<T>::type
                                                         ,0
                                                         >::type
                                       >
                   , bm::not_< boost::is_void<typename bf::result_type<T>::type> >
                   >
    {};
   }

  namespace traits
  {
    ////////////////////////////////////////////////////////////////////////////
    // Check if T can be used as a BSP compatible function
    ////////////////////////////////////////////////////////////////////////////
    template<class T>
    struct is_bsp_callable : details::is_bsp_callable_impl<T> {};

    ////////////////////////////////////////////////////////////////////////////
    // Overload for boost::lambda
    ////////////////////////////////////////////////////////////////////////////
    template<class T>
    struct is_bsp_callable<boost::lambda::lambda_functor<T> > : boost::true_type {};
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
    // Types are BSP compatible if :
    // - they're a PFO that support a T(int) call
    // - they're an unary function which :
    //        - as only one arguments
    //        - this one argument is integral
    //        - returns non-void type
    ////////////////////////////////////////////////////////////////////////////
    template<class T, bool EnableIf = details::is_function_type<T>::value>
    struct is_bsp_callable_impl
         : details::is_result_of_supported<T(int)>
    {};

    template<class T>
    struct is_bsp_callable_impl<T,true>
         : bm::and_< bm::bool_< bf::function_arity<T>::value == 1 >
                   , boost::is_integral<typename bm::at_c<typename bf::parameter_types<T>::type
                                                         ,0
                                                         >::type
                                       >
                   , bm::not_< boost::is_void<typename bf::result_type<T>::type> >
                   >
    {};
   }

  namespace traits
  {
    ////////////////////////////////////////////////////////////////////////////
    // Check if T can be used as a BSP compatible function
    ////////////////////////////////////////////////////////////////////////////
    template<class T>
    struct is_bsp_callable : details::is_bsp_callable_impl<T> {};

    ////////////////////////////////////////////////////////////////////////////
    // Overload for boost::lambda
    ////////////////////////////////////////////////////////////////////////////
    template<class T>
    struct is_bsp_callable<boost::lambda::lambda_functor<T> > : boost::true_type {};
  }
}
}
#endif

