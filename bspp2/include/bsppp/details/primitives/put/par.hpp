/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_DETAILS_PRIMITIVES_PUT_PAR_HPP_INCLUDED
#define BSPPP_DETAILS_PRIMITIVES_PUT_PAR_HPP_INCLUDED

#include <boost/function.hpp>
#include <bsppp/details/memory/buffer.hpp>
#include <bsppp/details/primitives/put/data.hpp>


#include <boost/range.hpp>


namespace MPI
{
namespace bsp
{
  //////////////////////////////////////////////////////////////////////////////
  // BSP Parallel vector of put() result.
  // This one is optimized so it doesn't allocate too much memory for the put
  // result arrays. This is hidden by the result_of::put<T> type.
  //////////////////////////////////////////////////////////////////////////////
  template<class T> class par< details::put_data<T> >
  {
    public:
    typedef details::put_data<T>        value_type;
    typedef details::put_data<T>&       reference;
    typedef details::put_data<T> const& const_reference;
    typedef details::put_data<T>*       pointer;
    typedef details::put_data<T> const* const_pointer;

    typedef typename value_type::base   base;

    par() : results_(details::put_impl<base>::extent()) {}

    par( const_reference f ) : results_(details::put_impl<base>::extent())
    {
      data_.reset(f,&results_);
    }

    par& operator=( const_reference f )
    {
      data_.reset(f,&results_);
      return *this;
    }

    reference       operator*()       { return data_;  }
    const_reference operator*() const { return data_;  }

    pointer         operator->()       { return &data_;  }
    const_pointer   operator->() const { return &data_;  }

    private:
    details::buffer<base> results_;
    value_type            data_;
  };
} }


namespace OMP
{
namespace bsp
{
  //////////////////////////////////////////////////////////////////////////////
  // BSP Parallel vector of put() result.
  // This one is optimized so it doesn't allocate too much memory for the put
  // result arrays. This is hidden by the result_of::put<T> type.
  //////////////////////////////////////////////////////////////////////////////
  template<class T> class par< details::put_data<T> >
  {
    public:
    typedef details::put_data<T>        value_type;
    typedef details::put_data<T>&       reference;
    typedef details::put_data<T> const& const_reference;
    typedef details::put_data<T>*       pointer;
    typedef details::put_data<T> const* const_pointer;


    typedef typename value_type::base   base;

    par() : results_(details::put_impl<base>::extent()) {}

    par( const_reference f ) : results_(details::put_impl<base>::extent())
    {
      data_.reset(f,&results_);
    }

    par& operator=( const_reference f )
    {
      data_.reset(f,&results_);
      return *this;
    }

    reference       operator*()       { return data_;  }
    const_reference operator*() const { return data_;  }

    pointer         operator->()       { return &data_;  }
    const_pointer   operator->() const { return &data_;  }


    private:
    details::buffer<base> results_;
    value_type            data_;
  };



  template<class T> inline
  boost::iterator_range< typename std::vector<T>::iterator > split (std::vector<T> & value)
   {

//     if (is_integral<T>::type == true_type)
//     {
//         return value;
//      }
//      else
//      {
        int offset= value.size()/size();



        return boost::make_iterator_range(value.begin()+(offset*pid()),value.begin()+(offset*pid())+offset);
     // }

      }



}
}

#endif
