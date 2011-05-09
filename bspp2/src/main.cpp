/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/


#include <bsppp/bsppp.hpp>

int bsp_main(int argc, char** argv);


#if defined(BSP_MPI_TARGET) || defined(BSP_HYB_TARGET)


/******************************************************************************
 * MPI Parallel environnement
 ******************************************************************************/

#include <boost/mpi.hpp>

//namespace bsp
//{
int main (int argc, char** argv)
{
/// start the MPI env

if(!MPI::bsp::details::runtime::running)
        {
          MPI::bsp::details::runtime::environment = new boost::mpi::environment(argc,argv);
          MPI::bsp::details::runtime::rank        = MPI::bsp::details::runtime::world.rank();
          MPI::bsp::details::runtime::procs       = MPI::bsp::details::runtime::world.size();
          MPI::bsp::details::runtime::running     = true;
        }

/// call to the user main function

bsp_main(argc, argv);


/// Finalize the MPI env


if(MPI::bsp::details::runtime::environment) delete MPI::bsp::details::runtime::environment;
MPI::bsp::details::runtime::environment = 0;




//}


}

#endif

#if defined(BSP_OMP_TARGET)



/******************************************************************************
 * OMP Parallel environnement
 ******************************************************************************/

#include <omp.h>
#include <boost/program_options.hpp>
//namespace bsp
//{
int main (int argc, char** argv)
{
//using namespace OMP::bsp;

/// start the OMP parallel section
#pragma omp parallel
{

/// call to the user main function
bsp_main(argc, argv);


/// Finalize the MPI env

}

//}


}



#endif
