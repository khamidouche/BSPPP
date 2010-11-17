/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/

#ifndef  TEST_GMV_FINE_HPP__INCLUDED__
#define  TEST_GMV_FINE_HPP__INCLUDED__


#include "bsp_GMV_fine.hpp"
#include "data.hpp"


using namespace std;
using namespace bsp;
namespace bl = boost::lambda;


//
//vector<int> transf0( int ind, par<vector<int> > const& v )
//  {
//    if(*pid_==0)
//     return *v;
//   else return vector<int>();
//
//  }



template<class T>
void test_gmv_fine(int argc, char ** argv){




      int p, pid, s, t, i, M,N,n;
    double  time0, time1,Tcomp,Tcomm;


    data<double> A;
    std::vector<double> U;
    std::vector<double> V;






        n=atoi(argv[1]);






    /* Compute 2D processor numbering from 1D numbering */




         A.resize(n,n);
         U.resize(n);
         V.resize(n);





  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      {
       A(i,j)=1.0;
       }
  }
  for(int j=0;j<n;j++)
      {
       U[j]=1.0;
       }


  for(int i=0;i<n;i++)
       V[i]=0.0;




            std::cout<<"Start of the MV Multiplication"<<std::endl;




    Tcomm=0.0;
    Tcomp=0.0;

     time0=bsp::time();

    bsp_GMV_fine<double>(n,U,A,V,Tcomp,Tcomm);
///////////////////////////////////////*



//////////////////////////////////////*


    time1=bsp::time();




           std::cout<<"This took only " <<time1-time0<<" seconds"<<std::endl;
           std::cout<<"This took only computing " <<Tcomp<<" seconds"<<std::endl;
           std::cout<<"This took only communication " <<Tcomm<<" seconds"<<std::endl;
           //std::cout<<"The output permutation is"<<std::endl;
         /*  std::ofstream  fout;
           fout.open("MV_result",std::ofstream::app);
           if(!fout.is_open()) printf("cannot open the FILE \n");
           else{
              fout <<bsp_procs()<<" computing "<< Tcomp<<" communication "<<Tcomm<<"  "<<n;
              fout << std::endl;
              fout.flush();
             }
           fout.close();
           */



            std::cout<<"The output Vector is"<<std::endl;

        for (i=0; i<4; i++)
                std::cout<<"rank = "<<pid<<" V [ "<<i<<" ] = "<<V[i]<<std::endl;






}



#endif


