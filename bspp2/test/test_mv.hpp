/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/

#ifndef  TEST_MV_HPP__INCLUDED__
#define  TEST_MV_HPP__INCLUDED__


#include <vector>
#include <iostream>
#include "boost/multi_array.hpp"

#include  "environement.hpp"
#include  "env_mpi.hpp"
#include  "par.hpp"
#include  "step.hpp"
#include  "transmition.hpp"


#include  "view.hpp"
#include  "bsp_mv.hpp"



//#include "bspedupack.h"

/* This is a test program which uses bspmv to multiply a
   sparse matrix A and a dense vector u to obtain a dense vector v.
   The sparse matrix and its distribution
   are read from an input file.
   The dense vector v is initialized by the test program.
   The distribution of v is read from an input file.
   The distribution of u is read from another input file.

   The output vector is defined by
       u[i]= (sum: 0<=j<n: a[i][j]*v[j]).
*/

#define DIV 0
#define MOD 1
#define NITERS 10
#define STRLEN 100

namespace BSP
{

 struct indexpair {int i,j; double a;} ;

//class indexpair
//  {
//
//
//    friend class boost::serialization::access;
//    template <class archive>
//    void inline serialize (archive &ar, const unsigned version)
//    {
//
//      //  utilisation de falg pour avoir la meme structure que optional
//     // bool flag= empty();
//      // envoyer le flag quelque soit ca valeur
//      ar & i;
//      ar & j;
//      ar & a;
//
//
//     // if(!flag){
//      //  si le pointeur n'est pas vide => envoyer les donner
//      //ar & boost::serialization::make_array(pointeur, size_);
//
//      //}
//    }
//
//     int get_i (){return i;}
//     int get_j (){return j;}
//     double get_a (){return a;}
// private:
//    int i;
//    int j;
//    double a;
//
//
//  };


//int P;
boost::optional<int> transmi_0 ( int ind,boost::optional<int > const& v)
  {

           if(bsp_rank()==0) return v;
           else  return boost::optional<int>();


  }
boost::optional<int> transmi_1 ( int ind,boost::optional<int > const& v,int &q)
  {

           if(bsp_rank()==0)
                  if(ind==q)return v;
                  else return boost::optional<int>();
           else  return boost::optional<int>();


  }
template<class T>
boost::optional<std::vector<T> > transmi_2 ( int ind,boost::optional<std::vector<T> > const& v,int &q)
  {

           if(bsp_rank()==0)
                  if(ind==q)return v;
                  else return boost::optional<std::vector<indexpair> >();
           else  return boost::optional<std::vector<indexpair> >();


  }


void bspinput2triple(int const& p, int const & s,
                      par<int> & NA, par<int>& NZ, par<std::vector<indexpair> > & A_I_J
                     //  int *pnA, int *pnz,
                     //int **pia, int **pja, double **pa
                     ){

    /* This function reads a sparse matrix in distributed
       Matrix Market format without the banner line
       from the input file and distributes
       matrix triples to the processors.
       The input consists of one line
           m n nz p  (number of rows, columns, nonzeros, processors)
       followed by p+1 lines with the starting numbers
       of the processor parts
           Pstart[0]
           Pstart[1]
           ...
           Pstart[p]
       which means that processor q will get all nonzeros
       numbered Pstart[q]..Pstart[q+1]-1.
       This is followed by nz lines in the format
           i j a     (row index, column index, numerical value).
       The input indices are assumed by Matrix Market to start
       counting at one, but they are converted to start from zero.
       The triples are stored into three arrays ia, ja, a,
       in arbitrary order.

       Input:
       p is the number of processors.
       s is the processor number, 0 <= s < p.

       Output:
       nA is the global matrix size.
       nz is the number of local nonzeros.
       a[k] is the numerical value of the k'th local nonzero,
            0 <= k < nz.
       ia[k] is the global row index of the  k'th local nonzero.
       ja[k] is the global column index.
    */

    int pA, mA, nA, nzA, nz, q, nzq, k, tagsz, status,l;//, *Pstart, *ia, *ja;
    //double value, *a;
    //indexpair t;
    char filename[STRLEN];
    FILE *fp;


    parfun<int> fun0;
    fun0=replicate(bl::bind(transmi_0,bl::_1,bl::_2));

    parfun<int> fun1;

    parfun<std::vector<indexpair> > fun2;

    std::vector<int> Pstart(p+1);


//    Pstart= vecalloci(p+1);
//    bsp_push_reg(&nA,SZINT);
//    bsp_push_reg(&nz,SZINT);
//    tagsz= sizeof(indexpair);
//    bsp_set_tagsize(&tagsz);
//    bsp_sync();

    if (s==0){
        /* Open the matrix file and read the header */
        printf("Please enter the filename of the matrix distribution\n");
        scanf("%s",filename);
        fp=fopen(filename,"r");

        /* A is an mA by nA matrix with nzA nonzeros
           distributed over pA processors. */
        fscanf(fp,"%d %d %d %d\n", &mA, &nA, &nzA, &pA);
        if(pA!=p)
            {std::cout<< "Error: p not equal to p(A)\n"<<std::endl;bsp_abort(1);}
        if(mA!=nA)
            {std::cout<<"Error: matrix is not square"<<std::endl; bsp_abort(1);}
        NA()= nA;
        for (q=0; q<=p; q++)
            fscanf(fp,"%d\n", &Pstart[q]);
//        for (q=0; q<p; q++){
//           //bsp_put(q,&nA,&nA,0,SZINT);
//            nz[q]= Pstart[q+1]-Pstart[q];
//            //bsp_put(q,&nzq,&nz,0,SZINT);
       // }

    }
    put(NA,fun0);

    for(q=0; q<p; q++)
     {
       if(s==0)
        NZ()=Pstart[q+1]-Pstart[q];

        fun1=replicate(bl::bind(transmi_1,bl::_1,bl::_2,q));
        put(NZ,fun1);

      }



//    bsp_sync();


    /* Handle the processors one at a time.
       This saves buffer memory, at the expense of p-1 extra syncs.
       Buffer memory needed for communication is at most the maximum
       amount of memory a processor needs to store its vector components. */

//    a= vecallocd(nz+1);
//    ia= vecalloci(nz+1);
//    ja= vecalloci(nz+1);

    A_I_J().resize(NZ());

//////////*************/////////////***************/////////////********
    for (q=0; q<p; q++){
        if (s==0){
            /* Read the nonzeros from the matrix file and
               send them to their destination */
               l=0;
            for (k=Pstart[q]; k<Pstart[q+1]; k++){
                fscanf(fp,"%d %d %lf\n", &A_I_J()[l].i, &A_I_J()[l].j, &A_I_J()[l].a);
                l++;
                /* Convert indices to range 0..n-1,
                   assuming it was 1..n */
//                t.i--;
                  A_I_J()[l].i--;
//                t.j--;
                  A_I_J()[l].j--;
                /* Send a triple to P(q). Tag is a pair (i,j).
                   Payload is a numerical value */
               // bsp_send(q,&t,&value,SZDBL);
            }
        }

        fun2=replicate(bl::bind(transmi_1,bl::_1,bl::_2,q));
        put(A_I_J,fun2);


//        bsp_sync();
//
//        if (s==q){
//            /* Store the received nonzeros */
//            for(k=0; k<nz; k++){
//                bsp_get_tag(&status,&t);
//                ia[k]= t.i;
//                ja[k]= t.j;
//                bsp_move(&a[k],SZDBL);
//            }
//        }
    }

//    *pnA= nA;
//    *pnz= nz;
//    *pa= a;
//    *pia= ia;
//    *pja= ja;
    if (s==0)
        fclose(fp);
//    bsp_pop_reg(&nz);
//    bsp_pop_reg(&nA);
//    bsp_sync();

} /* end bspinput2triple */

int key(int & i, int& radix, int const& keytype){
   /* This function computes the key of an index i
      according to the keytype */

       if (keytype==DIV)
           return i/radix;
       else /* keytype=MOD */
           return i%radix;

} /* end key */

void sort(par<int>const& NA, par<int>const& NZ, par<std::vector<indexpair> >& A_I_J,
             int & radix, int const &keytype){
   /* This function sorts the nonzero elements of an n by n sparse
      matrix A stored in triple format in arrays ia, ja, a.
      The sort is by counting.
      If keytype=DIV, the triples are sorted by increasing value of
      ia[k] div radix.
      if keytype=MOD, the triples are sorted by increasing value of
      ia[k] mod radix.
      The sorting is stable: ties are decided so that the original
      precedences are maintained. For a complete sort by increasing
      index ia[k], this function should be called twice:
      first with keytype=MOD, then with keytype=DIV.

      Input:
      n is the global size of the matrix.
      nz is the local number of nonzeros.
      a[k] is the numerical value of the k'th nonzero of the
           sparse matrix A, 0 <= k < nz.
      ia[k] is the global row index of the k'th nonzero.
      ja[k] is the global column index of the k'th nonzero.
      radix >= 1.

      Output: ia, ja, a in sorted order.
   */

  // int key(int i, int radix, int keytype);

   int /* *ia1, *ja1,*/ nbins,/* *startbin, *lengthbin,*/ r, k, newk,n;
  // double *a1;


   n=NA();

//   ia1= vecalloci(nz);
//   ja1= vecalloci(nz);
//   a1 = vecallocd(nz);
    std::vector<int> ia1(NZ());
    std::vector<int> ja1(NZ());
    std::vector<int> a1 (NZ());

   /* Allocate bins */
   if (keytype==DIV)
       nbins= (n%radix==0 ? n/radix : n/radix+1);
   else if (keytype==MOD)
       nbins= radix;
       std::vector<int> startbin (nbins);
       std::vector<int> lengthbin(nbins);
//   startbin= vecalloci(nbins);
//   lengthbin= vecalloci(nbins);

   /* Count the elements in each bin */
   for (r=0; r<nbins; r++)
       lengthbin[r]= 0;
   for (k=0; k<NZ(); k++){
       r= key(A_I_J()[k].i,radix,keytype);
       lengthbin[r]++;
   }

   /* Compute the starting positions */
   startbin[0]= 0;
   for (r=1; r<nbins; r++)
       startbin[r]= startbin[r-1] + lengthbin[r-1];

   /* Enter the elements into the bins in temporary arrays (ia1,ja1,a1) */
   for (k=0; k<NZ(); k++){
       r= key(A_I_J()[k].i,radix,keytype);
       newk= startbin[r];
       ia1[newk]= A_I_J()[k].i;
       ja1[newk]= A_I_J()[k].j;
       a1[newk] = A_I_J()[k].a;;
       startbin[r]++;
   }

   /* Copy the elements back to the orginal arrays */
   for (k=0; k<NZ(); k++){
       A_I_J()[k].i= ia1[k];
       A_I_J()[k].j= ja1[k];
       A_I_J()[k].a= a1[k];
   }

//   vecfreei(lengthbin);
//   vecfreei(startbin);
//   vecfreed(a1);
//   vecfreei(ja1);
//   vecfreei(ia1);

} /* end sort */

void triple2icrs(par<int>const& NA, par<int>const& NZ, par<std::vector<indexpair> >& A_I_J ,
                   int & pnrows, int & pncols,
                   std::vector<int>&prowindex, std::vector<int>&pcolindex
//                 int *pnrows, int *pncols,
//                 int **prowindex, int **pcolindex
                 ){
    /* This function converts a sparse matrix A given in triple
       format with global indices into a sparse matrix in
       incremental compressed row storage (ICRS) format with
       local indices.

       The conversion needs time and memory O(nz + sqrt(n))
       on each processor, which is O(nz(A)/p + n/p + p).

       Input:
       n is the global size of the matrix.
       nz is the local number of nonzeros.
       a[k] is the numerical value of the k'th nonzero
            of the sparse matrix A, 0 <= k <nz.
       ia[k] is the global row index of the k'th nonzero.
       ja[k] is the global column index of the k'th nonzero.

       Output:
       nrows is the number of local nonempty rows
       ncols is the number of local nonempty columns
       rowindex[i] is the global row index of the i'th
                   local row, 0 <= i < nrows.
       colindex[j] is the global column index of the j'th
                   local column, 0 <= j < ncols.
       a[k] is the numerical value of the k'th local nonzero of the
            sparse matrix A, 0 <= k < nz. The array is sorted by
            row index, ties being decided by column index.
       ia[k] = inc[k] is the increment in the local column index of the
              k'th local nonzero, compared to the column index of the
              (k-1)th nonzero, if this nonzero is in the same row;
              otherwise, ncols is added to the difference.
              By convention, the column index of the -1'th nonzero is 0.
   */

//   void sort(int n, int nz, int *ia, int *ja, double *a,
//             int radix, int keytype);

   int radix, i, iglob, iglob_last, j, jglob, jglob_last, k, inck,n;
      // nrows, ncols, *rowindex, *colindex;

   /* radix is the smallest power of two >= sqrt(n)
      The div and mod operations are cheap for powers of two.
      A radix of about sqrt(n) minimizes memory and time. */
      n=NA();

   for (radix=1; radix*radix<n; radix *= 2)
       ;

   /* Sort nonzeros by column index */
   sort(NA,NZ,A_I_J,radix,MOD);
   sort(NA,NZ,A_I_J,radix,DIV);

   /* Count the number of local columns */
   pncols= 0;
   jglob_last= -1;
   for(k=0; k<NZ(); k++){
       jglob= A_I_J()[k].j;
       if(jglob!=jglob_last)
           /* new column index */
           pncols++;
       jglob_last= jglob;
   }
   //colindex= vecalloci(ncols);
   pcolindex.resize(pncols);

   /* Convert global column indices to local ones.
      Initialize colindex */
   j= 0;
   jglob_last= -1;
   for(k=0; k<NZ(); k++){
       jglob= A_I_J()[k].j;
       if(jglob!=jglob_last){
           pcolindex[j]= jglob;
           j++;
       }
       A_I_J()[k].j= j-1; /* local index of last registered column */
       jglob_last= jglob;
   }

   /* Sort nonzeros by row index using radix-sort */
   sort(NA,NZ,A_I_J,radix,MOD);
   sort(NA,NZ,A_I_J,radix,DIV);

   /* Count the number of local rows */
   pnrows= 0;
   iglob_last= -1;
   for(k=0; k<NZ(); k++){
       iglob= A_I_J()[k].i;
       if(iglob!=iglob_last)
           /* new row index */
           pnrows++;
       iglob_last= iglob;
   }
   //rowindex= vecalloci(nrows);
   prowindex.resize(pnrows);

   /* Convert global row indices to local ones.
      Initialize rowindex and inc */
   i= 0;
   iglob_last= -1;
   for(k=0; k<NZ(); k++){
       if (k==0)
           inck= A_I_J()[k].j;
       else
           inck= A_I_J()[k].j - A_I_J()[k-1].j;
       iglob= A_I_J()[k].i;
       if(iglob!=iglob_last){
           prowindex[i]= iglob;
           i++;
           if(k>0)
               inck += pncols;
       }
       A_I_J()[k].i= inck; /* ia is used to store inc */
       iglob_last= iglob;
   }
   if (NZ()==0)
       A_I_J()[NZ()].j= 0;
   else
       A_I_J()[NZ()].i= pncols - A_I_J()[NZ()-1].j;
   A_I_J()[NZ()].j= 0;
   A_I_J()[NZ()].a= 0.0;

//   *pncols= ncols;
//   *pnrows= nrows;
//   *prowindex= rowindex;
//   *pcolindex= colindex;

} /* end triple2icrs */

            //void bspinputvec(int & p, int &s,// const char *filename,
            //                 int *pn, int *pnv, int **pvindex){
            //
            //    /* This function reads the distribution of a dense vector v
            //       from the input file and initializes the corresponding local
            //       index array.
            //       The input consists of one line
            //           n p    (number of components, processors)
            //       followed by n lines in the format
            //           i proc (index, processor number),
            //       where i=1,2,...,n.
            //
            //       Input:
            //       p is the number of processors.
            //       s is the processor number, 0 <= s < p.
            //       filename is the name of the input file.
            //
            //       Output:
            //       n is the global length of the vector.
            //       nv is the local length.
            //       vindex[i] is the global index corresponding to
            //                 the local index i, 0 <= i < nv.
            //    */
            //
            //    int nloc(int p, int s, int n);
            //
            //    int n, pv, q, np, b, i, k, globk, proc, ind, nv,
            //        *tmpproc, *tmpind, *Nv, *vindex;
            //    FILE *fp;
            //
            //    bsp_push_reg(&n,SZINT);
            //    bsp_push_reg(&nv,SZINT);
            //    bsp_sync();
            //
            //    if (s==0){
            //        /* Open the file and read the header */
            //
            //        fp=fopen(filename,"r");
            //        fscanf(fp,"%d %d\n", &n, &pv);
            //        if(pv!=p)
            //            bsp_abort("Error: p not equal to p(vec)\n");
            //        for (q=0; q<p; q++)
            //            bsp_put(q,&n,&n,0,SZINT);
            //    }
            //    bsp_sync();
            //
            //    /* The owner of the global index i and its local index
            //       are stored in temporary arrays which are distributed
            //       cyclically. */
            //    np= nloc(p,s,n);
            //    tmpproc= vecalloci(np);
            //    tmpind= vecalloci(np);
            //    bsp_push_reg(tmpproc,np*SZINT);
            //    bsp_push_reg(tmpind,np*SZINT);
            //    bsp_sync();
            //
            //    if (s==0){
            //        /* Allocate component counters */
            //        Nv= vecalloci(p);
            //        for (q=0; q<p; q++)
            //            Nv[q]= 0;
            //    }
            //
            //    /* block size for vector read */
            //    b= (n%p==0 ? n/p : n/p+1);
            //    for (q=0; q<p; q++){
            //        if(s==0){
            //            /* Read the vector components from file and
            //               put their owner and local index into their
            //               temporary location. This is done n/p components
            //               at a time to save memory  */
            //            for(k=q*b; k<(q+1)*b && k<n; k++){
            //                fscanf(fp,"%d %d\n", &i, &proc);
            //                /* Convert index and processor number to ranges
            //                   0..n-1 and 0..p-1, assuming they were
            //                   1..n and 1..p */
            //                i--;
            //                proc--;
            //                ind= Nv[proc];
            //                if(i!=k)
            //                    bsp_abort("Error: i not equal to index \n");
            //                bsp_put(i%p,&proc,tmpproc,(i/p)*SZINT,SZINT);
            //                bsp_put(i%p,&ind,tmpind,(i/p)*SZINT,SZINT);
            //                Nv[proc]++;
            //            }
            //        }
            //        bsp_sync();
            //    }
            //
            //    if(s==0){
            //        for (q=0; q<p; q++)
            //            bsp_put(q,&Nv[q],&nv,0,SZINT);
            //        vecfreei(Nv);
            //    }
            //    bsp_sync();
            //
            //    /* Store the components at their final destination */
            //    vindex= vecalloci(nv);
            //    bsp_push_reg(vindex,nv*SZINT);
            //    bsp_sync();
            //
            //    for(k=0; k<np; k++){
            //        globk= k*p+s;
            //        bsp_put(tmpproc[k],&globk,vindex,tmpind[k]*SZINT,SZINT);
            //    }
            //    bsp_sync();
            //
            //    bsp_pop_reg(vindex);
            //    vecfreei(tmpind);
            //    vecfreei(tmpproc);
            //
            //    *pn= n;
            //    *pnv= nv;
            //    *pvindex= vindex;
            //
            //} /* end bspinputvec */

void test_mv(int argc, char ** argv){
//    void bspinput2triple(int p, int s, int *pnA, int *pnz,
//             int **pia, int **pja, double **pa);
//    void triple2icrs(int n, int nz, int *ia,  int *ja, double *a,
//             int *pnrows, int *pncols,
//             int **prowindex, int **pcolindex);
//    void bspinputvec(int p, int s, const char *filename,
//             int *pn, int *pnv, int **pvindex);
//    void bspmv_init(int p, int s, int n, int nrows, int ncols,
//             int nv, int nu, int *rowindex, int *colindex,
//             int *vindex, int *uindex,
//             int *srcprocv, int *srcindv, int *destprocu, int *destindu);
//    void bspmv(int p, int s, int n, int nz, int nrows, int ncols,
//             double *a, int *inc,
//             int *srcprocv, int *srcindv, int *destprocu, int *destindu,
//             int nv, int nu, double *v, double *u);

    int s, p, n, nz, i, iglob, pnrows, pncols, iter;

    double  time0, time1, time2;
    //char vfilename[STRLEN], ufilename[STRLEN];

//
    typedef boost::multi_array<double, 2> array_type;
     array_type MAT_U (boost::extents[0][0]);
//     typedef std::vector<std::vector<double> > array_type;
//     array_type MAT_U;


    bsp_env env(argc, argv);
   {

    par<int> NA;
    NA=replicate(0);


    par<int> NZ;
    NZ=replicate(0);

    par<std::vector<indexpair> > A_I_J;
    A_I_J= replicate(std::vector<indexpair> (0));



    par<view<array_type> > ParViewMat_U;


    std::vector<int> prowindex(0);
    std::vector<int> pcolindex(0);

    //bsp_begin(P);
    p= bsp_procs(); /* p=P */
    s= bsp_rank();


    /* Input of sparse matrix */
    bspinput2triple(p,s,NA,NZ,A_I_J);

    /* Convert data structure to incremental compressed row storage */
    triple2icrs(NA,NZ,A_I_J,pnrows,pncols,prowindex,pcolindex);
    //vecfreei(ja);

    /* Read vector distributions */
//    if (s==0){
//        printf("Please enter the filename of the v-vector distribution\n");
//        scanf("%s",vfilename);
//    }
//    bspinputvec(p,s,vfilename,&n,&nv,&vindex);
//
//    if (s==0){
//        printf("Please enter the filename of the u-vector distribution\n");
//        scanf("%s",ufilename);
//    }
//    bspinputvec(p,s,ufilename,&n,&nu,&uindex);
    if (s==0){
        printf("Sparse matrix-vector multiplication");
        printf(" using %d processors\n",p);
    }

    /* Initialize input vector v */
   // v= vecallocd(nv);
   std::vector<double> v(NA());
   std::vector<double> u(NA());
   std::vector<double> u_p(NA());
    for(i=0; i<NA(); i++){
       // iglob= vindex[i];
        v[i]= i;//iglob+1;
        u[i]=0.0;
        u_p[i]=0.0;
    }
    //u= vecallocd(nu);



    MAT_U.resize(boost::extents[p][NA()]);
    //MAT_U.resize(p).resize(NA());

    ParViewMat_U = MAT_U;

    if (s==0){
        printf("Initialization for matrix-vector multiplications\n");
        fflush(stdout);
    }
//    bsp_sync();
//    time0= bsp_time();

//    srcprocv= vecalloci(ncols);
//    srcindv= vecalloci(ncols);
//    destprocu= vecalloci(nrows);
//    destindu= vecalloci(nrows);
//    bspmv_init(p,s,NA(),pnrows,pncols,//nv,nu,
//               prowindex,pcolindex,//vindex,uindex,srcprocv,srcindv,destprocu,destindu
//               );

    if (s==0){
        printf("Start of %d matrix-vector multiplications.\n",(int)NITERS);
        fflush(stdout);
    }
   // bsp_sync();
    time1= bsp_time();
    super_step()
    {
    for(iter=0; iter<NITERS; iter++)
        bsp_mv(p, s, NA, NZ, pnrows, A_I_J, prowindex, pcolindex, v, u_p, u, ParViewMat_U, MAT_U);
    }
    //bsp_sync();
    time2= bsp_time();

    if (s==0){
        printf("End of matrix-vector multiplications.\n");
        printf("Initialization took only %.6lf seconds.\n",time1-time0);
        printf("Each matvec took only %.6lf seconds.\n",
                      (time2-time1)/(double)NITERS);
        printf("The computed solution is:\n");
        fflush(stdout);
    }

//    for(i=0; i<nu; i++){
//        iglob=uindex[i];
//        printf("proc=%d i=%d, u=%lf \n",s,iglob,u[i]);
//    }
//
//    vecfreei(destindu); vecfreei(destprocu);
//    vecfreei(srcindv);  vecfreei(srcprocv);
//    vecfreed(u);        vecfreed(v);
//    vecfreei(uindex);   vecfreei(vindex);
//    vecfreei(rowindex); vecfreei(colindex);
//    vecfreei(ia);       vecfreed(a);
//    bsp_end();
   }

} /* end bspmv_test */

//int main(int argc, char **argv){
//
//    bsp_init(bspmv_test, argc, argv);
//    printf("How many processors do you want to use?\n");
//    scanf("%d",&P);
//    if (P>bsp_nprocs()){
//        printf("Not enough processors available:");
//        printf(" %d wanted, %d available\n", P, bsp_nprocs());
//        exit(1);
//    }
//    bspmv_test();
//    exit(0);
//}
}
#endif
