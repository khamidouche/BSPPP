/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/

#ifndef  BSP_GMV_HYB_MPI_HPP__INCLUDED__
#define  BSP_GMV_HYB_MPI_HPP__INCLUDED__


#include "GMV_Hyb_OMP_SPMD.hpp"
#include "data.hpp"

using namespace bsp;
using namespace std;
namespace bl = boost::lambda;


std::vector<double>  fun_ligne ( int ind, par<std::vector<double> > const& v, int s, int t, int N, int M)
  {
      if(ind==(s+(((t+1)%M)*N)))
                      return *v;
          else return  std::vector<double> ();

  }

std::vector<double>  fun_colone ( int ind, par<std::vector<double> > const& v, int t, int N)
  {
      if((ind/N)==t)
                      return *v;
          else return  std::vector<double> ();

  }



template<class T>
void inline bsp_GMV_mpi(int argc, char** argv,int const& M,int const &N,int const &s, int const& t,int const &n,int const& P,
           std::vector<T> & U,data<double> & A,vector<double> &V, par<std::vector<T> >& ParV,double& Tcomp, double & Tcomm)
           {





    double t1,t2;








     t1=bsp::time();
//    for(int i=0;i<n/N;i++)
//     {
//
//       for(int j=0;j<n/M;j++)
//        {
//          (*ParV)[i]+= A(i,j)*U[j];
//
//          }
//      }
        bsp_GMV_OMP_1( argc,argv,M,N,n,U, A, (*ParV), Tcomp, Tcomm);


      t2=bsp::time();
      Tcomp+=t2-t1;

  //synchronize();
        t1=bsp::time();

        par< boost::function< vector<double>(int)> > s2 = bl::bind(fun_ligne,bl::_1,ParV,s,t,N,M);
        result_of::put< boost::function<vector<double> (int)> >::type recv1;

        recv1 =put(s2);



    t2=bsp::time();
    Tcomm+=t2-t1;



t1=bsp::time();
if(P>2){
    for(int d=0;d<P;d++)
    {if(((d%N)==s)&&(d!=*pid_))
    {
//    for(int k=0;k<n/N;k++)
//         //(*ParV)[k]+= (*recv1)(s+((t+1)%M)*N)[k];
//         (*ParV)[k]+= (*recv1)(d)[k];
   bsp_GMV_OMP_2( argc, argv,N,n,(*ParV), (*recv1)(d));


    }
    }
}
t2=bsp::time();
Tcomp+=t2-t1;

t1=bsp::time();
 par< boost::function< vector<double>(int)> > s3 = bl::bind(fun_colone,bl::_1,ParV,t,N);
        result_of::put< boost::function<vector<double> (int)> >::type recv2;

        recv2=put(s3);
t2=bsp::time();
Tcomm+=t2-t1;
        V=(*ParV);



//if((M*N)>2){
// for(int k=0;k<n/(N*M);k++)
//         V[k+((n/(N*M))*(*pid_))]= (*ParV)[k+(t*(n/(N*M)))]+(*recv1)(s+((t+1)%M)*N)[k+(t*(n/((N*M))))];
//}else
// for(int k=0;k<n/(N*M);k++)
//         V[k+((n/(N*M))*(*pid_))]= (*ParV)[k+(t*(n/(N*M)))];






} /* end bspmv */



#endif


