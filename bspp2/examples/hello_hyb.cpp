
#include <iostream>
#include <bsppp/bsppp.hpp>

/*#include <functional>
#include <numeric>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
*/

using namespace std;


namespace bl = boost::lambda;

void fun_omp(int argc, char** argv, int mpi_pid)
{
     BSP_HYB_START(argc,argv)
     {
         int omp_pid= pid();
         int omp_size=size();

         cout<<"I'm thread rank "<<omp_pid<<" of MPI process rank "<<mpi_pid<<endl;

     }
     BSP_HYB_END()
}

int bsp_main(int argc, char** argv)
{
fun_omp(argc, argv, pid());

    return 0;
}

