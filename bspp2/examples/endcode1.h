#include <stdio.h>


static void usage(char *ar)
{
  fprintf(stderr, "Usage: %s <k> <npath> <time>\n", ar);
  fprintf(stderr, "  k:      length of paths\n");
  fprintf(stderr, "  npath:  number of paths to generate and verify\n");
  fprintf(stderr, "  time:   time interval (in seconds) for interactive display\n");
  exit(1);
}

int main(int argc, char *argv[])
{  

  int p, max, k, npath, time;
  char *r;

  int nbtrue[NB_VERIF_GOAL];
  int nbfalse[NB_VERIF_GOAL];
  int NBTRUE[NB_VERIF_GOAL];
  int NBFALSE[NB_VERIF_GOAL];

  if( argc != 4 )
    usage(argv[0]);

  k = strtol(argv[1], &r, 0);
  if( *r != 0 )
    {
      fprintf(stderr, "arg 1 `%s' is not a number\n", argv[1]);
      usage(argv[0]);
    }

  npath = strtol(argv[2], &r, 0);
  if( *r != 0 )
    {
      fprintf(stderr, "arg 2 `%s' is not a number\n", argv[2]);
      usage(argv[0]);
    }

  time = strtol(argv[3], &r, 0);
  if( *r != 0 )
    {
      fprintf(stderr, "arg 3 `%s' is not a number\n", argv[3]);
      usage(argv[0]);
    }







  for(p = 0; p < NB_VERIF_GOAL; p++)
    NBTRUE[p] = NBFALSE[p] = 0;
unsigned int id=42;

  for(;;)
    {
      run(id,nbtrue, nbfalse, k, time);
      //printf("rank = %d nbproc= %d  val =%d  adress=%p \n",omp_get_thread_num(),omp_get_num_threads(),nbtrue[0],&nbtrue[0]);

      for(p = 0; p < NB_VERIF_GOAL; p++)
	{
	  NBTRUE[p] += nbtrue[p];
	  NBFALSE[p] += nbfalse[p];
	}
      
      fprintf(stderr, "[2J");

      max = 0;
      for(p = 0; p < NB_VERIF_GOAL; p++)
	{
	  fprintf(stderr, "[%d;1Hgoal %d: %d|%d = %5.3g%%", 
		  p+1, p, NBTRUE[p], NBFALSE[p], 
		  100.0*(double)NBTRUE[p]/((double)NBTRUE[p]+(double)NBFALSE[p]));
	  if( NBTRUE[p] + NBFALSE[p] > max )
	    max = NBTRUE[p] + NBFALSE[p];
	}
      if(max >= npath)
	break;
      fprintf(stderr, "[%d;1HDone %g%%", p+1, 100.0 * (double)max / (double)npath);
    }

  fprintf(stderr, "[2J[1;1H");

  for(p = 0; p < NB_VERIF_GOAL; p++)
    printf("goal %d: %d|%d = %5.3g%%\n", p, NBTRUE[p], NBFALSE[p], 100.0*(double)NBTRUE[p]/((double)NBTRUE[p]+(double)NBFALSE[p]));



  return 0;
}
