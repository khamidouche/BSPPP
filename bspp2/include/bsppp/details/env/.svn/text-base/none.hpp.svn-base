/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_DETAILS_ENV_NONE_INCLUDED
#define BSPPP_DETAILS_ENV_NONE_INCLUDED

#error No BSP architecture selected

namespace bsppp
{
  namespace details
  {
    struct runtime
    {
      void init(int, char**) {}
      ~runtime()  {}

      // Informations about processus rank and world size
      int pid()   const { return 0;  }
      int size()  const { return 1; }
    };
  }
}

#define BSP_STARTUP()
/**/

#endif

#endif

