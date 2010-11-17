/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#include <iostream>
#include <bsppp/bsppp.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>


#include "data.hpp"

using namespace bsp;
using namespace std;
namespace bl = boost::lambda;


std::vector<double>  fun_ligne_omp ( int ind, par<std::vector<double> > const& v, int s, int t, int N, int M)
  {
      if(ind==(s+(((t+1)%M)*N)))
                      return *v;
          else return  std::vector<double> ();

  }



void bsp_GMV_OMP_1(int argc, char** argv,int const& M,int const &N,int const &n,
           std::vector<double> & U,data<double> & A, std::vector<double> & ParV,double& Tcomp, double & Tcomm)
           {



    BSP_FUNCTION(argc,argv)
    {

    int Nomp,Momp,tomp,somp,a,b, a1,b1,pid,nbproc,i,j;
    double t1,t2;

     pid=bsp::pid();
     nbproc=bsp::size();
    if(nbproc==1){Nomp=1;Momp=1;}
    if(nbproc==2){Nomp=2;Momp=1;}
    if(nbproc==4){Nomp=2;Momp=2;}
    if(nbproc==8){Nomp=4;Momp=2;}


       somp= pid%Nomp;  /* 0 <= s < M */
       tomp= pid/Nomp;


    par<vector<double> > ParV_OMP;
   // ParV_OMP=ParV.begin()+(n/(N*Nomp))*(*pid_);


a=n/(N*Nomp);
b=n/(M*Momp);
a1=somp*a;
b1=tomp*b;
     ParV_OMP=vector<double> (a);

     t1=bsp::time();
    for( i=0;i<a;i++)
     {

       for( j=0;j<b;j++)
        {
          (*ParV_OMP)[i]+= A(i+a1,j+b1)*U[j+b1];

          }
      }

     t2=bsp::time();
     if(pid==0) printf("le tempss = %f\n",t2-t1);
//     Tcomp+=t2-t1;

      //  t1=bsp::time();

        par< boost::function< vector<double>(int)> > s2_omp = bl::bind(fun_ligne_omp,bl::_1,ParV_OMP,somp,tomp,Nomp,Momp);
        result_of::put< boost::function<vector<double> (int)> >::type recv1_omp;
//     par< boost::function< vector<double>(int)> > s2 = bl::bind(fun_all,bl::_1,ParV);
//     result_of::put< boost::function<vector<double> (int)> >::type recv1;

        recv1_omp =put(s2_omp);



//    t2=bsp::time();
//    Tcomm+=t2-t1;

        if((nbproc==1)||(nbproc==2)) ParV=(*ParV_OMP);
        else {
        for(int k=0;k<n/(N*nbproc);k++)
         ParV[k+((n/(N*nbproc))*pid)]= (*ParV_OMP)[k+(tomp*(n/(N*nbproc)))]+(*recv1_omp)(somp+((tomp+1)%Momp)*Nomp)[k+(tomp*(n/(N*nbproc)))];
        }




    }
}


void  bsp_GMV_OMP_2(int argc, char** argv,int const &N,int const &n,
           std::vector<double> & ParV, std::vector<double> const& recv)
           {

    BSP_FUNCTION(argc,argv)
    {

  int pid,nbproc,a;
 pid=bsp::pid();
 nbproc=bsp::size();


a=n/(N*nbproc);

    for(int k=0;k<a;k++)
         ParV[k+a*pid]+= recv[k+a*pid];


    }
}










