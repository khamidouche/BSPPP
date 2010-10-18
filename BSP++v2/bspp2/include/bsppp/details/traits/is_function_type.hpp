/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_DETAILS_TRAITS_IS_FUNCTION_TYPE_HPP_INCLUDED
#define BSPPP_DETAILS_TRAITS_IS_FUNCTION_TYPE_HPP_INCLUDED

#include <boost/mpl/or.hpp>
#include <boost/mpl/and.hpp>
#include <boost/type_traits/is_function.hpp>
#include <boost/type_traits/is_pointer.hpp>
#include <boost/type_traits/remove_pointer.hpp>

namespace MPI
{
namespace bsp
{
  namespace details
  {
    template<class T>
    struct is_function_type
         : boost::mpl::or_< boost::is_function<T>
                          , boost::mpl::and_< boost::is_function<typename boost::remove_pointer<T>::type>
                                            , boost::is_pointer<T>
                                            >
                          > {};
  }
}
}
namespace OMP
{
namespace bsp
{
  namespace details
  {
    template<class T>
    struct is_function_type
         : boost::mpl::or_< boost::is_function<T>
                          , boost::mpl::and_< boost::is_function<typename boost::remove_pointer<T>::type>
                                            , boost::is_pointer<T>
                                            >
                          > {};
  }
}
}

#endif
