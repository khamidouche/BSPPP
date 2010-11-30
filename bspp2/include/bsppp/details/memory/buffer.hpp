/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_DETAILS_BUFFER_HPP_INCLUDED
#define BSPPP_DETAILS_BUFFER_HPP_INCLUDED

#include <algorithm>
#include <bsppp/details/environment.hpp>
#include <bsppp/details/memory.hpp>

////////////////////////////////////////////////////////////////////////////////
/// buffer<T> is a fixed-size, dynamic array with a swallow copy semantic
////////////////////////////////////////////////////////////////////////////////
namespace MPI
{
namespace bsp
{

  namespace details
  {  //////////// plus


    template<class T> class buffer
    {
      public:
      typedef T           value_type;
      typedef T&          reference;
      typedef T const &   const_reference;

      typedef T*          iterator;
      typedef T const *   const_iterator;

      buffer(size_t size) : size_(size) { /*details::alloc(data_,size_);*/alloc(data_,size_); }
      buffer& operator=( buffer src )   { swap(src); return *this;  } // no throws

      ~buffer() { release(data_); }

      void swap( buffer& dst ) // no throws
      {
        std::swap(size_,dst.size_);
        std::swap(data_,dst.data_);
      }

      reference       operator[](size_t i)        { return data_[i];  }
      const_reference operator[](size_t i)  const { return data_[i];  }

      iterator begin() {return data_;}
      iterator end()   {return data_+size_;}

      const_iterator begin() const   {return data_;}
      const_iterator end() const     {return data_+size_;}

      private:
      size_t  size_;
      T*      data_;
    };

    ////////////////////////////////////////////////////////////////////////////
    // swap function
    ////////////////////////////////////////////////////////////////////////////
    template<class T> inline
    void swap( buffer<T>& a, buffer<T>& b ) { a.swap(b); }
  }

}
}

namespace OMP
{
namespace bsp
{

  namespace details
  {  //////////// plus


    template<class T> class buffer
    {
      public:
      typedef T           value_type;
      typedef T&          reference;
      typedef T const &   const_reference;

      typedef T*          iterator;
      typedef T const *   const_iterator;


      buffer(size_t size) : size_(size) {  OMP::bsp::details::alloc(data_,size_); }
      buffer& operator=( buffer src )   { swap(src); return *this;  } // no throws

      ~buffer() { OMP::bsp::details::release(data_); }

      void swap( buffer& dst ) // no throws
      {
        std::swap(size_,dst.size_);
        std::swap(data_,dst.data_);
      }

      reference       operator[](size_t i)        { return data_[i];  }
      const_reference operator[](size_t i)  const { return data_[i];  }


      iterator begin() {return data_;}
      iterator end()   {return data_+size_;}

      const_iterator begin() const   {return data_;}
      const_iterator end() const     {return data_+size_;}

      private:
      size_t  size_;
      T*      data_;
    };

    ////////////////////////////////////////////////////////////////////////////
    // swap function
    ////////////////////////////////////////////////////////////////////////////
    template<class T> inline
    void swap( buffer<T>& a, buffer<T>& b ) { a.swap(b); }
  }

}
}

#endif
