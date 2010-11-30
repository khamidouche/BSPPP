/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_CORE_TRAITS_IS_PAR_HPP_INCLUDED
#define BSPPP_CORE_TRAITS_IS_PAR_HPP_INCLUDED

#include <boost/type_traits/remove_cv.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <bsppp/core/pid.hpp>



namespace MPI
{
namespace bsp
{
  template<class T> class par;

  namespace details
  {
    using boost::integral_constant;
    template<class T> struct is_par_impl                  : integral_constant<bool,false> {};
    template<class T> struct is_par_impl<par<T> >         : integral_constant<bool,true> {};
    template<>        struct is_par_impl<constant::pid_>  : integral_constant<bool,true> {};
  }

  namespace traits
  {
    ////////////////////////////////////////////////////////////////////////////
    // Does T behaves as a BSP Parallel vector
    ////////////////////////////////////////////////////////////////////////////
    template<class T>
    struct is_par : details::is_par_impl< typename boost::remove_cv<T>::type >
    {};
  }
}

}


namespace OMP
{
namespace bsp
{
  template<class T> class par;

  namespace details
  {
    using boost::integral_constant;
    template<class T> struct is_par_impl                  : integral_constant<bool,false> {};
    template<class T> struct is_par_impl<par<T> >         : integral_constant<bool,true> {};
    template<>        struct is_par_impl<constant::pid_>  : integral_constant<bool,true> {};
  }

  namespace traits
  {
    ////////////////////////////////////////////////////////////////////////////
    // Does T behaves as a BSP Parallel vector
    ////////////////////////////////////////////////////////////////////////////
    template<class T>
    struct is_par : details::is_par_impl< typename boost::remove_cv<T>::type >
    {};
  }
}

}


#endif
