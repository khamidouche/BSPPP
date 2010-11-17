#include <stdio.h>
#include <iostream>
#include <vector>
#include <bsppp/bsppp.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/serialization/utility.hpp>



using namespace bsp;
using namespace std;

namespace bl = boost::lambda;


pair<vector<int>,vector<int> > inline  f_comm_omp ( int ind, par<pair<vector<int>, vector<int> > > const& v)
  { 
	  return  *v;

  }




pair<vector<int>, vector<int> > main_omp(int argc, char **argv,int id_mpi, int k, int npath, int time)
{
  
  pair<vector<int>,vector<int> > OUT;
	
  BSP_FUNCTION(argc,argv)
  {
	  
  
  int p, max, rank, nbprocs, done;
  
   pair<vector<int>,vector<int> > sortie =make_pair(vector<int>(NB_VERIF_GOAL),vector<int>(NB_VERIF_GOAL) );
  par<std::pair<std::vector<int>,std::vector<int> > > PAR_OMP;
  PAR_OMP= make_pair(std::vector<int> (NB_VERIF_GOAL),std::vector<int> (NB_VERIF_GOAL) );
  
  //int NBTRUE[NB_VERIF_GOAL];
 // int NBFALSE[NB_VERIF_GOAL];
  rank=bsp::pid();
  nbprocs=bsp::size();
  
  
  

  for(p = 0; p < NB_VERIF_GOAL; p++)
    //NBTRUE[p] = NBFALSE[p] = 0;
    sortie.first[p]=sortie.second[p]=0;
 
  //T1=bsp::time();
   
unsigned int id= id_mpi*nbprocs+rank;
   
  for(;;)
    {
        
      run(id,&((*PAR_OMP).first[0]), &((*PAR_OMP).second[0]), k, time);
	  

         
         
	//  printf("yaww rank= %d , par1 = %d   par2 =%d \n",rank, (*PAR).first[0],(*PAR).second[0]);
	  
	  
	  par < boost::function<pair<vector<int>, vector<int> > (int)> > s = bl::bind(f_comm_omp,bl::_1,PAR_OMP);
      result_of::put< boost::function<pair<vector<int>, vector<int> >  (int)> > ::type recv;
      recv = put( s );
	  
      max = 0;
     for(int i=0;i<nbprocs;i++)
      for(p = 0; p < NB_VERIF_GOAL; p++)
	   {
	         sortie.first[p] += (*recv)(i).first[p];
		 sortie.second[p] += (*recv)(i).second[p];


	   }



              for(p = 0; p < NB_VERIF_GOAL; p++)
	       {
	
	  if( sortie.first[p] + sortie.second[p] > max )
	    max = sortie.first[p] + sortie.second[p];
	      }


	    if(max >= npath)
	    break; 
	
    }
  //T2=bsp::time();
	
     if(rank==0)
	 {
      
	 OUT= sortie;
	 }

  
  }
  return OUT;
}
