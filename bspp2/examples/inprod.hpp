/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef INPROD_HPP_INCLUDED
#define INPROD_HPP_INCLUDED


using namespace bsp;
namespace bl = boost::lambda;

int trans0( int to, par<int> const& p )
{
    if(*pid_==0)
         return  *p;
    else return int();
}




int inline nloc(int p, int s, int n){
    /* Compute number of local components of processor s for vector
       of length n distributed cyclically over p processors. */
    return  (n+p-s-1)/p ;
} /* end nloc */

template<class T>
inline T  compute (int N, std::vector<T>const& x,std::vector<T>const& y)
 { T res=0.0;

   for (int i=0;i<N;i++)
     res+= x[i]*y[i];

     return res;
  }

template<class T>
T bspip(int p, int s, int n, std::vector<T>& x, std::vector<T>& y,double & Tcomp,double & Tcomm)
{
   T alpha;
    int t;

   par<T> part;
   part=0;



      *part=compute(nloc(p,s,n),x,y);


 result_of::proj<double>::type fw1;
     fw1=proj(part);



      alpha= 0.0;
      for (t=0; t<p; t++)
          {
           alpha += fw1(t);
          }

    return alpha;

} /* end bspip */
template <class T>
void bspinprod(int argc, char ** argv){




    BSP_FUNCTION(argc,argv)
    {
     double  alpha, time0, time1,Tcomp,Tcomm;
    int p, s, nl, i, iglob;


      par<int> n;
      n = 0;


        p = bsp::size();  /* p = number of processors obtained */
        s= bsp::pid();    /* s = processor number */

        if (s==0){

             *n=atoi(argv[1]);
          //  if(*n<0) bsp_abort(1);
              }
              synchronize();

  par< boost::function< int(int)> > s1 = bl::bind(trans0,bl::_1,n);
     result_of::put< boost::function<int (int)> >::type recv;

        recv =put(s1);


        *n=(*recv)(0);


     std::vector<T> x;


      nl= nloc(p,s,*n);

      x.resize(nl);
      for (i=0; i<nl; i++){
          iglob= i*p+s;
          x[i]= iglob+1;
            }


     synchronize();

     time0=bsp::time();

      alpha= bspip<double>(p,s,*n,x,x,Tcomp,Tcomm);

     synchronize();
     time1=bsp::time();

      std::cout<< "processor "<<s<<"  n =  "<<*n<<"  alpha = "<<alpha<<std::endl;
      if (s==0)
      {std::cout<<"This took only : "<<time1-time0 << "  seconds"<<std::endl;/*
      std::cout<<"This took only computing : "<<Tcomp << "  seconds"<<std::endl;
      std::cout<<"This took only communication : "<<Tcomm << "  seconds"<<std::endl;*/
//           std::ofstream  fout;
//           fout.open("innerprod_result",std::ofstream::app);
//           if(!fout.is_open()) printf("cannot open the FILE \n");
//           else {
//              fout <<bsp_procs()<<" "<<"computaion "<<" "<<Tcomp <<" communication "<<Tcomm<<" "<<n();
//              fout << std::endl;
//              fout.flush();
//             }
//           fout.close();


      }


  }


}



#endif
