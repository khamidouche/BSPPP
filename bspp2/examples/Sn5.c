#include <stdlib.h>
#include <string.h>
#include <math.h>

static unsigned int get_random(unsigned int& id, unsigned int min, unsigned int max)
{
  max++;
  return min + (unsigned int)( (double)(max-min)*rand_r(&id)/(RAND_MAX+(double)min));
}

static double probability(unsigned int& id)
{
  double r = (double)((unsigned int)-2);
  double R = get_random(id, 0, (unsigned int)-2);
  r = ((double)R) / r;
  return r;
}
/* constants and macros */
#define new_(a) (a*)calloc(1, sizeof(a))
#define MAX(a,b) (((a)<(b))?(b):(a))
#define MIN(a,b) (((a)<(b))?(a):(b))


/* configuration and path definition */
typedef struct conf {
  int s_3_3;
  int s_1_1;
  int s_1_2;
  int s_1_3;
  int s_1_4;
  int s_1_5;
  int s_2_1;
  int s_2_2;
  int s_2_3;
  int s_2_4;
  int s_2_5;
  int s_3_1;
  int s_3_2;
  int s_3_4;
  int s_3_5;
  int s_4_1;
  int s_4_2;
  int s_4_3;
  int s_4_4;
  int s_4_5;
  int s_5_1;
  int s_5_2;
  int s_5_3;
  int s_5_4;
  int s_5_5;
  int s_0_0;
  int s_0_1;
  int s_0_2;
  int s_0_3;
  int s_0_4;
  int s_0_5;
  int s_0_6;
  int s_1_0;
  int s_1_6;
  int s_2_0;
  int s_2_6;
  int s_3_0;
  int s_3_6;
  int s_4_0;
  int s_4_6;
  int s_5_0;
  int s_5_6;
  int s_6_0;
  int s_6_6;
  int s_6_1;
  int s_6_2;
  int s_6_3;
  int s_6_4;
  int s_6_5;
} conf;

typedef struct path {

  int s_1_1;
  int s_1_2;
  int s_1_3;
  int s_1_4;
  int s_1_5;
  int s_2_1;
  int s_2_5;
  int s_3_1;
  int s_3_5;
  int s_4_1;
  int s_4_5;
  int s_5_1;
  int s_5_2;
  int s_5_3;
  int s_5_4;
  int s_5_5;
} path;

static void init_state(conf* current, path* current_path, path* first_path, int path_len)
{

  current->s_3_3 = 0;
  current->s_1_1 = 0;
  current->s_1_2 = 0;
  current->s_1_3 = 0;
  current->s_1_4 = 0;
  current->s_1_5 = 0;
  current->s_2_1 = 0;
  current->s_2_2 = 0;
  current->s_2_3 = 0;
  current->s_2_4 = 0;
  current->s_2_5 = 0;
  current->s_3_1 = 0;
  current->s_3_2 = 0;
  current->s_3_4 = 0;
  current->s_3_5 = 0;
  current->s_4_1 = 0;
  current->s_4_2 = 0;
  current->s_4_3 = 0;
  current->s_4_4 = 0;
  current->s_4_5 = 0;
  current->s_5_1 = 0;
  current->s_5_2 = 0;
  current->s_5_3 = 0;
  current->s_5_4 = 0;
  current->s_5_5 = 0;
  current->s_0_0 = 0;
  current->s_0_1 = 0;
  current->s_0_2 = 0;
  current->s_0_3 = 0;
  current->s_0_4 = 0;
  current->s_0_5 = 0;
  current->s_0_6 = 0;
  current->s_1_0 = 0;
  current->s_1_6 = 0;
  current->s_2_0 = 0;
  current->s_2_6 = 0;
  current->s_3_0 = 0;
  current->s_3_6 = 0;
  current->s_4_0 = 0;
  current->s_4_6 = 0;
  current->s_5_0 = 0;
  current->s_5_6 = 0;
  current->s_6_0 = 0;
  current->s_6_6 = 0;
  current->s_6_1 = 0;
  current->s_6_2 = 0;
  current->s_6_3 = 0;
  current->s_6_4 = 0;
  current->s_6_5 = 0;
  current_path->s_1_1 = current->s_1_1;
  current_path->s_1_2 = current->s_1_2;
  current_path->s_1_3 = current->s_1_3;
  current_path->s_1_4 = current->s_1_4;
  current_path->s_1_5 = current->s_1_5;
  current_path->s_2_1 = current->s_2_1;
  current_path->s_2_5 = current->s_2_5;
  current_path->s_3_1 = current->s_3_1;
  current_path->s_3_5 = current->s_3_5;
  current_path->s_4_1 = current->s_4_1;
  current_path->s_4_5 = current->s_4_5;
  current_path->s_5_1 = current->s_5_1;
  current_path->s_5_2 = current->s_5_2;
  current_path->s_5_3 = current->s_5_3;
  current_path->s_5_4 = current->s_5_4;
  current_path->s_5_5 = current->s_5_5;
}

static void append_state(conf* current, path* current_path)
{

  current_path->s_1_1 = current->s_1_1;
  current_path->s_1_2 = current->s_1_2;
  current_path->s_1_3 = current->s_1_3;
  current_path->s_1_4 = current->s_1_4;
  current_path->s_1_5 = current->s_1_5;
  current_path->s_2_1 = current->s_2_1;
  current_path->s_2_5 = current->s_2_5;
  current_path->s_3_1 = current->s_3_1;
  current_path->s_3_5 = current->s_3_5;
  current_path->s_4_1 = current->s_4_1;
  current_path->s_4_5 = current->s_4_5;
  current_path->s_5_1 = current->s_5_1;
  current_path->s_5_2 = current->s_5_2;
  current_path->s_5_3 = current->s_5_3;
  current_path->s_5_4 = current->s_5_4;
  current_path->s_5_5 = current->s_5_5;
}

typedef void (*action_t)(unsigned int& id, conf* current);
typedef int  (*guard_t)(unsigned int& id, conf* current);

struct rule {
  guard_t guard;
  action_t action;
};

static int __g0(unsigned int& id, conf* current)
{
  return (current->s_3_3==0);
}
static void __a0(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_3 = 3;
    }
  __rv_min = __rv_max;

}

static int __g1(unsigned int& id, conf* current)
{
  return ((current->s_3_3==1)&&((current->s_2_3==3)||((current->s_4_3==3)||((current->s_3_2==3)||(current->s_3_4==3)))));
}
static void __a1(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_3 = 3;
    }
  __rv_min = __rv_max;

}

static int __g2(unsigned int& id, conf* current)
{
  return ((current->s_3_3==1)&&!(((current->s_2_3==3)||((current->s_4_3==3)||((current->s_3_2==3)||(current->s_3_4==3))))));
}
static void __a2(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_3 = 2;
    }
  __rv_min = __rv_max;

}

static int __g3(unsigned int& id, conf* current)
{
  return (current->s_3_3==2);
}
static void __a3(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_3 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_3 = 1;
    }
  __rv_min = __rv_max;

}

static int __g4(unsigned int& id, conf* current)
{
  return (current->s_3_3==3);
}
static void __a4(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_3 = 3;
    }
  __rv_min = __rv_max;

}

static int __g5(unsigned int& id, conf* current)
{
  return (current->s_1_1==0);
}
static void __a5(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_1 = 1;
    }
  __rv_min = __rv_max;

}

static int __g6(unsigned int& id, conf* current)
{
  return ((current->s_1_1==1)&&((current->s_0_1==3)||((current->s_2_1==3)||((current->s_1_0==3)||(current->s_1_2==3)))));
}
static void __a6(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_1 = 3;
    }
  __rv_min = __rv_max;

}

static int __g7(unsigned int& id, conf* current)
{
  return ((current->s_1_1==1)&&!(((current->s_0_1==3)||((current->s_2_1==3)||((current->s_1_0==3)||(current->s_1_2==3))))));
}
static void __a7(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_1 = 2;
    }
  __rv_min = __rv_max;

}

static int __g8(unsigned int& id, conf* current)
{
  return (current->s_1_1==2);
}
static void __a8(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_1 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_1 = 1;
    }
  __rv_min = __rv_max;

}

static int __g9(unsigned int& id, conf* current)
{
  return (current->s_1_1==3);
}
static void __a9(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_1 = 3;
    }
  __rv_min = __rv_max;

}

static int __g10(unsigned int& id, conf* current)
{
  return (current->s_1_2==0);
}
static void __a10(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_2 = 1;
    }
  __rv_min = __rv_max;

}

static int __g11(unsigned int& id, conf* current)
{
  return ((current->s_1_2==1)&&((current->s_0_2==3)||((current->s_2_2==3)||((current->s_1_1==3)||(current->s_1_3==3)))));
}
static void __a11(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_2 = 3;
    }
  __rv_min = __rv_max;

}

static int __g12(unsigned int& id, conf* current)
{
  return ((current->s_1_2==1)&&!(((current->s_0_2==3)||((current->s_2_2==3)||((current->s_1_1==3)||(current->s_1_3==3))))));
}
static void __a12(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_2 = 2;
    }
  __rv_min = __rv_max;

}

static int __g13(unsigned int& id, conf* current)
{
  return (current->s_1_2==2);
}
static void __a13(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_2 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_2 = 1;
    }
  __rv_min = __rv_max;

}

static int __g14(unsigned int& id, conf* current)
{
  return (current->s_1_2==3);
}
static void __a14(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_2 = 3;
    }
  __rv_min = __rv_max;

}

static int __g15(unsigned int& id, conf* current)
{
  return (current->s_1_3==0);
}
static void __a15(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_3 = 1;
    }
  __rv_min = __rv_max;

}

static int __g16(unsigned int& id, conf* current)
{
  return ((current->s_1_3==1)&&((current->s_0_3==3)||((current->s_2_3==3)||((current->s_1_2==3)||(current->s_1_4==3)))));
}
static void __a16(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_3 = 3;
    }
  __rv_min = __rv_max;

}

static int __g17(unsigned int& id, conf* current)
{
  return ((current->s_1_3==1)&&!(((current->s_0_3==3)||((current->s_2_3==3)||((current->s_1_2==3)||(current->s_1_4==3))))));
}
static void __a17(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_3 = 2;
    }
  __rv_min = __rv_max;

}

static int __g18(unsigned int& id, conf* current)
{
  return (current->s_1_3==2);
}
static void __a18(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_3 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_3 = 1;
    }
  __rv_min = __rv_max;

}

static int __g19(unsigned int& id, conf* current)
{
  return (current->s_1_3==3);
}
static void __a19(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_3 = 3;
    }
  __rv_min = __rv_max;

}

static int __g20(unsigned int& id, conf* current)
{
  return (current->s_1_4==0);
}
static void __a20(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_4 = 1;
    }
  __rv_min = __rv_max;

}

static int __g21(unsigned int& id, conf* current)
{
  return ((current->s_1_4==1)&&((current->s_0_4==3)||((current->s_2_4==3)||((current->s_1_3==3)||(current->s_1_5==3)))));
}
static void __a21(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_4 = 3;
    }
  __rv_min = __rv_max;

}

static int __g22(unsigned int& id, conf* current)
{
  return ((current->s_1_4==1)&&!(((current->s_0_4==3)||((current->s_2_4==3)||((current->s_1_3==3)||(current->s_1_5==3))))));
}
static void __a22(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_4 = 2;
    }
  __rv_min = __rv_max;

}

static int __g23(unsigned int& id, conf* current)
{
  return (current->s_1_4==2);
}
static void __a23(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_4 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_4 = 1;
    }
  __rv_min = __rv_max;

}

static int __g24(unsigned int& id, conf* current)
{
  return (current->s_1_4==3);
}
static void __a24(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_4 = 3;
    }
  __rv_min = __rv_max;

}

static int __g25(unsigned int& id, conf* current)
{
  return (current->s_1_5==0);
}
static void __a25(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_5 = 1;
    }
  __rv_min = __rv_max;

}

static int __g26(unsigned int& id, conf* current)
{
  return ((current->s_1_5==1)&&((current->s_0_5==3)||((current->s_2_5==3)||((current->s_1_4==3)||(current->s_1_6==3)))));
}
static void __a26(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_5 = 3;
    }
  __rv_min = __rv_max;

}

static int __g27(unsigned int& id, conf* current)
{
  return ((current->s_1_5==1)&&!(((current->s_0_5==3)||((current->s_2_5==3)||((current->s_1_4==3)||(current->s_1_6==3))))));
}
static void __a27(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_5 = 2;
    }
  __rv_min = __rv_max;

}

static int __g28(unsigned int& id, conf* current)
{
  return (current->s_1_5==2);
}
static void __a28(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_5 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_5 = 1;
    }
  __rv_min = __rv_max;

}

static int __g29(unsigned int& id, conf* current)
{
  return (current->s_1_5==3);
}
static void __a29(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_1_5 = 3;
    }
  __rv_min = __rv_max;

}

static int __g30(unsigned int& id, conf* current)
{
  return (current->s_2_1==0);
}
static void __a30(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_1 = 1;
    }
  __rv_min = __rv_max;

}

static int __g31(unsigned int& id, conf* current)
{
  return ((current->s_2_1==1)&&((current->s_1_1==3)||((current->s_3_1==3)||((current->s_2_0==3)||(current->s_2_2==3)))));
}
static void __a31(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_1 = 3;
    }
  __rv_min = __rv_max;

}

static int __g32(unsigned int& id, conf* current)
{
  return ((current->s_2_1==1)&&!(((current->s_1_1==3)||((current->s_3_1==3)||((current->s_2_0==3)||(current->s_2_2==3))))));
}
static void __a32(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_1 = 2;
    }
  __rv_min = __rv_max;

}

static int __g33(unsigned int& id, conf* current)
{
  return (current->s_2_1==2);
}
static void __a33(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_1 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_1 = 1;
    }
  __rv_min = __rv_max;

}

static int __g34(unsigned int& id, conf* current)
{
  return (current->s_2_1==3);
}
static void __a34(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_1 = 3;
    }
  __rv_min = __rv_max;

}

static int __g35(unsigned int& id, conf* current)
{
  return (current->s_2_2==0);
}
static void __a35(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_2 = 1;
    }
  __rv_min = __rv_max;

}

static int __g36(unsigned int& id, conf* current)
{
  return ((current->s_2_2==1)&&((current->s_1_2==3)||((current->s_3_2==3)||((current->s_2_1==3)||(current->s_2_3==3)))));
}
static void __a36(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_2 = 3;
    }
  __rv_min = __rv_max;

}

static int __g37(unsigned int& id, conf* current)
{
  return ((current->s_2_2==1)&&!(((current->s_1_2==3)||((current->s_3_2==3)||((current->s_2_1==3)||(current->s_2_3==3))))));
}
static void __a37(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_2 = 2;
    }
  __rv_min = __rv_max;

}

static int __g38(unsigned int& id, conf* current)
{
  return (current->s_2_2==2);
}
static void __a38(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_2 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_2 = 1;
    }
  __rv_min = __rv_max;

}

static int __g39(unsigned int& id, conf* current)
{
  return (current->s_2_2==3);
}
static void __a39(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_2 = 3;
    }
  __rv_min = __rv_max;

}

static int __g40(unsigned int& id, conf* current)
{
  return (current->s_2_3==0);
}
static void __a40(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_3 = 1;
    }
  __rv_min = __rv_max;

}

static int __g41(unsigned int& id, conf* current)
{
  return ((current->s_2_3==1)&&((current->s_1_3==3)||((current->s_3_3==3)||((current->s_2_2==3)||(current->s_2_4==3)))));
}
static void __a41(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_3 = 3;
    }
  __rv_min = __rv_max;

}

static int __g42(unsigned int& id, conf* current)
{
  return ((current->s_2_3==1)&&!(((current->s_1_3==3)||((current->s_3_3==3)||((current->s_2_2==3)||(current->s_2_4==3))))));
}
static void __a42(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_3 = 2;
    }
  __rv_min = __rv_max;

}

static int __g43(unsigned int& id, conf* current)
{
  return (current->s_2_3==2);
}
static void __a43(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_3 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_3 = 1;
    }
  __rv_min = __rv_max;

}

static int __g44(unsigned int& id, conf* current)
{
  return (current->s_2_3==3);
}
static void __a44(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_3 = 3;
    }
  __rv_min = __rv_max;

}

static int __g45(unsigned int& id, conf* current)
{
  return (current->s_2_4==0);
}
static void __a45(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_4 = 1;
    }
  __rv_min = __rv_max;

}

static int __g46(unsigned int& id, conf* current)
{
  return ((current->s_2_4==1)&&((current->s_1_4==3)||((current->s_3_4==3)||((current->s_2_3==3)||(current->s_2_5==3)))));
}
static void __a46(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_4 = 3;
    }
  __rv_min = __rv_max;

}

static int __g47(unsigned int& id, conf* current)
{
  return ((current->s_2_4==1)&&!(((current->s_1_4==3)||((current->s_3_4==3)||((current->s_2_3==3)||(current->s_2_5==3))))));
}
static void __a47(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_4 = 2;
    }
  __rv_min = __rv_max;

}

static int __g48(unsigned int& id, conf* current)
{
  return (current->s_2_4==2);
}
static void __a48(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_4 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_4 = 1;
    }
  __rv_min = __rv_max;

}

static int __g49(unsigned int& id, conf* current)
{
  return (current->s_2_4==3);
}
static void __a49(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_4 = 3;
    }
  __rv_min = __rv_max;

}

static int __g50(unsigned int& id, conf* current)
{
  return (current->s_2_5==0);
}
static void __a50(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_5 = 1;
    }
  __rv_min = __rv_max;

}

static int __g51(unsigned int& id, conf* current)
{
  return ((current->s_2_5==1)&&((current->s_1_5==3)||((current->s_3_5==3)||((current->s_2_4==3)||(current->s_2_6==3)))));
}
static void __a51(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_5 = 3;
    }
  __rv_min = __rv_max;

}

static int __g52(unsigned int& id, conf* current)
{
  return ((current->s_2_5==1)&&!(((current->s_1_5==3)||((current->s_3_5==3)||((current->s_2_4==3)||(current->s_2_6==3))))));
}
static void __a52(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_5 = 2;
    }
  __rv_min = __rv_max;

}

static int __g53(unsigned int& id, conf* current)
{
  return (current->s_2_5==2);
}
static void __a53(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_5 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_5 = 1;
    }
  __rv_min = __rv_max;

}

static int __g54(unsigned int& id, conf* current)
{
  return (current->s_2_5==3);
}
static void __a54(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_2_5 = 3;
    }
  __rv_min = __rv_max;

}

static int __g55(unsigned int& id, conf* current)
{
  return (current->s_3_1==0);
}
static void __a55(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_1 = 1;
    }
  __rv_min = __rv_max;

}

static int __g56(unsigned int& id, conf* current)
{
  return ((current->s_3_1==1)&&((current->s_2_1==3)||((current->s_4_1==3)||((current->s_3_0==3)||(current->s_3_2==3)))));
}
static void __a56(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_1 = 3;
    }
  __rv_min = __rv_max;

}

static int __g57(unsigned int& id, conf* current)
{
  return ((current->s_3_1==1)&&!(((current->s_2_1==3)||((current->s_4_1==3)||((current->s_3_0==3)||(current->s_3_2==3))))));
}
static void __a57(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_1 = 2;
    }
  __rv_min = __rv_max;

}

static int __g58(unsigned int& id, conf* current)
{
  return (current->s_3_1==2);
}
static void __a58(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_1 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_1 = 1;
    }
  __rv_min = __rv_max;

}

static int __g59(unsigned int& id, conf* current)
{
  return (current->s_3_1==3);
}
static void __a59(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_1 = 3;
    }
  __rv_min = __rv_max;

}

static int __g60(unsigned int& id, conf* current)
{
  return (current->s_3_2==0);
}
static void __a60(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_2 = 1;
    }
  __rv_min = __rv_max;

}

static int __g61(unsigned int& id, conf* current)
{
  return ((current->s_3_2==1)&&((current->s_2_2==3)||((current->s_4_2==3)||((current->s_3_1==3)||(current->s_3_3==3)))));
}
static void __a61(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_2 = 3;
    }
  __rv_min = __rv_max;

}

static int __g62(unsigned int& id, conf* current)
{
  return ((current->s_3_2==1)&&!(((current->s_2_2==3)||((current->s_4_2==3)||((current->s_3_1==3)||(current->s_3_3==3))))));
}
static void __a62(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_2 = 2;
    }
  __rv_min = __rv_max;

}

static int __g63(unsigned int& id, conf* current)
{
  return (current->s_3_2==2);
}
static void __a63(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_2 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_2 = 1;
    }
  __rv_min = __rv_max;

}

static int __g64(unsigned int& id, conf* current)
{
  return (current->s_3_2==3);
}
static void __a64(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_2 = 3;
    }
  __rv_min = __rv_max;

}

static int __g65(unsigned int& id, conf* current)
{
  return (current->s_3_4==0);
}
static void __a65(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_4 = 1;
    }
  __rv_min = __rv_max;

}

static int __g66(unsigned int& id, conf* current)
{
  return ((current->s_3_4==1)&&((current->s_2_4==3)||((current->s_4_4==3)||((current->s_3_3==3)||(current->s_3_5==3)))));
}
static void __a66(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_4 = 3;
    }
  __rv_min = __rv_max;

}

static int __g67(unsigned int& id, conf* current)
{
  return ((current->s_3_4==1)&&!(((current->s_2_4==3)||((current->s_4_4==3)||((current->s_3_3==3)||(current->s_3_5==3))))));
}
static void __a67(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_4 = 2;
    }
  __rv_min = __rv_max;

}

static int __g68(unsigned int& id, conf* current)
{
  return (current->s_3_4==2);
}
static void __a68(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_4 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_4 = 1;
    }
  __rv_min = __rv_max;

}

static int __g69(unsigned int& id, conf* current)
{
  return (current->s_3_4==3);
}
static void __a69(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_4 = 3;
    }
  __rv_min = __rv_max;

}

static int __g70(unsigned int& id, conf* current)
{
  return (current->s_3_5==0);
}
static void __a70(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_5 = 1;
    }
  __rv_min = __rv_max;

}

static int __g71(unsigned int& id, conf* current)
{
  return ((current->s_3_5==1)&&((current->s_2_5==3)||((current->s_4_5==3)||((current->s_3_4==3)||(current->s_3_6==3)))));
}
static void __a71(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_5 = 3;
    }
  __rv_min = __rv_max;

}

static int __g72(unsigned int& id, conf* current)
{
  return ((current->s_3_5==1)&&!(((current->s_2_5==3)||((current->s_4_5==3)||((current->s_3_4==3)||(current->s_3_6==3))))));
}
static void __a72(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_5 = 2;
    }
  __rv_min = __rv_max;

}

static int __g73(unsigned int& id, conf* current)
{
  return (current->s_3_5==2);
}
static void __a73(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_5 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_5 = 1;
    }
  __rv_min = __rv_max;

}

static int __g74(unsigned int& id, conf* current)
{
  return (current->s_3_5==3);
}
static void __a74(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_3_5 = 3;
    }
  __rv_min = __rv_max;

}

static int __g75(unsigned int& id, conf* current)
{
  return (current->s_4_1==0);
}
static void __a75(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_1 = 1;
    }
  __rv_min = __rv_max;

}

static int __g76(unsigned int& id, conf* current)
{
  return ((current->s_4_1==1)&&((current->s_3_1==3)||((current->s_5_1==3)||((current->s_4_0==3)||(current->s_4_2==3)))));
}
static void __a76(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_1 = 3;
    }
  __rv_min = __rv_max;

}

static int __g77(unsigned int& id, conf* current)
{
  return ((current->s_4_1==1)&&!(((current->s_3_1==3)||((current->s_5_1==3)||((current->s_4_0==3)||(current->s_4_2==3))))));
}
static void __a77(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_1 = 2;
    }
  __rv_min = __rv_max;

}

static int __g78(unsigned int& id, conf* current)
{
  return (current->s_4_1==2);
}
static void __a78(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_1 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_1 = 1;
    }
  __rv_min = __rv_max;

}

static int __g79(unsigned int& id, conf* current)
{
  return (current->s_4_1==3);
}
static void __a79(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_1 = 3;
    }
  __rv_min = __rv_max;

}

static int __g80(unsigned int& id, conf* current)
{
  return (current->s_4_2==0);
}
static void __a80(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_2 = 1;
    }
  __rv_min = __rv_max;

}

static int __g81(unsigned int& id, conf* current)
{
  return ((current->s_4_2==1)&&((current->s_3_2==3)||((current->s_5_2==3)||((current->s_4_1==3)||(current->s_4_3==3)))));
}
static void __a81(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_2 = 3;
    }
  __rv_min = __rv_max;

}

static int __g82(unsigned int& id, conf* current)
{
  return ((current->s_4_2==1)&&!(((current->s_3_2==3)||((current->s_5_2==3)||((current->s_4_1==3)||(current->s_4_3==3))))));
}
static void __a82(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_2 = 2;
    }
  __rv_min = __rv_max;

}

static int __g83(unsigned int& id, conf* current)
{
  return (current->s_4_2==2);
}
static void __a83(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_2 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_2 = 1;
    }
  __rv_min = __rv_max;

}

static int __g84(unsigned int& id, conf* current)
{
  return (current->s_4_2==3);
}
static void __a84(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_2 = 3;
    }
  __rv_min = __rv_max;

}

static int __g85(unsigned int& id, conf* current)
{
  return (current->s_4_3==0);
}
static void __a85(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_3 = 1;
    }
  __rv_min = __rv_max;

}

static int __g86(unsigned int& id, conf* current)
{
  return ((current->s_4_3==1)&&((current->s_3_3==3)||((current->s_5_3==3)||((current->s_4_2==3)||(current->s_4_4==3)))));
}
static void __a86(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_3 = 3;
    }
  __rv_min = __rv_max;

}

static int __g87(unsigned int& id, conf* current)
{
  return ((current->s_4_3==1)&&!(((current->s_3_3==3)||((current->s_5_3==3)||((current->s_4_2==3)||(current->s_4_4==3))))));
}
static void __a87(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_3 = 2;
    }
  __rv_min = __rv_max;

}

static int __g88(unsigned int& id, conf* current)
{
  return (current->s_4_3==2);
}
static void __a88(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_3 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_3 = 1;
    }
  __rv_min = __rv_max;

}

static int __g89(unsigned int& id, conf* current)
{
  return (current->s_4_3==3);
}
static void __a89(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_3 = 3;
    }
  __rv_min = __rv_max;

}

static int __g90(unsigned int& id, conf* current)
{
  return (current->s_4_4==0);
}
static void __a90(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_4 = 1;
    }
  __rv_min = __rv_max;

}

static int __g91(unsigned int& id, conf* current)
{
  return ((current->s_4_4==1)&&((current->s_3_4==3)||((current->s_5_4==3)||((current->s_4_3==3)||(current->s_4_5==3)))));
}
static void __a91(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_4 = 3;
    }
  __rv_min = __rv_max;

}

static int __g92(unsigned int& id, conf* current)
{
  return ((current->s_4_4==1)&&!(((current->s_3_4==3)||((current->s_5_4==3)||((current->s_4_3==3)||(current->s_4_5==3))))));
}
static void __a92(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_4 = 2;
    }
  __rv_min = __rv_max;

}

static int __g93(unsigned int& id, conf* current)
{
  return (current->s_4_4==2);
}
static void __a93(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_4 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_4 = 1;
    }
  __rv_min = __rv_max;

}

static int __g94(unsigned int& id, conf* current)
{
  return (current->s_4_4==3);
}
static void __a94(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_4 = 3;
    }
  __rv_min = __rv_max;

}

static int __g95(unsigned int& id, conf* current)
{
  return (current->s_4_5==0);
}
static void __a95(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_5 = 1;
    }
  __rv_min = __rv_max;

}

static int __g96(unsigned int& id, conf* current)
{
  return ((current->s_4_5==1)&&((current->s_3_5==3)||((current->s_5_5==3)||((current->s_4_4==3)||(current->s_4_6==3)))));
}
static void __a96(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_5 = 3;
    }
  __rv_min = __rv_max;

}

static int __g97(unsigned int& id, conf* current)
{
  return ((current->s_4_5==1)&&!(((current->s_3_5==3)||((current->s_5_5==3)||((current->s_4_4==3)||(current->s_4_6==3))))));
}
static void __a97(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_5 = 2;
    }
  __rv_min = __rv_max;

}

static int __g98(unsigned int& id, conf* current)
{
  return (current->s_4_5==2);
}
static void __a98(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_5 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_5 = 1;
    }
  __rv_min = __rv_max;

}

static int __g99(unsigned int& id, conf* current)
{
  return (current->s_4_5==3);
}
static void __a99(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_4_5 = 3;
    }
  __rv_min = __rv_max;

}

static int __g100(unsigned int& id, conf* current)
{
  return (current->s_5_1==0);
}
static void __a100(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_1 = 1;
    }
  __rv_min = __rv_max;

}

static int __g101(unsigned int& id, conf* current)
{
  return ((current->s_5_1==1)&&((current->s_4_1==3)||((current->s_6_1==3)||((current->s_5_0==3)||(current->s_5_2==3)))));
}
static void __a101(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_1 = 3;
    }
  __rv_min = __rv_max;

}

static int __g102(unsigned int& id, conf* current)
{
  return ((current->s_5_1==1)&&!(((current->s_4_1==3)||((current->s_6_1==3)||((current->s_5_0==3)||(current->s_5_2==3))))));
}
static void __a102(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_1 = 2;
    }
  __rv_min = __rv_max;

}

static int __g103(unsigned int& id, conf* current)
{
  return (current->s_5_1==2);
}
static void __a103(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_1 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_1 = 1;
    }
  __rv_min = __rv_max;

}

static int __g104(unsigned int& id, conf* current)
{
  return (current->s_5_1==3);
}
static void __a104(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_1 = 3;
    }
  __rv_min = __rv_max;

}

static int __g105(unsigned int& id, conf* current)
{
  return (current->s_5_2==0);
}
static void __a105(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_2 = 1;
    }
  __rv_min = __rv_max;

}

static int __g106(unsigned int& id, conf* current)
{
  return ((current->s_5_2==1)&&((current->s_4_2==3)||((current->s_6_2==3)||((current->s_5_1==3)||(current->s_5_3==3)))));
}
static void __a106(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_2 = 3;
    }
  __rv_min = __rv_max;

}

static int __g107(unsigned int& id, conf* current)
{
  return ((current->s_5_2==1)&&!(((current->s_4_2==3)||((current->s_6_2==3)||((current->s_5_1==3)||(current->s_5_3==3))))));
}
static void __a107(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_2 = 2;
    }
  __rv_min = __rv_max;

}

static int __g108(unsigned int& id, conf* current)
{
  return (current->s_5_2==2);
}
static void __a108(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_2 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_2 = 1;
    }
  __rv_min = __rv_max;

}

static int __g109(unsigned int& id, conf* current)
{
  return (current->s_5_2==3);
}
static void __a109(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_2 = 3;
    }
  __rv_min = __rv_max;

}

static int __g110(unsigned int& id, conf* current)
{
  return (current->s_5_3==0);
}
static void __a110(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_3 = 1;
    }
  __rv_min = __rv_max;

}

static int __g111(unsigned int& id, conf* current)
{
  return ((current->s_5_3==1)&&((current->s_4_3==3)||((current->s_6_3==3)||((current->s_5_2==3)||(current->s_5_4==3)))));
}
static void __a111(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_3 = 3;
    }
  __rv_min = __rv_max;

}

static int __g112(unsigned int& id, conf* current)
{
  return ((current->s_5_3==1)&&!(((current->s_4_3==3)||((current->s_6_3==3)||((current->s_5_2==3)||(current->s_5_4==3))))));
}
static void __a112(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_3 = 2;
    }
  __rv_min = __rv_max;

}

static int __g113(unsigned int& id, conf* current)
{
  return (current->s_5_3==2);
}
static void __a113(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_3 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_3 = 1;
    }
  __rv_min = __rv_max;

}

static int __g114(unsigned int& id, conf* current)
{
  return (current->s_5_3==3);
}
static void __a114(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_3 = 3;
    }
  __rv_min = __rv_max;

}

static int __g115(unsigned int& id, conf* current)
{
  return (current->s_5_4==0);
}
static void __a115(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_4 = 1;
    }
  __rv_min = __rv_max;

}

static int __g116(unsigned int& id, conf* current)
{
  return ((current->s_5_4==1)&&((current->s_4_4==3)||((current->s_6_4==3)||((current->s_5_3==3)||(current->s_5_5==3)))));
}
static void __a116(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_4 = 3;
    }
  __rv_min = __rv_max;

}

static int __g117(unsigned int& id, conf* current)
{
  return ((current->s_5_4==1)&&!(((current->s_4_4==3)||((current->s_6_4==3)||((current->s_5_3==3)||(current->s_5_5==3))))));
}
static void __a117(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_4 = 2;
    }
  __rv_min = __rv_max;

}

static int __g118(unsigned int& id, conf* current)
{
  return (current->s_5_4==2);
}
static void __a118(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_4 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_4 = 1;
    }
  __rv_min = __rv_max;

}

static int __g119(unsigned int& id, conf* current)
{
  return (current->s_5_4==3);
}
static void __a119(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_4 = 3;
    }
  __rv_min = __rv_max;

}

static int __g120(unsigned int& id, conf* current)
{
  return (current->s_5_5==0);
}
static void __a120(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_5 = 1;
    }
  __rv_min = __rv_max;

}

static int __g121(unsigned int& id, conf* current)
{
  return ((current->s_5_5==1)&&((current->s_4_5==3)||((current->s_6_5==3)||((current->s_5_4==3)||(current->s_5_6==3)))));
}
static void __a121(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_5 = 3;
    }
  __rv_min = __rv_max;

}

static int __g122(unsigned int& id, conf* current)
{
  return ((current->s_5_5==1)&&!(((current->s_4_5==3)||((current->s_6_5==3)||((current->s_5_4==3)||(current->s_5_6==3))))));
}
static void __a122(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_5 = 2;
    }
  __rv_min = __rv_max;

}

static int __g123(unsigned int& id, conf* current)
{
  return (current->s_5_5==2);
}
static void __a123(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_5 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_5 = 1;
    }
  __rv_min = __rv_max;

}

static int __g124(unsigned int& id, conf* current)
{
  return (current->s_5_5==3);
}
static void __a124(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->s_5_5 = 3;
    }
  __rv_min = __rv_max;

}

#define NBRULES 125
static struct rule rules[125] = {
  { __g0, __a0 },
  { __g1, __a1 },
  { __g2, __a2 },
  { __g3, __a3 },
  { __g4, __a4 },
  { __g5, __a5 },
  { __g6, __a6 },
  { __g7, __a7 },
  { __g8, __a8 },
  { __g9, __a9 },
  { __g10, __a10 },
  { __g11, __a11 },
  { __g12, __a12 },
  { __g13, __a13 },
  { __g14, __a14 },
  { __g15, __a15 },
  { __g16, __a16 },
  { __g17, __a17 },
  { __g18, __a18 },
  { __g19, __a19 },
  { __g20, __a20 },
  { __g21, __a21 },
  { __g22, __a22 },
  { __g23, __a23 },
  { __g24, __a24 },
  { __g25, __a25 },
  { __g26, __a26 },
  { __g27, __a27 },
  { __g28, __a28 },
  { __g29, __a29 },
  { __g30, __a30 },
  { __g31, __a31 },
  { __g32, __a32 },
  { __g33, __a33 },
  { __g34, __a34 },
  { __g35, __a35 },
  { __g36, __a36 },
  { __g37, __a37 },
  { __g38, __a38 },
  { __g39, __a39 },
  { __g40, __a40 },
  { __g41, __a41 },
  { __g42, __a42 },
  { __g43, __a43 },
  { __g44, __a44 },
  { __g45, __a45 },
  { __g46, __a46 },
  { __g47, __a47 },
  { __g48, __a48 },
  { __g49, __a49 },
  { __g50, __a50 },
  { __g51, __a51 },
  { __g52, __a52 },
  { __g53, __a53 },
  { __g54, __a54 },
  { __g55, __a55 },
  { __g56, __a56 },
  { __g57, __a57 },
  { __g58, __a58 },
  { __g59, __a59 },
  { __g60, __a60 },
  { __g61, __a61 },
  { __g62, __a62 },
  { __g63, __a63 },
  { __g64, __a64 },
  { __g65, __a65 },
  { __g66, __a66 },
  { __g67, __a67 },
  { __g68, __a68 },
  { __g69, __a69 },
  { __g70, __a70 },
  { __g71, __a71 },
  { __g72, __a72 },
  { __g73, __a73 },
  { __g74, __a74 },
  { __g75, __a75 },
  { __g76, __a76 },
  { __g77, __a77 },
  { __g78, __a78 },
  { __g79, __a79 },
  { __g80, __a80 },
  { __g81, __a81 },
  { __g82, __a82 },
  { __g83, __a83 },
  { __g84, __a84 },
  { __g85, __a85 },
  { __g86, __a86 },
  { __g87, __a87 },
  { __g88, __a88 },
  { __g89, __a89 },
  { __g90, __a90 },
  { __g91, __a91 },
  { __g92, __a92 },
  { __g93, __a93 },
  { __g94, __a94 },
  { __g95, __a95 },
  { __g96, __a96 },
  { __g97, __a97 },
  { __g98, __a98 },
  { __g99, __a99 },
  { __g100, __a100 },
  { __g101, __a101 },
  { __g102, __a102 },
  { __g103, __a103 },
  { __g104, __a104 },
  { __g105, __a105 },
  { __g106, __a106 },
  { __g107, __a107 },
  { __g108, __a108 },
  { __g109, __a109 },
  { __g110, __a110 },
  { __g111, __a111 },
  { __g112, __a112 },
  { __g113, __a113 },
  { __g114, __a114 },
  { __g115, __a115 },
  { __g116, __a116 },
  { __g117, __a117 },
  { __g118, __a118 },
  { __g119, __a119 },
  { __g120, __a120 },
  { __g121, __a121 },
  { __g122, __a122 },
  { __g123, __a123 },
  { __g124, __a124 }
};

typedef int (*tester_t)(const path *);

static int until(tester_t __left, tester_t __right, const path *__p, const path* stop_path)
{
  int __cond;

  if(__p == stop_path) return 0;

  __cond = __right(__p);
  if (__cond)
    return 1;
  __cond = __left(__p);
  if (!__cond)
    return 0;
  if(__p + 1 == stop_path)
    return 0;
  return until(__left, __right, __p + 1, stop_path);
}

static int bounded_until(tester_t __left, int __lower, int __upper, tester_t __right, const path *__p, const path* stop_path)
{
  int __cond;

  if(__p == stop_path) return 0;

  if( __lower <= 0 )
    {
      if( __upper > 0 )
	{
	  __cond = __right(__p);
	  if (__cond)
	    return 1;
	  __cond = __left(__p);
	  if (!__cond)
	    return 0;
	  if(__p + 1 == stop_path)
	    return 0;
	  return bounded_until(__left, 0, __upper-1, __right, __p + 1, stop_path);
	}
      return 0;
    }
  __cond = __left(__p);
  if( __cond )
    return bounded_until(__left, __lower-1, __upper-1, __right, __p + 1, stop_path);
  return 0;
}

static int next(tester_t __w, const path *__p, const path* stop_path)
{
  if(__p == stop_path) return 0;
  if(__p + 1 == stop_path) return 0;
  return __w(__p + 1);
}

static int until_helper_1(const path *__p)
{
  return 1;
}
static int until_helper_2(const path *__p)
{
  return ((__p->s_1_1==3)||(__p->s_1_2==3)||(__p->s_1_3==3)||(__p->s_1_4==3)||(__p->s_1_5==3)||(__p->s_2_1==3)||(__p->s_2_5==3)||(__p->s_3_1==3)||(__p->s_3_5==3)||(__p->s_4_1==3)||(__p->s_4_5==3)||(__p->s_5_1==3)||(__p->s_5_2==3)||(__p->s_5_3==3)||(__p->s_5_4==3)||(__p->s_5_5==3)||(0>1));
}
static int verify_path_0(const path *__p, const path* stop_path)
{
  return until(until_helper_1, until_helper_2, __p, stop_path);
}
#define NB_VERIF_GOAL 1
typedef int (*verifier_func_t)(const path *__p, const path* stop_path);
verifier_func_t VERIF_GOAL[] = {
  verify_path_0
};

#include <sys/time.h>
#include <time.h>

static void run(unsigned int& id, int nbtrue[NB_VERIF_GOAL], int nbfalse[NB_VERIF_GOAL], int path_len, int some_time)
{
  int p, r;
  struct rule totest[NBRULES];
  int nbtotest;
  time_t start, end;
  conf *current = NULL;
  path *first_path = NULL, *current_path = NULL, *stop_path = NULL;
  current = new_(conf);
  first_path = (path*)malloc((path_len + 1) * sizeof(path));

  memset(nbtrue, 0, sizeof(int)*NB_VERIF_GOAL);
  memset(nbfalse, 0, sizeof(int)*NB_VERIF_GOAL);
  time(&start);
  do {
	   current_path = first_path;
      init_state(current, current_path, first_path, path_len);
      for(p = 0; p < path_len; p++)
	{
	  memcpy(totest, rules, NBRULES * sizeof(struct rule));
	  nbtotest = NBRULES;
	  while( nbtotest > 0 )
	    {
	      r = get_random(id, 0, nbtotest-1);
	      if( totest[r].guard(id, current) )
		break;
	      memcpy(&totest[r], &totest[nbtotest-1], sizeof(struct rule));
	      nbtotest--;
	    }
	  if( nbtotest == 0 )
	    break;
	  totest[r].action(id, current);
     ++current_path;
	  append_state(current, current_path);
	}
      stop_path = ++current_path;
      for(p = 0; p < NB_VERIF_GOAL; p++)
	{
	  if( VERIF_GOAL[p](first_path, stop_path) )
	    nbtrue[p]++;
	  else
	    nbfalse[p]++;
	}
    time(&end);
  } while (end-start < some_time);
}

#include "endcode.h"

