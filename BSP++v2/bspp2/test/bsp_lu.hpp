/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/

#ifndef  BSP_LU_HPP__INCLUDED__
#define  BSP_LU_HPP__INCLUDED__

# include <vector>







#define EPS 1.0e-15

namespace BSP
{



//void bsp_broadcast(double *x, int n, int src, int s0, int stride, int p0,
//                   int s, int phase){
//    /* Broadcast the vector x of length n from processor src to
//       processors s0+t*stride, 0 <= t < p0. Here n >= 0, p0 >= 1.
//       The vector x must have been registered previously.
//       Processors are numbered in one-dimensional fashion.
//       s = local processor identity.
//       phase= phase of two-phase broadcast (0 or 1)
//       Only one phase is performed, without synchronization.
//    */
//
//    int b, t, t1, dest, nbytes;
//
//    b= ( n%p0==0 ?  n/p0 : n/p0+1 ); /* block size */
//
//    if (phase==0 && s==src){
//        for (t=0; t<p0; t++){
//            dest= s0+t*stride;
//            nbytes= MIN(b,n-t*b)*SZDBL;
//            if (nbytes>0)
//                bsp_put(dest,&x[t*b],x,t*b*SZDBL,nbytes);
//        }
//    }
//
//    if (phase==1 && s%stride==s0%stride){
//        t=(s-s0)/stride; /* s = s0+t*stride */
//        if (0<=t && t<p0){
//            nbytes= MIN(b,n-t*b)*SZDBL;
//            if (nbytes>0){
//                for (t1=0; t1<p0; t1++){
//                    dest= s0+t1*stride;
//                    if (dest!=src)
//                        bsp_put(dest,&x[t*b],x,t*b*SZDBL,nbytes);
//                }
//            }
//        }
//    }
//
//} /* end bsp_broadcast */

//int nloc(int p, int s, int n){
//    /* Compute number of local components of processor s for vector
//       of length n distributed cyclically over p processors. */
//
//    return  (n+p-s-1)/p ;
//
//} /* end nloc */


view<double>  transmi ( int ind,view<double> const& v, int M,int N, int t )
  {
    if(bsp_rank()/M==t)
           if(ind==t+N) return v;
           else  return view<double> (_);
    else return view<double> (_);

  }


boost::optional<double> transmiPi ( int ind,boost::optional<double> const& v, int M,int K, int t,int s, int r )
  {
    if((K%M==s)&&(t==0))
           if(ind==r%M) return v;
           else  return boost::optional<double>();
    else return boost::optional<double>();

  }

boost::optional<double> transmiPi_inv ( int ind,boost::optional<double> const& v, int M,int K, int t,int s, int r )
  {
    if((r%M==s)&&(t==0))
           if(ind==K%M) return v;
           else  return boost::optional<double>();
    else return boost::optional<double>();

  }



boost::optional<int> transmi2 ( int ind,boost::optional<int> const& v, int M,int N, int t )
  {
    if(bsp_rank()/M==t)
           if(ind<t+N) return v;
           else  return boost::optional<int>();
    else return boost::optional<int>();

  }


boost::optional<std::vector<double> > transmiallrow ( int ind,boost::optional<std::vector<double> > const& v, int M,int N, int t )
  {
    if(bsp_rank()%M==t)
           if(ind<t+N) return v;
           else  return boost::optional<std::vector<double> >();
    else return boost::optional<std::vector<double> >();

  }

boost::optional<std::vector<double> > transmiallcol ( int ind,boost::optional<std::vector<double> > const& v, int M, int s )
  {
    if(bsp_rank()/M==s)
           if(ind%M==s) return v;
           else  return boost::optional<std::vector<double> >();
    else return boost::optional<std::vector<double> >();

  }


template<class T>
void bsp_lu(int M, int N, int s, int t, int n, std::vector<double>& pi, boost::multi_array<double, 2>& a)
{
    /* Compute LU decomposition of n by n matrix A with partial pivoting.
       Processors are numbered in two-dimensional fashion.
       Program text for P(s,t) = processor s+t*M,
       with 0 <= s < M and 0 <= t < N.
       A is distributed according to the M by N cyclic distribution.
    */


    //double *pa, *uk, *lk, *Max;
    int nlr, nlc, k, i, j;//, r *Imax;

    nlr=  nloc(M,s,n); /* number of local rows */
    nlc=  nloc(N,t,n); /* number of local columns */





//     if (nlr>0)
//        pa= a[0];
//    else
//        pa= NULL;
//    bsp_push_reg(pa,nlr*nlc*SZDBL);
//    bsp_push_reg(pi,nlr*SZINT);
//    uk= vecallocd(nlc); bsp_push_reg(uk,nlc*SZDBL);
//    lk= vecallocd(nlr); bsp_push_reg(lk,nlr*SZDBL);
//    Max= vecallocd(M); bsp_push_reg(Max,M*SZDBL);
//    Imax= vecalloci(M); bsp_push_reg(Imax,M*SZINT);



   // std::vector<double> uk(nlc);
   // std::vector<double> lk(nlr);
    std::vector<double> Max(M*N);

    std::vector<double> Imax(M*N);

    par<view<double> > ParMax;
    ParMax = Max;

    par<view<double> > ParImax;
    ParImax = Imax;

    parfun<view<double> > fun;


    par<int> ParR;
    ParR = replicate(0);

    par<double> ParPi;
    ParPi = replicate (0.0);

    parfun<double> parfunPi;
    parfun<double> parfunPi_inv;

    parfun<int> fun2;


    par<std::vector<double> > ParUk;
    ParUk = replicate(std::vector<double> (nlc) );

    par<std::vector<double> > ParLk;
    ParLk = replicate(std::vector<double> (nlr) );


    parfun<std::vector<double> > funrow;
    parfun<std::vector<double> > funcol;





   super_step(init_pi)
   {

    /* Initialize permutation vector pi */
        if (t==0){

            for(i=0; i<nlr; i++)
                pi[i]= i*M+s; /* global row index */
        }

   }

    for (k=0; k<n; k++){

            int kr, kr1, kc, kc1, imax, smax, s1;//, t1;
            double absmax, max, pivot;

           super_step()
           {
                /****** Superstep 0 ******/
                kr=  nloc(M,s,k); /* first local row with global index >= k */
                kr1= nloc(M,s,k+1);
                kc=  nloc(N,t,k);
                kc1= nloc(N,t,k+1);

                if (k%N==t){   /* k=kc*N+t */
                    /* Search for local absolute maximum in column k of A */
                    absmax= 0.0; imax= -1;
                    for (i=kr; i<nlr; i++){
                        if (fabs(a[i][kc])>absmax){
                            absmax= fabs(a[i][kc]);
                            imax= i;
                        }
                    }
                    if (absmax>0.0){
                        max= a[imax][kc];
                    } else {
                        max= 0.0;
                    }
                    Max[bsp_rank()] = max;
                    Imax[bsp_rank()]= imax;

                }//End of the if
                 // the communication must be done by all the process
                    /* Broadcast value and local index of maximum to P(*,t) */
    //                for(s1=0; s1<M; s1++){
    //                    bsp_put(s1+t*M,&max,Max,s*SZDBL,SZDBL);
    //                    bsp_put(s1+t*M,&imax,Imax,s*SZINT,SZINT);
    //                }
                 fun = replicate(bl::bind(transmi,bl::_1,bl::_2,M,N,t));

                 put(ParMax,fun);
                 put(ParImax,fun);

            }


            /****** Superstep 1 ******/
            super_step()
            {
                if (k%N==t){
                    /* Determine global absolute maximum (redundantly) */
                    absmax= 0.0;
                    for(s1=0; s1<M; s1++){
                        if (fabs(Max[s1])>absmax){
                            absmax= fabs(Max[s1]);
                            smax= s1;
                        }
                    }

                    if (absmax > EPS){
                        ParR()= Imax[smax]*M+smax; /* global index of pivot row */
                        pivot= Max[smax];
                        for(i=kr; i<nlr; i++)
                            a[i][kc] /= pivot;
                        if (s==smax)
                            a[imax][kc]= pivot; /* restore value of pivot */

                        /* Broadcast index of pivot row to P(*,*) */
    //                    for(t1=0; t1<N; t1++)
    //                        bsp_put(s+t1*M,&r,&r,0,SZINT);
                    } else {

                        bsp_abort(k);
                    }

                    //the comm must be done by all the process
//                   fun2 = replicate(bl::bind(transmi2,bl::_1,bl::_2,M,N,t));
//
//                   put(ParR,fun2);
                }
                fun2 = replicate(bl::bind(transmi2,bl::_1,bl::_2,M,N,t));

                put(ParR,fun2);
            }


            super_step()
            {
              parfunPi=replicate(bl::bind(transmiPi,bl::_1,bl::_2,M,k,t,s,ParR()));
              ParPi()= pi[k/M];
              put(ParPi,parfunPi);

              if(bsp_rank()==ParR()%M) pi[ParR()/M]=ParPi();


              parfunPi_inv=replicate(bl::bind(transmiPi_inv,bl::_1,bl::_2,M,k,t,s,ParR()));
              ParPi()= pi[ParR()/M];
              put(ParPi,parfunPi);

              if(bsp_rank()==k%M) pi[k/M]=ParPi();

              }


//            super_step()
//            {
//                  /****** Superstep 2 ******/
//
//                  if (k%M==s){
//                      /* Store pi(k) in pi(r) on P(r%M,0) */
//                      if (t==0)
//                          bsp_put(r%M,&pi[k/M],pi,(r/M)*SZINT,SZINT);
//                      /* Store row k of A in row r on P(r%M,t) */
//                      bsp_put(r%M+t*M,a[k/M],pa,(r/M)*nlc*SZDBL,nlc*SZDBL);
//                  }
//                  if (r%M==s){
//                      if (t==0)
//                          bsp_put(k%M,&pi[r/M],pi,(k/M)*SZINT,SZINT);
//                      bsp_put(k%M+t*M,a[r/M],pa,(k/M)*nlc*SZDBL,nlc*SZDBL);
//                  }
//            }


            super_step()
            {

                  /****** Superstep 3 ******/
                  /* Phase 0 of two-phase broadcasts */
                  if (k%N==t){
                      /* Store new column k in lk */
                      for(i=kr1; i<nlr; i++)
                          ParLk()[i-kr1]= a[i][kc];
                  }
                  if (k%M==s){
                      /* Store new row k in uk */
                      for(j=kc1; j<nlc; j++)
                          ParUk()[j-kc1]= a[kr][j];
                  }

                  funrow = replicate(bl::bind(transmiallrow,bl::_1,bl::_2,M,N,t));
                  funcol = replicate(bl::bind(transmiallcol,bl::_1,bl::_2,M,s));

                  put(ParLk, funrow);
                  put(ParUk, funcol);

    //              bsp_broadcast(lk,nlr-kr1,s+(k%N)*M,  s,M,N,s+t*M,0);
    //              bsp_broadcast(uk,nlc-kc1,(k%M)+t*M,t*M,1,M,s+t*M,0);

            }


            /****** Superstep 4 ******/
    //        /* Phase 1 of two-phase broadcasts */
    //        bsp_broadcast(lk,nlr-kr1,s+(k%N)*M,  s,M,N,s+t*M,1);
    //        bsp_broadcast(uk,nlc-kc1,(k%M)+t*M,t*M,1,M,s+t*M,1);
    //        bsp_sync();

            /****** Superstep 0 ******/
            /* Update of A */
            for(i=kr1; i<nlr; i++){
                for(j=kc1; j<nlc; j++)
                    a[i][j] -= ParLk()[i-kr1]*ParUk()[j-kc1];
            }
    }
//    bsp_pop_reg(Imax); vecfreei(Imax);
//    bsp_pop_reg(Max); vecfreed(Max);
//    bsp_pop_reg(lk); vecfreed(lk);
//    bsp_pop_reg(uk); vecfreed(uk);
//    bsp_pop_reg(pi);
//    bsp_pop_reg(pa);
//    bsp_pop_reg(&r);

} /* end bsplu */

}
#endif
