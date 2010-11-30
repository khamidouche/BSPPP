/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_DETAILS_TRAITS_IS_RESULT_OF_SUPPORTED_HPP_INCLUDED
#define BSPPP_DETAILS_TRAITS_IS_RESULT_OF_SUPPORTED_HPP_INCLUDED

#include <boost/mpl/or.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/function_types/result_type.hpp>
#include <bsppp/details/traits/enable_if_type.hpp>

namespace MPI
{
namespace bsp
{
  namespace details
  {
    //////////////////////////////////////////////////////////////////////////
    // Is result_type defined in a given type ?
    //////////////////////////////////////////////////////////////////////////
    BOOST_MPL_HAS_XXX_TRAIT_DEF(result_type)

    //////////////////////////////////////////////////////////////////////////
    // Is a inner result struct defined in a given type ?
    //////////////////////////////////////////////////////////////////////////
    template<class F, class FArgs, class Enable=void>
    struct result_defined
         : boost::false_type {};

    template<class F, class Args>
    struct result_defined< F
                         , Args
                         , typename enable_if_type<
                                    typename F::template result<Args>::type
                                                        >::type
                         >
         : boost::true_type {};

    namespace bft = boost::function_types;

    ////////////////////////////////////////////////////////////////////////////
    /// Checks for result_of protocol compliance
    /// Return boost::true_type if boost::result_of<T>::type is defined.
    ////////////////////////////////////////////////////////////////////////////
    template<class T, class Enable=void>
    struct is_result_of_supported : boost::false_type {};

    template<class T>
    struct is_result_of_supported<T, typename boost::enable_if<
          boost::mpl::or_< has_result_type<typename bft::result_type<T>::type>
                         , result_defined<typename bft::result_type<T>::type,T>
                         >
            >::type
        > : boost::true_type {};
  }
}
}

namespace OMP
{
namespace bsp
{
  namespace details
  {
    //////////////////////////////////////////////////////////////////////////
    // Is result_type defined in a given type ?
    //////////////////////////////////////////////////////////////////////////
    BOOST_MPL_HAS_XXX_TRAIT_DEF(result_type)

    //////////////////////////////////////////////////////////////////////////
    // Is a inner result struct defined in a given type ?
    //////////////////////////////////////////////////////////////////////////
    template<class F, class FArgs, class Enable=void>
    struct result_defined
         : boost::false_type {};

    template<class F, class Args>
    struct result_defined< F
                         , Args
                         , typename enable_if_type<
                                    typename F::template result<Args>::type
                                                        >::type
                         >
         : boost::true_type {};

    namespace bft = boost::function_types;

    ////////////////////////////////////////////////////////////////////////////
    /// Checks for result_of protocol compliance
    /// Return boost::true_type if boost::result_of<T>::type is defined.
    ////////////////////////////////////////////////////////////////////////////
    template<class T, class Enable=void>
    struct is_result_of_supported : boost::false_type {};

    template<class T>
    struct is_result_of_supported<T, typename boost::enable_if<
          boost::mpl::or_< has_result_type<typename bft::result_type<T>::type>
                         , result_defined<typename bft::result_type<T>::type,T>
                         >
            >::type
        > : boost::true_type {};
  }
}
}

#endif
