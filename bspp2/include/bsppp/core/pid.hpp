/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_CORE_PID_HPP_INCLUDED
#define BSPPP_CORE_PID_HPP_INCLUDED

#include <bsppp/core/environment.hpp>

namespace MPI
{
namespace bsp
{
  namespace constant
  {
    class pid_
    {
      public:
      typedef int value_type;
      typedef int reference;
      typedef int const_reference;

      int operator*() const { return pid(); }
    };
  }

  //////////////////////////////////////////////////////////////////////////////
  // BSP pid_ parallel vector
  // pid_ is a predefined parallel vector so that *pid_ is always equal to local
  // parallel machine rank.
  //////////////////////////////////////////////////////////////////////////////
  constant::pid_ const pid_ = {};
}
}

namespace OMP
{
namespace bsp
{
  namespace constant
  {
    class pid_
    {
      public:
      typedef int value_type;
      typedef int reference;
      typedef int const_reference;

      int operator*() const { return pid(); }
    };
  }

  //////////////////////////////////////////////////////////////////////////////
  // BSP pid_ parallel vector
  // pid_ is a predefined parallel vector so that *pid_ is always equal to local
  // parallel machine rank.
  //////////////////////////////////////////////////////////////////////////////
  constant::pid_ const pid_ = {};
}
}
#endif
