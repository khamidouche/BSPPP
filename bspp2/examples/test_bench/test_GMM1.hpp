/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/

#ifndef  TEST_GMM_HPP__INCLUDED__
#define  TEST_GMM_HPP__INCLUDED__




#include <vector>
#include <iostream>
#include <fstream>

//#include  "bsppp/include/bsppp.hpp"
#include  "data.hpp"
#include  "bsp_GMM1.hpp"


using namespace std;
using namespace bsp;
namespace bl = boost::lambda;



vector<int> transf0( int ind, par<vector<int> > const& v )
  {
    if(*pid_==0)
     return *v;
   else return vector<int>();

  }




//int f1(int i)
//  {
//    return 0;
//
//  }
//
//boost::optional<int> transf1( int ind,boost::optional<int> const& v )
//  {
//    if(bsp_rank()==0)
//     return v;
//   else return boost::optional<int>();
//
//  }
//


template<class T>
void test_gmm1(int argc, char ** argv){

//    int p, pid, s, t, nlr, nlc, i, j, iglob, jglob, m1,n1,nm,M,N,n;
//    double  time0, time1;

        BSP_FUNCTION(argc,argv)
    {


      int p, pid, s, t, m1,n1,nm,nlr,nlc,M=0,N=0,n=0,b=0;
    double  time0, time1,Tcomp,Tcomm;
    data<double> A,B,C;

        par<std::vector<int> > tab;
        tab=vector<int> (4);
        par<data<double> > ParA;
        par<data<double> > ParB;



        p=bsp::size();
        pid=bsp::pid();

     // std::cout<<"nb threads"<<bsp_procs()<<std::endl;
      if(pid==0)
      {


        (*tab)[0]=atoi(argv[1]);
        (*tab)[1]=atoi(argv[2]);
        (*tab)[2]=atoi(argv[3]);
        (*tab)[3]=atoi(argv[4]);



      }
      synchronize();

    par< boost::function< vector<int>(int)> > s1 = bl::bind(transf0,bl::_1,tab);
     result_of::put< boost::function<vector<int> (int)> >::type recv;

        recv =put(s1);

m1=(*recv)(0)[0];
n1=(*recv)(0)[1];
nm=(*recv)(0)[2];
b=(*recv)(0)[3];

    /* Compute 2D processor numbering from 1D numbering */


        s= pid%n1;  /* 0 <= s < M */
        t= pid/n1;  /* 0 <= t < N */


          nlr= nm/n1;
          nlc= nm/m1;

           A.resize(nlr,nlc);
           //B.resize(nlc,nlr);
           B.resize(nlr,nlc);
           C.resize(nlr,nlc);

//std::cout<<"okkkkkkk "<<pid<<std::endl;

//         ParA= data<double> (b,nlc);
//         //ParB= data<double> (nlc,b);
//         ParB= data<double> (nlr,b);
//



         ParA= data<double> (nlr,nlc);
         //ParB= data<double> (nlc,b);
         ParB= data<double> (nlr,nlc);



        if (s==0 && t==0){
             std::cout<<"MM Mulitiplication of "<< nm <<" by "<< nm<<" matrix"<<std::endl;
             std::cout<<"using the "<< m1 <<" by "<< n1<<" cyclic distribution "<<std::endl;

        }



  for(int i=0;i<nlr;i++)
    for(int j=0;j<nlc;j++)
    {

       C(i,j)=0.0;
       A(i,j)=1.0;
       B(i,j)=1.0;

    }
//for(int i=0;i<nlc;i++)
//    for(int j=0;j<nlr;j++)
//    {
//       B(i,j)=1.0;
//
//      }



        if (s==0 && t==0)
            std::cout<<"Start of the MM Multiplication"<<std::endl;



    synchronize();
   // printf("eeeeeeeeeee\n");
    //bsp_sync();
    Tcomm=0.0;
    Tcomp=0.0;
  //  std::cout<<"avanttttttttttt"<<std::endl;

     time0=bsp::time();

    bsp_GMM1<double>(m1,n1,s,t,nm,b,nlr,nlc,ParA,ParB,A,B,C,Tcomp,Tcomm);


    synchronize();
    //bsp_sync();
    time1=bsp::time();
  // std::cout<<"apresssssssssssssss "<<std::endl;

        if (s==0 && t==0){
           std::cout<<"End of MM "<<std::endl;
           std::cout<<"This took only " <<time1-time0<<" seconds"<<std::endl;
           std::cout<<"This took only computing " <<Tcomp<<" seconds"<<std::endl;
           std::cout<<"This took only communication " <<Tcomm<<" seconds"<<std::endl;
           //std::cout<<"The output permutation is"<<std::endl;
           std::ofstream  fout;
           fout.open("MM_result",std::ofstream::app);
           if(!fout.is_open()) printf("cannot open the FILE \n");
           else{
              fout <<p<<" computing "<< Tcomp<<" communication "<<Tcomm<<" "<<b;
              fout << std::endl;
              fout.flush();
             }
           fout.close();

        }


     synchronize();



        if (s==0 && t==0){
            std::cout<<"The output Matrix is"<<std::endl;

        for (int i=0; i<2; i++)
        for (int j=0; j<2; j++)
                //std::cout<<"rank = "<<bsp_rank()<<" C[ "<<i<<" ]["<<j<<"]= "<<C[i][j]<<std::endl;
                std::cout<<"rank = "<<pid<<" C[ "<<i<<" ]["<<j<<"]= "<<C(i,j)<<std::endl;

         }


       synchronize();

    }
  }


#endif




