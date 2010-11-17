/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/

#ifndef  TEST_GMV_HPP__INCLUDED__
#define  TEST_GMV_HPP__INCLUDED__


#include "bsp_GMV.hpp"
#include "data.hpp"


using namespace std;
using namespace bsp;
namespace bl = boost::lambda;



vector<int> transf0( int ind, par<vector<int> > const& v )
  {
    if(*pid_==0)
     return *v;
   else return vector<int>();

  }



template<class T>
void test_gmv(int argc, char ** argv){


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
    par<std::vector<int> > tab;
    tab=vector<int> (3);

      if(pid==0)
      {


        (*tab)[0]=atoi(argv[1]);
        (*tab)[1]=atoi(argv[2]);
        (*tab)[2]=atoi(argv[3]);


      }
      synchronize();

    par< boost::function< vector<int>(int)> > s1 = bl::bind(transf0,bl::_1,tab);
     result_of::put< boost::function<vector<int> (int)> >::type recv;

        recv =put(s1);

M=(*recv)(0)[0];
N=(*recv)(0)[1];
n=(*recv)(0)[2];


    /* Compute 2D processor numbering from 1D numbering */


        s= pid%N;
        t= pid/N;

         A.resize(n/N,n/M);
         U.resize(n/M);
         V.resize(n);
       ParV= std::vector<double>(n/N);




  for(int i=0;i<n/N;i++){
    for(int j=0;j<n/M;j++)
      {
       A(i,j)=1.0;
       }
  }
  for(int j=0;j<n/M;j++)
      {
       U[j]=1.0;
       }


  for(int i=0;i<n/N;i++)
      (*ParV)[i]=0.0;



        if (s==0 && t==0)
            std::cout<<"Start of the MV Multiplication"<<std::endl;


    synchronize();

    Tcomm=0.0;
    Tcomp=0.0;

     time0=bsp::time();

    bsp_GMV<double>(M,N,s,t,n,p,U,A,V,ParV,Tcomp,Tcomm);
///////////////////////////////////////*



//////////////////////////////////////*


    synchronize();
    time1=bsp::time();


        if (s==0 && t==0){

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
          }


        if (s==0 && t==0){
            std::cout<<"The output Vector is"<<std::endl;

        for (i=0; i<4; i++)
                std::cout<<"rank = "<<pid<<" V [ "<<i<<" ] = "<<V[i]<<std::endl;

         }


       synchronize();

    }
}



#endif

