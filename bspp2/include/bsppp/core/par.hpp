/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_CORE_PAR_HPP_INCLUDED
#define BSPPP_CORE_PAR_HPP_INCLUDED

#include <boost/function.hpp>
#include <boost/mpl/assert.hpp>
#include <bsppp/details/macros.hpp>
#include <bsppp/core/environment.hpp>
#include <boost/utility/enable_if.hpp>
#include <bsppp/core/traits/is_par.hpp>
#include <boost/type_traits/is_convertible.hpp>
#include <bsppp/core/traits/is_bsp_callable.hpp>


namespace OMP
{
namespace bsp
{
  //////////////////////////////////////////////////////////////////////////////
  // BSP Parallel vector
  // Parallels vector are the main data-structure used by BSP programs
  //////////////////////////////////////////////////////////////////////////////
  template<class T> class par;
} }

namespace MPI
{
namespace bsp
{
  //////////////////////////////////////////////////////////////////////////////
  // BSP Parallel vector
  // Parallels vector are the main data-structure used by BSP programs
  //////////////////////////////////////////////////////////////////////////////
  template<class T> class par
  {
    ////////////////////////////////////////////////////////////////////////////
    // Compile-time prevention of nested parallelism
    ////////////////////////////////////////////////////////////////////////////
    BOOST_MPL_ASSERT_MSG( (boost::mpl::not_< traits::is_par<T> >::value)
                        , BSP_NO_SUPPORT_FOR_NESTED_PARALLELISM
                        , (par<T>)
                        );

    public:
    ////////////////////////////////////////////////////////////////////////////
    // public typedefs for value and operator* return types
    ////////////////////////////////////////////////////////////////////////////
    typedef T         value_type;
    typedef T*        pointer;
    typedef T const*  const_pointer;
    typedef T&        reference;
    typedef T const&  const_reference;

    ////////////////////////////////////////////////////////////////////////////
    // Defautl Ctor
    ////////////////////////////////////////////////////////////////////////////
    #if !defined(BSP_HYB_TARGET)
    par() : data_() {}
    #else
    par() : data_(), omp_data(0) {}
    #endif

    ////////////////////////////////////////////////////////////////////////////
    // Ctor from a value_type. Sematically equivalent to replicate
    ////////////////////////////////////////////////////////////////////////////
    #if !defined(BSP_HYB_TARGET)
    par( const_reference v )  : data_(v)  {  }
    #else
    par( const_reference v )  : data_(v), omp_data(0)  {  }
    #endif

    ////////////////////////////////////////////////////////////////////////////
    // Ctor from a par<U>
    ////////////////////////////////////////////////////////////////////////////
    #if !defined(BSP_HYB_TARGET)
    template<class U>
    par( par<U> const& v
       , typename boost::enable_if< boost::is_convertible<T,U> >::type* = 0
       )
    : data_(*v) {}

    #else
    template<class U>
    par( par<U> const& v
       , typename boost::enable_if< boost::is_convertible<T,U> >::type* = 0
       )
    : data_(*v), omp_data(0) {}
    #endif
    ////////////////////////////////////////////////////////////////////////////
    // Ctor from a BSP Callable Entity
    ////////////////////////////////////////////////////////////////////////////
    #if !defined(BSP_HYB_TARGET)
    template<class F>
    par( F f
       , typename boost::enable_if< traits::is_bsp_callable<F> >::type* = 0
       )
    : data_(f) {}

    ////////////////////////////////////////////////////////////////////////////
    // Ctor from a C-Array. tab[i] is owned by processor with pid==i.
    ////////////////////////////////////////////////////////////////////////////
    template<int N>   par( const T (& t)[N] ) : data_(t[pid()]) {}

    #else
     template<class F>
    par( F f
       , typename boost::enable_if< traits::is_bsp_callable<F> >::type* = 0
       )
    : data_(f), omp_data(0) {}

    ////////////////////////////////////////////////////////////////////////////
    // Ctor from a C-Array. tab[i] is owned by processor with pid==i.
    ////////////////////////////////////////////////////////////////////////////
    template<int N>   par( const T (& t)[N] ) : data_(t[pid()]), omp_data(0)  {}
    #endif
    ////////////////////////////////////////////////////////////////////////////
    // Affectation from value_type
    ////////////////////////////////////////////////////////////////////////////
    par& operator=( const_reference v )
    {
      data_ = v;
      return *this;
    }

    #if defined(BSP_HYB_TARGET)
    par& operator=( OMP::bsp::par<T> const& v )
    {
      omp_data = &v;
      return *this;
    }

    par( OMP::bsp::par<T> const& v ) : omp_data(&v) {}
    #endif

    ////////////////////////////////////////////////////////////////////////////
    // Affectation from a par<U>
    ////////////////////////////////////////////////////////////////////////////
    template<class U>
    typename boost::enable_if< boost::is_convertible<T,U>, par&>::type
    operator=( par<U> const& v )
    {
      data_ = *v;
      return *this;
    }

    ////////////////////////////////////////////////////////////////////////////
    // Affectation from a BSP Callable Entity
    ////////////////////////////////////////////////////////////////////////////
    template<class F>
    typename boost::enable_if< traits::is_bsp_callable<F>, par&>::type
    operator=( F f )
    {
      data_ = f;
      return *this;
    }
    ////////////////////////////////////////////////////////////////////////////
    // Affectation from a C-Array. tab[i] is owned by processor with pid==i.
    ////////////////////////////////////////////////////////////////////////////
    template<int N>   par& operator=( const T (& t)[N] )
    {
      data_ = t[pid()];
      return *this;
    }

    #if !defined(BSP_HYB_TARGET)
    ////////////////////////////////////////////////////////////////////////////
    // operator* is the equivalent to $.$ in BSML v2
    // e.g. : let u = $v$; <-> u = *v;
    ////////////////////////////////////////////////////////////////////////////
    reference       operator*()       { return data_;  }
    const_reference operator*() const { return data_;  }

    ////////////////////////////////////////////////////////////////////////////
    // operator-> is the equivalent to $.$ in BSML v2 for method calls
    ////////////////////////////////////////////////////////////////////////////
    pointer       operator->()       { return &data_;  }
    const_pointer operator->() const { return &data_;  }

   #else

    ////////////////////////////////////////////////////////////////////////////
    // operator* is the equivalent to $.$ in BSML v2
    // e.g. : let u = $v$; <-> u = *v;
    ////////////////////////////////////////////////////////////////////////////
    reference       operator*()       { return data_;  }
    const_reference operator*() const { return omp_data ? *(*omp_data) : data_;  }

    ////////////////////////////////////////////////////////////////////////////
    // operator-> is the equivalent to $.$ in BSML v2 for method calls
    ////////////////////////////////////////////////////////////////////////////
    pointer       operator->()       { return &data_;  }
    const_pointer operator->() const { return omp_data ? &(*(*omp_data)) : &data_;  }
    #endif

    private:
    ////////////////////////////////////////////////////////////////////////////
    // par<T> holds one value_type per machine in the BSP environment.
    ////////////////////////////////////////////////////////////////////////////
    value_type data_;
    #if defined(BSP_HYB_TARGET)
    OMP::bsp::par<T> const* omp_data;
    #endif
  };
}
}


namespace OMP
{
namespace bsp
{
  //////////////////////////////////////////////////////////////////////////////
  // BSP Parallel vector
  // Parallels vector are the main data-structure used by BSP programs
  //////////////////////////////////////////////////////////////////////////////
  template<class T> class par
  {
    ////////////////////////////////////////////////////////////////////////////
    // Compile-time prevention of nested parallelism
    ////////////////////////////////////////////////////////////////////////////
    BOOST_MPL_ASSERT_MSG( (boost::mpl::not_< traits::is_par<T> >::value)
                        , BSP_NO_SUPPORT_FOR_NESTED_PARALLELISM
                        , (par<T>)
                        );

    public:
    ////////////////////////////////////////////////////////////////////////////
    // public typedefs for value and operator* return types
    ////////////////////////////////////////////////////////////////////////////
    typedef T         value_type;
    typedef T*        pointer;
    typedef T const*  const_pointer;
    typedef T&        reference;
    typedef T const&  const_reference;

    ////////////////////////////////////////////////////////////////////////////
    // Defautl Ctor
    ////////////////////////////////////////////////////////////////////////////
    par() : data_() {}

    ////////////////////////////////////////////////////////////////////////////
    // Ctor from a value_type. Sematically equivalent to replicate
    ////////////////////////////////////////////////////////////////////////////
    par( const_reference v )  : data_(v)  {  }

    ////////////////////////////////////////////////////////////////////////////
    // Ctor from a par<U>
    ////////////////////////////////////////////////////////////////////////////
    template<class U>
    par( par<U> const& v
       , typename boost::enable_if< boost::is_convertible<T,U> >::type* = 0
       )
    : data_(*v) {}

    ////////////////////////////////////////////////////////////////////////////
    // Ctor from a BSP Callable Entity
    ////////////////////////////////////////////////////////////////////////////
    template<class F>
    par( F f
       , typename boost::enable_if< traits::is_bsp_callable<F> >::type* = 0
       )
    : data_(f) {}

    ////////////////////////////////////////////////////////////////////////////
    // Ctor from a C-Array. tab[i] is owned by processor with pid==i.
    ////////////////////////////////////////////////////////////////////////////
    template<int N>   par( const T (& t)[N] ) : data_(t[pid()]) {}

    ////////////////////////////////////////////////////////////////////////////
    // Affectation from value_type
    ////////////////////////////////////////////////////////////////////////////
    par& operator=( const_reference v )
    {
      data_ = v;
      return *this;
    }

    ////////////////////////////////////////////////////////////////////////////
    // Affectation from a par<U>
    ////////////////////////////////////////////////////////////////////////////
    template<class U>
    typename boost::enable_if< boost::is_convertible<T,U>, par&>::type
    operator=( par<U> const& v )
    {
      data_ = *v;
      return *this;
    }

    ////////////////////////////////////////////////////////////////////////////
    // Affectation from a BSP Callable Entity
    ////////////////////////////////////////////////////////////////////////////
    template<class F>
    typename boost::enable_if< traits::is_bsp_callable<F>, par&>::type
    operator=( F f )
    {
      data_ = f;
      return *this;
    }
    ////////////////////////////////////////////////////////////////////////////
    // Affectation from a C-Array. tab[i] is owned by processor with pid==i.
    ////////////////////////////////////////////////////////////////////////////
    template<int N>   par& operator=( const T (& t)[N] )
    {
      data_ = t[pid()];
      return *this;
    }

    ////////////////////////////////////////////////////////////////////////////
    // operator* is the equivalent to $.$ in BSML v2
    // e.g. : let u = $v$; <-> u = *v;
    ////////////////////////////////////////////////////////////////////////////
    reference       operator*()       { return data_;  }
    const_reference operator*() const { return data_;  }

    ////////////////////////////////////////////////////////////////////////////
    // operator-> is the equivalent to $.$ in BSML v2 for method calls
    ////////////////////////////////////////////////////////////////////////////
    pointer       operator->()       { return &data_;  }
    const_pointer operator->() const { return &data_;  }

    private:
    ////////////////////////////////////////////////////////////////////////////
    // par<T> holds one value_type per machine in the BSP environment.
    ////////////////////////////////////////////////////////////////////////////
    value_type data_;
  };
}
}
#endif
