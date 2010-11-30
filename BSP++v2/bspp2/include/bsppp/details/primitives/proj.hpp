/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_DETAILS_PRIMITIVES_PROJ_HPP_INCLUDED
#define BSPPP_DETAILS_PRIMITIVES_PROJ_HPP_INCLUDED

#include <boost/ref.hpp>
#include <bsppp/core/traits/is_par.hpp>
#include <bsppp/details/memory/buffer.hpp>
#include <bsppp/details/primitives/proj/mpi.hpp>
#include <bsppp/details/primitives/proj/omp.hpp>
#include <bsppp/details/primitives/proj/gpu.hpp>

namespace MPI
{
namespace bsp
{
  namespace details
  {
    ////////////////////////////////////////////////////////////////////////////
    // Actual proj(p) resulting Polymorphic Function Object
    ////////////////////////////////////////////////////////////////////////////
    template<class T> struct proj
    {


      typedef typename buffer<T>::iterator       iterator;
      typedef typename buffer<T>::iterator const const_iterator;
      // Default constructor
      proj() : data_(size()) {}

      // Construction and affectation from proj(par<T>)
      template<class P> proj( P const& p ) : data_(size())
      {
        proj_impl(data_,pid(),*p.get());
      }

      template<class P> proj& operator=(P const& p)
      {

        proj_impl(data_,pid(),*p.get());
        return *this;
      }

      // result_of protocol compliance
      typedef T const& result_type;

      // polymorphic function obejct interface
      result_type operator()(int i) const { return data_[i]; }


      iterator begin() {return data_.begin();}
      iterator end() {return data_.end();}

      const_iterator begin() const {return data_.begin();}
      const_iterator end() const   {return data_.end();}

      private:
      details::buffer<T> data_;
    };
  }

  namespace result_of
  {
    ////////////////////////////////////////////////////////////////////////////
    // Return type of proj(par<T>)
    ////////////////////////////////////////////////////////////////////////////
    template<class T> struct proj { typedef details::proj<T> type; };
  }

  template<class T> struct result_of_proj : result_of::proj<T> {};

  //////////////////////////////////////////////////////////////////////////////
  // As in "New syntax for a High-level BSP language", section 2.2.3,
  // Given a parallel vector, it returns a function object that, applied to
  // the pid of a processor, returns the value of this parallel vector at this
  // processor. proj is a synchronous primitive that ends current super-step.
  //////////////////////////////////////////////////////////////////////////////
  template<class T> inline
  typename boost::enable_if< traits::is_par<T>
                           , boost::reference_wrapper<T const>
                           >::type
  proj(T const& v)         { return boost::cref(v);    }
}
}

namespace OMP
{
namespace bsp
{
  namespace details
  {
    ////////////////////////////////////////////////////////////////////////////
    // Actual proj(p) resulting Polymorphic Function Object
    ////////////////////////////////////////////////////////////////////////////
    template<class T> struct proj
    {
      typedef typename buffer<T>::iterator       iterator;
      typedef typename buffer<T>::iterator const const_iterator;
      // Default constructor
      proj() : data_(size()) {}

      // Construction and affectation from proj(par<T>)
      template<class P> proj( P const& p ) : data_(size())
      {
        proj_impl(data_,pid(),*p.get());
      }

      template<class P> proj& operator=(P const& p)
      {
        proj_impl(data_,pid(),*p.get());
        return *this;
      }

      // result_of protocol compliance
      typedef T const& result_type;

      // polymorphic function obejct interface
      result_type operator()(int i) const { return data_[i]; }


      iterator begin() {return data_.begin();}
      iterator end() {return data_.end();}

      const_iterator begin() const {return data_.begin();}
      const_iterator end() const   {return data_.end();}

      private:
      details::buffer<T> data_;
    };



  }

  namespace result_of
  {
    ////////////////////////////////////////////////////////////////////////////
    // Return type of proj(par<T>)
    ////////////////////////////////////////////////////////////////////////////
    template<class T> struct proj { typedef details::proj<T> type; };
  }

  template<class T> struct result_of_proj : result_of::proj<T> {};

  //////////////////////////////////////////////////////////////////////////////
  // As in "New syntax for a High-level BSP language", section 2.2.3,
  // Given a parallel vector, it returns a function object that, applied to
  // the pid of a processor, returns the value of this parallel vector at this
  // processor. proj is a synchronous primitive that ends current super-step.
  //////////////////////////////////////////////////////////////////////////////
  template<class T> inline
  typename boost::enable_if< traits::is_par<T>
                           , boost::reference_wrapper<T const>
                           >::type
  proj(T const& v)         { return boost::cref(v);    }
}
}

#endif
