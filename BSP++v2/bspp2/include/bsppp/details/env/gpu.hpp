/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_DETAILS_ENV_GPU_HPP_INCLUDED
#define BSPPP_DETAILS_ENV_GPU_HPP_INCLUDED

#if defined(BSP_GPU_TARGET)

namespace bsp
{
  namespace details
  {
    ////////////////////////////////////////////////////////////////////////////
    // GPU runtime
    ////////////////////////////////////////////////////////////////////////////
    struct runtime
    {
      static void startup(int argc, char** argv)
      {
      }

      static void shutdown()
      {
      }

      static int pid()     { return 0;   }
      static int size()    { return 0;  }
    };
  }
}

////////////////////////////////////////////////////////////////////////////////
// BSP Environnement helper macros
////////////////////////////////////////////////////////////////////////////////
#define BSP_STARTUP()

#endif

#endif
