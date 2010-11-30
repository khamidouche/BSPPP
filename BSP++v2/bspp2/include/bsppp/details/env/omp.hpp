/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef BSPPP_DETAILS_ENV_OMP_HPP_INCLUDED
#define BSPPP_DETAILS_ENV_OMP_HPP_INCLUDED



#include <omp.h>
#include <boost/program_options.hpp>
#include <bsppp/details/macros.hpp>
#include <sys/time.h>

namespace OMP
{
namespace bsp
{
  namespace details
  {
    namespace po = boost::program_options;

    ////////////////////////////////////////////////////////////////////////////
    // OpenMP runtime
    ////////////////////////////////////////////////////////////////////////////
    struct runtime
    {
      static void startup(int argc, char** argv)
      {/*
        po::options_description desc;
        desc.add_options()( "threads", po::value<int>());

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        if(vm.count("threads")) omp_set_num_threads(vm["threads"].as<int>());
        */
      }

      static void shutdown() {}

      static int pid()      { return omp_get_thread_num();  }
      static int size()     { return omp_get_num_threads(); }
      static double time()  {

                              //static int sec = -1;
                              struct timeval tv;
                              gettimeofday(&tv, NULL);
                              //if (sec < 0) sec = tv.tv_sec;
                              return (tv.tv_sec/* - sec*/) + 1.0e-6*tv.tv_usec;

                              }
    };
  }
}
}
////////////////////////////////////////////////////////////////////////////////
// BSP Environnement helper macros
////////////////////////////////////////////////////////////////////////////////
//#define BSP_STARTUP() //BSP_PRAGMA( omp parallel )




#endif
