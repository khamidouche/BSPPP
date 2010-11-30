/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_DETAILS_PRIMITIVES_SPLIT_HPP_INCLUDED
#define BSPPP_DETAILS_PRIMITIVES_SPLIT_HPP_INCLUDED

#include <boost/utility/result_of.hpp>
#include <bsppp/core/par.hpp>
#include <bsppp/details/primitives/is_range.hpp>
#include <boost/range/adaptor/sliced.hpp>


namespace OMP { namespace bsp
{




  struct split_
  {
    template<class Sig> struct result;
    template<class This,class Value,class Splitter>
    struct result<This(Value,Splitter)>
    {
      typedef typename
      boost::result_of<Splitter(Value,std::size_t,std::size_t)>::type splittee;
      typedef par<splittee> type;
    };

    template<class Value,class Splitter> inline
    typename result<split_(Value,Splitter)>::type
    operator()(Value const& v, Splitter s) const
    {
      typename result<split_(Value,Splitter)>::type that = s(v,pid(),size());
      return that;
    }

    ///
    template<class Value,class Splitter> inline
    typename result<split_(Value,Splitter)>::type
    operator()(Value & v, Splitter s) const
    {
      typename result<split_(Value,Splitter)>::type that = s(v,pid(),size());
      return that;
    }


  };

  template<class Value, class Splitter>
  struct  result_of_split
        : boost::result_of<split_(Value,Splitter)>
  {};

  //////////////////////////////////////////////////////////////////////////////
  // BSP Machine number of processor
  //////////////////////////////////////////////////////////////////////////////
  template<class Value, class Splitter> inline
  typename result_of_split<Value,Splitter>::type
  split( Value const& v, Splitter s )
  {
    split_ callee;
    return callee(v,s);
  }


  ///
  template<class Value, class Splitter> inline
  typename result_of_split<Value,Splitter>::type
  split( Value & v, Splitter s )
  {
    split_ callee;
    return callee(v,s);
  }




  /// linear spliter ///
  struct linear
{
  template<class Sig> struct result;
  template<class This,class Value>
  struct result<This(Value,std::size_t,std::size_t)>
  {
    typedef typename boost::mpl::if_<
                               boost::is_range<Value>
                             , typename boost::iterator_range< typename boost::range_iterator<Value >::type >
                             , Value
                             >::type type;



   // typedef boost::iterator_range< typename boost::range_iterator<Value const>::type > type;
  };

  template<class Value> inline
  typename result<linear(Value,std::size_t,std::size_t)>::type
  eval(Value const& v, std::size_t pid,std::size_t sz,boost::mpl::true_ const& ) const
  {
    std::size_t rs = boost::size(v)/sz;
    return boost::adaptors::slice(v,pid*rs,(pid+1)*rs);
  }

  template<class Value> inline
  typename result<linear(Value,std::size_t,std::size_t)>::type
  eval(Value const& v, std::size_t pid,std::size_t sz,boost::mpl::false_ const& ) const
  {

    return v;
  }

  template<class Value> inline
  typename result<linear(Value,std::size_t,std::size_t)>::type
  operator()(Value const& v, std::size_t pid,std::size_t sz) const
  {
    return eval(v,pid,sz,typename boost::is_range<Value>::type());
  }


  ////
  template<class Value> inline
  typename result<linear(Value,std::size_t,std::size_t)>::type
  eval(Value & v, std::size_t pid,std::size_t sz,boost::mpl::true_ const& ) const
  {
    std::size_t rs = boost::size(v)/sz;
    return boost::adaptors::slice(v,pid*rs,(pid+1)*rs);
  }

  template<class Value> inline
  typename result<linear(Value,std::size_t,std::size_t)>::type
  eval(Value & v, std::size_t pid,std::size_t sz,boost::mpl::false_ const& ) const
  {

    return v;
  }


  template<class Value> inline
  typename result<linear(Value,std::size_t,std::size_t)>::type
  operator()(Value & v, std::size_t pid,std::size_t sz) const
  {
    return eval(v,pid,sz,typename boost::is_range<Value>::type());
  }


};



}
}

#endif
