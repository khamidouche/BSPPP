/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/

#include <bsppp/bsppp.hpp>

#if defined(BSP_MPI_TARGET) or (BSP_HYB_TARGET)

/******************************************************************************
 * MPI Parallel environnement
 ******************************************************************************/
namespace MPI
{
namespace bsp
{
  namespace details
  {
    namespace bmpi = boost::mpi;

    bmpi::environment*  runtime::environment = 0;
    bmpi::communicator  runtime::world;
    int                 runtime::rank         = 0;
    int                 runtime::procs        = 1;
    bool                runtime::running      = false;
  }
}
}
#endif
