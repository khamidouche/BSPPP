/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/

#ifndef  BSP_GMM_HYB_MPI_HPP__INCLUDED__
#define  BSP_GMM_HYB_MPI_HPP__INCLUDED__

#include "test_GMM_Hyb_OMP.hpp"

#include "data.hpp"
using namespace std;
using namespace bsp;
namespace bl = boost::lambda;

//
//vector<double>  transmi_row ( int ind,par<vector<double>  > const& v, int s,int n)
//  {
//    if(ind%n==s) {return *v;}
//    else return vector<double> ();
//  return *v;
//  }


data<double>  transmi_row ( int ind,par<data<double>  > const& v, int s,int n)
  {
    if(ind%n==s) {return *v;}
    else return data<double> (1,0);
  //return *v;
  }

data<double>  transmi_col ( int ind,par<data<double>  > const& v, int t,int n)
  {
    if(ind/n==t) return *v;
    else return data<double> (1,0);
  }

data<double> transf1( int ind, par<data<double> > const& v )
  {
     return *v;

  }


template<class T>
void inline bsp_GMM_Hyb_MPI(int argc, char** argv,int const& m,int const &n,int const &s, int const& t,int const &nm, int const& b,
                      int const& nlr, int const& nlc,
                      par<data<double> >& ParA, par<data<double> >& ParB, data<double> const& A, data<double> const& B, data<double> & C, double & Tcomp, double & Tcomm)
                      {


    //int iglob;//, tagsz, status, nsums, nbytes, *pinc;
    //double sum, *psum, *pa, *vloc, *pvloc, *pvloc_end;
    double t1,t2;


//    parfun<data<double> > fun_row;
//    fun_row=replicate(bl::bind(transmi_row,bl::_1,bl::_2,s,n));
//
//
//
//    parfun<data<double> > fun_col;
//    fun_col=replicate(bl::bind(transmi_col,bl::_1,bl::_2,t,n));



//int cpt=0;
//   for(int kk=0;kk<nlr/b;kk++)
//     for(int kl=0;kl<nlc/b;kl++)
//    {


        for(int l=0;l<nlr;l++)
         for(int j=0;j<nlc;j++)
              {
              (*ParA)(l,j)=A(l,j);
              (*ParB)(l,j)=B(l,j);
              }
        //for(int i=0;i<nlc;i++)
//        for(int i=0;i<nlr;i++)
//         for(int l=0;l<b;l++)
//            (*ParB)(i,l)=B(i,l);

         t1=bsp::time();

        par< boost::function< data<double>(int)> > s2 = bl::bind(transmi_row,bl::_1,ParA,s,n);
        result_of::put< boost::function<data<double> (int)> >::type recv1;

        recv1 =put(s2);



        par< boost::function< data<double>(int)> > s3 = bl::bind(transmi_col,bl::_1,ParB,t,n);
        result_of::put< boost::function<data<double> (int)> >::type recv2;


        recv2 =put(s3);



     std::cout<<"okkkkkkkk "<<std::endl;

        synchronize();
        t2=bsp::time();
        Tcomm+=t2-t1;

           int l=-1;
            int kj;


//           t1=bsp::time();
           for(int a=0;a<m;a++)
            {
               l++;
//              int v1=0;
//              for(int i=0;i<b;i++)
//               for(int k=0,kj=0;k<nlc;k++,kj++)
//               {
//                   if(v1==1){l--;v1=0;}
//                for(int j=0;j<b;j++){
//                                // printf("rank %d  index = %d, A(%d;%d)= %f \n",bsp_rank(),s+a*n,i,k,ParA(s+a*n)(i,k));
//
//                if((k%nlr==0)&&(k!=0)&&(v1==0)) {
//                l++;v1=1;kj=0;}
//
//
//              // C(i+(kk*b),j+(kl*b))+= (*recv1)(s+a*n)(i,k)*(*recv2)(l+t*n)(kj,j);
//               C(i+(kk*b),j+(kl*b))+= A(i,k)*B(kj,j);
//              // C(i+indi,j+indj)+= (*recv1)(s+a*n)(i,k)*(*recv2)(l+t*n)(kj,j);
//              // C(i,j)+= (*recv1)(s+a*n)(i,k)*(*recv2)(l+t*n)(kj,j);
//                 // cpt++;
//
//                }
//               }
           std::cout<<"avant  "<<std::endl;
             gmm_hyb_omp(argc,argv,nlr,nlc,b,(*recv1)(s+a*n),(*recv2)(a+t*n),C,Tcomp,Tcomm);

             }
//            t2=bsp::time();
//            Tcomp+=t2-t1;

          //synchronize();

   //  }

//std::cout<<"le compteur  "<<cpt<<std::endl;



} /* end bspmv */


#endif





