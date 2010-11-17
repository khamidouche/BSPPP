#include <stdlib.h>
#include <string.h>
#include <math.h>

//static
 unsigned int get_random(unsigned int min, unsigned int max)
{
  max++;
   unsigned int seed;
  return min + (unsigned int)( (double)(max-min)*rand_r(&seed)/(RAND_MAX+(double)min));
}

//static 
double probability()
{
  double r = (double)((unsigned int)-2);
  double R = get_random(0, (unsigned int)-2);
  r = ((double)R) / r;
  return r;
}
/* constants and macros */
#define new_(a) (a*)calloc(1, sizeof(a))
#define MAX(a,b) (((a)<(b))?(b):(a))
#define MIN(a,b) (((a)<(b))?(a):(b))


/* configuration and path definition */
typedef struct conf {
  int p1;
  int p2;
  int p3;
  int p4;
  int p5;
  int p6;
  int p7;
  int p8;
  int p9;
  int p10;
} conf;
//static
 conf *current = NULL;

typedef struct trans_conf {
  int* p1;
  int* p2;
  int* p3;
  int* p4;
  int* p5;
  int* p6;
  int* p7;
  int* p8;
  int* p9;
  int* p10;
} trans_conf;

//static 
trans_conf trans_current;

//static 
trans_conf *p_trans_current = NULL;

void init_trans_conf(void)
{
  trans_current.p1 = &current->p1;
  trans_current.p2 = &current->p2;
  trans_current.p3 = &current->p3;
  trans_current.p4 = &current->p4;
  trans_current.p5 = &current->p5;
  trans_current.p6 = &current->p6;
  trans_current.p7 = &current->p7;
  trans_current.p8 = &current->p8;
  trans_current.p9 = &current->p9;
  trans_current.p10 = &current->p10;
}

typedef struct path {
  struct path *next;

  int p1;
  int p2;
  int p3;
  int p4;
  int p5;
  int p6;
  int p7;
  int p8;
  int p9;
  int p10;
} path;

//static 
path *first_path = NULL, *current_path = NULL;

//static 
void init_state()
{
  if(current == NULL) current = new_(conf);
  if(first_path == NULL) first_path = new_(path);
  current_path = first_path;

  current->p1 = 0;
  current->p2 = 0;
  current->p3 = 0;
  current->p4 = 0;
  current->p5 = 0;
  current->p6 = 0;
  current->p7 = 0;
  current->p8 = 0;
  current->p9 = 0;
  current->p10 = 0;
  first_path->p1 = current->p1;
  first_path->p2 = current->p2;
  first_path->p3 = current->p3;
  first_path->p4 = current->p4;
  first_path->p5 = current->p5;
  first_path->p6 = current->p6;
  first_path->p7 = current->p7;
  first_path->p8 = current->p8;
  first_path->p9 = current->p9;
  first_path->p10 = current->p10;
}

//static 
void append_state()
{
  path *n;
  if( current_path->next )
    n = current_path->next;
  else
    n = new_(path);
  n->p1 = current->p1;
  n->p2 = current->p2;
  n->p3 = current->p3;
  n->p4 = current->p4;
  n->p5 = current->p5;
  n->p6 = current->p6;
  n->p7 = current->p7;
  n->p8 = current->p8;
  n->p9 = current->p9;
  n->p10 = current->p10;
  current_path->next = n;
  current_path = n;
}

typedef void (*action_t)(void);
typedef int  (*guard_t)(void);

typedef struct rule_t {
  guard_t guard;
  action_t action;
} rule_t;

//static 
int __g_0_0(void)
{
  return (*p_trans_current->p1==0);
}
//static
 void __a_0_0(void)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability();
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      *p_trans_current->p1 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      *p_trans_current->p1 = 1;
    }
  __rv_min = __rv_max;

}

//static
 int __g_0_1(void)
{
  return (*p_trans_current->p1==1);
}
//static
 void __a_0_1(void)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability();
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      *p_trans_current->p1 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      *p_trans_current->p1 = 3;
    }
  __rv_min = __rv_max;

}

//static 
int __g_0_2(void)
{
  return ((*p_trans_current->p1==2)&&((*p_trans_current->p2>=0)&&(*p_trans_current->p2<=4))||(*p_trans_current->p2==6)||(*p_trans_current->p2==10));
}
//static
 void __a_0_2(void)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability();
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      *p_trans_current->p1 = 4;
    }
  __rv_min = __rv_max;

}

//static
 int __g_0_3(void)
{
  return ((*p_trans_current->p1==2)&&!(((*p_trans_current->p2>=0)&&(*p_trans_current->p2<=4))||(*p_trans_current->p2==6)||(*p_trans_current->p2==10)));
}
//static
 void __a_0_3(void)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability();
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      *p_trans_current->p1 = 2;
    }
  __rv_min = __rv_max;

}

//static
 int __g_0_4(void)
{
  return ((*p_trans_current->p1==3)&&((*p_trans_current->p10>=0)&&(*p_trans_current->p10<=3))||(*p_trans_current->p10==5)||(*p_trans_current->p10==7));
}
//static 
void __a_0_4(void)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability();
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      *p_trans_current->p1 = 5;
    }
  __rv_min = __rv_max;

}

//static
 int __g_0_5(void)
{
  return ((*p_trans_current->p1==3)&&!(((*p_trans_current->p10>=0)&&(*p_trans_current->p10<=3))||(*p_trans_current->p10==5)||(*p_trans_current->p10==7)));
}
//static
 void __a_0_5(void)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability();
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      *p_trans_current->p1 = 3;
    }
  __rv_min = __rv_max;

}

//static 
int __g_0_6(void)
{
  return ((*p_trans_current->p1==4)&&((*p_trans_current->p10>=0)&&(*p_trans_current->p10<=3))||(*p_trans_current->p10==5)||(*p_trans_current->p10==7));
}
//static
 void __a_0_6(void)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability();
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      *p_trans_current->p1 = 8;
    }
  __rv_min = __rv_max;

}

//static 
int __g_0_7(void)
{
  return ((*p_trans_current->p1==4)&&!(((*p_trans_current->p10>=0)&&(*p_trans_current->p10<=3))||(*p_trans_current->p10==5)||(*p_trans_current->p10==7)));
}
//static
 void __a_0_7(void)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability();
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      *p_trans_current->p1 = 6;
    }
  __rv_min = __rv_max;

}

//static
 int __g_0_8(void)
{
  return ((*p_trans_current->p1==5)&&((*p_trans_current->p2>=0)&&(*p_trans_current->p2<=4))||(*p_trans_current->p2==6)||(*p_trans_current->p2==10));
}
//static 
void __a_0_8(void)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability();
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      *p_trans_current->p1 = 8;
    }
  __rv_min = __rv_max;

}

//static
 int __g_0_9(void)
{
  return ((*p_trans_current->p1==5)&&!(((*p_trans_current->p2>=0)&&(*p_trans_current->p2<=4))||(*p_trans_current->p2==6)||(*p_trans_current->p2==10)));
}
//static
 void __a_0_9(void)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability();
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      *p_trans_current->p1 = 7;
    }
  __rv_min = __rv_max;

}

//static 
int __g_0_10(void)
{
  return (*p_trans_current->p1==6);
}
//static
 void __a_0_10(void)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability();
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      *p_trans_current->p1 = 1;
    }
  __rv_min = __rv_max;

}

//static
 int __g_0_11(void)
{
  return (*p_trans_current->p1==7);
}
//static
 void __a_0_11(void)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability();
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      *p_trans_current->p1 = 1;
    }
  __rv_min = __rv_max;

}

//static
 int __g_0_12(void)
{
  return (*p_trans_current->p1==8);
}
//static
 void __a_0_12(void)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability();
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      *p_trans_current->p1 = 9;
    }
  __rv_min = __rv_max;

}

//static
 int __g_0_13(void)
{
  return (*p_trans_current->p1==9);
}
//static
 void __a_0_13(void)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability();
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      *p_trans_current->p1 = 10;
    }
  __rv_min = __rv_max;

}

//static
 int __g_0_14(void)
{
  return (*p_trans_current->p1==10);
}
//static
 void __a_0_14(void)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability();
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      *p_trans_current->p1 = 0;
    }
  __rv_min = __rv_max;

}

//static
 const struct rule_t rules_0[] = {
  { __g_0_0, __a_0_0 },
  { __g_0_1, __a_0_1 },
  { __g_0_2, __a_0_2 },
  { __g_0_3, __a_0_3 },
  { __g_0_4, __a_0_4 },
  { __g_0_5, __a_0_5 },
  { __g_0_6, __a_0_6 },
  { __g_0_7, __a_0_7 },
  { __g_0_8, __a_0_8 },
  { __g_0_9, __a_0_9 },
  { __g_0_10, __a_0_10 },
  { __g_0_11, __a_0_11 },
  { __g_0_12, __a_0_12 },
  { __g_0_13, __a_0_13 },
  { __g_0_14, __a_0_14 },
};

//static
 struct rule_t currules_0_0[] = {
  { __g_0_0, __a_0_0 },
  { __g_0_1, __a_0_1 },
  { __g_0_2, __a_0_2 },
  { __g_0_3, __a_0_3 },
  { __g_0_4, __a_0_4 },
  { __g_0_5, __a_0_5 },
  { __g_0_6, __a_0_6 },
  { __g_0_7, __a_0_7 },
  { __g_0_8, __a_0_8 },
  { __g_0_9, __a_0_9 },
  { __g_0_10, __a_0_10 },
  { __g_0_11, __a_0_11 },
  { __g_0_12, __a_0_12 },
  { __g_0_13, __a_0_13 },
  { __g_0_14, __a_0_14 },
};

//static
 struct rule_t currules_0_1[] = {
  { __g_0_0, __a_0_0 },
  { __g_0_1, __a_0_1 },
  { __g_0_2, __a_0_2 },
  { __g_0_3, __a_0_3 },
  { __g_0_4, __a_0_4 },
  { __g_0_5, __a_0_5 },
  { __g_0_6, __a_0_6 },
  { __g_0_7, __a_0_7 },
  { __g_0_8, __a_0_8 },
  { __g_0_9, __a_0_9 },
  { __g_0_10, __a_0_10 },
  { __g_0_11, __a_0_11 },
  { __g_0_12, __a_0_12 },
  { __g_0_13, __a_0_13 },
  { __g_0_14, __a_0_14 },
};

//static
 struct rule_t currules_0_2[] = {
  { __g_0_0, __a_0_0 },
  { __g_0_1, __a_0_1 },
  { __g_0_2, __a_0_2 },
  { __g_0_3, __a_0_3 },
  { __g_0_4, __a_0_4 },
  { __g_0_5, __a_0_5 },
  { __g_0_6, __a_0_6 },
  { __g_0_7, __a_0_7 },
  { __g_0_8, __a_0_8 },
  { __g_0_9, __a_0_9 },
  { __g_0_10, __a_0_10 },
  { __g_0_11, __a_0_11 },
  { __g_0_12, __a_0_12 },
  { __g_0_13, __a_0_13 },
  { __g_0_14, __a_0_14 },
};

//static
 struct rule_t currules_0_3[] = {
  { __g_0_0, __a_0_0 },
  { __g_0_1, __a_0_1 },
  { __g_0_2, __a_0_2 },
  { __g_0_3, __a_0_3 },
  { __g_0_4, __a_0_4 },
  { __g_0_5, __a_0_5 },
  { __g_0_6, __a_0_6 },
  { __g_0_7, __a_0_7 },
  { __g_0_8, __a_0_8 },
  { __g_0_9, __a_0_9 },
  { __g_0_10, __a_0_10 },
  { __g_0_11, __a_0_11 },
  { __g_0_12, __a_0_12 },
  { __g_0_13, __a_0_13 },
  { __g_0_14, __a_0_14 },
};

//static 
struct rule_t currules_0_4[] = {
  { __g_0_0, __a_0_0 },
  { __g_0_1, __a_0_1 },
  { __g_0_2, __a_0_2 },
  { __g_0_3, __a_0_3 },
  { __g_0_4, __a_0_4 },
  { __g_0_5, __a_0_5 },
  { __g_0_6, __a_0_6 },
  { __g_0_7, __a_0_7 },
  { __g_0_8, __a_0_8 },
  { __g_0_9, __a_0_9 },
  { __g_0_10, __a_0_10 },
  { __g_0_11, __a_0_11 },
  { __g_0_12, __a_0_12 },
  { __g_0_13, __a_0_13 },
  { __g_0_14, __a_0_14 },
};

//static 
struct rule_t currules_0_5[] = {
  { __g_0_0, __a_0_0 },
  { __g_0_1, __a_0_1 },
  { __g_0_2, __a_0_2 },
  { __g_0_3, __a_0_3 },
  { __g_0_4, __a_0_4 },
  { __g_0_5, __a_0_5 },
  { __g_0_6, __a_0_6 },
  { __g_0_7, __a_0_7 },
  { __g_0_8, __a_0_8 },
  { __g_0_9, __a_0_9 },
  { __g_0_10, __a_0_10 },
  { __g_0_11, __a_0_11 },
  { __g_0_12, __a_0_12 },
  { __g_0_13, __a_0_13 },
  { __g_0_14, __a_0_14 },
};

//static 
struct rule_t currules_0_6[] = {
  { __g_0_0, __a_0_0 },
  { __g_0_1, __a_0_1 },
  { __g_0_2, __a_0_2 },
  { __g_0_3, __a_0_3 },
  { __g_0_4, __a_0_4 },
  { __g_0_5, __a_0_5 },
  { __g_0_6, __a_0_6 },
  { __g_0_7, __a_0_7 },
  { __g_0_8, __a_0_8 },
  { __g_0_9, __a_0_9 },
  { __g_0_10, __a_0_10 },
  { __g_0_11, __a_0_11 },
  { __g_0_12, __a_0_12 },
  { __g_0_13, __a_0_13 },
  { __g_0_14, __a_0_14 },
};

//static 
struct rule_t currules_0_7[] = {
  { __g_0_0, __a_0_0 },
  { __g_0_1, __a_0_1 },
  { __g_0_2, __a_0_2 },
  { __g_0_3, __a_0_3 },
  { __g_0_4, __a_0_4 },
  { __g_0_5, __a_0_5 },
  { __g_0_6, __a_0_6 },
  { __g_0_7, __a_0_7 },
  { __g_0_8, __a_0_8 },
  { __g_0_9, __a_0_9 },
  { __g_0_10, __a_0_10 },
  { __g_0_11, __a_0_11 },
  { __g_0_12, __a_0_12 },
  { __g_0_13, __a_0_13 },
  { __g_0_14, __a_0_14 },
};

//static 
struct rule_t currules_0_8[] = {
  { __g_0_0, __a_0_0 },
  { __g_0_1, __a_0_1 },
  { __g_0_2, __a_0_2 },
  { __g_0_3, __a_0_3 },
  { __g_0_4, __a_0_4 },
  { __g_0_5, __a_0_5 },
  { __g_0_6, __a_0_6 },
  { __g_0_7, __a_0_7 },
  { __g_0_8, __a_0_8 },
  { __g_0_9, __a_0_9 },
  { __g_0_10, __a_0_10 },
  { __g_0_11, __a_0_11 },
  { __g_0_12, __a_0_12 },
  { __g_0_13, __a_0_13 },
  { __g_0_14, __a_0_14 },
};

//static 
struct rule_t currules_0_9[] = {
  { __g_0_0, __a_0_0 },
  { __g_0_1, __a_0_1 },
  { __g_0_2, __a_0_2 },
  { __g_0_3, __a_0_3 },
  { __g_0_4, __a_0_4 },
  { __g_0_5, __a_0_5 },
  { __g_0_6, __a_0_6 },
  { __g_0_7, __a_0_7 },
  { __g_0_8, __a_0_8 },
  { __g_0_9, __a_0_9 },
  { __g_0_10, __a_0_10 },
  { __g_0_11, __a_0_11 },
  { __g_0_12, __a_0_12 },
  { __g_0_13, __a_0_13 },
  { __g_0_14, __a_0_14 },
};

//static 
const struct rule_t* rules[] = { rules_0 };

//static 
struct rule_t* currules[] = { currules_0_0, currules_0_1, currules_0_2, currules_0_3, currules_0_4, currules_0_5, currules_0_6, currules_0_7, currules_0_8, currules_0_9 };

//static 
const int nbrules[] = { 15 };
//static
 const int nbvirtualrules[] = { 150 };
//static
 const int nbmodules[] = { 10 };

#define NBRULES 15
#define NBVIRTUALRULES 150
#define NBMODULES 10
#define NBMODULETYPES 1

typedef void (*trans_func)(void);

//static
 void translation_0(void)
{
  trans_current.p1 = &current->p1;
  trans_current.p2 = &current->p2;
  trans_current.p10 = &current->p10;
}

//static
 void translation_0_0(void)
{
  trans_current.p1 = &current->p2;
  trans_current.p2 = &current->p3;
  trans_current.p10 = &current->p1;
}

//static 
void translation_0_1(void)
{
  trans_current.p1 = &current->p3;
  trans_current.p2 = &current->p4;
  trans_current.p10 = &current->p2;
}

//static 
void translation_0_2(void)
{
  trans_current.p1 = &current->p4;
  trans_current.p2 = &current->p5;
  trans_current.p10 = &current->p3;
}

//static 
void translation_0_3(void)
{
  trans_current.p1 = &current->p5;
  trans_current.p2 = &current->p6;
  trans_current.p10 = &current->p4;
}

//static 
void translation_0_4(void)
{
  trans_current.p1 = &current->p6;
  trans_current.p2 = &current->p7;
  trans_current.p10 = &current->p5;
}

//static
 void translation_0_5(void)
{
  trans_current.p1 = &current->p7;
  trans_current.p2 = &current->p8;
  trans_current.p10 = &current->p6;
}

//static
 void translation_0_6(void)
{
  trans_current.p1 = &current->p8;
  trans_current.p2 = &current->p9;
  trans_current.p10 = &current->p7;
}

//static
 void translation_0_7(void)
{
  trans_current.p1 = &current->p9;
  trans_current.p2 = &current->p10;
  trans_current.p10 = &current->p8;
}

//static
 void translation_0_8(void)
{
  trans_current.p1 = &current->p10;
  trans_current.p2 = &current->p1;
  trans_current.p10 = &current->p9;
}

//static
 const trans_func tf_0[] = { translation_0, translation_0_0, translation_0_1, translation_0_2, translation_0_3, translation_0_4, translation_0_5, translation_0_6, translation_0_7, translation_0_8 };

//static 
const trans_func* tf[] = { tf_0 };

//static
 void init_nbcurrules(int nbcurrules[NBMODULES])
{
  int acc, i, j;

  for (acc = 0, i = 0; i < NBMODULETYPES; acc += nbmodules[i++])
    for (j = 0; j < nbmodules[i]; j++)
      nbcurrules[acc + j] = nbrules[i];
}

//static
 void init_currules(void)
{
  int acc, i, j, k;

  for (acc = 0, i = 0; i < NBMODULETYPES; acc += nbmodules[i++])
    for (j = 0; j < nbmodules[i]; j++)
      for (k = 0; k < nbrules[i]; k++)
        memcpy(&currules[acc + j][k], &rules[i][k], sizeof(struct rule_t));
}

typedef int (*tester_t)(const path *);

//static 
int until(tester_t __left, tester_t __right, const path *__p)
{
  int __cond;

  if(!__p) return 0;

  __cond = __right(__p);
  if (__cond)
    return 1;
  __cond = __left(__p);
  if (!__cond)
    return 0;
  if(!__p->next)
    return 0;
  return until(__left, __right, __p->next);
}

//static 
int bounded_until(tester_t __left, int __lower, int __upper, tester_t __right, const path *__p)
{
  int __cond;

  if(!__p) return 0;

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
	  if(!__p->next)
	    return 0;
	  return bounded_until(__left, 0, __upper-1, __right, __p->next);
	}
      return 0;
    }
  __cond = __left(__p);
  if( __cond )
    return bounded_until(__left, __lower-1, __upper-1, __right, __p->next);
  return 0;
}

//static
 int next(tester_t __w, const path *__p)
{
  if(!__p) return 0;
  if(!__p->next) return 0;
  return __w(__p->next);
}

//static
 int until_helper_1(const path *__p)
{
  return 1;
}
//static
 int until_helper_2(const path *__p)
{
  return ((__p->p1>7)||(__p->p2>7)||(__p->p3>7)||(__p->p4>7)||(__p->p5>7)||(__p->p6>7)||(__p->p7>7)||(__p->p8>7)||(__p->p9>7)||(__p->p10>7));
}
//static
 int verify_path_0(const path *__p)
{
  return until(until_helper_1, until_helper_2, __p);
}
#define NB_VERIF_GOAL 1
typedef int (*verifier_func_t)(const path *__p);
verifier_func_t VERIF_GOAL[] = {
  verify_path_0
};

#include <sys/time.h>
#include <time.h>
#include <iostream>




//static 
void run(int nbtrue[NB_VERIF_GOAL], int nbfalse[NB_VERIF_GOAL], int path_len, int some_time)
{
  int p, r, acc, itype, irule, imodule;
  int nbtotest;
  time_t start, end;
  int nbcurvirtualrules[NBMODULETYPES];
  int nbcurrules[NBMODULES];

  p_trans_current = &trans_current;
  init_trans_conf();
  memset(nbtrue, 0, sizeof(int)*NB_VERIF_GOAL);
  memset(nbfalse, 0, sizeof(int)*NB_VERIF_GOAL);
  time(&start);
  //std::cout<<"yawwwwww ***   "<<&trans_current<<std::endl;
  do
  {
    init_state();
    for(p = 0; p < path_len; p++)
    {
      memcpy(nbcurvirtualrules, nbvirtualrules, NBMODULETYPES * sizeof(int));
      init_nbcurrules(nbcurrules);
      init_currules();
      nbtotest = NBVIRTUALRULES;
      while( nbtotest > 0 )
      {
        r = get_random(0, nbtotest - 1);

        for (itype = 0, acc = 0; itype < NBMODULETYPES; acc += nbcurvirtualrules[itype], itype++)
          if (r < nbcurvirtualrules[itype] + acc)
            break;
        for (imodule = 0, acc = 0; imodule < NBMODULES; acc += nbcurrules[imodule], imodule++)
          if (r < nbcurrules[imodule] + acc)
            break;
        irule = r - acc;

        tf[itype][0]();
        tf[itype][imodule]();
        if( currules[imodule][irule].guard() )
          break;

        memcpy(&currules[imodule][irule], &currules[imodule][nbcurrules[imodule] - 1], sizeof(struct rule_t));
        nbcurrules[imodule]--;
        nbcurvirtualrules[itype]--;
        nbtotest--;
      }
      if( nbtotest == 0 )
        break;
      currules[imodule][irule].action();
      append_state();
    }

    for(p = 0; p < NB_VERIF_GOAL; p++)
    {
      if( VERIF_GOAL[p](first_path) )
        nbtrue[p]++;
      else
        nbfalse[p]++;
    }

  
  // printf("rank === %d time = %f\n",bsp::pid(),t2-t1);
    time(&end);
  } while (end-start < some_time);
 
}

#include "endcode.h"
