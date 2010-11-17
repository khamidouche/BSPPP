/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/

#ifndef  TEST_DATA_HPP__INCLUDED__
#define  TEST_DATA_HPP__INCLUDED__




#include <vector>
#include <iostream>
#include <fstream>


#include  "data.hpp"



using namespace std;
//using namespace bsp;
//namespace bl = boost::lambda;
//
//
//
//data<double> transf0( int ind, par<data<double> > const& v )
//  {
//     return *v;
//
//  }
//
//
//

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
void test_data(int argc, char ** argv){

//    int p, pid, s, t, nlr, nlc, i, j, iglob, jglob, m1,n1,nm,M,N,n;
//    double  time0, time1;

////////        BSP_FUNCTION(argc,argv)
////////    {
////////
////////
////////      int p, pid;
////////    double  time0, time1,Tcomp,Tcomm;
////////
////////        par<data<double> > ParA;
////////        par<data<double> > ParB;
////////
////////
////////        p=bsp::size();
////////        pid=bsp::pid();
////////
////////
////////
////////std::cout<<p<<"  "<<pid<<std::endl;
////////
////////         ParA= data<double> (20,20);
////////         ParB= data<double> (20,20);
////////
////////
////////std::cout<<p<<"  "<<pid<<std::endl;
////////
////////
////////
////////
////////  for(int i=0;i<20;i++)
////////    for(int j=0;j<20;j++)
////////    {
////////
////////       (*ParA)(i,j)=1.0;
////////       (*ParB)(i,j)=1.0;
////////
////////
////////    }
////////
////////std::cout<<p<<" **** "<<pid<<std::endl;
////////   par< boost::function< data<double>(int)> > s1 = bl::bind(transf0,bl::_1,ParA);
////////     result_of::put< boost::function<data<double> (int)> >::type recv;
////////
////////        recv =put(s1);
////////
////////
////////   par< boost::function< data<double>(int)> > s2 = bl::bind(transf0,bl::_1,ParB);
////////     result_of::put< boost::function<data<double> (int)> >::type recv1;
////////
////////        recv1 =put(s2);
////////
////////
////////
////////std::cout<<p<<" //// "<<pid<<std::endl;
////////
////////    synchronize();
////////   // printf("eeeeeeeeeee\n");
////////    //bsp_sync();
////////    Tcomm=0.0;
////////    Tcomp=0.0;
////////
////////
////////     time0=bsp::time();
////////
////////if(pid==0)
////////{
////////  for(int a=0;a<p;a++)
////////   for(int i=0;i<5;i++)
////////    for(int j=0;j<5;j++)
////////    {
////////
////////       std::cout<<"data = "<<a<<"    "<<(*recv)(a)(i,j)<<std::endl;
////////
////////
////////    }
////////}
////////    synchronize();
////////    //bsp_sync();
////////    time1=bsp::time();
////////
////////
////////
////////
////////
////////     synchronize();
////////
////////
////////
////////
////////
////////    }

std::cout<<"ok 0"<<std::endl;
data<int> A(20,20);
data<int> B;
std::cout<<"construction ok "<<std::endl;
for(int i=0;i<20;i++)
 for(int j=0;j<20;j++)
     A(i,j)=i+j;

data<int> C(A);
std::cout<<"copie construction  ok "<<std::endl;
std::cout<<"C (0,2)== "<<C(0,2)<<std::endl;

B=A;
std::cout<<"copie ok"<<std::endl;
std::cout<<"B (0,2)== "<<B(0,2)<<std::endl;

  }


#endif





