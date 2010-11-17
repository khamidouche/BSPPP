/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/

#ifndef  TEST_GMM_FINE_HPP__INCLUDED__
#define  TEST_GMM_FINE_HPP__INCLUDED__




#include <vector>
#include <iostream>
#include <fstream>

//#include  "bsppp/include/bsppp.hpp"
#include  "data.hpp"
#include  "bsp_GMM_fine.hpp"


using namespace std;
using namespace bsp;
namespace bl = boost::lambda;


template<class T>
void test_gmm_fine(int argc, char ** argv){

//    int p, pid, s, t, nlr, nlc, i, j, iglob, jglob, m1,n1,nm,M,N,n;
//    double  time0, time1;



      int nm,b;
    double  time0, time1,Tcomp,Tcomm;
    data<double> A,B,C;








        nm=atoi(argv[1]);
        b=atoi(argv[2]);





    /* Compute 2D processor numbering from 1D numbering */



           A.resize(nm,nm);
           //B.resize(nlc,nlr);
           B.resize(nm,nm);
           C.resize(nm,nm);








             std::cout<<"MM Mulitiplication of "<< nm <<" by "<< nm<<" matrix"<<std::endl;





  for(int i=0;i<nm;i++)
    for(int j=0;j<nm;j++)
    {

       C(i,j)=0.0;
       A(i,j)=1.0;
       B(i,j)=1.0;

    }




            std::cout<<"Start of the MM Multiplication"<<std::endl;


    Tcomm=0.0;
    Tcomp=0.0;


     time0=bsp::time();

    bsp_GMM_fine<double>(nm,b,A,B,C,Tcomp,Tcomm);



    time1=bsp::time();



           std::cout<<"End of MM "<<std::endl;
           std::cout<<"This took only " <<time1-time0<<" seconds"<<std::endl;
           std::cout<<"This took only computing " <<Tcomp<<" seconds"<<std::endl;
           std::cout<<"This took only communication " <<Tcomm<<" seconds"<<std::endl;
           //std::cout<<"The output permutation is"<<std::endl;










            std::cout<<"The output Matrix is"<<std::endl;

        for (int i=0; i<2; i++)
        for (int j=0; j<2; j++){
                //std::cout<<"rank = "<<bsp_rank()<<" C[ "<<i<<" ]["<<j<<"]= "<<C[i][j]<<std::endl;
                std::cout<<" C[ "<<i<<" ]["<<j<<"]= "<<C(i,j)<<std::endl;
//                std::cout<<" C[ "<<nlr-i-1<<" ]["<<nlc-j-1<<"]= "<<C(nlr-i-1,nlc-j-1)<<std::endl;
        }





    }



#endif





