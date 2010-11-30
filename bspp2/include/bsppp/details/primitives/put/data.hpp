/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_DETAILS_PRIMITIVES_PUT_DATA_HPP_INCLUDED
#define BSPPP_DETAILS_PRIMITIVES_PUT_DATA_HPP_INCLUDED

#include <boost/function.hpp>
#include <bsppp/details/memory/buffer.hpp>
#include <bsppp/core/traits/bsp_result.hpp>
#include <bsppp/details/primitives/put/mpi.hpp>
#include <bsppp/details/primitives/put/omp.hpp>
#include <bsppp/details/primitives/put/gpu.hpp>

namespace MPI
{
namespace bsp
{
  namespace details
  {
    template<class Func> struct put_data
    {
      typedef typename traits::bsp_result<Func>::type base;

      typedef typename buffer<base>::iterator       iterator;
      typedef typename buffer<base>::iterator const const_iterator;


      put_data(): pid1(pid()), size1(size()) {}

      put_data(par< Func > const& f) : function_(*f), pid1(pid()),size1(size()) {}

      void reset(put_data const& v,buffer<base>* p)
      {
        function_ = v.function_;
        data_     = p;
        put_impl<base>::init(*data_,function_,pid1,size1);
      }

      typedef base const& result_type;
      result_type operator()(int i) const
      {
        return put_impl<base>::at(*data_,i,pid1,size1);
      }

      iterator begin() {return data_->begin();}
      iterator end() {return data_->end();}

      const_iterator begin() const {return data_->begin();}
      const_iterator end() const   {return data_->end();}

      private:
      Func        function_;
      buffer<base>*  data_;

      int pid1;
      int size1;
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
    template<class Func> struct put_data
    {
      typedef typename traits::bsp_result<Func>::type base;

      typedef typename buffer<base>::iterator       iterator;
      typedef typename buffer<base>::iterator const const_iterator;

      put_data(): pid1(pid()), size1(size()) {}

      put_data(par< Func > const& f) : function_(*f), pid1(pid()),size1(size()) {}

      void reset(put_data const& v,buffer<base>* p)
      {
        function_ = v.function_;
        data_     = p;
        put_impl<base>::init(*data_,function_,pid1,size1);
      }

      typedef base const& result_type;
      result_type operator()(int i) const
      {
        return put_impl<base>::at(*data_,i,pid1,size1);
      }


      iterator begin() {return data_->begin();}
      iterator end() {return data_->end();}

      const_iterator begin() const {return data_->begin();}
      const_iterator end() const   {return data_->end();}

      private:
      Func        function_;
      buffer<base>*  data_;

      int pid1;
      int size1;
    };
  }
}
}

#endif
