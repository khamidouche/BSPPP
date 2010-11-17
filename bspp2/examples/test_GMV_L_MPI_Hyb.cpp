/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/



#include "bsp_GMV_L_MPI_Hyb.hpp"
#include "data.hpp"

#include <vector>
#include <iostream>
#include <fstream>


#include <bsppp/bsppp.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>

using namespace std;
using namespace bsp;
namespace bl = boost::lambda;



int transf0( int ind, par<int > const& v )
  {
    if(*pid_==0)
     return *v;
   else return int();

  }



template<class T>
void test_gmv_L_mpi_Hyb(int argc, char ** argv){


       BSP_FUNCTION(argc,argv)
    {

      int p, pid, s, t, i, M,N,n;
    double  time0, time1,Tcomp,Tcomm;

    p=bsp::size();
    pid=bsp::pid();

    data<double> A;
    std::vector<double> U;
    std::vector<double> V;
    par<std::vector<double> > ParV;
    par<int> taille;
    taille=0;

      if(pid==0)
      {


        *taille=atoi(argv[1]);

      }
      synchronize();

    par< boost::function< int(int)> > s1 = bl::bind(transf0,bl::_1,taille);
     result_of::put< boost::function<int (int)> >::type recv;

        recv =put(s1);


n=(*recv)(0);


    /* Compute 2D processor numbering from 1D numbering */




         A.resize(n/p,n);
         U.resize(n);
         V.resize(n);
       ParV= std::vector<double>(n/p);




  for(int i=0;i<n/p;i++){
    for(int j=0;j<n;j++)
      {
       A(i,j)=1.0;
       }
  }
  for(int j=0;j<n;j++)
      {
       U[j]=1.0;
       }


  for(int i=0;i<n/p;i++)
      (*ParV)[i]=0.0;



        if (pid==0)
            std::cout<<"Start of the MV Multiplication"<<std::endl;


    synchronize();

    Tcomm=0.0;
    Tcomp=0.0;

     time0=bsp::time();

    bsp_GMV_L_mpi_Hyb<double>(argc,argv,n,p,U,A,V,ParV,Tcomp,Tcomm);
///////////////////////////////////////*



//////////////////////////////////////*


    synchronize();
    time1=bsp::time();


        if (pid==0){

           std::cout<<"This took only " <<time1-time0<<" seconds"<<std::endl;
           std::cout<<"This took only computing " <<Tcomp<<" seconds"<<std::endl;
           std::cout<<"This took only communication " <<Tcomm<<" seconds"<<std::endl;
           //std::cout<<"The output permutation is"<<std::endl;
           std::ofstream  fout;
           fout.open("MV_result",std::ofstream::app);
           if(!fout.is_open()) printf("cannot open the FILE \n");
           else{
              fout <<p<<" computing "<< Tcomp<<" communication "<<Tcomm<<"  "<<n;
              fout << std::endl;
              fout.flush();
             }
           fout.close();

          }


        if (pid==0){
            std::cout<<"The output Vector is"<<std::endl;

        for (i=0; i<4; i++)
                std::cout<<"rank = "<<pid<<" V [ "<<i<<" ] = "<<V[i]<<std::endl;

         }


       synchronize();

    }
}


//int main(int argc, char** argv)
//{
//
//  test_gmv_L_mpi_Hyb<double>(argc,argv);
//  return 0;
//}





