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


data<double>  trans_row_omp ( int ind,par<data<double>  > const& v, int s,int n)
  {
     // std::cout<<"ind "<<ind<<" n "<<n<<" s = "<<s<<std::endl;
//    if(ind%n==s) {/*std::cout<<"**** pid= "<<*pid_<<"   *** ind = "<<ind<<std::endl; */return *v;}
//    else  {/*std::cout<<"---- pid= "<<*pid_<<"   ----ind = "<<ind<<std::endl; */return data<double> (1,0);}
 return *v;
  }

data<double>  trans_col_omp ( int ind,par<data<double>  > const& v, int t,int n)
  {
//    if(ind/n==t) return *v;
//    else return data<double> (1,0);
return *v;
  }



void gmm_hyb_omp(int argc, char** argv,
                      int const& nlr, int const& nlc,int const& b,
                       data<double> const& A, data<double> const & B, data<double> & C, double & Tcomp, double & Tcomm)
                      {

         BSP_FUNCTION(argc,argv)
    {
    //int iglob;//, tagsz, status, nsums, nbytes, *pinc;
    //double sum, *psum, *pa, *vloc, *pvloc, *pvloc_end;
    double t1,t2;

    int nlr_omp,nlc_omp, s_omp,t_omp,p_omp,pid_omp;
        p_omp=bsp::size();
        pid_omp=bsp::pid();

    nlr_omp=nlr/2;
    nlc_omp=nlc/2;
    s_omp= pid_omp%2;
    t_omp= pid_omp/2;

     int indi=s_omp*nlr_omp;
     int indj=t_omp*nlc_omp;

        par<data<double> > ParA_omp;
        par<data<double> > ParB_omp;

         ParA_omp= data<double> (b,nlc_omp);
//         //ParB= data<double> (nlc,b);
         ParB_omp= data<double> (nlr_omp,b);





 std::cout<<"rank=  "<<pid_omp<<" A = "<<A.size()<<" B = "<<B.size()<<" C = "<<C.size()<<std::endl;
synchronize();
//int cpt=0;
   for(int kk=0;kk<nlr_omp/b;kk++)
     for(int kl=0;kl<nlc_omp/b;kl++)

    {


        for(int l=0;l<b;l++)
         for(int j=0;j<nlc_omp;j++)

              (*ParA_omp)(l,j)=A(l+indi,j+indj);

        for(int i=0;i<nlr_omp;i++)
         for(int l=0;l<b;l++)
            (*ParB_omp)(i,l)=B(i+indi,l+indj);
 //std::cout<<"avant comm 111 "<<std::endl;
         t1=bsp::time();
     par< boost::function< data<double>(int)> > s2_omp = bl::bind(trans_row_omp,bl::_1,ParA_omp,s_omp,2);
        result_of::put< boost::function<data<double> (int)> >::type recv1_omp;
//std::cout<<"avant comm 22222222  "<<std::endl;
        recv1_omp =put(s2_omp);
         // synchronize();

        par< boost::function< data<double>(int)> > s3_omp = bl::bind(trans_col_omp,bl::_1,ParB_omp,t_omp,2);
        result_of::put< boost::function<data<double> (int)> >::type recv2_omp;

//std::cout<<"avant comm 444444444 "<<std::endl;
        recv2_omp =put(s3_omp);

// std::cout<<"apres comm "<<std::endl;




     // if(pid_omp==0)
      {
      std::cout<<"rank = "<<pid_omp<<" la donnée 0 est "<<(*recv1_omp)(0).size()<<std::endl;
      std::cout<<"rank = "<<pid_omp<<" la donnée 1 est "<<(*recv1_omp)(1).size()<<std::endl;
      std::cout<<"rank = "<<pid_omp<<" la donnée 2 est "<<(*recv1_omp)(2).size()<<std::endl;
      std::cout<<"rank = "<<pid_omp<<" la donnée 3 est "<<(*recv1_omp)(3).size()<<std::endl;
      }

        synchronize();
        t2=bsp::time();
        if(pid_omp==0)Tcomm+=t2-t1;

           int l=-1;
            int kj;


           t1=bsp::time();
           for(int a=0;a<2;a++)
            {
//                l++;
//              int v1=0;
              for(int i=0;i<b;i++)
               for(int k=0,kj=0;k<nlc_omp;k++,kj++)
               {
                  // if(v1==1){l--;v1=0;}
                for(int j=0;j<b;j++){
                                // printf("rank %d  index = %d, A(%d;%d)= %f \n",bsp_rank(),s+a*n,i,k,ParA(s+a*n)(i,k));

                if((k%nlr_omp==0)&&(k!=0)) {
                kj=0;}

               // std::cout<<"dans la boucle  rank=  "<<pid_omp<<"  nb = "<<p_omp<<"  i= "<<i+indi+(kk*b)<<std::endl;
              // C(i+indi+(kk*b),j+indj+(kl*b))+= (*recv1_omp)(s_omp+a*2)(i,k);//*(*recv2_omp)(a+t_omp*2)(k,j);
               C(i+indi+(kk*b),j+indj+(kl*b))+= (*ParA_omp)(i,k)*(*ParB_omp)(kj,j);
              //C(i+(kk*b),j+(kl*b))+= A(i,k)*B(kj,j);

                }
               }

             }
            t2=bsp::time();
            if(pid_omp==0)Tcomp+=t2-t1;

          //synchronize();

     }
    }
//std::cout<<"le compteur  "<<cpt<<std::endl;



} /* end bspmv */








