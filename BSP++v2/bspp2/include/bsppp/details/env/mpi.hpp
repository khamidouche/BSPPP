/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_DETAILS_ENV_MPI_HPP_INCLUDED
#define BSPPP_DETAILS_ENV_MPI_HPP_INCLUDED

#include <boost/mpi.hpp>
#include <sys/time.h>

namespace MPI
{
namespace bsp
{

  namespace details
  {
    namespace bmpi = boost::mpi;

    ////////////////////////////////////////////////////////////////////////////
    // MPI runtime
    ////////////////////////////////////////////////////////////////////////////
    struct runtime
    {
      static void startup(int argc, char** argv)
      {
//        if(!running)
//        {
//          environment = new bmpi::environment(argc,argv);
//          rank        = world.rank();
//          procs       = world.size();
//          running     = true;
//        }
      }

      static void shutdown()
      {
//        if(environment) delete environment;
//        environment = 0;
      }

      static int pid()     { return rank;   }
      static int size()    { return procs;  }
      static double time()  {

                              static int sec = -1;
                              struct timeval tv;
                              gettimeofday(&tv, NULL);
                              if (sec < 0) sec = tv.tv_sec;
                              return (tv.tv_sec - sec) + 1.0e-6*tv.tv_usec;

                              }


      static bmpi::environment*  environment;
      static bmpi::communicator world;
      static int  rank;
      static int  procs;
      static bool running;
    };
  }
}
}
////////////////////////////////////////////////////////////////////////////////
// BSP Environnement helper macros
////////////////////////////////////////////////////////////////////////////////
#define BSP_STARTUP() BSP_PRAGMA( omp parallel ) \
  {                                              \
   using OMP::bsp::pid;                 \
   using OMP::bsp::time;                 \
   using OMP::bsp::size;                \
   using OMP::bsp::par;                \
   using OMP::bsp::put;                \
   using OMP::bsp::proj;                \
   using OMP::bsp::synchronize; \
    using OMP::bsp::result_of_proj;    \
    using OMP::bsp::result_of_put;    \
 using OMP::bsp::result_of_split;\
 using OMP::bsp::split; \
 using OMP::bsp::linear; \
   /**/



#define BSP_HYB_END() }



#endif
