#include <stdio.h>
#include <iostream>
#include <vector>
//#include "/home/hamidou/bsppp/branches/bspp2/include/bsppp/bsppp.hpp"
#include <bsppp/bsppp.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/serialization/utility.hpp>



using namespace bsp;
using namespace std;

namespace bl = boost::lambda;

//static
 void usage(char *ar)
{
  fprintf(stderr, "Usage: %s <k> <npath> <time>\n", ar);
  fprintf(stderr, "  k:      length of paths\n");
  fprintf(stderr, "  npath:  number of paths to generate and verify\n");
  fprintf(stderr, "  time:   time interval (in seconds) for interactive display\n");
  exit(1);
}


pair<vector<int>,vector<int> > inline  f_comm ( int ind, par<pair<vector<int>, vector<int> > > const& v)
  { 
	  return  *v;

  }

vector<int> inline  f_comm1 ( int ind, par<vector<int> > const& v)
  { 
	  return  *v;

  }



int main(int argc, char **argv)
{
	
  BSP_FUNCTION(argc,argv)
  {
	  
  
  int p, max, k, npath, time, rank, nbprocs, done;
  char *r;
  double T1,T2;

  /*int nbtrue[NB_VERIF_GOAL];
  int nbfalse[NB_VERIF_GOAL];*/
  
 /* par<std::vector<int> > P_nbtrue (NB_VERIF_GOAL);
  par<std::vector<int> > P_nbfalse (NB_VERIF_GOAL);*/
  
  par<std::pair<std::vector<int>,std::vector<int> > > PAR;
  PAR= make_pair(std::vector<int> (NB_VERIF_GOAL),std::vector<int> (NB_VERIF_GOAL) );
  

  par<vector<int> > ParArg;
  ParArg= vector<int>(3);

 
  
  int NBTRUE[NB_VERIF_GOAL];
  int NBFALSE[NB_VERIF_GOAL];
  rank=bsp::pid();
  nbprocs=bsp::size();
  
  if(rank==0)
  {
	  
  
	  if( argc != 4 )
		usage(argv[0]);

	  (*ParArg)[0] = strtol(argv[1], &r, 0);
	  if( *r != 0 )
		{
		  fprintf(stderr, "arg 1 `%s' is not a number\n", argv[1]);
		  usage(argv[0]);
		}

	  (*ParArg)[1] = strtol(argv[2], &r, 0);
	  if( *r != 0 )
		{
		  fprintf(stderr, "arg 2 `%s' is not a number\n", argv[2]);
		  usage(argv[0]);
		}

	  (*ParArg)[2] = strtol(argv[3], &r, 0);
	  if( *r != 0 )
		{
		  fprintf(stderr, "arg 3 `%s' is not a number\n", argv[3]);
		  usage(argv[0]);
		}
  }

      par < boost::function<vector<int> (int)> > sarg = bl::bind(f_comm1,bl::_1,ParArg);
      result_of::put< boost::function<vector<int>  (int)> > ::type recvarg;
      recvarg = put( sarg );
      

     k=(*recvarg)(0)[0];
     npath=(*recvarg)(0)[1];
     time=(*recvarg)(0)[2];
     

    // printf("le rank =%d k=%d npath=%d time=%d \n",rank,k,npath,time);


  for(p = 0; p < NB_VERIF_GOAL; p++)
    NBTRUE[p] = NBFALSE[p] = 0;
 
  unsigned int id=rank;

  T1=bsp::time();
  for(;;)
    {
        
      run(id,&((*PAR).first[0]), &((*PAR).second[0]), k, time);
	  

         
         
	//  printf("yaww rank= %d , par1 = %d   par2 =%d \n",rank, (*PAR).first[0],(*PAR).second[0]);
	  
	  
	  par < boost::function<pair<vector<int>, vector<int> > (int)> > s = bl::bind(f_comm,bl::_1,PAR);
      result_of::put< boost::function<pair<vector<int>, vector<int> >  (int)> > ::type recv;
      recv = put( s );
	  
      max = 0;
     for(int i=0;i<nbprocs;i++)
      for(p = 0; p < NB_VERIF_GOAL; p++)
	   {
	         NBTRUE[p] += (*recv)(i).first[p];
		 NBFALSE[p] += (*recv)(i).second[p];


		//if( NBTRUE[p] + NBFALSE[p] > max )
	      // max = NBTRUE[p] + NBFALSE[p];
	   }



              for(p = 0; p < NB_VERIF_GOAL; p++)
	       {
	  //fprintf(stderr, "[%d;1Hgoal %d: %d|%d = %5.3g%%", 
	  //	  p+1, p, NBTRUE[p], NBFALSE[p], 
	  //	  100.0*(double)NBTRUE[p]/((double)NBTRUE[p]+(double)NBFALSE[p]));
	  if( NBTRUE[p] + NBFALSE[p] > max )
	    max = NBTRUE[p] + NBFALSE[p];
	      }





             // fprintf(stderr, "[2J");
             
	   
	    //done+=max;
		//printf("yaww rank= %d , done= %d\n",rank,done);
	    if(max >= npath)
	    break; 
	// fprintf(stderr, "[%d;1HDone %g%%", p+1, 100.0 * (double)max / (double)npath);
    }
  T2=bsp::time();
	
     if(rank==0)
	 {
       printf("le temps est %f\n",T2-T1);
		 
      fprintf(stderr, "[2J");

      
      for(p = 0; p < NB_VERIF_GOAL; p++)
	  {
	  fprintf(stderr, "[%d;1Hgoal %d: %d|%d = %5.3g%%", 
		  p+1, p, NBTRUE[p], NBFALSE[p], 
		  100.0*(double)NBTRUE[p]/((double)NBTRUE[p]+(double)NBFALSE[p]));
	 
	  }
       /* fprintf(stderr, "[%d;1HDone %g%%", p+1, 100.0 * (double)max / (double)npath);
	
	 
	    fprintf(stderr, "[2J[1;1H");*/

      /*for(p = 0; p < NB_VERIF_GOAL; p++)
        printf("goal %d: %d|%d = %5.3g%%\n", p, NBTRUE[p], NBFALSE[p], 100.0*(double)NBTRUE[p]/((double)NBTRUE[p]+(double)NBFALSE[p]));*/

	 
	 
	 }

  
  }
  return 0;
}
