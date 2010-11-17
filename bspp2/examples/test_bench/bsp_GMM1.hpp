/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/

#ifndef  BSP_GMM_HPP__INCLUDED__
#define  BSP_GMM_HPP__INCLUDED__



#include "data.hpp"
using namespace std;
using namespace bsp;
namespace bl = boost::lambda;




data<double>  transmi_row ( int ind,par<data<double>  > const& v, int s,int n)
  {
    if(ind%n==s) {return *v;}
    else return data<double> (1,0);
   //  return *v;
  }

data<double>  transmi_col ( int ind,par<data<double>  > const& v, int t,int n)
  {
    if(ind/n==t) return *v;
    else return data<double> (1,0);
      return *v;
  }



template<class T>
void inline bsp_GMM1(int const& m,int const &n,int const &s, int const& t,int const &nm, int const& b,
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
//    {

        t1=bsp::time();
        for(int l=0;l<nlr;l++)
         for(int j=0;j<nlc;j++)

              (*ParA)(l,j)=A(l,j);


        //for(int i=0;i<nlc;i++)
        for(int i=0;i<nlr;i++)
         for(int l=0;l<nlc;l++)
            (*ParB)(i,l)=B(i,l);

     // std::cout<<"avant la comm 111  s= "<<s<<"  n = "<<n<<std::endl;
        par< boost::function< data<double>(int)> > s2 = bl::bind(transmi_row,bl::_1,ParA,s,n);
        result_of::put< boost::function<data<double> (int)> >::type recv1;
   // std::cout<<"avant la comm____11 "<<std::endl;
        recv1 =put(s2);
   // std::cout<<"apres  la comm___11 "<<std::endl;
        par< boost::function< data<double>(int)> > s3 = bl::bind(transmi_col,bl::_1,ParB,t,n);
        result_of::put< boost::function<data<double> (int)> >::type recv2;


        recv2 =put(s3);

    //  std::cout<<"apres la commm  "<<std::endl;
//          put(ParA,fun_row);
//          put(ParB,fun_col);



      //  synchronize();
        t2=bsp::time();
        Tcomm+=t2-t1;

           int l=-1;
            int kj;


           t1=bsp::time();
           for(int a=0;a<m;a++)
            {
                l++;
              int v1=0;
              for(int i=0;i<nlr;i++)
               for(int k=0,kj=0;k<nlc;k++,kj++)
               {
                   if(v1==1){l--;v1=0;}
                for(int j=0;j<nlc;j++){
                                // printf("rank %d  index = %d, A(%d;%d)= %f \n",bsp_rank(),s+a*n,i,k,ParA(s+a*n)(i,k));
                //C(i+kk*b,j+kk*b)+= ParA(s+a*n)(i,k)*ParB(s+t*n)(k,j);
               //C(i+kk*b,j+kk*b)+= (*recv1)(s+a*n)(i,k)*(*recv2)(s+t*n)(k,j);
                if((k%nlr==0)&&(k!=0)&&(v1==0)) {
                l++;v1=1;kj=0;}


              // C(i+kk*b,j+kk*b)+= (*recv1)(s+a*n)(i,k)*(*recv2)(l+t*n)(kj,j);
               C(i,j)+= (*recv1)(s+a*n)(i,k)*(*recv2)(l+t*n)(kj,j);
                 // cpt++;

                }
               }

             }
            t2=bsp::time();
            Tcomp+=t2-t1;

          //synchronize();

    // }
//std::cout<<"fin de compute  "<<std::endl;



} /* end bspmv */


#endif




