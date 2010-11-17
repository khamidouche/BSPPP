/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/

#ifndef  BSP_PROBE_HPP__INCLUDED__
#define  BSP_PROBE_HPP__INCLUDED__


//#include "bspedupack.h"
#include <vector>
#include <iostream>
#include <boost/lambda/bind.hpp>

#include  "environement.hpp"
#include  "env_mpi.hpp"
#include  "par.hpp"
#include  "step.hpp"
#include  "transmition.hpp"


#include  "view.hpp"


//#include <boost/array.hpp>

/*  This program measures p, r, g, and l of a BSP computer
    using bsp_put for communication.
*/

#define NITERS 100     /* number of iterations */
#define MAXN 2048     /* maximum length of DAXPY computation */
#define MAXH 512       /* maximum h in h-relation */
#define MEGA 1000000.0
#define TYPE float

//#define MAX(a,b) ((a)>(b) ? (a) : (b))
//#define MIN(a,b) ((a)<(b) ? (a) : (b))

namespace BSP
{
int P; /* number of processors requested */

template <class T>
void inline leastsquares(int const h0, int const h1, boost::array<T,MAXH+1>&t, double& g, double& l){
    /* This function computes the parameters g and l of the
       linear function T(h)= g*h+l that best fits
       the data points (h,t[h]) with h0 <= h <= h1. */
//
//    double nh, sumt, sumth, sumh, sumhh, a;
//    int h;
//
//    nh= h1-h0+1;
//    /* Compute sums:
//        sumt  =  sum of t[h] over h0 <= h <= h1
//        sumth =         t[h]*h
//        sumh  =         h
//        sumhh =         h*h     */
//    sumt= sumth= 0.0;
//    for (h=h0; h<=h1; h++){
//        sumt  += t[h];
//        sumth += t[h]*h;
//    }
//    sumh= (h1*h1-h0*h0+h1+h0)/2;
//    sumhh= ( h1*(h1+1)*(2*h1+1) - (h0-1)*h0*(2*h0-1))/6;
//
//    /* Solve      nh*l +  sumh*g =  sumt
//                sumh*l + sumhh*g = sumth */
//    if(fabs(nh)>fabs(sumh)){
//        a= sumh/nh;
//        /* subtract a times first eqn from second eqn */
//        g= (sumth-a*sumt)/(sumhh-a*sumh);
//        l= (sumt-sumh* g)/nh;
//    } else {
//        a= nh/sumh;
//        /* subtract a times second eqn from first eqn */
//        g= (sumt-a*sumth)/(sumh-a*sumhh);
//        l= (sumth-sumhh* g)/sumh;
//    }


 double sumx,sumy, carsumx,carsumy, sumcarx,n, sumxy;

 sumx=sumy=carsumx=carsumy=sumcarx=n=sumxy=0.0;
 n=h1-h0+1;
 for(int i=h0;i<h1;i++)
   {
     sumx += i;
     sumy += t[i];
     sumxy+=t[i]*i;
     sumcarx+= (i*i);

   }
   l=((sumy*sumcarx)-(sumx*sumxy))/((n*sumcarx)-(sumx*sumx));
   g= ((n*sumxy)-(sumx*sumy))/((n*sumcarx)-(sumx*sumx));



} /* end leastsquares */

///  initiate the vectors used to the compute of daxpy ///
void initiate (boost::array<TYPE,MAXN>& A)
{
  for(size_t i= 0; i<A.size();i++) A[i]= i;
}

void calcul( boost::array<TYPE,MAXN> const& A,boost::array<TYPE,MAXN>& B,boost::array<TYPE,MAXN>& C
           , TYPE const& alpha, TYPE const& beta, int const &n
           )
{
  for (int iter=0; iter<NITERS; iter++)
  {
    for (int i=0; i<n; i++) B[i] += alpha*A[i];
    for (int i=0; i<n; i++) C[i] -= beta*A[i];
  }
}

void initiate_src(int const & h, par<TYPE>& x)
{
   x() = h;
}

//template <class T>
boost::optional<TYPE> transf ( int ind,boost::optional<TYPE> const& v,int i, int p, int s )
  {
    if(ind==(s+1+i%(p-1))%p)
     return v;
   else return boost::optional<TYPE>();

  }


template <class T>
void bspbench(int argc, char ** argv){
    //void leastsquares(int h0, int h1, double *t, double *g, double *l);
    int p, s, s1, n, h;
    double alpha, beta,time0, time1, time , mintime, maxtime,
           nflops, r=0, g0, l0, g, l;
    boost::array<T,MAXH+1> t;
    boost::array<T,MAXN> x;
    boost::array<T,MAXN> y;
    boost::array<T,MAXN> z;


    //vector<int> destproc(MAXH);
    //vector<int> destindex(MAXH);

  //  vector<T> src(MAXH);


   // vector<T> t(MAXH+1);
  //  vector<T> Time;
   // vector<T> dest;

    /// starting the environement ///
    bsp_env env(argc, argv);
    {
    //  std::cout<<"start the environement ..."<< std::endl;


     par<view<T> > Partime;

     boost::array<par<T>,MAXH> src;



   // TIME= Time,Time;
    //DEST= dest(2*MAXH+bsp_procs() ),Time(2*MAXH+bsp_procs() );

    parfun<view<T> > trans_0;
    trans_0 = replicate(bl::if_then_else_return((rank_ == 0), value_, _));
            //, bl::if_then_else_return((rank_ == 0), value_, _);

    std::vector<parfun<TYPE> > trans_i;

//        trans_i = bl::if_then_else_return(((rank_==s+1+i%(p-1))%p), value_, _)
//                , bl::if_then_else_return(((rank_==s+1+i%(p-1))%p), value_, _);
   // trans_i= &transmission<T>,&transmission<T>;



//    par<std::vector<T>(std::vetor<T>&) > INIT;
//    INIT = &initiale,&initiale;

//    par <std::vector<T>(std::vector<T>const &, std::vector<T>&, std::vector<T>&, T const &, T const &) > CALCUL;
//    CALCUL= & calcul,& calcul;

    super_step(determine_P)
    {
      p = bsp_procs();
      s = bsp_rank();
     // synchronize();

      }

    std::vector<TYPE> Time(p);
//    std::vector<view<double> > viewtime(p);
//
//    for(int i=0;i<p;i++)
//    {
//     viewtime[i].set_pointeur(&Time[i]);// = &viewtime[i];//=view<double>(&viewtime[i], 4);
//     viewtime[i].set_size(1);// = 4;
//    }


   // Partime=viewtime[0],viewtime[1];
   Partime = Time;

   par<T> vide;
   parfun<T> funvide;


    //std::cout<< "rank  "<<s<<"tab "<<Partime(0).size()<<std::endl;

    for (n=1; n <= MAXN; n *= 2)
    {

      super_step(init_comp_r)
       {
         alpha= 1.0/3.0;
         beta= 4.0/9.0;
         initiate(x);
         initiate(y);
         initiate(z);

         time0= bsp_time();
         calcul(x, y, z, alpha, beta,n);
         time1= bsp_time();
         Time[bsp_rank()] = time1-time0;
         //std::cout<<"rank "<< bsp_rank()<<"time "<< Time[bsp_rank()]<<std::endl;
         put(Partime,trans_0);
        }


        super_step(do_proc_0)
        {
          if(s==0)
              {
                mintime = *(std::min_element(Time.begin(),Time.end()));
                maxtime = *(std::max_element(Time.begin(),Time.end()));
               //std::cout<<"min= "<<mintime<<"max= "<<maxtime<<std::endl;
//                for(size_t i=0;i<Time.size();++i) printf("%g ",Time[i]);
//                printf("\n");

                if (mintime>0.0)
                {
                /* Compute r = average computing rate in flop/s */
                nflops= 4*NITERS*n;
                r= 0.0;
                for(s1=0; s1<p; s1++)
                     r += nflops/Time[s1];
                     // r += Time[s1];
                r /= p;
                printf("n= %5d min= %7.3lf max= %7.3lf av= %7.3lf Mflop/s ",
                       n, nflops/(maxtime*MEGA),nflops/(mintime*MEGA), r/MEGA);
                fflush(stdout);
                /* Output for fooling benchmark-detecting compilers */
                printf(" fool=%7.1lf\n",y[n-1]+z[n-1]);
                }
                fflush(stdout);
              }
          //synchronize();
          }


      }



//       synchronize();
//
//
//        super_step(clacul_l_L)
//       {
//
//         time0= bsp_time();
//        for(int iter=0; iter<NITERS; iter++)
//             {
//               synchronize();
//
//               }
//         time1= bsp_time();
//         time = time1-time0;
//         std::cout<<"rank  "<<s<<"le temps L lower  =  "<<time<<" l lower =  "<<(time*r)/NITERS<<std::endl;
//
//        }
//
//
//
//
//      super_step(clacul_l_H)
//       {
//         vide   = replicate(0.0f);
//         funvide= replicate(_);
//         time0= bsp_time();
//        for(int iter=0; iter<NITERS; iter++)
//             {
////               async_put(vide,funvide);
////               synchronize();
//                put(vide,funvide);
//               }
//         time1= bsp_time();
//         time = time1-time0;
//         std::cout<<"rank  "<<s<<"le temps L higt =  "<<time<<" l higt =  "<<(time*r)/NITERS<<std::endl;
//
//        }



      for (h=0; h<=MAXH; h++)
       {
         trans_i.resize(h);
         super_step(init_calcul_g_l)
         {
           for(int i=0;i<h;i++)
             {
              // std::cout<<"000000000000000"<<std::endl;
               src[i] = replicate(2.0f);
               initiate_src(i,src[i]);
              // int ind= (s+1+i%(p-1))%p;
               //std::cout<<"11111111111111111111"<<std::endl;
//               trans_i[i] = bl::if_then_else_return(rank_==0, value_, _)
//                          , bl::if_then_else_return(rank_==0, value_, _);

               trans_i[i] = replicate(bl::bind(transf,bl::_1,bl::_2,i,p,s));
                          //, bl::bind(transf,bl::_1,bl::_2,i,p,s);
                          //, bl::bind(transf,bl::_1,bl::_2,i,p,s);

//             transmission tt(p,s,i);
//             trans_i[i]=tt,tt;
             //  std::cout<<"222222222222222222"<<std::endl;
          //

              }

          //synchronize();
          }
          super_step(time_calcul_g_l)
           {/* Measure time of NITERS h-relations */
             time0= bsp_time();
             for(int iter=0; iter<NITERS; iter++)
             {
                for(int i=0; i<h; i++) async_put(src[i],trans_i[i]);
                synchronize();
             }
              time1= bsp_time();
              time = time1-time0;

               /* Compute time of one h-relation */
              if (s==0)
                {
                //t[h]= (time*r)/NITERS;
                t[h]= (time)/NITERS;
                 printf("Time of %5d-relation= %lf sec= %lf flops\n",
                   h, time/NITERS, t[h]); fflush(stdout);
//                 t[h]=time/NITERS;
//
//                 std::cout<<h<<"  "<<t[h]<<std::endl;
                }
             //synchronize();
            }

         }

          super_step(work_P0)
           {

             if (s==0)
               {
               printf("size of TYPE = %d bytes\n",sizeof(TYPE));
               leastsquares(0,p,t,g0,l0);
               printf("Range h=0 to p   : g= %lf, l= %lf\n",g0,l0);
               leastsquares(p,MAXH,t,g,l);
               printf("Range h=p to HMAX: g= %lf sec, l= %lf sec\n",g,l);

               printf("The bottom line for this BSP computer is:\n");
               printf("p= %d, r= %.3lf Mflop/s, g= %lf sec, l= %lf sec\n",
                     p,r/MEGA,g,l);
               fflush(stdout);
               }
          // synchronize();
           }

    }//end env




}
}
#endif

