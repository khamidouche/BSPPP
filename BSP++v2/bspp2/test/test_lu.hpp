/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/

#ifndef  TEST_LU_HPP__INCLUDED__
#define  TEST_LU_HPP__INCLUDED__




#include <vector>
#include <iostream>
#include "boost/multi_array.hpp"


#include  "environement.hpp"
#include  "env_mpi.hpp"
#include  "par.hpp"
#include  "step.hpp"
#include  "transmition.hpp"


#include  "view.hpp"
#include  "bsp_lu.hpp"



namespace BSP
{


/*  This is a test program which uses bsplu to decompose an n by n
    matrix A into triangular factors L and U, with partial row pivoting.
    The decomposition is A(pi(i),j)=(LU)(i,j), for 0 <= i,j < n,
    where pi is a permutation.

    The input matrix A is a row-rotated version of a matrix B:
        the matrix B is defined by: B(i,j)= 0.5*i+1     if i<=j
                                            0.5*j+0.5      i>j,
        the matrix A is defined by: A(i,j)= B((i-1) mod n, j).

    This should give as output:
        the matrix L given by: L(i,j)= 0   if i<j,
                                     = 1      i=j,
                                     = 0.5    i>j.
        the matrix U given by: U(i,j)= 1   if i<=j,
                                     = 0      i>j.
        the permutation pi given by:  pi(i)= (i+1) mod n.

    Output of L and U is in triples (i,j,L\U(i,j)):
        (i,j,0.5) for i>j
        (i,j,1)   for i<=j
    Output of pi is in pairs (i,pi(i))
        (i,(i+1) mod n) for all i.

    The matrix A is constructed such that the pivot choice is unique.
    In stage k of the LU decomposition, row k is swapped with row r=k+1.
    For the M by N cyclic distribution this forces a row swap
    between processor rows.
*/


boost::optional<int> transf1( int ind,boost::optional<int> const& v )
  {
    if(bsp_rank()==0)
     return v;
   else return boost::optional<int>();

  }



template<class T>
void test_lu(int argc, char ** argv){

    int p, pid, s, t, nlr, nlc, i, j, iglob, jglob, m1,n1,nm,M,N,n;
    double  time0, time1;

    bsp_env env(argc, argv);
    {
      if(bsp_rank()==0)
      {
        std::cout << "donner M "<<std::endl;
        std::cin >> M;
        std::cout << "donner N "<<std::endl;
        std::cin >> N;
        std::cout << "donner n "<<std::endl;
        std::cin >> n;
      }

     typedef boost::multi_array<double, 2> array_type;
     array_type a(boost::extents[0][0]);
     std::vector<double> pi;


      par<int> MM;
      MM = replicate(M);
      par<int> NN;
      NN = replicate(N);
      par<int> nn;
      nn = replicate(n);



      parfun<int> fun;
      fun = replicate(transf1);


      super_step(init)
      {
        p=bsp_procs(); /* p=M*N */
        pid=bsp_rank();

       put(MM,fun);
       put(NN,fun);
       put(nn,fun);
      }



    /* Compute 2D processor numbering from 1D numbering */
    super_step()
    {
        m1=MM();
        n1=NN();
        nm=nn();

        s= pid%m1;  /* 0 <= s < M */
        t= pid/m1;  /* 0 <= t < N */

        /* Allocate and initialize matrix */
        nlr=  nloc(m1,s,nm); /* number of local rows */
        nlc=  nloc(n1,t,nm); /* number of local columns */



         a.resize(boost::extents[nlr][nlc]);

         pi.resize(nlr);


        if (s==0 && t==0){
             std::cout<<"LU decomposition of "<< nm <<" by "<< nm<<" matrix"<<std::endl;
             std::cout<<"using the "<< m1 <<" by "<< n1<<" cyclic distribution"<<std::endl;

        }
        for (i=0; i<nlr; i++){
            iglob= i*m1+s;         /* Global row index in A */
            iglob= (iglob-1+nm)%nm; /* Global row index in B */
            for (j=0; j<nlc; j++){
                jglob= j*n1+t;     /* Global column index in A and B */
                a[i][j]= (iglob<=jglob ? 0.5*iglob+1 : 0.5*(jglob+1) );
            }
        }

        if (s==0 && t==0)
            std::cout<<"Start of LU decomposition"<<std::endl;


    }
    //bsp_sync();
    super_step()
    {
     time0=bsp_time();

    bsp_lu<double>(m1,n1,s,t,nm,pi,a);

    }
    //bsp_sync();
    time1=bsp_time();
    super_step()
    {
        if (s==0 && t==0){
           std::cout<<"End of LU decomposition"<<std::endl;
           std::cout<<"This took only " <<time1-time0<<" seconds"<<std::endl;
           std::cout<<"The output permutation is"<<std::endl;

        }

        if (t==0){
            for (i=0; i<nlr; i++){
                iglob=i*m1+s;
                std::cout<<"i= "<<iglob<<" pi= "<<pi[i]<<" proc= ( "<<s<<" , "<<t<<" )"<<std::endl;

            }

        }
     }//bsp_sync();

     super_step()
    {
        if (s==0 && t==0){
            std::cout<<"The output matrix is"<<std::endl;
        }
        for (i=0; i<nlr; i++){
            iglob=i*m1+s;
            for (j=0; j<nlc; j++){
                jglob=j*n1+t;
                std::cout<<"i= "<<iglob<<" j= "<<jglob<<" a= "<<a[i][j]<<" proc= ( "<<s<<" , "<<t<<" )"<<std::endl;

            }
        }
    }

    }
}

//int main(int argc, char **argv){
//
//    bsp_init(bsplu_test, argc, argv);
//
//    printf("Please enter number of processor rows M:\n");
//    scanf("%d",&M);
//    printf("Please enter number of processor columns N:\n");
//    scanf("%d",&N);
//    if (M*N > bsp_nprocs()){
//        printf("Sorry, not enough processors available.\n");
//        fflush(stdout);
//        exit(1);
//    }
//
//    bsplu_test();
//    exit(0);
//
//} /* end main */
}

#endif
