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
  int p11;
  int p12;
  int p13;
  int p14;
  int p15;
  int p16;
  int p17;
  int p18;
  int p19;
  int p20;
  int p21;
  int p22;
  int p23;
  int p24;
  int p25;
  int p26;
  int p27;
  int p28;
  int p29;
  int p30;
  int p31;
  int p32;
  int p33;
  int p34;
  int p35;
  int p36;
  int p37;
  int p38;
  int p39;
  int p40;
  int p41;
  int p42;
  int p43;
  int p44;
  int p45;
  int p46;
  int p47;
  int p48;
  int p49;
  int p50;
} conf;

typedef struct path {

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
  int p11;
  int p12;
  int p13;
  int p14;
  int p15;
  int p16;
  int p17;
  int p18;
  int p19;
  int p20;
  int p21;
  int p22;
  int p23;
  int p24;
  int p25;
  int p26;
  int p27;
  int p28;
  int p29;
  int p30;
  int p31;
  int p32;
  int p33;
  int p34;
  int p35;
  int p36;
  int p37;
  int p38;
  int p39;
  int p40;
  int p41;
  int p42;
  int p43;
  int p44;
  int p45;
  int p46;
  int p47;
  int p48;
  int p49;
  int p50;
} path;

static void init_state(conf* current, path* current_path, path* first_path, int path_len)
{

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
  current->p11 = 0;
  current->p12 = 0;
  current->p13 = 0;
  current->p14 = 0;
  current->p15 = 0;
  current->p16 = 0;
  current->p17 = 0;
  current->p18 = 0;
  current->p19 = 0;
  current->p20 = 0;
  current->p21 = 0;
  current->p22 = 0;
  current->p23 = 0;
  current->p24 = 0;
  current->p25 = 0;
  current->p26 = 0;
  current->p27 = 0;
  current->p28 = 0;
  current->p29 = 0;
  current->p30 = 0;
  current->p31 = 0;
  current->p32 = 0;
  current->p33 = 0;
  current->p34 = 0;
  current->p35 = 0;
  current->p36 = 0;
  current->p37 = 0;
  current->p38 = 0;
  current->p39 = 0;
  current->p40 = 0;
  current->p41 = 0;
  current->p42 = 0;
  current->p43 = 0;
  current->p44 = 0;
  current->p45 = 0;
  current->p46 = 0;
  current->p47 = 0;
  current->p48 = 0;
  current->p49 = 0;
  current->p50 = 0;
  current_path->p1 = current->p1;
  current_path->p2 = current->p2;
  current_path->p3 = current->p3;
  current_path->p4 = current->p4;
  current_path->p5 = current->p5;
  current_path->p6 = current->p6;
  current_path->p7 = current->p7;
  current_path->p8 = current->p8;
  current_path->p9 = current->p9;
  current_path->p10 = current->p10;
  current_path->p11 = current->p11;
  current_path->p12 = current->p12;
  current_path->p13 = current->p13;
  current_path->p14 = current->p14;
  current_path->p15 = current->p15;
  current_path->p16 = current->p16;
  current_path->p17 = current->p17;
  current_path->p18 = current->p18;
  current_path->p19 = current->p19;
  current_path->p20 = current->p20;
  current_path->p21 = current->p21;
  current_path->p22 = current->p22;
  current_path->p23 = current->p23;
  current_path->p24 = current->p24;
  current_path->p25 = current->p25;
  current_path->p26 = current->p26;
  current_path->p27 = current->p27;
  current_path->p28 = current->p28;
  current_path->p29 = current->p29;
  current_path->p30 = current->p30;
  current_path->p31 = current->p31;
  current_path->p32 = current->p32;
  current_path->p33 = current->p33;
  current_path->p34 = current->p34;
  current_path->p35 = current->p35;
  current_path->p36 = current->p36;
  current_path->p37 = current->p37;
  current_path->p38 = current->p38;
  current_path->p39 = current->p39;
  current_path->p40 = current->p40;
  current_path->p41 = current->p41;
  current_path->p42 = current->p42;
  current_path->p43 = current->p43;
  current_path->p44 = current->p44;
  current_path->p45 = current->p45;
  current_path->p46 = current->p46;
  current_path->p47 = current->p47;
  current_path->p48 = current->p48;
  current_path->p49 = current->p49;
  current_path->p50 = current->p50;
}

static void append_state(conf* current, path* current_path)
{

  current_path->p1 = current->p1;
  current_path->p2 = current->p2;
  current_path->p3 = current->p3;
  current_path->p4 = current->p4;
  current_path->p5 = current->p5;
  current_path->p6 = current->p6;
  current_path->p7 = current->p7;
  current_path->p8 = current->p8;
  current_path->p9 = current->p9;
  current_path->p10 = current->p10;
  current_path->p11 = current->p11;
  current_path->p12 = current->p12;
  current_path->p13 = current->p13;
  current_path->p14 = current->p14;
  current_path->p15 = current->p15;
  current_path->p16 = current->p16;
  current_path->p17 = current->p17;
  current_path->p18 = current->p18;
  current_path->p19 = current->p19;
  current_path->p20 = current->p20;
  current_path->p21 = current->p21;
  current_path->p22 = current->p22;
  current_path->p23 = current->p23;
  current_path->p24 = current->p24;
  current_path->p25 = current->p25;
  current_path->p26 = current->p26;
  current_path->p27 = current->p27;
  current_path->p28 = current->p28;
  current_path->p29 = current->p29;
  current_path->p30 = current->p30;
  current_path->p31 = current->p31;
  current_path->p32 = current->p32;
  current_path->p33 = current->p33;
  current_path->p34 = current->p34;
  current_path->p35 = current->p35;
  current_path->p36 = current->p36;
  current_path->p37 = current->p37;
  current_path->p38 = current->p38;
  current_path->p39 = current->p39;
  current_path->p40 = current->p40;
  current_path->p41 = current->p41;
  current_path->p42 = current->p42;
  current_path->p43 = current->p43;
  current_path->p44 = current->p44;
  current_path->p45 = current->p45;
  current_path->p46 = current->p46;
  current_path->p47 = current->p47;
  current_path->p48 = current->p48;
  current_path->p49 = current->p49;
  current_path->p50 = current->p50;
}

typedef void (*action_t)(unsigned int& id, conf* current);
typedef int  (*guard_t)(unsigned int& id, conf* current);

struct rule {
  guard_t guard;
  action_t action;
};

static int __g0(unsigned int& id, conf* current)
{
  return (current->p1==0);
}
static void __a0(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p1 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p1 = 1;
    }
  __rv_min = __rv_max;

}

static int __g1(unsigned int& id, conf* current)
{
  return (current->p1==1);
}
static void __a1(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p1 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p1 = 3;
    }
  __rv_min = __rv_max;

}

static int __g2(unsigned int& id, conf* current)
{
  return ((current->p1==2)&&((current->p2>=0)&&(current->p2<=4))||(current->p2==6)||(current->p2==10));
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
      current->p1 = 4;
    }
  __rv_min = __rv_max;

}

static int __g3(unsigned int& id, conf* current)
{
  return ((current->p1==2)&&!(((current->p2>=0)&&(current->p2<=4))||(current->p2==6)||(current->p2==10)));
}
static void __a3(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p1 = 2;
    }
  __rv_min = __rv_max;

}

static int __g4(unsigned int& id, conf* current)
{
  return ((current->p1==3)&&((current->p50>=0)&&(current->p50<=3))||(current->p50==5)||(current->p50==7));
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
      current->p1 = 5;
    }
  __rv_min = __rv_max;

}

static int __g5(unsigned int& id, conf* current)
{
  return ((current->p1==3)&&!(((current->p50>=0)&&(current->p50<=3))||(current->p50==5)||(current->p50==7)));
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
      current->p1 = 3;
    }
  __rv_min = __rv_max;

}

static int __g6(unsigned int& id, conf* current)
{
  return ((current->p1==4)&&((current->p50>=0)&&(current->p50<=3))||(current->p50==5)||(current->p50==7));
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
      current->p1 = 8;
    }
  __rv_min = __rv_max;

}

static int __g7(unsigned int& id, conf* current)
{
  return ((current->p1==4)&&!(((current->p50>=0)&&(current->p50<=3))||(current->p50==5)||(current->p50==7)));
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
      current->p1 = 6;
    }
  __rv_min = __rv_max;

}

static int __g8(unsigned int& id, conf* current)
{
  return ((current->p1==5)&&((current->p2>=0)&&(current->p2<=4))||(current->p2==6)||(current->p2==10));
}
static void __a8(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p1 = 8;
    }
  __rv_min = __rv_max;

}

static int __g9(unsigned int& id, conf* current)
{
  return ((current->p1==5)&&!(((current->p2>=0)&&(current->p2<=4))||(current->p2==6)||(current->p2==10)));
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
      current->p1 = 7;
    }
  __rv_min = __rv_max;

}

static int __g10(unsigned int& id, conf* current)
{
  return (current->p1==6);
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
      current->p1 = 1;
    }
  __rv_min = __rv_max;

}

static int __g11(unsigned int& id, conf* current)
{
  return (current->p1==7);
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
      current->p1 = 1;
    }
  __rv_min = __rv_max;

}

static int __g12(unsigned int& id, conf* current)
{
  return (current->p1==8);
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
      current->p1 = 9;
    }
  __rv_min = __rv_max;

}

static int __g13(unsigned int& id, conf* current)
{
  return (current->p1==9);
}
static void __a13(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p1 = 10;
    }
  __rv_min = __rv_max;

}

static int __g14(unsigned int& id, conf* current)
{
  return (current->p1==10);
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
      current->p1 = 0;
    }
  __rv_min = __rv_max;

}

static int __g15(unsigned int& id, conf* current)
{
  return (current->p2==0);
}
static void __a15(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p2 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p2 = 1;
    }
  __rv_min = __rv_max;

}

static int __g16(unsigned int& id, conf* current)
{
  return (current->p2==1);
}
static void __a16(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p2 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p2 = 3;
    }
  __rv_min = __rv_max;

}

static int __g17(unsigned int& id, conf* current)
{
  return ((current->p2==2)&&((current->p3>=0)&&(current->p3<=4))||(current->p3==6)||(current->p3==10));
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
      current->p2 = 4;
    }
  __rv_min = __rv_max;

}

static int __g18(unsigned int& id, conf* current)
{
  return ((current->p2==2)&&!(((current->p3>=0)&&(current->p3<=4))||(current->p3==6)||(current->p3==10)));
}
static void __a18(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p2 = 2;
    }
  __rv_min = __rv_max;

}

static int __g19(unsigned int& id, conf* current)
{
  return ((current->p2==3)&&((current->p1>=0)&&(current->p1<=3))||(current->p1==5)||(current->p1==7));
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
      current->p2 = 5;
    }
  __rv_min = __rv_max;

}

static int __g20(unsigned int& id, conf* current)
{
  return ((current->p2==3)&&!(((current->p1>=0)&&(current->p1<=3))||(current->p1==5)||(current->p1==7)));
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
      current->p2 = 3;
    }
  __rv_min = __rv_max;

}

static int __g21(unsigned int& id, conf* current)
{
  return ((current->p2==4)&&((current->p1>=0)&&(current->p1<=3))||(current->p1==5)||(current->p1==7));
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
      current->p2 = 8;
    }
  __rv_min = __rv_max;

}

static int __g22(unsigned int& id, conf* current)
{
  return ((current->p2==4)&&!(((current->p1>=0)&&(current->p1<=3))||(current->p1==5)||(current->p1==7)));
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
      current->p2 = 6;
    }
  __rv_min = __rv_max;

}

static int __g23(unsigned int& id, conf* current)
{
  return ((current->p2==5)&&((current->p3>=0)&&(current->p3<=4))||(current->p3==6)||(current->p3==10));
}
static void __a23(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p2 = 8;
    }
  __rv_min = __rv_max;

}

static int __g24(unsigned int& id, conf* current)
{
  return ((current->p2==5)&&!(((current->p3>=0)&&(current->p3<=4))||(current->p3==6)||(current->p3==10)));
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
      current->p2 = 7;
    }
  __rv_min = __rv_max;

}

static int __g25(unsigned int& id, conf* current)
{
  return (current->p2==6);
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
      current->p2 = 1;
    }
  __rv_min = __rv_max;

}

static int __g26(unsigned int& id, conf* current)
{
  return (current->p2==7);
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
      current->p2 = 1;
    }
  __rv_min = __rv_max;

}

static int __g27(unsigned int& id, conf* current)
{
  return (current->p2==8);
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
      current->p2 = 9;
    }
  __rv_min = __rv_max;

}

static int __g28(unsigned int& id, conf* current)
{
  return (current->p2==9);
}
static void __a28(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p2 = 10;
    }
  __rv_min = __rv_max;

}

static int __g29(unsigned int& id, conf* current)
{
  return (current->p2==10);
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
      current->p2 = 0;
    }
  __rv_min = __rv_max;

}

static int __g30(unsigned int& id, conf* current)
{
  return (current->p3==0);
}
static void __a30(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p3 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p3 = 1;
    }
  __rv_min = __rv_max;

}

static int __g31(unsigned int& id, conf* current)
{
  return (current->p3==1);
}
static void __a31(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p3 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p3 = 3;
    }
  __rv_min = __rv_max;

}

static int __g32(unsigned int& id, conf* current)
{
  return ((current->p3==2)&&((current->p4>=0)&&(current->p4<=4))||(current->p4==6)||(current->p4==10));
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
      current->p3 = 4;
    }
  __rv_min = __rv_max;

}

static int __g33(unsigned int& id, conf* current)
{
  return ((current->p3==2)&&!(((current->p4>=0)&&(current->p4<=4))||(current->p4==6)||(current->p4==10)));
}
static void __a33(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p3 = 2;
    }
  __rv_min = __rv_max;

}

static int __g34(unsigned int& id, conf* current)
{
  return ((current->p3==3)&&((current->p2>=0)&&(current->p2<=3))||(current->p2==5)||(current->p2==7));
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
      current->p3 = 5;
    }
  __rv_min = __rv_max;

}

static int __g35(unsigned int& id, conf* current)
{
  return ((current->p3==3)&&!(((current->p2>=0)&&(current->p2<=3))||(current->p2==5)||(current->p2==7)));
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
      current->p3 = 3;
    }
  __rv_min = __rv_max;

}

static int __g36(unsigned int& id, conf* current)
{
  return ((current->p3==4)&&((current->p2>=0)&&(current->p2<=3))||(current->p2==5)||(current->p2==7));
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
      current->p3 = 8;
    }
  __rv_min = __rv_max;

}

static int __g37(unsigned int& id, conf* current)
{
  return ((current->p3==4)&&!(((current->p2>=0)&&(current->p2<=3))||(current->p2==5)||(current->p2==7)));
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
      current->p3 = 6;
    }
  __rv_min = __rv_max;

}

static int __g38(unsigned int& id, conf* current)
{
  return ((current->p3==5)&&((current->p4>=0)&&(current->p4<=4))||(current->p4==6)||(current->p4==10));
}
static void __a38(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p3 = 8;
    }
  __rv_min = __rv_max;

}

static int __g39(unsigned int& id, conf* current)
{
  return ((current->p3==5)&&!(((current->p4>=0)&&(current->p4<=4))||(current->p4==6)||(current->p4==10)));
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
      current->p3 = 7;
    }
  __rv_min = __rv_max;

}

static int __g40(unsigned int& id, conf* current)
{
  return (current->p3==6);
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
      current->p3 = 1;
    }
  __rv_min = __rv_max;

}

static int __g41(unsigned int& id, conf* current)
{
  return (current->p3==7);
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
      current->p3 = 1;
    }
  __rv_min = __rv_max;

}

static int __g42(unsigned int& id, conf* current)
{
  return (current->p3==8);
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
      current->p3 = 9;
    }
  __rv_min = __rv_max;

}

static int __g43(unsigned int& id, conf* current)
{
  return (current->p3==9);
}
static void __a43(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p3 = 10;
    }
  __rv_min = __rv_max;

}

static int __g44(unsigned int& id, conf* current)
{
  return (current->p3==10);
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
      current->p3 = 0;
    }
  __rv_min = __rv_max;

}

static int __g45(unsigned int& id, conf* current)
{
  return (current->p4==0);
}
static void __a45(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p4 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p4 = 1;
    }
  __rv_min = __rv_max;

}

static int __g46(unsigned int& id, conf* current)
{
  return (current->p4==1);
}
static void __a46(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p4 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p4 = 3;
    }
  __rv_min = __rv_max;

}

static int __g47(unsigned int& id, conf* current)
{
  return ((current->p4==2)&&((current->p5>=0)&&(current->p5<=4))||(current->p5==6)||(current->p5==10));
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
      current->p4 = 4;
    }
  __rv_min = __rv_max;

}

static int __g48(unsigned int& id, conf* current)
{
  return ((current->p4==2)&&!(((current->p5>=0)&&(current->p5<=4))||(current->p5==6)||(current->p5==10)));
}
static void __a48(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p4 = 2;
    }
  __rv_min = __rv_max;

}

static int __g49(unsigned int& id, conf* current)
{
  return ((current->p4==3)&&((current->p3>=0)&&(current->p3<=3))||(current->p3==5)||(current->p3==7));
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
      current->p4 = 5;
    }
  __rv_min = __rv_max;

}

static int __g50(unsigned int& id, conf* current)
{
  return ((current->p4==3)&&!(((current->p3>=0)&&(current->p3<=3))||(current->p3==5)||(current->p3==7)));
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
      current->p4 = 3;
    }
  __rv_min = __rv_max;

}

static int __g51(unsigned int& id, conf* current)
{
  return ((current->p4==4)&&((current->p3>=0)&&(current->p3<=3))||(current->p3==5)||(current->p3==7));
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
      current->p4 = 8;
    }
  __rv_min = __rv_max;

}

static int __g52(unsigned int& id, conf* current)
{
  return ((current->p4==4)&&!(((current->p3>=0)&&(current->p3<=3))||(current->p3==5)||(current->p3==7)));
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
      current->p4 = 6;
    }
  __rv_min = __rv_max;

}

static int __g53(unsigned int& id, conf* current)
{
  return ((current->p4==5)&&((current->p5>=0)&&(current->p5<=4))||(current->p5==6)||(current->p5==10));
}
static void __a53(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p4 = 8;
    }
  __rv_min = __rv_max;

}

static int __g54(unsigned int& id, conf* current)
{
  return ((current->p4==5)&&!(((current->p5>=0)&&(current->p5<=4))||(current->p5==6)||(current->p5==10)));
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
      current->p4 = 7;
    }
  __rv_min = __rv_max;

}

static int __g55(unsigned int& id, conf* current)
{
  return (current->p4==6);
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
      current->p4 = 1;
    }
  __rv_min = __rv_max;

}

static int __g56(unsigned int& id, conf* current)
{
  return (current->p4==7);
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
      current->p4 = 1;
    }
  __rv_min = __rv_max;

}

static int __g57(unsigned int& id, conf* current)
{
  return (current->p4==8);
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
      current->p4 = 9;
    }
  __rv_min = __rv_max;

}

static int __g58(unsigned int& id, conf* current)
{
  return (current->p4==9);
}
static void __a58(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p4 = 10;
    }
  __rv_min = __rv_max;

}

static int __g59(unsigned int& id, conf* current)
{
  return (current->p4==10);
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
      current->p4 = 0;
    }
  __rv_min = __rv_max;

}

static int __g60(unsigned int& id, conf* current)
{
  return (current->p5==0);
}
static void __a60(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p5 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p5 = 1;
    }
  __rv_min = __rv_max;

}

static int __g61(unsigned int& id, conf* current)
{
  return (current->p5==1);
}
static void __a61(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p5 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p5 = 3;
    }
  __rv_min = __rv_max;

}

static int __g62(unsigned int& id, conf* current)
{
  return ((current->p5==2)&&((current->p6>=0)&&(current->p6<=4))||(current->p6==6)||(current->p6==10));
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
      current->p5 = 4;
    }
  __rv_min = __rv_max;

}

static int __g63(unsigned int& id, conf* current)
{
  return ((current->p5==2)&&!(((current->p6>=0)&&(current->p6<=4))||(current->p6==6)||(current->p6==10)));
}
static void __a63(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p5 = 2;
    }
  __rv_min = __rv_max;

}

static int __g64(unsigned int& id, conf* current)
{
  return ((current->p5==3)&&((current->p4>=0)&&(current->p4<=3))||(current->p4==5)||(current->p4==7));
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
      current->p5 = 5;
    }
  __rv_min = __rv_max;

}

static int __g65(unsigned int& id, conf* current)
{
  return ((current->p5==3)&&!(((current->p4>=0)&&(current->p4<=3))||(current->p4==5)||(current->p4==7)));
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
      current->p5 = 3;
    }
  __rv_min = __rv_max;

}

static int __g66(unsigned int& id, conf* current)
{
  return ((current->p5==4)&&((current->p4>=0)&&(current->p4<=3))||(current->p4==5)||(current->p4==7));
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
      current->p5 = 8;
    }
  __rv_min = __rv_max;

}

static int __g67(unsigned int& id, conf* current)
{
  return ((current->p5==4)&&!(((current->p4>=0)&&(current->p4<=3))||(current->p4==5)||(current->p4==7)));
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
      current->p5 = 6;
    }
  __rv_min = __rv_max;

}

static int __g68(unsigned int& id, conf* current)
{
  return ((current->p5==5)&&((current->p6>=0)&&(current->p6<=4))||(current->p6==6)||(current->p6==10));
}
static void __a68(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p5 = 8;
    }
  __rv_min = __rv_max;

}

static int __g69(unsigned int& id, conf* current)
{
  return ((current->p5==5)&&!(((current->p6>=0)&&(current->p6<=4))||(current->p6==6)||(current->p6==10)));
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
      current->p5 = 7;
    }
  __rv_min = __rv_max;

}

static int __g70(unsigned int& id, conf* current)
{
  return (current->p5==6);
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
      current->p5 = 1;
    }
  __rv_min = __rv_max;

}

static int __g71(unsigned int& id, conf* current)
{
  return (current->p5==7);
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
      current->p5 = 1;
    }
  __rv_min = __rv_max;

}

static int __g72(unsigned int& id, conf* current)
{
  return (current->p5==8);
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
      current->p5 = 9;
    }
  __rv_min = __rv_max;

}

static int __g73(unsigned int& id, conf* current)
{
  return (current->p5==9);
}
static void __a73(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p5 = 10;
    }
  __rv_min = __rv_max;

}

static int __g74(unsigned int& id, conf* current)
{
  return (current->p5==10);
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
      current->p5 = 0;
    }
  __rv_min = __rv_max;

}

static int __g75(unsigned int& id, conf* current)
{
  return (current->p6==0);
}
static void __a75(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p6 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p6 = 1;
    }
  __rv_min = __rv_max;

}

static int __g76(unsigned int& id, conf* current)
{
  return (current->p6==1);
}
static void __a76(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p6 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p6 = 3;
    }
  __rv_min = __rv_max;

}

static int __g77(unsigned int& id, conf* current)
{
  return ((current->p6==2)&&((current->p7>=0)&&(current->p7<=4))||(current->p7==6)||(current->p7==10));
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
      current->p6 = 4;
    }
  __rv_min = __rv_max;

}

static int __g78(unsigned int& id, conf* current)
{
  return ((current->p6==2)&&!(((current->p7>=0)&&(current->p7<=4))||(current->p7==6)||(current->p7==10)));
}
static void __a78(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p6 = 2;
    }
  __rv_min = __rv_max;

}

static int __g79(unsigned int& id, conf* current)
{
  return ((current->p6==3)&&((current->p5>=0)&&(current->p5<=3))||(current->p5==5)||(current->p5==7));
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
      current->p6 = 5;
    }
  __rv_min = __rv_max;

}

static int __g80(unsigned int& id, conf* current)
{
  return ((current->p6==3)&&!(((current->p5>=0)&&(current->p5<=3))||(current->p5==5)||(current->p5==7)));
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
      current->p6 = 3;
    }
  __rv_min = __rv_max;

}

static int __g81(unsigned int& id, conf* current)
{
  return ((current->p6==4)&&((current->p5>=0)&&(current->p5<=3))||(current->p5==5)||(current->p5==7));
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
      current->p6 = 8;
    }
  __rv_min = __rv_max;

}

static int __g82(unsigned int& id, conf* current)
{
  return ((current->p6==4)&&!(((current->p5>=0)&&(current->p5<=3))||(current->p5==5)||(current->p5==7)));
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
      current->p6 = 6;
    }
  __rv_min = __rv_max;

}

static int __g83(unsigned int& id, conf* current)
{
  return ((current->p6==5)&&((current->p7>=0)&&(current->p7<=4))||(current->p7==6)||(current->p7==10));
}
static void __a83(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p6 = 8;
    }
  __rv_min = __rv_max;

}

static int __g84(unsigned int& id, conf* current)
{
  return ((current->p6==5)&&!(((current->p7>=0)&&(current->p7<=4))||(current->p7==6)||(current->p7==10)));
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
      current->p6 = 7;
    }
  __rv_min = __rv_max;

}

static int __g85(unsigned int& id, conf* current)
{
  return (current->p6==6);
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
      current->p6 = 1;
    }
  __rv_min = __rv_max;

}

static int __g86(unsigned int& id, conf* current)
{
  return (current->p6==7);
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
      current->p6 = 1;
    }
  __rv_min = __rv_max;

}

static int __g87(unsigned int& id, conf* current)
{
  return (current->p6==8);
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
      current->p6 = 9;
    }
  __rv_min = __rv_max;

}

static int __g88(unsigned int& id, conf* current)
{
  return (current->p6==9);
}
static void __a88(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p6 = 10;
    }
  __rv_min = __rv_max;

}

static int __g89(unsigned int& id, conf* current)
{
  return (current->p6==10);
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
      current->p6 = 0;
    }
  __rv_min = __rv_max;

}

static int __g90(unsigned int& id, conf* current)
{
  return (current->p7==0);
}
static void __a90(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p7 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p7 = 1;
    }
  __rv_min = __rv_max;

}

static int __g91(unsigned int& id, conf* current)
{
  return (current->p7==1);
}
static void __a91(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p7 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p7 = 3;
    }
  __rv_min = __rv_max;

}

static int __g92(unsigned int& id, conf* current)
{
  return ((current->p7==2)&&((current->p8>=0)&&(current->p8<=4))||(current->p8==6)||(current->p8==10));
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
      current->p7 = 4;
    }
  __rv_min = __rv_max;

}

static int __g93(unsigned int& id, conf* current)
{
  return ((current->p7==2)&&!(((current->p8>=0)&&(current->p8<=4))||(current->p8==6)||(current->p8==10)));
}
static void __a93(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p7 = 2;
    }
  __rv_min = __rv_max;

}

static int __g94(unsigned int& id, conf* current)
{
  return ((current->p7==3)&&((current->p6>=0)&&(current->p6<=3))||(current->p6==5)||(current->p6==7));
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
      current->p7 = 5;
    }
  __rv_min = __rv_max;

}

static int __g95(unsigned int& id, conf* current)
{
  return ((current->p7==3)&&!(((current->p6>=0)&&(current->p6<=3))||(current->p6==5)||(current->p6==7)));
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
      current->p7 = 3;
    }
  __rv_min = __rv_max;

}

static int __g96(unsigned int& id, conf* current)
{
  return ((current->p7==4)&&((current->p6>=0)&&(current->p6<=3))||(current->p6==5)||(current->p6==7));
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
      current->p7 = 8;
    }
  __rv_min = __rv_max;

}

static int __g97(unsigned int& id, conf* current)
{
  return ((current->p7==4)&&!(((current->p6>=0)&&(current->p6<=3))||(current->p6==5)||(current->p6==7)));
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
      current->p7 = 6;
    }
  __rv_min = __rv_max;

}

static int __g98(unsigned int& id, conf* current)
{
  return ((current->p7==5)&&((current->p8>=0)&&(current->p8<=4))||(current->p8==6)||(current->p8==10));
}
static void __a98(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p7 = 8;
    }
  __rv_min = __rv_max;

}

static int __g99(unsigned int& id, conf* current)
{
  return ((current->p7==5)&&!(((current->p8>=0)&&(current->p8<=4))||(current->p8==6)||(current->p8==10)));
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
      current->p7 = 7;
    }
  __rv_min = __rv_max;

}

static int __g100(unsigned int& id, conf* current)
{
  return (current->p7==6);
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
      current->p7 = 1;
    }
  __rv_min = __rv_max;

}

static int __g101(unsigned int& id, conf* current)
{
  return (current->p7==7);
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
      current->p7 = 1;
    }
  __rv_min = __rv_max;

}

static int __g102(unsigned int& id, conf* current)
{
  return (current->p7==8);
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
      current->p7 = 9;
    }
  __rv_min = __rv_max;

}

static int __g103(unsigned int& id, conf* current)
{
  return (current->p7==9);
}
static void __a103(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p7 = 10;
    }
  __rv_min = __rv_max;

}

static int __g104(unsigned int& id, conf* current)
{
  return (current->p7==10);
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
      current->p7 = 0;
    }
  __rv_min = __rv_max;

}

static int __g105(unsigned int& id, conf* current)
{
  return (current->p8==0);
}
static void __a105(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p8 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p8 = 1;
    }
  __rv_min = __rv_max;

}

static int __g106(unsigned int& id, conf* current)
{
  return (current->p8==1);
}
static void __a106(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p8 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p8 = 3;
    }
  __rv_min = __rv_max;

}

static int __g107(unsigned int& id, conf* current)
{
  return ((current->p8==2)&&((current->p9>=0)&&(current->p9<=4))||(current->p9==6)||(current->p9==10));
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
      current->p8 = 4;
    }
  __rv_min = __rv_max;

}

static int __g108(unsigned int& id, conf* current)
{
  return ((current->p8==2)&&!(((current->p9>=0)&&(current->p9<=4))||(current->p9==6)||(current->p9==10)));
}
static void __a108(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p8 = 2;
    }
  __rv_min = __rv_max;

}

static int __g109(unsigned int& id, conf* current)
{
  return ((current->p8==3)&&((current->p7>=0)&&(current->p7<=3))||(current->p7==5)||(current->p7==7));
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
      current->p8 = 5;
    }
  __rv_min = __rv_max;

}

static int __g110(unsigned int& id, conf* current)
{
  return ((current->p8==3)&&!(((current->p7>=0)&&(current->p7<=3))||(current->p7==5)||(current->p7==7)));
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
      current->p8 = 3;
    }
  __rv_min = __rv_max;

}

static int __g111(unsigned int& id, conf* current)
{
  return ((current->p8==4)&&((current->p7>=0)&&(current->p7<=3))||(current->p7==5)||(current->p7==7));
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
      current->p8 = 8;
    }
  __rv_min = __rv_max;

}

static int __g112(unsigned int& id, conf* current)
{
  return ((current->p8==4)&&!(((current->p7>=0)&&(current->p7<=3))||(current->p7==5)||(current->p7==7)));
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
      current->p8 = 6;
    }
  __rv_min = __rv_max;

}

static int __g113(unsigned int& id, conf* current)
{
  return ((current->p8==5)&&((current->p9>=0)&&(current->p9<=4))||(current->p9==6)||(current->p9==10));
}
static void __a113(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p8 = 8;
    }
  __rv_min = __rv_max;

}

static int __g114(unsigned int& id, conf* current)
{
  return ((current->p8==5)&&!(((current->p9>=0)&&(current->p9<=4))||(current->p9==6)||(current->p9==10)));
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
      current->p8 = 7;
    }
  __rv_min = __rv_max;

}

static int __g115(unsigned int& id, conf* current)
{
  return (current->p8==6);
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
      current->p8 = 1;
    }
  __rv_min = __rv_max;

}

static int __g116(unsigned int& id, conf* current)
{
  return (current->p8==7);
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
      current->p8 = 1;
    }
  __rv_min = __rv_max;

}

static int __g117(unsigned int& id, conf* current)
{
  return (current->p8==8);
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
      current->p8 = 9;
    }
  __rv_min = __rv_max;

}

static int __g118(unsigned int& id, conf* current)
{
  return (current->p8==9);
}
static void __a118(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p8 = 10;
    }
  __rv_min = __rv_max;

}

static int __g119(unsigned int& id, conf* current)
{
  return (current->p8==10);
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
      current->p8 = 0;
    }
  __rv_min = __rv_max;

}

static int __g120(unsigned int& id, conf* current)
{
  return (current->p9==0);
}
static void __a120(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p9 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p9 = 1;
    }
  __rv_min = __rv_max;

}

static int __g121(unsigned int& id, conf* current)
{
  return (current->p9==1);
}
static void __a121(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p9 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p9 = 3;
    }
  __rv_min = __rv_max;

}

static int __g122(unsigned int& id, conf* current)
{
  return ((current->p9==2)&&((current->p10>=0)&&(current->p10<=4))||(current->p10==6)||(current->p10==10));
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
      current->p9 = 4;
    }
  __rv_min = __rv_max;

}

static int __g123(unsigned int& id, conf* current)
{
  return ((current->p9==2)&&!(((current->p10>=0)&&(current->p10<=4))||(current->p10==6)||(current->p10==10)));
}
static void __a123(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p9 = 2;
    }
  __rv_min = __rv_max;

}

static int __g124(unsigned int& id, conf* current)
{
  return ((current->p9==3)&&((current->p8>=0)&&(current->p8<=3))||(current->p8==5)||(current->p8==7));
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
      current->p9 = 5;
    }
  __rv_min = __rv_max;

}

static int __g125(unsigned int& id, conf* current)
{
  return ((current->p9==3)&&!(((current->p8>=0)&&(current->p8<=3))||(current->p8==5)||(current->p8==7)));
}
static void __a125(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p9 = 3;
    }
  __rv_min = __rv_max;

}

static int __g126(unsigned int& id, conf* current)
{
  return ((current->p9==4)&&((current->p8>=0)&&(current->p8<=3))||(current->p8==5)||(current->p8==7));
}
static void __a126(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p9 = 8;
    }
  __rv_min = __rv_max;

}

static int __g127(unsigned int& id, conf* current)
{
  return ((current->p9==4)&&!(((current->p8>=0)&&(current->p8<=3))||(current->p8==5)||(current->p8==7)));
}
static void __a127(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p9 = 6;
    }
  __rv_min = __rv_max;

}

static int __g128(unsigned int& id, conf* current)
{
  return ((current->p9==5)&&((current->p10>=0)&&(current->p10<=4))||(current->p10==6)||(current->p10==10));
}
static void __a128(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p9 = 8;
    }
  __rv_min = __rv_max;

}

static int __g129(unsigned int& id, conf* current)
{
  return ((current->p9==5)&&!(((current->p10>=0)&&(current->p10<=4))||(current->p10==6)||(current->p10==10)));
}
static void __a129(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p9 = 7;
    }
  __rv_min = __rv_max;

}

static int __g130(unsigned int& id, conf* current)
{
  return (current->p9==6);
}
static void __a130(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p9 = 1;
    }
  __rv_min = __rv_max;

}

static int __g131(unsigned int& id, conf* current)
{
  return (current->p9==7);
}
static void __a131(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p9 = 1;
    }
  __rv_min = __rv_max;

}

static int __g132(unsigned int& id, conf* current)
{
  return (current->p9==8);
}
static void __a132(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p9 = 9;
    }
  __rv_min = __rv_max;

}

static int __g133(unsigned int& id, conf* current)
{
  return (current->p9==9);
}
static void __a133(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p9 = 10;
    }
  __rv_min = __rv_max;

}

static int __g134(unsigned int& id, conf* current)
{
  return (current->p9==10);
}
static void __a134(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p9 = 0;
    }
  __rv_min = __rv_max;

}

static int __g135(unsigned int& id, conf* current)
{
  return (current->p10==0);
}
static void __a135(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p10 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p10 = 1;
    }
  __rv_min = __rv_max;

}

static int __g136(unsigned int& id, conf* current)
{
  return (current->p10==1);
}
static void __a136(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p10 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p10 = 3;
    }
  __rv_min = __rv_max;

}

static int __g137(unsigned int& id, conf* current)
{
  return ((current->p10==2)&&((current->p11>=0)&&(current->p11<=4))||(current->p11==6)||(current->p11==10));
}
static void __a137(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p10 = 4;
    }
  __rv_min = __rv_max;

}

static int __g138(unsigned int& id, conf* current)
{
  return ((current->p10==2)&&!(((current->p11>=0)&&(current->p11<=4))||(current->p11==6)||(current->p11==10)));
}
static void __a138(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p10 = 2;
    }
  __rv_min = __rv_max;

}

static int __g139(unsigned int& id, conf* current)
{
  return ((current->p10==3)&&((current->p9>=0)&&(current->p9<=3))||(current->p9==5)||(current->p9==7));
}
static void __a139(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p10 = 5;
    }
  __rv_min = __rv_max;

}

static int __g140(unsigned int& id, conf* current)
{
  return ((current->p10==3)&&!(((current->p9>=0)&&(current->p9<=3))||(current->p9==5)||(current->p9==7)));
}
static void __a140(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p10 = 3;
    }
  __rv_min = __rv_max;

}

static int __g141(unsigned int& id, conf* current)
{
  return ((current->p10==4)&&((current->p9>=0)&&(current->p9<=3))||(current->p9==5)||(current->p9==7));
}
static void __a141(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p10 = 8;
    }
  __rv_min = __rv_max;

}

static int __g142(unsigned int& id, conf* current)
{
  return ((current->p10==4)&&!(((current->p9>=0)&&(current->p9<=3))||(current->p9==5)||(current->p9==7)));
}
static void __a142(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p10 = 6;
    }
  __rv_min = __rv_max;

}

static int __g143(unsigned int& id, conf* current)
{
  return ((current->p10==5)&&((current->p11>=0)&&(current->p11<=4))||(current->p11==6)||(current->p11==10));
}
static void __a143(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p10 = 8;
    }
  __rv_min = __rv_max;

}

static int __g144(unsigned int& id, conf* current)
{
  return ((current->p10==5)&&!(((current->p11>=0)&&(current->p11<=4))||(current->p11==6)||(current->p11==10)));
}
static void __a144(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p10 = 7;
    }
  __rv_min = __rv_max;

}

static int __g145(unsigned int& id, conf* current)
{
  return (current->p10==6);
}
static void __a145(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p10 = 1;
    }
  __rv_min = __rv_max;

}

static int __g146(unsigned int& id, conf* current)
{
  return (current->p10==7);
}
static void __a146(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p10 = 1;
    }
  __rv_min = __rv_max;

}

static int __g147(unsigned int& id, conf* current)
{
  return (current->p10==8);
}
static void __a147(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p10 = 9;
    }
  __rv_min = __rv_max;

}

static int __g148(unsigned int& id, conf* current)
{
  return (current->p10==9);
}
static void __a148(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p10 = 10;
    }
  __rv_min = __rv_max;

}

static int __g149(unsigned int& id, conf* current)
{
  return (current->p10==10);
}
static void __a149(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p10 = 0;
    }
  __rv_min = __rv_max;

}

static int __g150(unsigned int& id, conf* current)
{
  return (current->p11==0);
}
static void __a150(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p11 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p11 = 1;
    }
  __rv_min = __rv_max;

}

static int __g151(unsigned int& id, conf* current)
{
  return (current->p11==1);
}
static void __a151(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p11 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p11 = 3;
    }
  __rv_min = __rv_max;

}

static int __g152(unsigned int& id, conf* current)
{
  return ((current->p11==2)&&((current->p12>=0)&&(current->p12<=4))||(current->p12==6)||(current->p12==10));
}
static void __a152(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p11 = 4;
    }
  __rv_min = __rv_max;

}

static int __g153(unsigned int& id, conf* current)
{
  return ((current->p11==2)&&!(((current->p12>=0)&&(current->p12<=4))||(current->p12==6)||(current->p12==10)));
}
static void __a153(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p11 = 2;
    }
  __rv_min = __rv_max;

}

static int __g154(unsigned int& id, conf* current)
{
  return ((current->p11==3)&&((current->p10>=0)&&(current->p10<=3))||(current->p10==5)||(current->p10==7));
}
static void __a154(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p11 = 5;
    }
  __rv_min = __rv_max;

}

static int __g155(unsigned int& id, conf* current)
{
  return ((current->p11==3)&&!(((current->p10>=0)&&(current->p10<=3))||(current->p10==5)||(current->p10==7)));
}
static void __a155(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p11 = 3;
    }
  __rv_min = __rv_max;

}

static int __g156(unsigned int& id, conf* current)
{
  return ((current->p11==4)&&((current->p10>=0)&&(current->p10<=3))||(current->p10==5)||(current->p10==7));
}
static void __a156(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p11 = 8;
    }
  __rv_min = __rv_max;

}

static int __g157(unsigned int& id, conf* current)
{
  return ((current->p11==4)&&!(((current->p10>=0)&&(current->p10<=3))||(current->p10==5)||(current->p10==7)));
}
static void __a157(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p11 = 6;
    }
  __rv_min = __rv_max;

}

static int __g158(unsigned int& id, conf* current)
{
  return ((current->p11==5)&&((current->p12>=0)&&(current->p12<=4))||(current->p12==6)||(current->p12==10));
}
static void __a158(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p11 = 8;
    }
  __rv_min = __rv_max;

}

static int __g159(unsigned int& id, conf* current)
{
  return ((current->p11==5)&&!(((current->p12>=0)&&(current->p12<=4))||(current->p12==6)||(current->p12==10)));
}
static void __a159(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p11 = 7;
    }
  __rv_min = __rv_max;

}

static int __g160(unsigned int& id, conf* current)
{
  return (current->p11==6);
}
static void __a160(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p11 = 1;
    }
  __rv_min = __rv_max;

}

static int __g161(unsigned int& id, conf* current)
{
  return (current->p11==7);
}
static void __a161(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p11 = 1;
    }
  __rv_min = __rv_max;

}

static int __g162(unsigned int& id, conf* current)
{
  return (current->p11==8);
}
static void __a162(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p11 = 9;
    }
  __rv_min = __rv_max;

}

static int __g163(unsigned int& id, conf* current)
{
  return (current->p11==9);
}
static void __a163(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p11 = 10;
    }
  __rv_min = __rv_max;

}

static int __g164(unsigned int& id, conf* current)
{
  return (current->p11==10);
}
static void __a164(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p11 = 0;
    }
  __rv_min = __rv_max;

}

static int __g165(unsigned int& id, conf* current)
{
  return (current->p12==0);
}
static void __a165(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p12 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p12 = 1;
    }
  __rv_min = __rv_max;

}

static int __g166(unsigned int& id, conf* current)
{
  return (current->p12==1);
}
static void __a166(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p12 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p12 = 3;
    }
  __rv_min = __rv_max;

}

static int __g167(unsigned int& id, conf* current)
{
  return ((current->p12==2)&&((current->p13>=0)&&(current->p13<=4))||(current->p13==6)||(current->p13==10));
}
static void __a167(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p12 = 4;
    }
  __rv_min = __rv_max;

}

static int __g168(unsigned int& id, conf* current)
{
  return ((current->p12==2)&&!(((current->p13>=0)&&(current->p13<=4))||(current->p13==6)||(current->p13==10)));
}
static void __a168(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p12 = 2;
    }
  __rv_min = __rv_max;

}

static int __g169(unsigned int& id, conf* current)
{
  return ((current->p12==3)&&((current->p11>=0)&&(current->p11<=3))||(current->p11==5)||(current->p11==7));
}
static void __a169(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p12 = 5;
    }
  __rv_min = __rv_max;

}

static int __g170(unsigned int& id, conf* current)
{
  return ((current->p12==3)&&!(((current->p11>=0)&&(current->p11<=3))||(current->p11==5)||(current->p11==7)));
}
static void __a170(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p12 = 3;
    }
  __rv_min = __rv_max;

}

static int __g171(unsigned int& id, conf* current)
{
  return ((current->p12==4)&&((current->p11>=0)&&(current->p11<=3))||(current->p11==5)||(current->p11==7));
}
static void __a171(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p12 = 8;
    }
  __rv_min = __rv_max;

}

static int __g172(unsigned int& id, conf* current)
{
  return ((current->p12==4)&&!(((current->p11>=0)&&(current->p11<=3))||(current->p11==5)||(current->p11==7)));
}
static void __a172(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p12 = 6;
    }
  __rv_min = __rv_max;

}

static int __g173(unsigned int& id, conf* current)
{
  return ((current->p12==5)&&((current->p13>=0)&&(current->p13<=4))||(current->p13==6)||(current->p13==10));
}
static void __a173(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p12 = 8;
    }
  __rv_min = __rv_max;

}

static int __g174(unsigned int& id, conf* current)
{
  return ((current->p12==5)&&!(((current->p13>=0)&&(current->p13<=4))||(current->p13==6)||(current->p13==10)));
}
static void __a174(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p12 = 7;
    }
  __rv_min = __rv_max;

}

static int __g175(unsigned int& id, conf* current)
{
  return (current->p12==6);
}
static void __a175(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p12 = 1;
    }
  __rv_min = __rv_max;

}

static int __g176(unsigned int& id, conf* current)
{
  return (current->p12==7);
}
static void __a176(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p12 = 1;
    }
  __rv_min = __rv_max;

}

static int __g177(unsigned int& id, conf* current)
{
  return (current->p12==8);
}
static void __a177(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p12 = 9;
    }
  __rv_min = __rv_max;

}

static int __g178(unsigned int& id, conf* current)
{
  return (current->p12==9);
}
static void __a178(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p12 = 10;
    }
  __rv_min = __rv_max;

}

static int __g179(unsigned int& id, conf* current)
{
  return (current->p12==10);
}
static void __a179(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p12 = 0;
    }
  __rv_min = __rv_max;

}

static int __g180(unsigned int& id, conf* current)
{
  return (current->p13==0);
}
static void __a180(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p13 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p13 = 1;
    }
  __rv_min = __rv_max;

}

static int __g181(unsigned int& id, conf* current)
{
  return (current->p13==1);
}
static void __a181(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p13 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p13 = 3;
    }
  __rv_min = __rv_max;

}

static int __g182(unsigned int& id, conf* current)
{
  return ((current->p13==2)&&((current->p14>=0)&&(current->p14<=4))||(current->p14==6)||(current->p14==10));
}
static void __a182(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p13 = 4;
    }
  __rv_min = __rv_max;

}

static int __g183(unsigned int& id, conf* current)
{
  return ((current->p13==2)&&!(((current->p14>=0)&&(current->p14<=4))||(current->p14==6)||(current->p14==10)));
}
static void __a183(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p13 = 2;
    }
  __rv_min = __rv_max;

}

static int __g184(unsigned int& id, conf* current)
{
  return ((current->p13==3)&&((current->p12>=0)&&(current->p12<=3))||(current->p12==5)||(current->p12==7));
}
static void __a184(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p13 = 5;
    }
  __rv_min = __rv_max;

}

static int __g185(unsigned int& id, conf* current)
{
  return ((current->p13==3)&&!(((current->p12>=0)&&(current->p12<=3))||(current->p12==5)||(current->p12==7)));
}
static void __a185(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p13 = 3;
    }
  __rv_min = __rv_max;

}

static int __g186(unsigned int& id, conf* current)
{
  return ((current->p13==4)&&((current->p12>=0)&&(current->p12<=3))||(current->p12==5)||(current->p12==7));
}
static void __a186(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p13 = 8;
    }
  __rv_min = __rv_max;

}

static int __g187(unsigned int& id, conf* current)
{
  return ((current->p13==4)&&!(((current->p12>=0)&&(current->p12<=3))||(current->p12==5)||(current->p12==7)));
}
static void __a187(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p13 = 6;
    }
  __rv_min = __rv_max;

}

static int __g188(unsigned int& id, conf* current)
{
  return ((current->p13==5)&&((current->p14>=0)&&(current->p14<=4))||(current->p14==6)||(current->p14==10));
}
static void __a188(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p13 = 8;
    }
  __rv_min = __rv_max;

}

static int __g189(unsigned int& id, conf* current)
{
  return ((current->p13==5)&&!(((current->p14>=0)&&(current->p14<=4))||(current->p14==6)||(current->p14==10)));
}
static void __a189(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p13 = 7;
    }
  __rv_min = __rv_max;

}

static int __g190(unsigned int& id, conf* current)
{
  return (current->p13==6);
}
static void __a190(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p13 = 1;
    }
  __rv_min = __rv_max;

}

static int __g191(unsigned int& id, conf* current)
{
  return (current->p13==7);
}
static void __a191(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p13 = 1;
    }
  __rv_min = __rv_max;

}

static int __g192(unsigned int& id, conf* current)
{
  return (current->p13==8);
}
static void __a192(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p13 = 9;
    }
  __rv_min = __rv_max;

}

static int __g193(unsigned int& id, conf* current)
{
  return (current->p13==9);
}
static void __a193(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p13 = 10;
    }
  __rv_min = __rv_max;

}

static int __g194(unsigned int& id, conf* current)
{
  return (current->p13==10);
}
static void __a194(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p13 = 0;
    }
  __rv_min = __rv_max;

}

static int __g195(unsigned int& id, conf* current)
{
  return (current->p14==0);
}
static void __a195(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p14 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p14 = 1;
    }
  __rv_min = __rv_max;

}

static int __g196(unsigned int& id, conf* current)
{
  return (current->p14==1);
}
static void __a196(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p14 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p14 = 3;
    }
  __rv_min = __rv_max;

}

static int __g197(unsigned int& id, conf* current)
{
  return ((current->p14==2)&&((current->p15>=0)&&(current->p15<=4))||(current->p15==6)||(current->p15==10));
}
static void __a197(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p14 = 4;
    }
  __rv_min = __rv_max;

}

static int __g198(unsigned int& id, conf* current)
{
  return ((current->p14==2)&&!(((current->p15>=0)&&(current->p15<=4))||(current->p15==6)||(current->p15==10)));
}
static void __a198(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p14 = 2;
    }
  __rv_min = __rv_max;

}

static int __g199(unsigned int& id, conf* current)
{
  return ((current->p14==3)&&((current->p13>=0)&&(current->p13<=3))||(current->p13==5)||(current->p13==7));
}
static void __a199(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p14 = 5;
    }
  __rv_min = __rv_max;

}

static int __g200(unsigned int& id, conf* current)
{
  return ((current->p14==3)&&!(((current->p13>=0)&&(current->p13<=3))||(current->p13==5)||(current->p13==7)));
}
static void __a200(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p14 = 3;
    }
  __rv_min = __rv_max;

}

static int __g201(unsigned int& id, conf* current)
{
  return ((current->p14==4)&&((current->p13>=0)&&(current->p13<=3))||(current->p13==5)||(current->p13==7));
}
static void __a201(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p14 = 8;
    }
  __rv_min = __rv_max;

}

static int __g202(unsigned int& id, conf* current)
{
  return ((current->p14==4)&&!(((current->p13>=0)&&(current->p13<=3))||(current->p13==5)||(current->p13==7)));
}
static void __a202(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p14 = 6;
    }
  __rv_min = __rv_max;

}

static int __g203(unsigned int& id, conf* current)
{
  return ((current->p14==5)&&((current->p15>=0)&&(current->p15<=4))||(current->p15==6)||(current->p15==10));
}
static void __a203(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p14 = 8;
    }
  __rv_min = __rv_max;

}

static int __g204(unsigned int& id, conf* current)
{
  return ((current->p14==5)&&!(((current->p15>=0)&&(current->p15<=4))||(current->p15==6)||(current->p15==10)));
}
static void __a204(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p14 = 7;
    }
  __rv_min = __rv_max;

}

static int __g205(unsigned int& id, conf* current)
{
  return (current->p14==6);
}
static void __a205(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p14 = 1;
    }
  __rv_min = __rv_max;

}

static int __g206(unsigned int& id, conf* current)
{
  return (current->p14==7);
}
static void __a206(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p14 = 1;
    }
  __rv_min = __rv_max;

}

static int __g207(unsigned int& id, conf* current)
{
  return (current->p14==8);
}
static void __a207(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p14 = 9;
    }
  __rv_min = __rv_max;

}

static int __g208(unsigned int& id, conf* current)
{
  return (current->p14==9);
}
static void __a208(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p14 = 10;
    }
  __rv_min = __rv_max;

}

static int __g209(unsigned int& id, conf* current)
{
  return (current->p14==10);
}
static void __a209(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p14 = 0;
    }
  __rv_min = __rv_max;

}

static int __g210(unsigned int& id, conf* current)
{
  return (current->p15==0);
}
static void __a210(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p15 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p15 = 1;
    }
  __rv_min = __rv_max;

}

static int __g211(unsigned int& id, conf* current)
{
  return (current->p15==1);
}
static void __a211(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p15 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p15 = 3;
    }
  __rv_min = __rv_max;

}

static int __g212(unsigned int& id, conf* current)
{
  return ((current->p15==2)&&((current->p16>=0)&&(current->p16<=4))||(current->p16==6)||(current->p16==10));
}
static void __a212(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p15 = 4;
    }
  __rv_min = __rv_max;

}

static int __g213(unsigned int& id, conf* current)
{
  return ((current->p15==2)&&!(((current->p16>=0)&&(current->p16<=4))||(current->p16==6)||(current->p16==10)));
}
static void __a213(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p15 = 2;
    }
  __rv_min = __rv_max;

}

static int __g214(unsigned int& id, conf* current)
{
  return ((current->p15==3)&&((current->p14>=0)&&(current->p14<=3))||(current->p14==5)||(current->p14==7));
}
static void __a214(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p15 = 5;
    }
  __rv_min = __rv_max;

}

static int __g215(unsigned int& id, conf* current)
{
  return ((current->p15==3)&&!(((current->p14>=0)&&(current->p14<=3))||(current->p14==5)||(current->p14==7)));
}
static void __a215(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p15 = 3;
    }
  __rv_min = __rv_max;

}

static int __g216(unsigned int& id, conf* current)
{
  return ((current->p15==4)&&((current->p14>=0)&&(current->p14<=3))||(current->p14==5)||(current->p14==7));
}
static void __a216(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p15 = 8;
    }
  __rv_min = __rv_max;

}

static int __g217(unsigned int& id, conf* current)
{
  return ((current->p15==4)&&!(((current->p14>=0)&&(current->p14<=3))||(current->p14==5)||(current->p14==7)));
}
static void __a217(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p15 = 6;
    }
  __rv_min = __rv_max;

}

static int __g218(unsigned int& id, conf* current)
{
  return ((current->p15==5)&&((current->p16>=0)&&(current->p16<=4))||(current->p16==6)||(current->p16==10));
}
static void __a218(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p15 = 8;
    }
  __rv_min = __rv_max;

}

static int __g219(unsigned int& id, conf* current)
{
  return ((current->p15==5)&&!(((current->p16>=0)&&(current->p16<=4))||(current->p16==6)||(current->p16==10)));
}
static void __a219(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p15 = 7;
    }
  __rv_min = __rv_max;

}

static int __g220(unsigned int& id, conf* current)
{
  return (current->p15==6);
}
static void __a220(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p15 = 1;
    }
  __rv_min = __rv_max;

}

static int __g221(unsigned int& id, conf* current)
{
  return (current->p15==7);
}
static void __a221(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p15 = 1;
    }
  __rv_min = __rv_max;

}

static int __g222(unsigned int& id, conf* current)
{
  return (current->p15==8);
}
static void __a222(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p15 = 9;
    }
  __rv_min = __rv_max;

}

static int __g223(unsigned int& id, conf* current)
{
  return (current->p15==9);
}
static void __a223(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p15 = 10;
    }
  __rv_min = __rv_max;

}

static int __g224(unsigned int& id, conf* current)
{
  return (current->p15==10);
}
static void __a224(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p15 = 0;
    }
  __rv_min = __rv_max;

}

static int __g225(unsigned int& id, conf* current)
{
  return (current->p16==0);
}
static void __a225(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p16 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p16 = 1;
    }
  __rv_min = __rv_max;

}

static int __g226(unsigned int& id, conf* current)
{
  return (current->p16==1);
}
static void __a226(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p16 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p16 = 3;
    }
  __rv_min = __rv_max;

}

static int __g227(unsigned int& id, conf* current)
{
  return ((current->p16==2)&&((current->p17>=0)&&(current->p17<=4))||(current->p17==6)||(current->p17==10));
}
static void __a227(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p16 = 4;
    }
  __rv_min = __rv_max;

}

static int __g228(unsigned int& id, conf* current)
{
  return ((current->p16==2)&&!(((current->p17>=0)&&(current->p17<=4))||(current->p17==6)||(current->p17==10)));
}
static void __a228(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p16 = 2;
    }
  __rv_min = __rv_max;

}

static int __g229(unsigned int& id, conf* current)
{
  return ((current->p16==3)&&((current->p15>=0)&&(current->p15<=3))||(current->p15==5)||(current->p15==7));
}
static void __a229(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p16 = 5;
    }
  __rv_min = __rv_max;

}

static int __g230(unsigned int& id, conf* current)
{
  return ((current->p16==3)&&!(((current->p15>=0)&&(current->p15<=3))||(current->p15==5)||(current->p15==7)));
}
static void __a230(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p16 = 3;
    }
  __rv_min = __rv_max;

}

static int __g231(unsigned int& id, conf* current)
{
  return ((current->p16==4)&&((current->p15>=0)&&(current->p15<=3))||(current->p15==5)||(current->p15==7));
}
static void __a231(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p16 = 8;
    }
  __rv_min = __rv_max;

}

static int __g232(unsigned int& id, conf* current)
{
  return ((current->p16==4)&&!(((current->p15>=0)&&(current->p15<=3))||(current->p15==5)||(current->p15==7)));
}
static void __a232(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p16 = 6;
    }
  __rv_min = __rv_max;

}

static int __g233(unsigned int& id, conf* current)
{
  return ((current->p16==5)&&((current->p17>=0)&&(current->p17<=4))||(current->p17==6)||(current->p17==10));
}
static void __a233(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p16 = 8;
    }
  __rv_min = __rv_max;

}

static int __g234(unsigned int& id, conf* current)
{
  return ((current->p16==5)&&!(((current->p17>=0)&&(current->p17<=4))||(current->p17==6)||(current->p17==10)));
}
static void __a234(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p16 = 7;
    }
  __rv_min = __rv_max;

}

static int __g235(unsigned int& id, conf* current)
{
  return (current->p16==6);
}
static void __a235(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p16 = 1;
    }
  __rv_min = __rv_max;

}

static int __g236(unsigned int& id, conf* current)
{
  return (current->p16==7);
}
static void __a236(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p16 = 1;
    }
  __rv_min = __rv_max;

}

static int __g237(unsigned int& id, conf* current)
{
  return (current->p16==8);
}
static void __a237(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p16 = 9;
    }
  __rv_min = __rv_max;

}

static int __g238(unsigned int& id, conf* current)
{
  return (current->p16==9);
}
static void __a238(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p16 = 10;
    }
  __rv_min = __rv_max;

}

static int __g239(unsigned int& id, conf* current)
{
  return (current->p16==10);
}
static void __a239(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p16 = 0;
    }
  __rv_min = __rv_max;

}

static int __g240(unsigned int& id, conf* current)
{
  return (current->p17==0);
}
static void __a240(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p17 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p17 = 1;
    }
  __rv_min = __rv_max;

}

static int __g241(unsigned int& id, conf* current)
{
  return (current->p17==1);
}
static void __a241(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p17 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p17 = 3;
    }
  __rv_min = __rv_max;

}

static int __g242(unsigned int& id, conf* current)
{
  return ((current->p17==2)&&((current->p18>=0)&&(current->p18<=4))||(current->p18==6)||(current->p18==10));
}
static void __a242(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p17 = 4;
    }
  __rv_min = __rv_max;

}

static int __g243(unsigned int& id, conf* current)
{
  return ((current->p17==2)&&!(((current->p18>=0)&&(current->p18<=4))||(current->p18==6)||(current->p18==10)));
}
static void __a243(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p17 = 2;
    }
  __rv_min = __rv_max;

}

static int __g244(unsigned int& id, conf* current)
{
  return ((current->p17==3)&&((current->p16>=0)&&(current->p16<=3))||(current->p16==5)||(current->p16==7));
}
static void __a244(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p17 = 5;
    }
  __rv_min = __rv_max;

}

static int __g245(unsigned int& id, conf* current)
{
  return ((current->p17==3)&&!(((current->p16>=0)&&(current->p16<=3))||(current->p16==5)||(current->p16==7)));
}
static void __a245(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p17 = 3;
    }
  __rv_min = __rv_max;

}

static int __g246(unsigned int& id, conf* current)
{
  return ((current->p17==4)&&((current->p16>=0)&&(current->p16<=3))||(current->p16==5)||(current->p16==7));
}
static void __a246(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p17 = 8;
    }
  __rv_min = __rv_max;

}

static int __g247(unsigned int& id, conf* current)
{
  return ((current->p17==4)&&!(((current->p16>=0)&&(current->p16<=3))||(current->p16==5)||(current->p16==7)));
}
static void __a247(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p17 = 6;
    }
  __rv_min = __rv_max;

}

static int __g248(unsigned int& id, conf* current)
{
  return ((current->p17==5)&&((current->p18>=0)&&(current->p18<=4))||(current->p18==6)||(current->p18==10));
}
static void __a248(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p17 = 8;
    }
  __rv_min = __rv_max;

}

static int __g249(unsigned int& id, conf* current)
{
  return ((current->p17==5)&&!(((current->p18>=0)&&(current->p18<=4))||(current->p18==6)||(current->p18==10)));
}
static void __a249(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p17 = 7;
    }
  __rv_min = __rv_max;

}

static int __g250(unsigned int& id, conf* current)
{
  return (current->p17==6);
}
static void __a250(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p17 = 1;
    }
  __rv_min = __rv_max;

}

static int __g251(unsigned int& id, conf* current)
{
  return (current->p17==7);
}
static void __a251(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p17 = 1;
    }
  __rv_min = __rv_max;

}

static int __g252(unsigned int& id, conf* current)
{
  return (current->p17==8);
}
static void __a252(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p17 = 9;
    }
  __rv_min = __rv_max;

}

static int __g253(unsigned int& id, conf* current)
{
  return (current->p17==9);
}
static void __a253(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p17 = 10;
    }
  __rv_min = __rv_max;

}

static int __g254(unsigned int& id, conf* current)
{
  return (current->p17==10);
}
static void __a254(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p17 = 0;
    }
  __rv_min = __rv_max;

}

static int __g255(unsigned int& id, conf* current)
{
  return (current->p18==0);
}
static void __a255(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p18 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p18 = 1;
    }
  __rv_min = __rv_max;

}

static int __g256(unsigned int& id, conf* current)
{
  return (current->p18==1);
}
static void __a256(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p18 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p18 = 3;
    }
  __rv_min = __rv_max;

}

static int __g257(unsigned int& id, conf* current)
{
  return ((current->p18==2)&&((current->p19>=0)&&(current->p19<=4))||(current->p19==6)||(current->p19==10));
}
static void __a257(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p18 = 4;
    }
  __rv_min = __rv_max;

}

static int __g258(unsigned int& id, conf* current)
{
  return ((current->p18==2)&&!(((current->p19>=0)&&(current->p19<=4))||(current->p19==6)||(current->p19==10)));
}
static void __a258(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p18 = 2;
    }
  __rv_min = __rv_max;

}

static int __g259(unsigned int& id, conf* current)
{
  return ((current->p18==3)&&((current->p17>=0)&&(current->p17<=3))||(current->p17==5)||(current->p17==7));
}
static void __a259(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p18 = 5;
    }
  __rv_min = __rv_max;

}

static int __g260(unsigned int& id, conf* current)
{
  return ((current->p18==3)&&!(((current->p17>=0)&&(current->p17<=3))||(current->p17==5)||(current->p17==7)));
}
static void __a260(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p18 = 3;
    }
  __rv_min = __rv_max;

}

static int __g261(unsigned int& id, conf* current)
{
  return ((current->p18==4)&&((current->p17>=0)&&(current->p17<=3))||(current->p17==5)||(current->p17==7));
}
static void __a261(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p18 = 8;
    }
  __rv_min = __rv_max;

}

static int __g262(unsigned int& id, conf* current)
{
  return ((current->p18==4)&&!(((current->p17>=0)&&(current->p17<=3))||(current->p17==5)||(current->p17==7)));
}
static void __a262(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p18 = 6;
    }
  __rv_min = __rv_max;

}

static int __g263(unsigned int& id, conf* current)
{
  return ((current->p18==5)&&((current->p19>=0)&&(current->p19<=4))||(current->p19==6)||(current->p19==10));
}
static void __a263(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p18 = 8;
    }
  __rv_min = __rv_max;

}

static int __g264(unsigned int& id, conf* current)
{
  return ((current->p18==5)&&!(((current->p19>=0)&&(current->p19<=4))||(current->p19==6)||(current->p19==10)));
}
static void __a264(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p18 = 7;
    }
  __rv_min = __rv_max;

}

static int __g265(unsigned int& id, conf* current)
{
  return (current->p18==6);
}
static void __a265(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p18 = 1;
    }
  __rv_min = __rv_max;

}

static int __g266(unsigned int& id, conf* current)
{
  return (current->p18==7);
}
static void __a266(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p18 = 1;
    }
  __rv_min = __rv_max;

}

static int __g267(unsigned int& id, conf* current)
{
  return (current->p18==8);
}
static void __a267(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p18 = 9;
    }
  __rv_min = __rv_max;

}

static int __g268(unsigned int& id, conf* current)
{
  return (current->p18==9);
}
static void __a268(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p18 = 10;
    }
  __rv_min = __rv_max;

}

static int __g269(unsigned int& id, conf* current)
{
  return (current->p18==10);
}
static void __a269(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p18 = 0;
    }
  __rv_min = __rv_max;

}

static int __g270(unsigned int& id, conf* current)
{
  return (current->p19==0);
}
static void __a270(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p19 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p19 = 1;
    }
  __rv_min = __rv_max;

}

static int __g271(unsigned int& id, conf* current)
{
  return (current->p19==1);
}
static void __a271(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p19 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p19 = 3;
    }
  __rv_min = __rv_max;

}

static int __g272(unsigned int& id, conf* current)
{
  return ((current->p19==2)&&((current->p20>=0)&&(current->p20<=4))||(current->p20==6)||(current->p20==10));
}
static void __a272(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p19 = 4;
    }
  __rv_min = __rv_max;

}

static int __g273(unsigned int& id, conf* current)
{
  return ((current->p19==2)&&!(((current->p20>=0)&&(current->p20<=4))||(current->p20==6)||(current->p20==10)));
}
static void __a273(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p19 = 2;
    }
  __rv_min = __rv_max;

}

static int __g274(unsigned int& id, conf* current)
{
  return ((current->p19==3)&&((current->p18>=0)&&(current->p18<=3))||(current->p18==5)||(current->p18==7));
}
static void __a274(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p19 = 5;
    }
  __rv_min = __rv_max;

}

static int __g275(unsigned int& id, conf* current)
{
  return ((current->p19==3)&&!(((current->p18>=0)&&(current->p18<=3))||(current->p18==5)||(current->p18==7)));
}
static void __a275(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p19 = 3;
    }
  __rv_min = __rv_max;

}

static int __g276(unsigned int& id, conf* current)
{
  return ((current->p19==4)&&((current->p18>=0)&&(current->p18<=3))||(current->p18==5)||(current->p18==7));
}
static void __a276(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p19 = 8;
    }
  __rv_min = __rv_max;

}

static int __g277(unsigned int& id, conf* current)
{
  return ((current->p19==4)&&!(((current->p18>=0)&&(current->p18<=3))||(current->p18==5)||(current->p18==7)));
}
static void __a277(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p19 = 6;
    }
  __rv_min = __rv_max;

}

static int __g278(unsigned int& id, conf* current)
{
  return ((current->p19==5)&&((current->p20>=0)&&(current->p20<=4))||(current->p20==6)||(current->p20==10));
}
static void __a278(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p19 = 8;
    }
  __rv_min = __rv_max;

}

static int __g279(unsigned int& id, conf* current)
{
  return ((current->p19==5)&&!(((current->p20>=0)&&(current->p20<=4))||(current->p20==6)||(current->p20==10)));
}
static void __a279(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p19 = 7;
    }
  __rv_min = __rv_max;

}

static int __g280(unsigned int& id, conf* current)
{
  return (current->p19==6);
}
static void __a280(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p19 = 1;
    }
  __rv_min = __rv_max;

}

static int __g281(unsigned int& id, conf* current)
{
  return (current->p19==7);
}
static void __a281(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p19 = 1;
    }
  __rv_min = __rv_max;

}

static int __g282(unsigned int& id, conf* current)
{
  return (current->p19==8);
}
static void __a282(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p19 = 9;
    }
  __rv_min = __rv_max;

}

static int __g283(unsigned int& id, conf* current)
{
  return (current->p19==9);
}
static void __a283(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p19 = 10;
    }
  __rv_min = __rv_max;

}

static int __g284(unsigned int& id, conf* current)
{
  return (current->p19==10);
}
static void __a284(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p19 = 0;
    }
  __rv_min = __rv_max;

}

static int __g285(unsigned int& id, conf* current)
{
  return (current->p20==0);
}
static void __a285(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p20 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p20 = 1;
    }
  __rv_min = __rv_max;

}

static int __g286(unsigned int& id, conf* current)
{
  return (current->p20==1);
}
static void __a286(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p20 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p20 = 3;
    }
  __rv_min = __rv_max;

}

static int __g287(unsigned int& id, conf* current)
{
  return ((current->p20==2)&&((current->p21>=0)&&(current->p21<=4))||(current->p21==6)||(current->p21==10));
}
static void __a287(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p20 = 4;
    }
  __rv_min = __rv_max;

}

static int __g288(unsigned int& id, conf* current)
{
  return ((current->p20==2)&&!(((current->p21>=0)&&(current->p21<=4))||(current->p21==6)||(current->p21==10)));
}
static void __a288(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p20 = 2;
    }
  __rv_min = __rv_max;

}

static int __g289(unsigned int& id, conf* current)
{
  return ((current->p20==3)&&((current->p19>=0)&&(current->p19<=3))||(current->p19==5)||(current->p19==7));
}
static void __a289(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p20 = 5;
    }
  __rv_min = __rv_max;

}

static int __g290(unsigned int& id, conf* current)
{
  return ((current->p20==3)&&!(((current->p19>=0)&&(current->p19<=3))||(current->p19==5)||(current->p19==7)));
}
static void __a290(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p20 = 3;
    }
  __rv_min = __rv_max;

}

static int __g291(unsigned int& id, conf* current)
{
  return ((current->p20==4)&&((current->p19>=0)&&(current->p19<=3))||(current->p19==5)||(current->p19==7));
}
static void __a291(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p20 = 8;
    }
  __rv_min = __rv_max;

}

static int __g292(unsigned int& id, conf* current)
{
  return ((current->p20==4)&&!(((current->p19>=0)&&(current->p19<=3))||(current->p19==5)||(current->p19==7)));
}
static void __a292(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p20 = 6;
    }
  __rv_min = __rv_max;

}

static int __g293(unsigned int& id, conf* current)
{
  return ((current->p20==5)&&((current->p21>=0)&&(current->p21<=4))||(current->p21==6)||(current->p21==10));
}
static void __a293(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p20 = 8;
    }
  __rv_min = __rv_max;

}

static int __g294(unsigned int& id, conf* current)
{
  return ((current->p20==5)&&!(((current->p21>=0)&&(current->p21<=4))||(current->p21==6)||(current->p21==10)));
}
static void __a294(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p20 = 7;
    }
  __rv_min = __rv_max;

}

static int __g295(unsigned int& id, conf* current)
{
  return (current->p20==6);
}
static void __a295(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p20 = 1;
    }
  __rv_min = __rv_max;

}

static int __g296(unsigned int& id, conf* current)
{
  return (current->p20==7);
}
static void __a296(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p20 = 1;
    }
  __rv_min = __rv_max;

}

static int __g297(unsigned int& id, conf* current)
{
  return (current->p20==8);
}
static void __a297(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p20 = 9;
    }
  __rv_min = __rv_max;

}

static int __g298(unsigned int& id, conf* current)
{
  return (current->p20==9);
}
static void __a298(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p20 = 10;
    }
  __rv_min = __rv_max;

}

static int __g299(unsigned int& id, conf* current)
{
  return (current->p20==10);
}
static void __a299(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p20 = 0;
    }
  __rv_min = __rv_max;

}

static int __g300(unsigned int& id, conf* current)
{
  return (current->p21==0);
}
static void __a300(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p21 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p21 = 1;
    }
  __rv_min = __rv_max;

}

static int __g301(unsigned int& id, conf* current)
{
  return (current->p21==1);
}
static void __a301(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p21 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p21 = 3;
    }
  __rv_min = __rv_max;

}

static int __g302(unsigned int& id, conf* current)
{
  return ((current->p21==2)&&((current->p22>=0)&&(current->p22<=4))||(current->p22==6)||(current->p22==10));
}
static void __a302(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p21 = 4;
    }
  __rv_min = __rv_max;

}

static int __g303(unsigned int& id, conf* current)
{
  return ((current->p21==2)&&!(((current->p22>=0)&&(current->p22<=4))||(current->p22==6)||(current->p22==10)));
}
static void __a303(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p21 = 2;
    }
  __rv_min = __rv_max;

}

static int __g304(unsigned int& id, conf* current)
{
  return ((current->p21==3)&&((current->p20>=0)&&(current->p20<=3))||(current->p20==5)||(current->p20==7));
}
static void __a304(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p21 = 5;
    }
  __rv_min = __rv_max;

}

static int __g305(unsigned int& id, conf* current)
{
  return ((current->p21==3)&&!(((current->p20>=0)&&(current->p20<=3))||(current->p20==5)||(current->p20==7)));
}
static void __a305(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p21 = 3;
    }
  __rv_min = __rv_max;

}

static int __g306(unsigned int& id, conf* current)
{
  return ((current->p21==4)&&((current->p20>=0)&&(current->p20<=3))||(current->p20==5)||(current->p20==7));
}
static void __a306(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p21 = 8;
    }
  __rv_min = __rv_max;

}

static int __g307(unsigned int& id, conf* current)
{
  return ((current->p21==4)&&!(((current->p20>=0)&&(current->p20<=3))||(current->p20==5)||(current->p20==7)));
}
static void __a307(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p21 = 6;
    }
  __rv_min = __rv_max;

}

static int __g308(unsigned int& id, conf* current)
{
  return ((current->p21==5)&&((current->p22>=0)&&(current->p22<=4))||(current->p22==6)||(current->p22==10));
}
static void __a308(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p21 = 8;
    }
  __rv_min = __rv_max;

}

static int __g309(unsigned int& id, conf* current)
{
  return ((current->p21==5)&&!(((current->p22>=0)&&(current->p22<=4))||(current->p22==6)||(current->p22==10)));
}
static void __a309(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p21 = 7;
    }
  __rv_min = __rv_max;

}

static int __g310(unsigned int& id, conf* current)
{
  return (current->p21==6);
}
static void __a310(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p21 = 1;
    }
  __rv_min = __rv_max;

}

static int __g311(unsigned int& id, conf* current)
{
  return (current->p21==7);
}
static void __a311(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p21 = 1;
    }
  __rv_min = __rv_max;

}

static int __g312(unsigned int& id, conf* current)
{
  return (current->p21==8);
}
static void __a312(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p21 = 9;
    }
  __rv_min = __rv_max;

}

static int __g313(unsigned int& id, conf* current)
{
  return (current->p21==9);
}
static void __a313(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p21 = 10;
    }
  __rv_min = __rv_max;

}

static int __g314(unsigned int& id, conf* current)
{
  return (current->p21==10);
}
static void __a314(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p21 = 0;
    }
  __rv_min = __rv_max;

}

static int __g315(unsigned int& id, conf* current)
{
  return (current->p22==0);
}
static void __a315(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p22 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p22 = 1;
    }
  __rv_min = __rv_max;

}

static int __g316(unsigned int& id, conf* current)
{
  return (current->p22==1);
}
static void __a316(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p22 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p22 = 3;
    }
  __rv_min = __rv_max;

}

static int __g317(unsigned int& id, conf* current)
{
  return ((current->p22==2)&&((current->p23>=0)&&(current->p23<=4))||(current->p23==6)||(current->p23==10));
}
static void __a317(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p22 = 4;
    }
  __rv_min = __rv_max;

}

static int __g318(unsigned int& id, conf* current)
{
  return ((current->p22==2)&&!(((current->p23>=0)&&(current->p23<=4))||(current->p23==6)||(current->p23==10)));
}
static void __a318(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p22 = 2;
    }
  __rv_min = __rv_max;

}

static int __g319(unsigned int& id, conf* current)
{
  return ((current->p22==3)&&((current->p21>=0)&&(current->p21<=3))||(current->p21==5)||(current->p21==7));
}
static void __a319(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p22 = 5;
    }
  __rv_min = __rv_max;

}

static int __g320(unsigned int& id, conf* current)
{
  return ((current->p22==3)&&!(((current->p21>=0)&&(current->p21<=3))||(current->p21==5)||(current->p21==7)));
}
static void __a320(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p22 = 3;
    }
  __rv_min = __rv_max;

}

static int __g321(unsigned int& id, conf* current)
{
  return ((current->p22==4)&&((current->p21>=0)&&(current->p21<=3))||(current->p21==5)||(current->p21==7));
}
static void __a321(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p22 = 8;
    }
  __rv_min = __rv_max;

}

static int __g322(unsigned int& id, conf* current)
{
  return ((current->p22==4)&&!(((current->p21>=0)&&(current->p21<=3))||(current->p21==5)||(current->p21==7)));
}
static void __a322(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p22 = 6;
    }
  __rv_min = __rv_max;

}

static int __g323(unsigned int& id, conf* current)
{
  return ((current->p22==5)&&((current->p23>=0)&&(current->p23<=4))||(current->p23==6)||(current->p23==10));
}
static void __a323(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p22 = 8;
    }
  __rv_min = __rv_max;

}

static int __g324(unsigned int& id, conf* current)
{
  return ((current->p22==5)&&!(((current->p23>=0)&&(current->p23<=4))||(current->p23==6)||(current->p23==10)));
}
static void __a324(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p22 = 7;
    }
  __rv_min = __rv_max;

}

static int __g325(unsigned int& id, conf* current)
{
  return (current->p22==6);
}
static void __a325(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p22 = 1;
    }
  __rv_min = __rv_max;

}

static int __g326(unsigned int& id, conf* current)
{
  return (current->p22==7);
}
static void __a326(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p22 = 1;
    }
  __rv_min = __rv_max;

}

static int __g327(unsigned int& id, conf* current)
{
  return (current->p22==8);
}
static void __a327(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p22 = 9;
    }
  __rv_min = __rv_max;

}

static int __g328(unsigned int& id, conf* current)
{
  return (current->p22==9);
}
static void __a328(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p22 = 10;
    }
  __rv_min = __rv_max;

}

static int __g329(unsigned int& id, conf* current)
{
  return (current->p22==10);
}
static void __a329(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p22 = 0;
    }
  __rv_min = __rv_max;

}

static int __g330(unsigned int& id, conf* current)
{
  return (current->p23==0);
}
static void __a330(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p23 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p23 = 1;
    }
  __rv_min = __rv_max;

}

static int __g331(unsigned int& id, conf* current)
{
  return (current->p23==1);
}
static void __a331(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p23 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p23 = 3;
    }
  __rv_min = __rv_max;

}

static int __g332(unsigned int& id, conf* current)
{
  return ((current->p23==2)&&((current->p24>=0)&&(current->p24<=4))||(current->p24==6)||(current->p24==10));
}
static void __a332(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p23 = 4;
    }
  __rv_min = __rv_max;

}

static int __g333(unsigned int& id, conf* current)
{
  return ((current->p23==2)&&!(((current->p24>=0)&&(current->p24<=4))||(current->p24==6)||(current->p24==10)));
}
static void __a333(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p23 = 2;
    }
  __rv_min = __rv_max;

}

static int __g334(unsigned int& id, conf* current)
{
  return ((current->p23==3)&&((current->p22>=0)&&(current->p22<=3))||(current->p22==5)||(current->p22==7));
}
static void __a334(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p23 = 5;
    }
  __rv_min = __rv_max;

}

static int __g335(unsigned int& id, conf* current)
{
  return ((current->p23==3)&&!(((current->p22>=0)&&(current->p22<=3))||(current->p22==5)||(current->p22==7)));
}
static void __a335(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p23 = 3;
    }
  __rv_min = __rv_max;

}

static int __g336(unsigned int& id, conf* current)
{
  return ((current->p23==4)&&((current->p22>=0)&&(current->p22<=3))||(current->p22==5)||(current->p22==7));
}
static void __a336(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p23 = 8;
    }
  __rv_min = __rv_max;

}

static int __g337(unsigned int& id, conf* current)
{
  return ((current->p23==4)&&!(((current->p22>=0)&&(current->p22<=3))||(current->p22==5)||(current->p22==7)));
}
static void __a337(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p23 = 6;
    }
  __rv_min = __rv_max;

}

static int __g338(unsigned int& id, conf* current)
{
  return ((current->p23==5)&&((current->p24>=0)&&(current->p24<=4))||(current->p24==6)||(current->p24==10));
}
static void __a338(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p23 = 8;
    }
  __rv_min = __rv_max;

}

static int __g339(unsigned int& id, conf* current)
{
  return ((current->p23==5)&&!(((current->p24>=0)&&(current->p24<=4))||(current->p24==6)||(current->p24==10)));
}
static void __a339(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p23 = 7;
    }
  __rv_min = __rv_max;

}

static int __g340(unsigned int& id, conf* current)
{
  return (current->p23==6);
}
static void __a340(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p23 = 1;
    }
  __rv_min = __rv_max;

}

static int __g341(unsigned int& id, conf* current)
{
  return (current->p23==7);
}
static void __a341(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p23 = 1;
    }
  __rv_min = __rv_max;

}

static int __g342(unsigned int& id, conf* current)
{
  return (current->p23==8);
}
static void __a342(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p23 = 9;
    }
  __rv_min = __rv_max;

}

static int __g343(unsigned int& id, conf* current)
{
  return (current->p23==9);
}
static void __a343(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p23 = 10;
    }
  __rv_min = __rv_max;

}

static int __g344(unsigned int& id, conf* current)
{
  return (current->p23==10);
}
static void __a344(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p23 = 0;
    }
  __rv_min = __rv_max;

}

static int __g345(unsigned int& id, conf* current)
{
  return (current->p24==0);
}
static void __a345(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p24 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p24 = 1;
    }
  __rv_min = __rv_max;

}

static int __g346(unsigned int& id, conf* current)
{
  return (current->p24==1);
}
static void __a346(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p24 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p24 = 3;
    }
  __rv_min = __rv_max;

}

static int __g347(unsigned int& id, conf* current)
{
  return ((current->p24==2)&&((current->p25>=0)&&(current->p25<=4))||(current->p25==6)||(current->p25==10));
}
static void __a347(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p24 = 4;
    }
  __rv_min = __rv_max;

}

static int __g348(unsigned int& id, conf* current)
{
  return ((current->p24==2)&&!(((current->p25>=0)&&(current->p25<=4))||(current->p25==6)||(current->p25==10)));
}
static void __a348(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p24 = 2;
    }
  __rv_min = __rv_max;

}

static int __g349(unsigned int& id, conf* current)
{
  return ((current->p24==3)&&((current->p23>=0)&&(current->p23<=3))||(current->p23==5)||(current->p23==7));
}
static void __a349(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p24 = 5;
    }
  __rv_min = __rv_max;

}

static int __g350(unsigned int& id, conf* current)
{
  return ((current->p24==3)&&!(((current->p23>=0)&&(current->p23<=3))||(current->p23==5)||(current->p23==7)));
}
static void __a350(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p24 = 3;
    }
  __rv_min = __rv_max;

}

static int __g351(unsigned int& id, conf* current)
{
  return ((current->p24==4)&&((current->p23>=0)&&(current->p23<=3))||(current->p23==5)||(current->p23==7));
}
static void __a351(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p24 = 8;
    }
  __rv_min = __rv_max;

}

static int __g352(unsigned int& id, conf* current)
{
  return ((current->p24==4)&&!(((current->p23>=0)&&(current->p23<=3))||(current->p23==5)||(current->p23==7)));
}
static void __a352(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p24 = 6;
    }
  __rv_min = __rv_max;

}

static int __g353(unsigned int& id, conf* current)
{
  return ((current->p24==5)&&((current->p25>=0)&&(current->p25<=4))||(current->p25==6)||(current->p25==10));
}
static void __a353(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p24 = 8;
    }
  __rv_min = __rv_max;

}

static int __g354(unsigned int& id, conf* current)
{
  return ((current->p24==5)&&!(((current->p25>=0)&&(current->p25<=4))||(current->p25==6)||(current->p25==10)));
}
static void __a354(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p24 = 7;
    }
  __rv_min = __rv_max;

}

static int __g355(unsigned int& id, conf* current)
{
  return (current->p24==6);
}
static void __a355(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p24 = 1;
    }
  __rv_min = __rv_max;

}

static int __g356(unsigned int& id, conf* current)
{
  return (current->p24==7);
}
static void __a356(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p24 = 1;
    }
  __rv_min = __rv_max;

}

static int __g357(unsigned int& id, conf* current)
{
  return (current->p24==8);
}
static void __a357(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p24 = 9;
    }
  __rv_min = __rv_max;

}

static int __g358(unsigned int& id, conf* current)
{
  return (current->p24==9);
}
static void __a358(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p24 = 10;
    }
  __rv_min = __rv_max;

}

static int __g359(unsigned int& id, conf* current)
{
  return (current->p24==10);
}
static void __a359(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p24 = 0;
    }
  __rv_min = __rv_max;

}

static int __g360(unsigned int& id, conf* current)
{
  return (current->p25==0);
}
static void __a360(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p25 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p25 = 1;
    }
  __rv_min = __rv_max;

}

static int __g361(unsigned int& id, conf* current)
{
  return (current->p25==1);
}
static void __a361(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p25 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p25 = 3;
    }
  __rv_min = __rv_max;

}

static int __g362(unsigned int& id, conf* current)
{
  return ((current->p25==2)&&((current->p26>=0)&&(current->p26<=4))||(current->p26==6)||(current->p26==10));
}
static void __a362(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p25 = 4;
    }
  __rv_min = __rv_max;

}

static int __g363(unsigned int& id, conf* current)
{
  return ((current->p25==2)&&!(((current->p26>=0)&&(current->p26<=4))||(current->p26==6)||(current->p26==10)));
}
static void __a363(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p25 = 2;
    }
  __rv_min = __rv_max;

}

static int __g364(unsigned int& id, conf* current)
{
  return ((current->p25==3)&&((current->p24>=0)&&(current->p24<=3))||(current->p24==5)||(current->p24==7));
}
static void __a364(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p25 = 5;
    }
  __rv_min = __rv_max;

}

static int __g365(unsigned int& id, conf* current)
{
  return ((current->p25==3)&&!(((current->p24>=0)&&(current->p24<=3))||(current->p24==5)||(current->p24==7)));
}
static void __a365(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p25 = 3;
    }
  __rv_min = __rv_max;

}

static int __g366(unsigned int& id, conf* current)
{
  return ((current->p25==4)&&((current->p24>=0)&&(current->p24<=3))||(current->p24==5)||(current->p24==7));
}
static void __a366(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p25 = 8;
    }
  __rv_min = __rv_max;

}

static int __g367(unsigned int& id, conf* current)
{
  return ((current->p25==4)&&!(((current->p24>=0)&&(current->p24<=3))||(current->p24==5)||(current->p24==7)));
}
static void __a367(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p25 = 6;
    }
  __rv_min = __rv_max;

}

static int __g368(unsigned int& id, conf* current)
{
  return ((current->p25==5)&&((current->p26>=0)&&(current->p26<=4))||(current->p26==6)||(current->p26==10));
}
static void __a368(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p25 = 8;
    }
  __rv_min = __rv_max;

}

static int __g369(unsigned int& id, conf* current)
{
  return ((current->p25==5)&&!(((current->p26>=0)&&(current->p26<=4))||(current->p26==6)||(current->p26==10)));
}
static void __a369(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p25 = 7;
    }
  __rv_min = __rv_max;

}

static int __g370(unsigned int& id, conf* current)
{
  return (current->p25==6);
}
static void __a370(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p25 = 1;
    }
  __rv_min = __rv_max;

}

static int __g371(unsigned int& id, conf* current)
{
  return (current->p25==7);
}
static void __a371(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p25 = 1;
    }
  __rv_min = __rv_max;

}

static int __g372(unsigned int& id, conf* current)
{
  return (current->p25==8);
}
static void __a372(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p25 = 9;
    }
  __rv_min = __rv_max;

}

static int __g373(unsigned int& id, conf* current)
{
  return (current->p25==9);
}
static void __a373(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p25 = 10;
    }
  __rv_min = __rv_max;

}

static int __g374(unsigned int& id, conf* current)
{
  return (current->p25==10);
}
static void __a374(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p25 = 0;
    }
  __rv_min = __rv_max;

}

static int __g375(unsigned int& id, conf* current)
{
  return (current->p26==0);
}
static void __a375(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p26 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p26 = 1;
    }
  __rv_min = __rv_max;

}

static int __g376(unsigned int& id, conf* current)
{
  return (current->p26==1);
}
static void __a376(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p26 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p26 = 3;
    }
  __rv_min = __rv_max;

}

static int __g377(unsigned int& id, conf* current)
{
  return ((current->p26==2)&&((current->p27>=0)&&(current->p27<=4))||(current->p27==6)||(current->p27==10));
}
static void __a377(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p26 = 4;
    }
  __rv_min = __rv_max;

}

static int __g378(unsigned int& id, conf* current)
{
  return ((current->p26==2)&&!(((current->p27>=0)&&(current->p27<=4))||(current->p27==6)||(current->p27==10)));
}
static void __a378(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p26 = 2;
    }
  __rv_min = __rv_max;

}

static int __g379(unsigned int& id, conf* current)
{
  return ((current->p26==3)&&((current->p25>=0)&&(current->p25<=3))||(current->p25==5)||(current->p25==7));
}
static void __a379(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p26 = 5;
    }
  __rv_min = __rv_max;

}

static int __g380(unsigned int& id, conf* current)
{
  return ((current->p26==3)&&!(((current->p25>=0)&&(current->p25<=3))||(current->p25==5)||(current->p25==7)));
}
static void __a380(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p26 = 3;
    }
  __rv_min = __rv_max;

}

static int __g381(unsigned int& id, conf* current)
{
  return ((current->p26==4)&&((current->p25>=0)&&(current->p25<=3))||(current->p25==5)||(current->p25==7));
}
static void __a381(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p26 = 8;
    }
  __rv_min = __rv_max;

}

static int __g382(unsigned int& id, conf* current)
{
  return ((current->p26==4)&&!(((current->p25>=0)&&(current->p25<=3))||(current->p25==5)||(current->p25==7)));
}
static void __a382(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p26 = 6;
    }
  __rv_min = __rv_max;

}

static int __g383(unsigned int& id, conf* current)
{
  return ((current->p26==5)&&((current->p27>=0)&&(current->p27<=4))||(current->p27==6)||(current->p27==10));
}
static void __a383(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p26 = 8;
    }
  __rv_min = __rv_max;

}

static int __g384(unsigned int& id, conf* current)
{
  return ((current->p26==5)&&!(((current->p27>=0)&&(current->p27<=4))||(current->p27==6)||(current->p27==10)));
}
static void __a384(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p26 = 7;
    }
  __rv_min = __rv_max;

}

static int __g385(unsigned int& id, conf* current)
{
  return (current->p26==6);
}
static void __a385(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p26 = 1;
    }
  __rv_min = __rv_max;

}

static int __g386(unsigned int& id, conf* current)
{
  return (current->p26==7);
}
static void __a386(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p26 = 1;
    }
  __rv_min = __rv_max;

}

static int __g387(unsigned int& id, conf* current)
{
  return (current->p26==8);
}
static void __a387(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p26 = 9;
    }
  __rv_min = __rv_max;

}

static int __g388(unsigned int& id, conf* current)
{
  return (current->p26==9);
}
static void __a388(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p26 = 10;
    }
  __rv_min = __rv_max;

}

static int __g389(unsigned int& id, conf* current)
{
  return (current->p26==10);
}
static void __a389(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p26 = 0;
    }
  __rv_min = __rv_max;

}

static int __g390(unsigned int& id, conf* current)
{
  return (current->p27==0);
}
static void __a390(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p27 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p27 = 1;
    }
  __rv_min = __rv_max;

}

static int __g391(unsigned int& id, conf* current)
{
  return (current->p27==1);
}
static void __a391(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p27 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p27 = 3;
    }
  __rv_min = __rv_max;

}

static int __g392(unsigned int& id, conf* current)
{
  return ((current->p27==2)&&((current->p28>=0)&&(current->p28<=4))||(current->p28==6)||(current->p28==10));
}
static void __a392(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p27 = 4;
    }
  __rv_min = __rv_max;

}

static int __g393(unsigned int& id, conf* current)
{
  return ((current->p27==2)&&!(((current->p28>=0)&&(current->p28<=4))||(current->p28==6)||(current->p28==10)));
}
static void __a393(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p27 = 2;
    }
  __rv_min = __rv_max;

}

static int __g394(unsigned int& id, conf* current)
{
  return ((current->p27==3)&&((current->p26>=0)&&(current->p26<=3))||(current->p26==5)||(current->p26==7));
}
static void __a394(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p27 = 5;
    }
  __rv_min = __rv_max;

}

static int __g395(unsigned int& id, conf* current)
{
  return ((current->p27==3)&&!(((current->p26>=0)&&(current->p26<=3))||(current->p26==5)||(current->p26==7)));
}
static void __a395(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p27 = 3;
    }
  __rv_min = __rv_max;

}

static int __g396(unsigned int& id, conf* current)
{
  return ((current->p27==4)&&((current->p26>=0)&&(current->p26<=3))||(current->p26==5)||(current->p26==7));
}
static void __a396(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p27 = 8;
    }
  __rv_min = __rv_max;

}

static int __g397(unsigned int& id, conf* current)
{
  return ((current->p27==4)&&!(((current->p26>=0)&&(current->p26<=3))||(current->p26==5)||(current->p26==7)));
}
static void __a397(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p27 = 6;
    }
  __rv_min = __rv_max;

}

static int __g398(unsigned int& id, conf* current)
{
  return ((current->p27==5)&&((current->p28>=0)&&(current->p28<=4))||(current->p28==6)||(current->p28==10));
}
static void __a398(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p27 = 8;
    }
  __rv_min = __rv_max;

}

static int __g399(unsigned int& id, conf* current)
{
  return ((current->p27==5)&&!(((current->p28>=0)&&(current->p28<=4))||(current->p28==6)||(current->p28==10)));
}
static void __a399(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p27 = 7;
    }
  __rv_min = __rv_max;

}

static int __g400(unsigned int& id, conf* current)
{
  return (current->p27==6);
}
static void __a400(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p27 = 1;
    }
  __rv_min = __rv_max;

}

static int __g401(unsigned int& id, conf* current)
{
  return (current->p27==7);
}
static void __a401(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p27 = 1;
    }
  __rv_min = __rv_max;

}

static int __g402(unsigned int& id, conf* current)
{
  return (current->p27==8);
}
static void __a402(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p27 = 9;
    }
  __rv_min = __rv_max;

}

static int __g403(unsigned int& id, conf* current)
{
  return (current->p27==9);
}
static void __a403(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p27 = 10;
    }
  __rv_min = __rv_max;

}

static int __g404(unsigned int& id, conf* current)
{
  return (current->p27==10);
}
static void __a404(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p27 = 0;
    }
  __rv_min = __rv_max;

}

static int __g405(unsigned int& id, conf* current)
{
  return (current->p28==0);
}
static void __a405(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p28 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p28 = 1;
    }
  __rv_min = __rv_max;

}

static int __g406(unsigned int& id, conf* current)
{
  return (current->p28==1);
}
static void __a406(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p28 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p28 = 3;
    }
  __rv_min = __rv_max;

}

static int __g407(unsigned int& id, conf* current)
{
  return ((current->p28==2)&&((current->p29>=0)&&(current->p29<=4))||(current->p29==6)||(current->p29==10));
}
static void __a407(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p28 = 4;
    }
  __rv_min = __rv_max;

}

static int __g408(unsigned int& id, conf* current)
{
  return ((current->p28==2)&&!(((current->p29>=0)&&(current->p29<=4))||(current->p29==6)||(current->p29==10)));
}
static void __a408(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p28 = 2;
    }
  __rv_min = __rv_max;

}

static int __g409(unsigned int& id, conf* current)
{
  return ((current->p28==3)&&((current->p27>=0)&&(current->p27<=3))||(current->p27==5)||(current->p27==7));
}
static void __a409(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p28 = 5;
    }
  __rv_min = __rv_max;

}

static int __g410(unsigned int& id, conf* current)
{
  return ((current->p28==3)&&!(((current->p27>=0)&&(current->p27<=3))||(current->p27==5)||(current->p27==7)));
}
static void __a410(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p28 = 3;
    }
  __rv_min = __rv_max;

}

static int __g411(unsigned int& id, conf* current)
{
  return ((current->p28==4)&&((current->p27>=0)&&(current->p27<=3))||(current->p27==5)||(current->p27==7));
}
static void __a411(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p28 = 8;
    }
  __rv_min = __rv_max;

}

static int __g412(unsigned int& id, conf* current)
{
  return ((current->p28==4)&&!(((current->p27>=0)&&(current->p27<=3))||(current->p27==5)||(current->p27==7)));
}
static void __a412(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p28 = 6;
    }
  __rv_min = __rv_max;

}

static int __g413(unsigned int& id, conf* current)
{
  return ((current->p28==5)&&((current->p29>=0)&&(current->p29<=4))||(current->p29==6)||(current->p29==10));
}
static void __a413(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p28 = 8;
    }
  __rv_min = __rv_max;

}

static int __g414(unsigned int& id, conf* current)
{
  return ((current->p28==5)&&!(((current->p29>=0)&&(current->p29<=4))||(current->p29==6)||(current->p29==10)));
}
static void __a414(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p28 = 7;
    }
  __rv_min = __rv_max;

}

static int __g415(unsigned int& id, conf* current)
{
  return (current->p28==6);
}
static void __a415(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p28 = 1;
    }
  __rv_min = __rv_max;

}

static int __g416(unsigned int& id, conf* current)
{
  return (current->p28==7);
}
static void __a416(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p28 = 1;
    }
  __rv_min = __rv_max;

}

static int __g417(unsigned int& id, conf* current)
{
  return (current->p28==8);
}
static void __a417(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p28 = 9;
    }
  __rv_min = __rv_max;

}

static int __g418(unsigned int& id, conf* current)
{
  return (current->p28==9);
}
static void __a418(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p28 = 10;
    }
  __rv_min = __rv_max;

}

static int __g419(unsigned int& id, conf* current)
{
  return (current->p28==10);
}
static void __a419(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p28 = 0;
    }
  __rv_min = __rv_max;

}

static int __g420(unsigned int& id, conf* current)
{
  return (current->p29==0);
}
static void __a420(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p29 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p29 = 1;
    }
  __rv_min = __rv_max;

}

static int __g421(unsigned int& id, conf* current)
{
  return (current->p29==1);
}
static void __a421(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p29 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p29 = 3;
    }
  __rv_min = __rv_max;

}

static int __g422(unsigned int& id, conf* current)
{
  return ((current->p29==2)&&((current->p30>=0)&&(current->p30<=4))||(current->p30==6)||(current->p30==10));
}
static void __a422(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p29 = 4;
    }
  __rv_min = __rv_max;

}

static int __g423(unsigned int& id, conf* current)
{
  return ((current->p29==2)&&!(((current->p30>=0)&&(current->p30<=4))||(current->p30==6)||(current->p30==10)));
}
static void __a423(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p29 = 2;
    }
  __rv_min = __rv_max;

}

static int __g424(unsigned int& id, conf* current)
{
  return ((current->p29==3)&&((current->p28>=0)&&(current->p28<=3))||(current->p28==5)||(current->p28==7));
}
static void __a424(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p29 = 5;
    }
  __rv_min = __rv_max;

}

static int __g425(unsigned int& id, conf* current)
{
  return ((current->p29==3)&&!(((current->p28>=0)&&(current->p28<=3))||(current->p28==5)||(current->p28==7)));
}
static void __a425(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p29 = 3;
    }
  __rv_min = __rv_max;

}

static int __g426(unsigned int& id, conf* current)
{
  return ((current->p29==4)&&((current->p28>=0)&&(current->p28<=3))||(current->p28==5)||(current->p28==7));
}
static void __a426(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p29 = 8;
    }
  __rv_min = __rv_max;

}

static int __g427(unsigned int& id, conf* current)
{
  return ((current->p29==4)&&!(((current->p28>=0)&&(current->p28<=3))||(current->p28==5)||(current->p28==7)));
}
static void __a427(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p29 = 6;
    }
  __rv_min = __rv_max;

}

static int __g428(unsigned int& id, conf* current)
{
  return ((current->p29==5)&&((current->p30>=0)&&(current->p30<=4))||(current->p30==6)||(current->p30==10));
}
static void __a428(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p29 = 8;
    }
  __rv_min = __rv_max;

}

static int __g429(unsigned int& id, conf* current)
{
  return ((current->p29==5)&&!(((current->p30>=0)&&(current->p30<=4))||(current->p30==6)||(current->p30==10)));
}
static void __a429(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p29 = 7;
    }
  __rv_min = __rv_max;

}

static int __g430(unsigned int& id, conf* current)
{
  return (current->p29==6);
}
static void __a430(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p29 = 1;
    }
  __rv_min = __rv_max;

}

static int __g431(unsigned int& id, conf* current)
{
  return (current->p29==7);
}
static void __a431(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p29 = 1;
    }
  __rv_min = __rv_max;

}

static int __g432(unsigned int& id, conf* current)
{
  return (current->p29==8);
}
static void __a432(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p29 = 9;
    }
  __rv_min = __rv_max;

}

static int __g433(unsigned int& id, conf* current)
{
  return (current->p29==9);
}
static void __a433(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p29 = 10;
    }
  __rv_min = __rv_max;

}

static int __g434(unsigned int& id, conf* current)
{
  return (current->p29==10);
}
static void __a434(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p29 = 0;
    }
  __rv_min = __rv_max;

}

static int __g435(unsigned int& id, conf* current)
{
  return (current->p30==0);
}
static void __a435(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p30 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p30 = 1;
    }
  __rv_min = __rv_max;

}

static int __g436(unsigned int& id, conf* current)
{
  return (current->p30==1);
}
static void __a436(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p30 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p30 = 3;
    }
  __rv_min = __rv_max;

}

static int __g437(unsigned int& id, conf* current)
{
  return ((current->p30==2)&&((current->p31>=0)&&(current->p31<=4))||(current->p31==6)||(current->p31==10));
}
static void __a437(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p30 = 4;
    }
  __rv_min = __rv_max;

}

static int __g438(unsigned int& id, conf* current)
{
  return ((current->p30==2)&&!(((current->p31>=0)&&(current->p31<=4))||(current->p31==6)||(current->p31==10)));
}
static void __a438(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p30 = 2;
    }
  __rv_min = __rv_max;

}

static int __g439(unsigned int& id, conf* current)
{
  return ((current->p30==3)&&((current->p29>=0)&&(current->p29<=3))||(current->p29==5)||(current->p29==7));
}
static void __a439(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p30 = 5;
    }
  __rv_min = __rv_max;

}

static int __g440(unsigned int& id, conf* current)
{
  return ((current->p30==3)&&!(((current->p29>=0)&&(current->p29<=3))||(current->p29==5)||(current->p29==7)));
}
static void __a440(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p30 = 3;
    }
  __rv_min = __rv_max;

}

static int __g441(unsigned int& id, conf* current)
{
  return ((current->p30==4)&&((current->p29>=0)&&(current->p29<=3))||(current->p29==5)||(current->p29==7));
}
static void __a441(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p30 = 8;
    }
  __rv_min = __rv_max;

}

static int __g442(unsigned int& id, conf* current)
{
  return ((current->p30==4)&&!(((current->p29>=0)&&(current->p29<=3))||(current->p29==5)||(current->p29==7)));
}
static void __a442(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p30 = 6;
    }
  __rv_min = __rv_max;

}

static int __g443(unsigned int& id, conf* current)
{
  return ((current->p30==5)&&((current->p31>=0)&&(current->p31<=4))||(current->p31==6)||(current->p31==10));
}
static void __a443(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p30 = 8;
    }
  __rv_min = __rv_max;

}

static int __g444(unsigned int& id, conf* current)
{
  return ((current->p30==5)&&!(((current->p31>=0)&&(current->p31<=4))||(current->p31==6)||(current->p31==10)));
}
static void __a444(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p30 = 7;
    }
  __rv_min = __rv_max;

}

static int __g445(unsigned int& id, conf* current)
{
  return (current->p30==6);
}
static void __a445(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p30 = 1;
    }
  __rv_min = __rv_max;

}

static int __g446(unsigned int& id, conf* current)
{
  return (current->p30==7);
}
static void __a446(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p30 = 1;
    }
  __rv_min = __rv_max;

}

static int __g447(unsigned int& id, conf* current)
{
  return (current->p30==8);
}
static void __a447(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p30 = 9;
    }
  __rv_min = __rv_max;

}

static int __g448(unsigned int& id, conf* current)
{
  return (current->p30==9);
}
static void __a448(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p30 = 10;
    }
  __rv_min = __rv_max;

}

static int __g449(unsigned int& id, conf* current)
{
  return (current->p30==10);
}
static void __a449(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p30 = 0;
    }
  __rv_min = __rv_max;

}

static int __g450(unsigned int& id, conf* current)
{
  return (current->p31==0);
}
static void __a450(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p31 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p31 = 1;
    }
  __rv_min = __rv_max;

}

static int __g451(unsigned int& id, conf* current)
{
  return (current->p31==1);
}
static void __a451(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p31 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p31 = 3;
    }
  __rv_min = __rv_max;

}

static int __g452(unsigned int& id, conf* current)
{
  return ((current->p31==2)&&((current->p32>=0)&&(current->p32<=4))||(current->p32==6)||(current->p32==10));
}
static void __a452(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p31 = 4;
    }
  __rv_min = __rv_max;

}

static int __g453(unsigned int& id, conf* current)
{
  return ((current->p31==2)&&!(((current->p32>=0)&&(current->p32<=4))||(current->p32==6)||(current->p32==10)));
}
static void __a453(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p31 = 2;
    }
  __rv_min = __rv_max;

}

static int __g454(unsigned int& id, conf* current)
{
  return ((current->p31==3)&&((current->p30>=0)&&(current->p30<=3))||(current->p30==5)||(current->p30==7));
}
static void __a454(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p31 = 5;
    }
  __rv_min = __rv_max;

}

static int __g455(unsigned int& id, conf* current)
{
  return ((current->p31==3)&&!(((current->p30>=0)&&(current->p30<=3))||(current->p30==5)||(current->p30==7)));
}
static void __a455(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p31 = 3;
    }
  __rv_min = __rv_max;

}

static int __g456(unsigned int& id, conf* current)
{
  return ((current->p31==4)&&((current->p30>=0)&&(current->p30<=3))||(current->p30==5)||(current->p30==7));
}
static void __a456(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p31 = 8;
    }
  __rv_min = __rv_max;

}

static int __g457(unsigned int& id, conf* current)
{
  return ((current->p31==4)&&!(((current->p30>=0)&&(current->p30<=3))||(current->p30==5)||(current->p30==7)));
}
static void __a457(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p31 = 6;
    }
  __rv_min = __rv_max;

}

static int __g458(unsigned int& id, conf* current)
{
  return ((current->p31==5)&&((current->p32>=0)&&(current->p32<=4))||(current->p32==6)||(current->p32==10));
}
static void __a458(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p31 = 8;
    }
  __rv_min = __rv_max;

}

static int __g459(unsigned int& id, conf* current)
{
  return ((current->p31==5)&&!(((current->p32>=0)&&(current->p32<=4))||(current->p32==6)||(current->p32==10)));
}
static void __a459(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p31 = 7;
    }
  __rv_min = __rv_max;

}

static int __g460(unsigned int& id, conf* current)
{
  return (current->p31==6);
}
static void __a460(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p31 = 1;
    }
  __rv_min = __rv_max;

}

static int __g461(unsigned int& id, conf* current)
{
  return (current->p31==7);
}
static void __a461(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p31 = 1;
    }
  __rv_min = __rv_max;

}

static int __g462(unsigned int& id, conf* current)
{
  return (current->p31==8);
}
static void __a462(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p31 = 9;
    }
  __rv_min = __rv_max;

}

static int __g463(unsigned int& id, conf* current)
{
  return (current->p31==9);
}
static void __a463(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p31 = 10;
    }
  __rv_min = __rv_max;

}

static int __g464(unsigned int& id, conf* current)
{
  return (current->p31==10);
}
static void __a464(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p31 = 0;
    }
  __rv_min = __rv_max;

}

static int __g465(unsigned int& id, conf* current)
{
  return (current->p32==0);
}
static void __a465(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p32 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p32 = 1;
    }
  __rv_min = __rv_max;

}

static int __g466(unsigned int& id, conf* current)
{
  return (current->p32==1);
}
static void __a466(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p32 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p32 = 3;
    }
  __rv_min = __rv_max;

}

static int __g467(unsigned int& id, conf* current)
{
  return ((current->p32==2)&&((current->p33>=0)&&(current->p33<=4))||(current->p33==6)||(current->p33==10));
}
static void __a467(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p32 = 4;
    }
  __rv_min = __rv_max;

}

static int __g468(unsigned int& id, conf* current)
{
  return ((current->p32==2)&&!(((current->p33>=0)&&(current->p33<=4))||(current->p33==6)||(current->p33==10)));
}
static void __a468(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p32 = 2;
    }
  __rv_min = __rv_max;

}

static int __g469(unsigned int& id, conf* current)
{
  return ((current->p32==3)&&((current->p31>=0)&&(current->p31<=3))||(current->p31==5)||(current->p31==7));
}
static void __a469(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p32 = 5;
    }
  __rv_min = __rv_max;

}

static int __g470(unsigned int& id, conf* current)
{
  return ((current->p32==3)&&!(((current->p31>=0)&&(current->p31<=3))||(current->p31==5)||(current->p31==7)));
}
static void __a470(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p32 = 3;
    }
  __rv_min = __rv_max;

}

static int __g471(unsigned int& id, conf* current)
{
  return ((current->p32==4)&&((current->p31>=0)&&(current->p31<=3))||(current->p31==5)||(current->p31==7));
}
static void __a471(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p32 = 8;
    }
  __rv_min = __rv_max;

}

static int __g472(unsigned int& id, conf* current)
{
  return ((current->p32==4)&&!(((current->p31>=0)&&(current->p31<=3))||(current->p31==5)||(current->p31==7)));
}
static void __a472(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p32 = 6;
    }
  __rv_min = __rv_max;

}

static int __g473(unsigned int& id, conf* current)
{
  return ((current->p32==5)&&((current->p33>=0)&&(current->p33<=4))||(current->p33==6)||(current->p33==10));
}
static void __a473(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p32 = 8;
    }
  __rv_min = __rv_max;

}

static int __g474(unsigned int& id, conf* current)
{
  return ((current->p32==5)&&!(((current->p33>=0)&&(current->p33<=4))||(current->p33==6)||(current->p33==10)));
}
static void __a474(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p32 = 7;
    }
  __rv_min = __rv_max;

}

static int __g475(unsigned int& id, conf* current)
{
  return (current->p32==6);
}
static void __a475(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p32 = 1;
    }
  __rv_min = __rv_max;

}

static int __g476(unsigned int& id, conf* current)
{
  return (current->p32==7);
}
static void __a476(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p32 = 1;
    }
  __rv_min = __rv_max;

}

static int __g477(unsigned int& id, conf* current)
{
  return (current->p32==8);
}
static void __a477(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p32 = 9;
    }
  __rv_min = __rv_max;

}

static int __g478(unsigned int& id, conf* current)
{
  return (current->p32==9);
}
static void __a478(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p32 = 10;
    }
  __rv_min = __rv_max;

}

static int __g479(unsigned int& id, conf* current)
{
  return (current->p32==10);
}
static void __a479(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p32 = 0;
    }
  __rv_min = __rv_max;

}

static int __g480(unsigned int& id, conf* current)
{
  return (current->p33==0);
}
static void __a480(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p33 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p33 = 1;
    }
  __rv_min = __rv_max;

}

static int __g481(unsigned int& id, conf* current)
{
  return (current->p33==1);
}
static void __a481(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p33 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p33 = 3;
    }
  __rv_min = __rv_max;

}

static int __g482(unsigned int& id, conf* current)
{
  return ((current->p33==2)&&((current->p34>=0)&&(current->p34<=4))||(current->p34==6)||(current->p34==10));
}
static void __a482(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p33 = 4;
    }
  __rv_min = __rv_max;

}

static int __g483(unsigned int& id, conf* current)
{
  return ((current->p33==2)&&!(((current->p34>=0)&&(current->p34<=4))||(current->p34==6)||(current->p34==10)));
}
static void __a483(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p33 = 2;
    }
  __rv_min = __rv_max;

}

static int __g484(unsigned int& id, conf* current)
{
  return ((current->p33==3)&&((current->p32>=0)&&(current->p32<=3))||(current->p32==5)||(current->p32==7));
}
static void __a484(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p33 = 5;
    }
  __rv_min = __rv_max;

}

static int __g485(unsigned int& id, conf* current)
{
  return ((current->p33==3)&&!(((current->p32>=0)&&(current->p32<=3))||(current->p32==5)||(current->p32==7)));
}
static void __a485(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p33 = 3;
    }
  __rv_min = __rv_max;

}

static int __g486(unsigned int& id, conf* current)
{
  return ((current->p33==4)&&((current->p32>=0)&&(current->p32<=3))||(current->p32==5)||(current->p32==7));
}
static void __a486(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p33 = 8;
    }
  __rv_min = __rv_max;

}

static int __g487(unsigned int& id, conf* current)
{
  return ((current->p33==4)&&!(((current->p32>=0)&&(current->p32<=3))||(current->p32==5)||(current->p32==7)));
}
static void __a487(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p33 = 6;
    }
  __rv_min = __rv_max;

}

static int __g488(unsigned int& id, conf* current)
{
  return ((current->p33==5)&&((current->p34>=0)&&(current->p34<=4))||(current->p34==6)||(current->p34==10));
}
static void __a488(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p33 = 8;
    }
  __rv_min = __rv_max;

}

static int __g489(unsigned int& id, conf* current)
{
  return ((current->p33==5)&&!(((current->p34>=0)&&(current->p34<=4))||(current->p34==6)||(current->p34==10)));
}
static void __a489(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p33 = 7;
    }
  __rv_min = __rv_max;

}

static int __g490(unsigned int& id, conf* current)
{
  return (current->p33==6);
}
static void __a490(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p33 = 1;
    }
  __rv_min = __rv_max;

}

static int __g491(unsigned int& id, conf* current)
{
  return (current->p33==7);
}
static void __a491(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p33 = 1;
    }
  __rv_min = __rv_max;

}

static int __g492(unsigned int& id, conf* current)
{
  return (current->p33==8);
}
static void __a492(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p33 = 9;
    }
  __rv_min = __rv_max;

}

static int __g493(unsigned int& id, conf* current)
{
  return (current->p33==9);
}
static void __a493(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p33 = 10;
    }
  __rv_min = __rv_max;

}

static int __g494(unsigned int& id, conf* current)
{
  return (current->p33==10);
}
static void __a494(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p33 = 0;
    }
  __rv_min = __rv_max;

}

static int __g495(unsigned int& id, conf* current)
{
  return (current->p34==0);
}
static void __a495(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p34 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p34 = 1;
    }
  __rv_min = __rv_max;

}

static int __g496(unsigned int& id, conf* current)
{
  return (current->p34==1);
}
static void __a496(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p34 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p34 = 3;
    }
  __rv_min = __rv_max;

}

static int __g497(unsigned int& id, conf* current)
{
  return ((current->p34==2)&&((current->p35>=0)&&(current->p35<=4))||(current->p35==6)||(current->p35==10));
}
static void __a497(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p34 = 4;
    }
  __rv_min = __rv_max;

}

static int __g498(unsigned int& id, conf* current)
{
  return ((current->p34==2)&&!(((current->p35>=0)&&(current->p35<=4))||(current->p35==6)||(current->p35==10)));
}
static void __a498(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p34 = 2;
    }
  __rv_min = __rv_max;

}

static int __g499(unsigned int& id, conf* current)
{
  return ((current->p34==3)&&((current->p33>=0)&&(current->p33<=3))||(current->p33==5)||(current->p33==7));
}
static void __a499(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p34 = 5;
    }
  __rv_min = __rv_max;

}

static int __g500(unsigned int& id, conf* current)
{
  return ((current->p34==3)&&!(((current->p33>=0)&&(current->p33<=3))||(current->p33==5)||(current->p33==7)));
}
static void __a500(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p34 = 3;
    }
  __rv_min = __rv_max;

}

static int __g501(unsigned int& id, conf* current)
{
  return ((current->p34==4)&&((current->p33>=0)&&(current->p33<=3))||(current->p33==5)||(current->p33==7));
}
static void __a501(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p34 = 8;
    }
  __rv_min = __rv_max;

}

static int __g502(unsigned int& id, conf* current)
{
  return ((current->p34==4)&&!(((current->p33>=0)&&(current->p33<=3))||(current->p33==5)||(current->p33==7)));
}
static void __a502(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p34 = 6;
    }
  __rv_min = __rv_max;

}

static int __g503(unsigned int& id, conf* current)
{
  return ((current->p34==5)&&((current->p35>=0)&&(current->p35<=4))||(current->p35==6)||(current->p35==10));
}
static void __a503(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p34 = 8;
    }
  __rv_min = __rv_max;

}

static int __g504(unsigned int& id, conf* current)
{
  return ((current->p34==5)&&!(((current->p35>=0)&&(current->p35<=4))||(current->p35==6)||(current->p35==10)));
}
static void __a504(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p34 = 7;
    }
  __rv_min = __rv_max;

}

static int __g505(unsigned int& id, conf* current)
{
  return (current->p34==6);
}
static void __a505(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p34 = 1;
    }
  __rv_min = __rv_max;

}

static int __g506(unsigned int& id, conf* current)
{
  return (current->p34==7);
}
static void __a506(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p34 = 1;
    }
  __rv_min = __rv_max;

}

static int __g507(unsigned int& id, conf* current)
{
  return (current->p34==8);
}
static void __a507(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p34 = 9;
    }
  __rv_min = __rv_max;

}

static int __g508(unsigned int& id, conf* current)
{
  return (current->p34==9);
}
static void __a508(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p34 = 10;
    }
  __rv_min = __rv_max;

}

static int __g509(unsigned int& id, conf* current)
{
  return (current->p34==10);
}
static void __a509(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p34 = 0;
    }
  __rv_min = __rv_max;

}

static int __g510(unsigned int& id, conf* current)
{
  return (current->p35==0);
}
static void __a510(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p35 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p35 = 1;
    }
  __rv_min = __rv_max;

}

static int __g511(unsigned int& id, conf* current)
{
  return (current->p35==1);
}
static void __a511(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p35 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p35 = 3;
    }
  __rv_min = __rv_max;

}

static int __g512(unsigned int& id, conf* current)
{
  return ((current->p35==2)&&((current->p36>=0)&&(current->p36<=4))||(current->p36==6)||(current->p36==10));
}
static void __a512(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p35 = 4;
    }
  __rv_min = __rv_max;

}

static int __g513(unsigned int& id, conf* current)
{
  return ((current->p35==2)&&!(((current->p36>=0)&&(current->p36<=4))||(current->p36==6)||(current->p36==10)));
}
static void __a513(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p35 = 2;
    }
  __rv_min = __rv_max;

}

static int __g514(unsigned int& id, conf* current)
{
  return ((current->p35==3)&&((current->p34>=0)&&(current->p34<=3))||(current->p34==5)||(current->p34==7));
}
static void __a514(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p35 = 5;
    }
  __rv_min = __rv_max;

}

static int __g515(unsigned int& id, conf* current)
{
  return ((current->p35==3)&&!(((current->p34>=0)&&(current->p34<=3))||(current->p34==5)||(current->p34==7)));
}
static void __a515(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p35 = 3;
    }
  __rv_min = __rv_max;

}

static int __g516(unsigned int& id, conf* current)
{
  return ((current->p35==4)&&((current->p34>=0)&&(current->p34<=3))||(current->p34==5)||(current->p34==7));
}
static void __a516(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p35 = 8;
    }
  __rv_min = __rv_max;

}

static int __g517(unsigned int& id, conf* current)
{
  return ((current->p35==4)&&!(((current->p34>=0)&&(current->p34<=3))||(current->p34==5)||(current->p34==7)));
}
static void __a517(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p35 = 6;
    }
  __rv_min = __rv_max;

}

static int __g518(unsigned int& id, conf* current)
{
  return ((current->p35==5)&&((current->p36>=0)&&(current->p36<=4))||(current->p36==6)||(current->p36==10));
}
static void __a518(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p35 = 8;
    }
  __rv_min = __rv_max;

}

static int __g519(unsigned int& id, conf* current)
{
  return ((current->p35==5)&&!(((current->p36>=0)&&(current->p36<=4))||(current->p36==6)||(current->p36==10)));
}
static void __a519(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p35 = 7;
    }
  __rv_min = __rv_max;

}

static int __g520(unsigned int& id, conf* current)
{
  return (current->p35==6);
}
static void __a520(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p35 = 1;
    }
  __rv_min = __rv_max;

}

static int __g521(unsigned int& id, conf* current)
{
  return (current->p35==7);
}
static void __a521(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p35 = 1;
    }
  __rv_min = __rv_max;

}

static int __g522(unsigned int& id, conf* current)
{
  return (current->p35==8);
}
static void __a522(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p35 = 9;
    }
  __rv_min = __rv_max;

}

static int __g523(unsigned int& id, conf* current)
{
  return (current->p35==9);
}
static void __a523(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p35 = 10;
    }
  __rv_min = __rv_max;

}

static int __g524(unsigned int& id, conf* current)
{
  return (current->p35==10);
}
static void __a524(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p35 = 0;
    }
  __rv_min = __rv_max;

}

static int __g525(unsigned int& id, conf* current)
{
  return (current->p36==0);
}
static void __a525(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p36 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p36 = 1;
    }
  __rv_min = __rv_max;

}

static int __g526(unsigned int& id, conf* current)
{
  return (current->p36==1);
}
static void __a526(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p36 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p36 = 3;
    }
  __rv_min = __rv_max;

}

static int __g527(unsigned int& id, conf* current)
{
  return ((current->p36==2)&&((current->p37>=0)&&(current->p37<=4))||(current->p37==6)||(current->p37==10));
}
static void __a527(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p36 = 4;
    }
  __rv_min = __rv_max;

}

static int __g528(unsigned int& id, conf* current)
{
  return ((current->p36==2)&&!(((current->p37>=0)&&(current->p37<=4))||(current->p37==6)||(current->p37==10)));
}
static void __a528(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p36 = 2;
    }
  __rv_min = __rv_max;

}

static int __g529(unsigned int& id, conf* current)
{
  return ((current->p36==3)&&((current->p35>=0)&&(current->p35<=3))||(current->p35==5)||(current->p35==7));
}
static void __a529(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p36 = 5;
    }
  __rv_min = __rv_max;

}

static int __g530(unsigned int& id, conf* current)
{
  return ((current->p36==3)&&!(((current->p35>=0)&&(current->p35<=3))||(current->p35==5)||(current->p35==7)));
}
static void __a530(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p36 = 3;
    }
  __rv_min = __rv_max;

}

static int __g531(unsigned int& id, conf* current)
{
  return ((current->p36==4)&&((current->p35>=0)&&(current->p35<=3))||(current->p35==5)||(current->p35==7));
}
static void __a531(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p36 = 8;
    }
  __rv_min = __rv_max;

}

static int __g532(unsigned int& id, conf* current)
{
  return ((current->p36==4)&&!(((current->p35>=0)&&(current->p35<=3))||(current->p35==5)||(current->p35==7)));
}
static void __a532(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p36 = 6;
    }
  __rv_min = __rv_max;

}

static int __g533(unsigned int& id, conf* current)
{
  return ((current->p36==5)&&((current->p37>=0)&&(current->p37<=4))||(current->p37==6)||(current->p37==10));
}
static void __a533(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p36 = 8;
    }
  __rv_min = __rv_max;

}

static int __g534(unsigned int& id, conf* current)
{
  return ((current->p36==5)&&!(((current->p37>=0)&&(current->p37<=4))||(current->p37==6)||(current->p37==10)));
}
static void __a534(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p36 = 7;
    }
  __rv_min = __rv_max;

}

static int __g535(unsigned int& id, conf* current)
{
  return (current->p36==6);
}
static void __a535(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p36 = 1;
    }
  __rv_min = __rv_max;

}

static int __g536(unsigned int& id, conf* current)
{
  return (current->p36==7);
}
static void __a536(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p36 = 1;
    }
  __rv_min = __rv_max;

}

static int __g537(unsigned int& id, conf* current)
{
  return (current->p36==8);
}
static void __a537(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p36 = 9;
    }
  __rv_min = __rv_max;

}

static int __g538(unsigned int& id, conf* current)
{
  return (current->p36==9);
}
static void __a538(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p36 = 10;
    }
  __rv_min = __rv_max;

}

static int __g539(unsigned int& id, conf* current)
{
  return (current->p36==10);
}
static void __a539(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p36 = 0;
    }
  __rv_min = __rv_max;

}

static int __g540(unsigned int& id, conf* current)
{
  return (current->p37==0);
}
static void __a540(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p37 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p37 = 1;
    }
  __rv_min = __rv_max;

}

static int __g541(unsigned int& id, conf* current)
{
  return (current->p37==1);
}
static void __a541(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p37 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p37 = 3;
    }
  __rv_min = __rv_max;

}

static int __g542(unsigned int& id, conf* current)
{
  return ((current->p37==2)&&((current->p38>=0)&&(current->p38<=4))||(current->p38==6)||(current->p38==10));
}
static void __a542(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p37 = 4;
    }
  __rv_min = __rv_max;

}

static int __g543(unsigned int& id, conf* current)
{
  return ((current->p37==2)&&!(((current->p38>=0)&&(current->p38<=4))||(current->p38==6)||(current->p38==10)));
}
static void __a543(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p37 = 2;
    }
  __rv_min = __rv_max;

}

static int __g544(unsigned int& id, conf* current)
{
  return ((current->p37==3)&&((current->p36>=0)&&(current->p36<=3))||(current->p36==5)||(current->p36==7));
}
static void __a544(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p37 = 5;
    }
  __rv_min = __rv_max;

}

static int __g545(unsigned int& id, conf* current)
{
  return ((current->p37==3)&&!(((current->p36>=0)&&(current->p36<=3))||(current->p36==5)||(current->p36==7)));
}
static void __a545(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p37 = 3;
    }
  __rv_min = __rv_max;

}

static int __g546(unsigned int& id, conf* current)
{
  return ((current->p37==4)&&((current->p36>=0)&&(current->p36<=3))||(current->p36==5)||(current->p36==7));
}
static void __a546(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p37 = 8;
    }
  __rv_min = __rv_max;

}

static int __g547(unsigned int& id, conf* current)
{
  return ((current->p37==4)&&!(((current->p36>=0)&&(current->p36<=3))||(current->p36==5)||(current->p36==7)));
}
static void __a547(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p37 = 6;
    }
  __rv_min = __rv_max;

}

static int __g548(unsigned int& id, conf* current)
{
  return ((current->p37==5)&&((current->p38>=0)&&(current->p38<=4))||(current->p38==6)||(current->p38==10));
}
static void __a548(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p37 = 8;
    }
  __rv_min = __rv_max;

}

static int __g549(unsigned int& id, conf* current)
{
  return ((current->p37==5)&&!(((current->p38>=0)&&(current->p38<=4))||(current->p38==6)||(current->p38==10)));
}
static void __a549(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p37 = 7;
    }
  __rv_min = __rv_max;

}

static int __g550(unsigned int& id, conf* current)
{
  return (current->p37==6);
}
static void __a550(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p37 = 1;
    }
  __rv_min = __rv_max;

}

static int __g551(unsigned int& id, conf* current)
{
  return (current->p37==7);
}
static void __a551(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p37 = 1;
    }
  __rv_min = __rv_max;

}

static int __g552(unsigned int& id, conf* current)
{
  return (current->p37==8);
}
static void __a552(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p37 = 9;
    }
  __rv_min = __rv_max;

}

static int __g553(unsigned int& id, conf* current)
{
  return (current->p37==9);
}
static void __a553(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p37 = 10;
    }
  __rv_min = __rv_max;

}

static int __g554(unsigned int& id, conf* current)
{
  return (current->p37==10);
}
static void __a554(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p37 = 0;
    }
  __rv_min = __rv_max;

}

static int __g555(unsigned int& id, conf* current)
{
  return (current->p38==0);
}
static void __a555(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p38 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p38 = 1;
    }
  __rv_min = __rv_max;

}

static int __g556(unsigned int& id, conf* current)
{
  return (current->p38==1);
}
static void __a556(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p38 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p38 = 3;
    }
  __rv_min = __rv_max;

}

static int __g557(unsigned int& id, conf* current)
{
  return ((current->p38==2)&&((current->p39>=0)&&(current->p39<=4))||(current->p39==6)||(current->p39==10));
}
static void __a557(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p38 = 4;
    }
  __rv_min = __rv_max;

}

static int __g558(unsigned int& id, conf* current)
{
  return ((current->p38==2)&&!(((current->p39>=0)&&(current->p39<=4))||(current->p39==6)||(current->p39==10)));
}
static void __a558(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p38 = 2;
    }
  __rv_min = __rv_max;

}

static int __g559(unsigned int& id, conf* current)
{
  return ((current->p38==3)&&((current->p37>=0)&&(current->p37<=3))||(current->p37==5)||(current->p37==7));
}
static void __a559(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p38 = 5;
    }
  __rv_min = __rv_max;

}

static int __g560(unsigned int& id, conf* current)
{
  return ((current->p38==3)&&!(((current->p37>=0)&&(current->p37<=3))||(current->p37==5)||(current->p37==7)));
}
static void __a560(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p38 = 3;
    }
  __rv_min = __rv_max;

}

static int __g561(unsigned int& id, conf* current)
{
  return ((current->p38==4)&&((current->p37>=0)&&(current->p37<=3))||(current->p37==5)||(current->p37==7));
}
static void __a561(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p38 = 8;
    }
  __rv_min = __rv_max;

}

static int __g562(unsigned int& id, conf* current)
{
  return ((current->p38==4)&&!(((current->p37>=0)&&(current->p37<=3))||(current->p37==5)||(current->p37==7)));
}
static void __a562(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p38 = 6;
    }
  __rv_min = __rv_max;

}

static int __g563(unsigned int& id, conf* current)
{
  return ((current->p38==5)&&((current->p39>=0)&&(current->p39<=4))||(current->p39==6)||(current->p39==10));
}
static void __a563(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p38 = 8;
    }
  __rv_min = __rv_max;

}

static int __g564(unsigned int& id, conf* current)
{
  return ((current->p38==5)&&!(((current->p39>=0)&&(current->p39<=4))||(current->p39==6)||(current->p39==10)));
}
static void __a564(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p38 = 7;
    }
  __rv_min = __rv_max;

}

static int __g565(unsigned int& id, conf* current)
{
  return (current->p38==6);
}
static void __a565(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p38 = 1;
    }
  __rv_min = __rv_max;

}

static int __g566(unsigned int& id, conf* current)
{
  return (current->p38==7);
}
static void __a566(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p38 = 1;
    }
  __rv_min = __rv_max;

}

static int __g567(unsigned int& id, conf* current)
{
  return (current->p38==8);
}
static void __a567(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p38 = 9;
    }
  __rv_min = __rv_max;

}

static int __g568(unsigned int& id, conf* current)
{
  return (current->p38==9);
}
static void __a568(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p38 = 10;
    }
  __rv_min = __rv_max;

}

static int __g569(unsigned int& id, conf* current)
{
  return (current->p38==10);
}
static void __a569(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p38 = 0;
    }
  __rv_min = __rv_max;

}

static int __g570(unsigned int& id, conf* current)
{
  return (current->p39==0);
}
static void __a570(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p39 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p39 = 1;
    }
  __rv_min = __rv_max;

}

static int __g571(unsigned int& id, conf* current)
{
  return (current->p39==1);
}
static void __a571(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p39 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p39 = 3;
    }
  __rv_min = __rv_max;

}

static int __g572(unsigned int& id, conf* current)
{
  return ((current->p39==2)&&((current->p40>=0)&&(current->p40<=4))||(current->p40==6)||(current->p40==10));
}
static void __a572(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p39 = 4;
    }
  __rv_min = __rv_max;

}

static int __g573(unsigned int& id, conf* current)
{
  return ((current->p39==2)&&!(((current->p40>=0)&&(current->p40<=4))||(current->p40==6)||(current->p40==10)));
}
static void __a573(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p39 = 2;
    }
  __rv_min = __rv_max;

}

static int __g574(unsigned int& id, conf* current)
{
  return ((current->p39==3)&&((current->p38>=0)&&(current->p38<=3))||(current->p38==5)||(current->p38==7));
}
static void __a574(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p39 = 5;
    }
  __rv_min = __rv_max;

}

static int __g575(unsigned int& id, conf* current)
{
  return ((current->p39==3)&&!(((current->p38>=0)&&(current->p38<=3))||(current->p38==5)||(current->p38==7)));
}
static void __a575(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p39 = 3;
    }
  __rv_min = __rv_max;

}

static int __g576(unsigned int& id, conf* current)
{
  return ((current->p39==4)&&((current->p38>=0)&&(current->p38<=3))||(current->p38==5)||(current->p38==7));
}
static void __a576(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p39 = 8;
    }
  __rv_min = __rv_max;

}

static int __g577(unsigned int& id, conf* current)
{
  return ((current->p39==4)&&!(((current->p38>=0)&&(current->p38<=3))||(current->p38==5)||(current->p38==7)));
}
static void __a577(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p39 = 6;
    }
  __rv_min = __rv_max;

}

static int __g578(unsigned int& id, conf* current)
{
  return ((current->p39==5)&&((current->p40>=0)&&(current->p40<=4))||(current->p40==6)||(current->p40==10));
}
static void __a578(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p39 = 8;
    }
  __rv_min = __rv_max;

}

static int __g579(unsigned int& id, conf* current)
{
  return ((current->p39==5)&&!(((current->p40>=0)&&(current->p40<=4))||(current->p40==6)||(current->p40==10)));
}
static void __a579(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p39 = 7;
    }
  __rv_min = __rv_max;

}

static int __g580(unsigned int& id, conf* current)
{
  return (current->p39==6);
}
static void __a580(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p39 = 1;
    }
  __rv_min = __rv_max;

}

static int __g581(unsigned int& id, conf* current)
{
  return (current->p39==7);
}
static void __a581(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p39 = 1;
    }
  __rv_min = __rv_max;

}

static int __g582(unsigned int& id, conf* current)
{
  return (current->p39==8);
}
static void __a582(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p39 = 9;
    }
  __rv_min = __rv_max;

}

static int __g583(unsigned int& id, conf* current)
{
  return (current->p39==9);
}
static void __a583(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p39 = 10;
    }
  __rv_min = __rv_max;

}

static int __g584(unsigned int& id, conf* current)
{
  return (current->p39==10);
}
static void __a584(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p39 = 0;
    }
  __rv_min = __rv_max;

}

static int __g585(unsigned int& id, conf* current)
{
  return (current->p40==0);
}
static void __a585(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p40 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p40 = 1;
    }
  __rv_min = __rv_max;

}

static int __g586(unsigned int& id, conf* current)
{
  return (current->p40==1);
}
static void __a586(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p40 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p40 = 3;
    }
  __rv_min = __rv_max;

}

static int __g587(unsigned int& id, conf* current)
{
  return ((current->p40==2)&&((current->p41>=0)&&(current->p41<=4))||(current->p41==6)||(current->p41==10));
}
static void __a587(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p40 = 4;
    }
  __rv_min = __rv_max;

}

static int __g588(unsigned int& id, conf* current)
{
  return ((current->p40==2)&&!(((current->p41>=0)&&(current->p41<=4))||(current->p41==6)||(current->p41==10)));
}
static void __a588(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p40 = 2;
    }
  __rv_min = __rv_max;

}

static int __g589(unsigned int& id, conf* current)
{
  return ((current->p40==3)&&((current->p39>=0)&&(current->p39<=3))||(current->p39==5)||(current->p39==7));
}
static void __a589(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p40 = 5;
    }
  __rv_min = __rv_max;

}

static int __g590(unsigned int& id, conf* current)
{
  return ((current->p40==3)&&!(((current->p39>=0)&&(current->p39<=3))||(current->p39==5)||(current->p39==7)));
}
static void __a590(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p40 = 3;
    }
  __rv_min = __rv_max;

}

static int __g591(unsigned int& id, conf* current)
{
  return ((current->p40==4)&&((current->p39>=0)&&(current->p39<=3))||(current->p39==5)||(current->p39==7));
}
static void __a591(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p40 = 8;
    }
  __rv_min = __rv_max;

}

static int __g592(unsigned int& id, conf* current)
{
  return ((current->p40==4)&&!(((current->p39>=0)&&(current->p39<=3))||(current->p39==5)||(current->p39==7)));
}
static void __a592(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p40 = 6;
    }
  __rv_min = __rv_max;

}

static int __g593(unsigned int& id, conf* current)
{
  return ((current->p40==5)&&((current->p41>=0)&&(current->p41<=4))||(current->p41==6)||(current->p41==10));
}
static void __a593(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p40 = 8;
    }
  __rv_min = __rv_max;

}

static int __g594(unsigned int& id, conf* current)
{
  return ((current->p40==5)&&!(((current->p41>=0)&&(current->p41<=4))||(current->p41==6)||(current->p41==10)));
}
static void __a594(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p40 = 7;
    }
  __rv_min = __rv_max;

}

static int __g595(unsigned int& id, conf* current)
{
  return (current->p40==6);
}
static void __a595(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p40 = 1;
    }
  __rv_min = __rv_max;

}

static int __g596(unsigned int& id, conf* current)
{
  return (current->p40==7);
}
static void __a596(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p40 = 1;
    }
  __rv_min = __rv_max;

}

static int __g597(unsigned int& id, conf* current)
{
  return (current->p40==8);
}
static void __a597(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p40 = 9;
    }
  __rv_min = __rv_max;

}

static int __g598(unsigned int& id, conf* current)
{
  return (current->p40==9);
}
static void __a598(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p40 = 10;
    }
  __rv_min = __rv_max;

}

static int __g599(unsigned int& id, conf* current)
{
  return (current->p40==10);
}
static void __a599(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p40 = 0;
    }
  __rv_min = __rv_max;

}

static int __g600(unsigned int& id, conf* current)
{
  return (current->p41==0);
}
static void __a600(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p41 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p41 = 1;
    }
  __rv_min = __rv_max;

}

static int __g601(unsigned int& id, conf* current)
{
  return (current->p41==1);
}
static void __a601(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p41 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p41 = 3;
    }
  __rv_min = __rv_max;

}

static int __g602(unsigned int& id, conf* current)
{
  return ((current->p41==2)&&((current->p42>=0)&&(current->p42<=4))||(current->p42==6)||(current->p42==10));
}
static void __a602(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p41 = 4;
    }
  __rv_min = __rv_max;

}

static int __g603(unsigned int& id, conf* current)
{
  return ((current->p41==2)&&!(((current->p42>=0)&&(current->p42<=4))||(current->p42==6)||(current->p42==10)));
}
static void __a603(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p41 = 2;
    }
  __rv_min = __rv_max;

}

static int __g604(unsigned int& id, conf* current)
{
  return ((current->p41==3)&&((current->p40>=0)&&(current->p40<=3))||(current->p40==5)||(current->p40==7));
}
static void __a604(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p41 = 5;
    }
  __rv_min = __rv_max;

}

static int __g605(unsigned int& id, conf* current)
{
  return ((current->p41==3)&&!(((current->p40>=0)&&(current->p40<=3))||(current->p40==5)||(current->p40==7)));
}
static void __a605(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p41 = 3;
    }
  __rv_min = __rv_max;

}

static int __g606(unsigned int& id, conf* current)
{
  return ((current->p41==4)&&((current->p40>=0)&&(current->p40<=3))||(current->p40==5)||(current->p40==7));
}
static void __a606(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p41 = 8;
    }
  __rv_min = __rv_max;

}

static int __g607(unsigned int& id, conf* current)
{
  return ((current->p41==4)&&!(((current->p40>=0)&&(current->p40<=3))||(current->p40==5)||(current->p40==7)));
}
static void __a607(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p41 = 6;
    }
  __rv_min = __rv_max;

}

static int __g608(unsigned int& id, conf* current)
{
  return ((current->p41==5)&&((current->p42>=0)&&(current->p42<=4))||(current->p42==6)||(current->p42==10));
}
static void __a608(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p41 = 8;
    }
  __rv_min = __rv_max;

}

static int __g609(unsigned int& id, conf* current)
{
  return ((current->p41==5)&&!(((current->p42>=0)&&(current->p42<=4))||(current->p42==6)||(current->p42==10)));
}
static void __a609(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p41 = 7;
    }
  __rv_min = __rv_max;

}

static int __g610(unsigned int& id, conf* current)
{
  return (current->p41==6);
}
static void __a610(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p41 = 1;
    }
  __rv_min = __rv_max;

}

static int __g611(unsigned int& id, conf* current)
{
  return (current->p41==7);
}
static void __a611(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p41 = 1;
    }
  __rv_min = __rv_max;

}

static int __g612(unsigned int& id, conf* current)
{
  return (current->p41==8);
}
static void __a612(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p41 = 9;
    }
  __rv_min = __rv_max;

}

static int __g613(unsigned int& id, conf* current)
{
  return (current->p41==9);
}
static void __a613(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p41 = 10;
    }
  __rv_min = __rv_max;

}

static int __g614(unsigned int& id, conf* current)
{
  return (current->p41==10);
}
static void __a614(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p41 = 0;
    }
  __rv_min = __rv_max;

}

static int __g615(unsigned int& id, conf* current)
{
  return (current->p42==0);
}
static void __a615(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p42 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p42 = 1;
    }
  __rv_min = __rv_max;

}

static int __g616(unsigned int& id, conf* current)
{
  return (current->p42==1);
}
static void __a616(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p42 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p42 = 3;
    }
  __rv_min = __rv_max;

}

static int __g617(unsigned int& id, conf* current)
{
  return ((current->p42==2)&&((current->p43>=0)&&(current->p43<=4))||(current->p43==6)||(current->p43==10));
}
static void __a617(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p42 = 4;
    }
  __rv_min = __rv_max;

}

static int __g618(unsigned int& id, conf* current)
{
  return ((current->p42==2)&&!(((current->p43>=0)&&(current->p43<=4))||(current->p43==6)||(current->p43==10)));
}
static void __a618(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p42 = 2;
    }
  __rv_min = __rv_max;

}

static int __g619(unsigned int& id, conf* current)
{
  return ((current->p42==3)&&((current->p41>=0)&&(current->p41<=3))||(current->p41==5)||(current->p41==7));
}
static void __a619(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p42 = 5;
    }
  __rv_min = __rv_max;

}

static int __g620(unsigned int& id, conf* current)
{
  return ((current->p42==3)&&!(((current->p41>=0)&&(current->p41<=3))||(current->p41==5)||(current->p41==7)));
}
static void __a620(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p42 = 3;
    }
  __rv_min = __rv_max;

}

static int __g621(unsigned int& id, conf* current)
{
  return ((current->p42==4)&&((current->p41>=0)&&(current->p41<=3))||(current->p41==5)||(current->p41==7));
}
static void __a621(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p42 = 8;
    }
  __rv_min = __rv_max;

}

static int __g622(unsigned int& id, conf* current)
{
  return ((current->p42==4)&&!(((current->p41>=0)&&(current->p41<=3))||(current->p41==5)||(current->p41==7)));
}
static void __a622(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p42 = 6;
    }
  __rv_min = __rv_max;

}

static int __g623(unsigned int& id, conf* current)
{
  return ((current->p42==5)&&((current->p43>=0)&&(current->p43<=4))||(current->p43==6)||(current->p43==10));
}
static void __a623(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p42 = 8;
    }
  __rv_min = __rv_max;

}

static int __g624(unsigned int& id, conf* current)
{
  return ((current->p42==5)&&!(((current->p43>=0)&&(current->p43<=4))||(current->p43==6)||(current->p43==10)));
}
static void __a624(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p42 = 7;
    }
  __rv_min = __rv_max;

}

static int __g625(unsigned int& id, conf* current)
{
  return (current->p42==6);
}
static void __a625(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p42 = 1;
    }
  __rv_min = __rv_max;

}

static int __g626(unsigned int& id, conf* current)
{
  return (current->p42==7);
}
static void __a626(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p42 = 1;
    }
  __rv_min = __rv_max;

}

static int __g627(unsigned int& id, conf* current)
{
  return (current->p42==8);
}
static void __a627(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p42 = 9;
    }
  __rv_min = __rv_max;

}

static int __g628(unsigned int& id, conf* current)
{
  return (current->p42==9);
}
static void __a628(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p42 = 10;
    }
  __rv_min = __rv_max;

}

static int __g629(unsigned int& id, conf* current)
{
  return (current->p42==10);
}
static void __a629(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p42 = 0;
    }
  __rv_min = __rv_max;

}

static int __g630(unsigned int& id, conf* current)
{
  return (current->p43==0);
}
static void __a630(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p43 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p43 = 1;
    }
  __rv_min = __rv_max;

}

static int __g631(unsigned int& id, conf* current)
{
  return (current->p43==1);
}
static void __a631(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p43 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p43 = 3;
    }
  __rv_min = __rv_max;

}

static int __g632(unsigned int& id, conf* current)
{
  return ((current->p43==2)&&((current->p44>=0)&&(current->p44<=4))||(current->p44==6)||(current->p44==10));
}
static void __a632(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p43 = 4;
    }
  __rv_min = __rv_max;

}

static int __g633(unsigned int& id, conf* current)
{
  return ((current->p43==2)&&!(((current->p44>=0)&&(current->p44<=4))||(current->p44==6)||(current->p44==10)));
}
static void __a633(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p43 = 2;
    }
  __rv_min = __rv_max;

}

static int __g634(unsigned int& id, conf* current)
{
  return ((current->p43==3)&&((current->p42>=0)&&(current->p42<=3))||(current->p42==5)||(current->p42==7));
}
static void __a634(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p43 = 5;
    }
  __rv_min = __rv_max;

}

static int __g635(unsigned int& id, conf* current)
{
  return ((current->p43==3)&&!(((current->p42>=0)&&(current->p42<=3))||(current->p42==5)||(current->p42==7)));
}
static void __a635(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p43 = 3;
    }
  __rv_min = __rv_max;

}

static int __g636(unsigned int& id, conf* current)
{
  return ((current->p43==4)&&((current->p42>=0)&&(current->p42<=3))||(current->p42==5)||(current->p42==7));
}
static void __a636(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p43 = 8;
    }
  __rv_min = __rv_max;

}

static int __g637(unsigned int& id, conf* current)
{
  return ((current->p43==4)&&!(((current->p42>=0)&&(current->p42<=3))||(current->p42==5)||(current->p42==7)));
}
static void __a637(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p43 = 6;
    }
  __rv_min = __rv_max;

}

static int __g638(unsigned int& id, conf* current)
{
  return ((current->p43==5)&&((current->p44>=0)&&(current->p44<=4))||(current->p44==6)||(current->p44==10));
}
static void __a638(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p43 = 8;
    }
  __rv_min = __rv_max;

}

static int __g639(unsigned int& id, conf* current)
{
  return ((current->p43==5)&&!(((current->p44>=0)&&(current->p44<=4))||(current->p44==6)||(current->p44==10)));
}
static void __a639(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p43 = 7;
    }
  __rv_min = __rv_max;

}

static int __g640(unsigned int& id, conf* current)
{
  return (current->p43==6);
}
static void __a640(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p43 = 1;
    }
  __rv_min = __rv_max;

}

static int __g641(unsigned int& id, conf* current)
{
  return (current->p43==7);
}
static void __a641(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p43 = 1;
    }
  __rv_min = __rv_max;

}

static int __g642(unsigned int& id, conf* current)
{
  return (current->p43==8);
}
static void __a642(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p43 = 9;
    }
  __rv_min = __rv_max;

}

static int __g643(unsigned int& id, conf* current)
{
  return (current->p43==9);
}
static void __a643(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p43 = 10;
    }
  __rv_min = __rv_max;

}

static int __g644(unsigned int& id, conf* current)
{
  return (current->p43==10);
}
static void __a644(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p43 = 0;
    }
  __rv_min = __rv_max;

}

static int __g645(unsigned int& id, conf* current)
{
  return (current->p44==0);
}
static void __a645(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p44 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p44 = 1;
    }
  __rv_min = __rv_max;

}

static int __g646(unsigned int& id, conf* current)
{
  return (current->p44==1);
}
static void __a646(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p44 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p44 = 3;
    }
  __rv_min = __rv_max;

}

static int __g647(unsigned int& id, conf* current)
{
  return ((current->p44==2)&&((current->p45>=0)&&(current->p45<=4))||(current->p45==6)||(current->p45==10));
}
static void __a647(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p44 = 4;
    }
  __rv_min = __rv_max;

}

static int __g648(unsigned int& id, conf* current)
{
  return ((current->p44==2)&&!(((current->p45>=0)&&(current->p45<=4))||(current->p45==6)||(current->p45==10)));
}
static void __a648(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p44 = 2;
    }
  __rv_min = __rv_max;

}

static int __g649(unsigned int& id, conf* current)
{
  return ((current->p44==3)&&((current->p43>=0)&&(current->p43<=3))||(current->p43==5)||(current->p43==7));
}
static void __a649(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p44 = 5;
    }
  __rv_min = __rv_max;

}

static int __g650(unsigned int& id, conf* current)
{
  return ((current->p44==3)&&!(((current->p43>=0)&&(current->p43<=3))||(current->p43==5)||(current->p43==7)));
}
static void __a650(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p44 = 3;
    }
  __rv_min = __rv_max;

}

static int __g651(unsigned int& id, conf* current)
{
  return ((current->p44==4)&&((current->p43>=0)&&(current->p43<=3))||(current->p43==5)||(current->p43==7));
}
static void __a651(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p44 = 8;
    }
  __rv_min = __rv_max;

}

static int __g652(unsigned int& id, conf* current)
{
  return ((current->p44==4)&&!(((current->p43>=0)&&(current->p43<=3))||(current->p43==5)||(current->p43==7)));
}
static void __a652(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p44 = 6;
    }
  __rv_min = __rv_max;

}

static int __g653(unsigned int& id, conf* current)
{
  return ((current->p44==5)&&((current->p45>=0)&&(current->p45<=4))||(current->p45==6)||(current->p45==10));
}
static void __a653(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p44 = 8;
    }
  __rv_min = __rv_max;

}

static int __g654(unsigned int& id, conf* current)
{
  return ((current->p44==5)&&!(((current->p45>=0)&&(current->p45<=4))||(current->p45==6)||(current->p45==10)));
}
static void __a654(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p44 = 7;
    }
  __rv_min = __rv_max;

}

static int __g655(unsigned int& id, conf* current)
{
  return (current->p44==6);
}
static void __a655(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p44 = 1;
    }
  __rv_min = __rv_max;

}

static int __g656(unsigned int& id, conf* current)
{
  return (current->p44==7);
}
static void __a656(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p44 = 1;
    }
  __rv_min = __rv_max;

}

static int __g657(unsigned int& id, conf* current)
{
  return (current->p44==8);
}
static void __a657(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p44 = 9;
    }
  __rv_min = __rv_max;

}

static int __g658(unsigned int& id, conf* current)
{
  return (current->p44==9);
}
static void __a658(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p44 = 10;
    }
  __rv_min = __rv_max;

}

static int __g659(unsigned int& id, conf* current)
{
  return (current->p44==10);
}
static void __a659(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p44 = 0;
    }
  __rv_min = __rv_max;

}

static int __g660(unsigned int& id, conf* current)
{
  return (current->p45==0);
}
static void __a660(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p45 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p45 = 1;
    }
  __rv_min = __rv_max;

}

static int __g661(unsigned int& id, conf* current)
{
  return (current->p45==1);
}
static void __a661(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p45 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p45 = 3;
    }
  __rv_min = __rv_max;

}

static int __g662(unsigned int& id, conf* current)
{
  return ((current->p45==2)&&((current->p46>=0)&&(current->p46<=4))||(current->p46==6)||(current->p46==10));
}
static void __a662(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p45 = 4;
    }
  __rv_min = __rv_max;

}

static int __g663(unsigned int& id, conf* current)
{
  return ((current->p45==2)&&!(((current->p46>=0)&&(current->p46<=4))||(current->p46==6)||(current->p46==10)));
}
static void __a663(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p45 = 2;
    }
  __rv_min = __rv_max;

}

static int __g664(unsigned int& id, conf* current)
{
  return ((current->p45==3)&&((current->p44>=0)&&(current->p44<=3))||(current->p44==5)||(current->p44==7));
}
static void __a664(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p45 = 5;
    }
  __rv_min = __rv_max;

}

static int __g665(unsigned int& id, conf* current)
{
  return ((current->p45==3)&&!(((current->p44>=0)&&(current->p44<=3))||(current->p44==5)||(current->p44==7)));
}
static void __a665(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p45 = 3;
    }
  __rv_min = __rv_max;

}

static int __g666(unsigned int& id, conf* current)
{
  return ((current->p45==4)&&((current->p44>=0)&&(current->p44<=3))||(current->p44==5)||(current->p44==7));
}
static void __a666(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p45 = 8;
    }
  __rv_min = __rv_max;

}

static int __g667(unsigned int& id, conf* current)
{
  return ((current->p45==4)&&!(((current->p44>=0)&&(current->p44<=3))||(current->p44==5)||(current->p44==7)));
}
static void __a667(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p45 = 6;
    }
  __rv_min = __rv_max;

}

static int __g668(unsigned int& id, conf* current)
{
  return ((current->p45==5)&&((current->p46>=0)&&(current->p46<=4))||(current->p46==6)||(current->p46==10));
}
static void __a668(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p45 = 8;
    }
  __rv_min = __rv_max;

}

static int __g669(unsigned int& id, conf* current)
{
  return ((current->p45==5)&&!(((current->p46>=0)&&(current->p46<=4))||(current->p46==6)||(current->p46==10)));
}
static void __a669(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p45 = 7;
    }
  __rv_min = __rv_max;

}

static int __g670(unsigned int& id, conf* current)
{
  return (current->p45==6);
}
static void __a670(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p45 = 1;
    }
  __rv_min = __rv_max;

}

static int __g671(unsigned int& id, conf* current)
{
  return (current->p45==7);
}
static void __a671(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p45 = 1;
    }
  __rv_min = __rv_max;

}

static int __g672(unsigned int& id, conf* current)
{
  return (current->p45==8);
}
static void __a672(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p45 = 9;
    }
  __rv_min = __rv_max;

}

static int __g673(unsigned int& id, conf* current)
{
  return (current->p45==9);
}
static void __a673(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p45 = 10;
    }
  __rv_min = __rv_max;

}

static int __g674(unsigned int& id, conf* current)
{
  return (current->p45==10);
}
static void __a674(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p45 = 0;
    }
  __rv_min = __rv_max;

}

static int __g675(unsigned int& id, conf* current)
{
  return (current->p46==0);
}
static void __a675(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p46 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p46 = 1;
    }
  __rv_min = __rv_max;

}

static int __g676(unsigned int& id, conf* current)
{
  return (current->p46==1);
}
static void __a676(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p46 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p46 = 3;
    }
  __rv_min = __rv_max;

}

static int __g677(unsigned int& id, conf* current)
{
  return ((current->p46==2)&&((current->p47>=0)&&(current->p47<=4))||(current->p47==6)||(current->p47==10));
}
static void __a677(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p46 = 4;
    }
  __rv_min = __rv_max;

}

static int __g678(unsigned int& id, conf* current)
{
  return ((current->p46==2)&&!(((current->p47>=0)&&(current->p47<=4))||(current->p47==6)||(current->p47==10)));
}
static void __a678(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p46 = 2;
    }
  __rv_min = __rv_max;

}

static int __g679(unsigned int& id, conf* current)
{
  return ((current->p46==3)&&((current->p45>=0)&&(current->p45<=3))||(current->p45==5)||(current->p45==7));
}
static void __a679(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p46 = 5;
    }
  __rv_min = __rv_max;

}

static int __g680(unsigned int& id, conf* current)
{
  return ((current->p46==3)&&!(((current->p45>=0)&&(current->p45<=3))||(current->p45==5)||(current->p45==7)));
}
static void __a680(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p46 = 3;
    }
  __rv_min = __rv_max;

}

static int __g681(unsigned int& id, conf* current)
{
  return ((current->p46==4)&&((current->p45>=0)&&(current->p45<=3))||(current->p45==5)||(current->p45==7));
}
static void __a681(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p46 = 8;
    }
  __rv_min = __rv_max;

}

static int __g682(unsigned int& id, conf* current)
{
  return ((current->p46==4)&&!(((current->p45>=0)&&(current->p45<=3))||(current->p45==5)||(current->p45==7)));
}
static void __a682(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p46 = 6;
    }
  __rv_min = __rv_max;

}

static int __g683(unsigned int& id, conf* current)
{
  return ((current->p46==5)&&((current->p47>=0)&&(current->p47<=4))||(current->p47==6)||(current->p47==10));
}
static void __a683(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p46 = 8;
    }
  __rv_min = __rv_max;

}

static int __g684(unsigned int& id, conf* current)
{
  return ((current->p46==5)&&!(((current->p47>=0)&&(current->p47<=4))||(current->p47==6)||(current->p47==10)));
}
static void __a684(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p46 = 7;
    }
  __rv_min = __rv_max;

}

static int __g685(unsigned int& id, conf* current)
{
  return (current->p46==6);
}
static void __a685(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p46 = 1;
    }
  __rv_min = __rv_max;

}

static int __g686(unsigned int& id, conf* current)
{
  return (current->p46==7);
}
static void __a686(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p46 = 1;
    }
  __rv_min = __rv_max;

}

static int __g687(unsigned int& id, conf* current)
{
  return (current->p46==8);
}
static void __a687(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p46 = 9;
    }
  __rv_min = __rv_max;

}

static int __g688(unsigned int& id, conf* current)
{
  return (current->p46==9);
}
static void __a688(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p46 = 10;
    }
  __rv_min = __rv_max;

}

static int __g689(unsigned int& id, conf* current)
{
  return (current->p46==10);
}
static void __a689(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p46 = 0;
    }
  __rv_min = __rv_max;

}

static int __g690(unsigned int& id, conf* current)
{
  return (current->p47==0);
}
static void __a690(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p47 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p47 = 1;
    }
  __rv_min = __rv_max;

}

static int __g691(unsigned int& id, conf* current)
{
  return (current->p47==1);
}
static void __a691(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p47 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p47 = 3;
    }
  __rv_min = __rv_max;

}

static int __g692(unsigned int& id, conf* current)
{
  return ((current->p47==2)&&((current->p48>=0)&&(current->p48<=4))||(current->p48==6)||(current->p48==10));
}
static void __a692(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p47 = 4;
    }
  __rv_min = __rv_max;

}

static int __g693(unsigned int& id, conf* current)
{
  return ((current->p47==2)&&!(((current->p48>=0)&&(current->p48<=4))||(current->p48==6)||(current->p48==10)));
}
static void __a693(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p47 = 2;
    }
  __rv_min = __rv_max;

}

static int __g694(unsigned int& id, conf* current)
{
  return ((current->p47==3)&&((current->p46>=0)&&(current->p46<=3))||(current->p46==5)||(current->p46==7));
}
static void __a694(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p47 = 5;
    }
  __rv_min = __rv_max;

}

static int __g695(unsigned int& id, conf* current)
{
  return ((current->p47==3)&&!(((current->p46>=0)&&(current->p46<=3))||(current->p46==5)||(current->p46==7)));
}
static void __a695(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p47 = 3;
    }
  __rv_min = __rv_max;

}

static int __g696(unsigned int& id, conf* current)
{
  return ((current->p47==4)&&((current->p46>=0)&&(current->p46<=3))||(current->p46==5)||(current->p46==7));
}
static void __a696(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p47 = 8;
    }
  __rv_min = __rv_max;

}

static int __g697(unsigned int& id, conf* current)
{
  return ((current->p47==4)&&!(((current->p46>=0)&&(current->p46<=3))||(current->p46==5)||(current->p46==7)));
}
static void __a697(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p47 = 6;
    }
  __rv_min = __rv_max;

}

static int __g698(unsigned int& id, conf* current)
{
  return ((current->p47==5)&&((current->p48>=0)&&(current->p48<=4))||(current->p48==6)||(current->p48==10));
}
static void __a698(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p47 = 8;
    }
  __rv_min = __rv_max;

}

static int __g699(unsigned int& id, conf* current)
{
  return ((current->p47==5)&&!(((current->p48>=0)&&(current->p48<=4))||(current->p48==6)||(current->p48==10)));
}
static void __a699(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p47 = 7;
    }
  __rv_min = __rv_max;

}

static int __g700(unsigned int& id, conf* current)
{
  return (current->p47==6);
}
static void __a700(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p47 = 1;
    }
  __rv_min = __rv_max;

}

static int __g701(unsigned int& id, conf* current)
{
  return (current->p47==7);
}
static void __a701(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p47 = 1;
    }
  __rv_min = __rv_max;

}

static int __g702(unsigned int& id, conf* current)
{
  return (current->p47==8);
}
static void __a702(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p47 = 9;
    }
  __rv_min = __rv_max;

}

static int __g703(unsigned int& id, conf* current)
{
  return (current->p47==9);
}
static void __a703(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p47 = 10;
    }
  __rv_min = __rv_max;

}

static int __g704(unsigned int& id, conf* current)
{
  return (current->p47==10);
}
static void __a704(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p47 = 0;
    }
  __rv_min = __rv_max;

}

static int __g705(unsigned int& id, conf* current)
{
  return (current->p48==0);
}
static void __a705(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p48 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p48 = 1;
    }
  __rv_min = __rv_max;

}

static int __g706(unsigned int& id, conf* current)
{
  return (current->p48==1);
}
static void __a706(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p48 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p48 = 3;
    }
  __rv_min = __rv_max;

}

static int __g707(unsigned int& id, conf* current)
{
  return ((current->p48==2)&&((current->p49>=0)&&(current->p49<=4))||(current->p49==6)||(current->p49==10));
}
static void __a707(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p48 = 4;
    }
  __rv_min = __rv_max;

}

static int __g708(unsigned int& id, conf* current)
{
  return ((current->p48==2)&&!(((current->p49>=0)&&(current->p49<=4))||(current->p49==6)||(current->p49==10)));
}
static void __a708(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p48 = 2;
    }
  __rv_min = __rv_max;

}

static int __g709(unsigned int& id, conf* current)
{
  return ((current->p48==3)&&((current->p47>=0)&&(current->p47<=3))||(current->p47==5)||(current->p47==7));
}
static void __a709(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p48 = 5;
    }
  __rv_min = __rv_max;

}

static int __g710(unsigned int& id, conf* current)
{
  return ((current->p48==3)&&!(((current->p47>=0)&&(current->p47<=3))||(current->p47==5)||(current->p47==7)));
}
static void __a710(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p48 = 3;
    }
  __rv_min = __rv_max;

}

static int __g711(unsigned int& id, conf* current)
{
  return ((current->p48==4)&&((current->p47>=0)&&(current->p47<=3))||(current->p47==5)||(current->p47==7));
}
static void __a711(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p48 = 8;
    }
  __rv_min = __rv_max;

}

static int __g712(unsigned int& id, conf* current)
{
  return ((current->p48==4)&&!(((current->p47>=0)&&(current->p47<=3))||(current->p47==5)||(current->p47==7)));
}
static void __a712(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p48 = 6;
    }
  __rv_min = __rv_max;

}

static int __g713(unsigned int& id, conf* current)
{
  return ((current->p48==5)&&((current->p49>=0)&&(current->p49<=4))||(current->p49==6)||(current->p49==10));
}
static void __a713(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p48 = 8;
    }
  __rv_min = __rv_max;

}

static int __g714(unsigned int& id, conf* current)
{
  return ((current->p48==5)&&!(((current->p49>=0)&&(current->p49<=4))||(current->p49==6)||(current->p49==10)));
}
static void __a714(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p48 = 7;
    }
  __rv_min = __rv_max;

}

static int __g715(unsigned int& id, conf* current)
{
  return (current->p48==6);
}
static void __a715(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p48 = 1;
    }
  __rv_min = __rv_max;

}

static int __g716(unsigned int& id, conf* current)
{
  return (current->p48==7);
}
static void __a716(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p48 = 1;
    }
  __rv_min = __rv_max;

}

static int __g717(unsigned int& id, conf* current)
{
  return (current->p48==8);
}
static void __a717(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p48 = 9;
    }
  __rv_min = __rv_max;

}

static int __g718(unsigned int& id, conf* current)
{
  return (current->p48==9);
}
static void __a718(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p48 = 10;
    }
  __rv_min = __rv_max;

}

static int __g719(unsigned int& id, conf* current)
{
  return (current->p48==10);
}
static void __a719(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p48 = 0;
    }
  __rv_min = __rv_max;

}

static int __g720(unsigned int& id, conf* current)
{
  return (current->p49==0);
}
static void __a720(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p49 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p49 = 1;
    }
  __rv_min = __rv_max;

}

static int __g721(unsigned int& id, conf* current)
{
  return (current->p49==1);
}
static void __a721(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p49 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p49 = 3;
    }
  __rv_min = __rv_max;

}

static int __g722(unsigned int& id, conf* current)
{
  return ((current->p49==2)&&((current->p50>=0)&&(current->p50<=4))||(current->p50==6)||(current->p50==10));
}
static void __a722(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p49 = 4;
    }
  __rv_min = __rv_max;

}

static int __g723(unsigned int& id, conf* current)
{
  return ((current->p49==2)&&!(((current->p50>=0)&&(current->p50<=4))||(current->p50==6)||(current->p50==10)));
}
static void __a723(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p49 = 2;
    }
  __rv_min = __rv_max;

}

static int __g724(unsigned int& id, conf* current)
{
  return ((current->p49==3)&&((current->p48>=0)&&(current->p48<=3))||(current->p48==5)||(current->p48==7));
}
static void __a724(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p49 = 5;
    }
  __rv_min = __rv_max;

}

static int __g725(unsigned int& id, conf* current)
{
  return ((current->p49==3)&&!(((current->p48>=0)&&(current->p48<=3))||(current->p48==5)||(current->p48==7)));
}
static void __a725(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p49 = 3;
    }
  __rv_min = __rv_max;

}

static int __g726(unsigned int& id, conf* current)
{
  return ((current->p49==4)&&((current->p48>=0)&&(current->p48<=3))||(current->p48==5)||(current->p48==7));
}
static void __a726(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p49 = 8;
    }
  __rv_min = __rv_max;

}

static int __g727(unsigned int& id, conf* current)
{
  return ((current->p49==4)&&!(((current->p48>=0)&&(current->p48<=3))||(current->p48==5)||(current->p48==7)));
}
static void __a727(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p49 = 6;
    }
  __rv_min = __rv_max;

}

static int __g728(unsigned int& id, conf* current)
{
  return ((current->p49==5)&&((current->p50>=0)&&(current->p50<=4))||(current->p50==6)||(current->p50==10));
}
static void __a728(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p49 = 8;
    }
  __rv_min = __rv_max;

}

static int __g729(unsigned int& id, conf* current)
{
  return ((current->p49==5)&&!(((current->p50>=0)&&(current->p50<=4))||(current->p50==6)||(current->p50==10)));
}
static void __a729(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p49 = 7;
    }
  __rv_min = __rv_max;

}

static int __g730(unsigned int& id, conf* current)
{
  return (current->p49==6);
}
static void __a730(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p49 = 1;
    }
  __rv_min = __rv_max;

}

static int __g731(unsigned int& id, conf* current)
{
  return (current->p49==7);
}
static void __a731(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p49 = 1;
    }
  __rv_min = __rv_max;

}

static int __g732(unsigned int& id, conf* current)
{
  return (current->p49==8);
}
static void __a732(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p49 = 9;
    }
  __rv_min = __rv_max;

}

static int __g733(unsigned int& id, conf* current)
{
  return (current->p49==9);
}
static void __a733(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p49 = 10;
    }
  __rv_min = __rv_max;

}

static int __g734(unsigned int& id, conf* current)
{
  return (current->p49==10);
}
static void __a734(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p49 = 0;
    }
  __rv_min = __rv_max;

}

static int __g735(unsigned int& id, conf* current)
{
  return (current->p50==0);
}
static void __a735(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.2;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p50 = 0;
    }
  __rv_min = __rv_max;
  __rv_max += 0.8;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p50 = 1;
    }
  __rv_min = __rv_max;

}

static int __g736(unsigned int& id, conf* current)
{
  return (current->p50==1);
}
static void __a736(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p50 = 2;
    }
  __rv_min = __rv_max;
  __rv_max += 0.5;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p50 = 3;
    }
  __rv_min = __rv_max;

}

static int __g737(unsigned int& id, conf* current)
{
  return ((current->p50==2)&&((current->p1>=0)&&(current->p1<=4))||(current->p1==6)||(current->p1==10));
}
static void __a737(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p50 = 4;
    }
  __rv_min = __rv_max;

}

static int __g738(unsigned int& id, conf* current)
{
  return ((current->p50==2)&&!(((current->p1>=0)&&(current->p1<=4))||(current->p1==6)||(current->p1==10)));
}
static void __a738(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p50 = 2;
    }
  __rv_min = __rv_max;

}

static int __g739(unsigned int& id, conf* current)
{
  return ((current->p50==3)&&((current->p49>=0)&&(current->p49<=3))||(current->p49==5)||(current->p49==7));
}
static void __a739(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p50 = 5;
    }
  __rv_min = __rv_max;

}

static int __g740(unsigned int& id, conf* current)
{
  return ((current->p50==3)&&!(((current->p49>=0)&&(current->p49<=3))||(current->p49==5)||(current->p49==7)));
}
static void __a740(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p50 = 3;
    }
  __rv_min = __rv_max;

}

static int __g741(unsigned int& id, conf* current)
{
  return ((current->p50==4)&&((current->p49>=0)&&(current->p49<=3))||(current->p49==5)||(current->p49==7));
}
static void __a741(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p50 = 8;
    }
  __rv_min = __rv_max;

}

static int __g742(unsigned int& id, conf* current)
{
  return ((current->p50==4)&&!(((current->p49>=0)&&(current->p49<=3))||(current->p49==5)||(current->p49==7)));
}
static void __a742(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p50 = 6;
    }
  __rv_min = __rv_max;

}

static int __g743(unsigned int& id, conf* current)
{
  return ((current->p50==5)&&((current->p1>=0)&&(current->p1<=4))||(current->p1==6)||(current->p1==10));
}
static void __a743(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p50 = 8;
    }
  __rv_min = __rv_max;

}

static int __g744(unsigned int& id, conf* current)
{
  return ((current->p50==5)&&!(((current->p1>=0)&&(current->p1<=4))||(current->p1==6)||(current->p1==10)));
}
static void __a744(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p50 = 7;
    }
  __rv_min = __rv_max;

}

static int __g745(unsigned int& id, conf* current)
{
  return (current->p50==6);
}
static void __a745(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p50 = 1;
    }
  __rv_min = __rv_max;

}

static int __g746(unsigned int& id, conf* current)
{
  return (current->p50==7);
}
static void __a746(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p50 = 1;
    }
  __rv_min = __rv_max;

}

static int __g747(unsigned int& id, conf* current)
{
  return (current->p50==8);
}
static void __a747(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p50 = 9;
    }
  __rv_min = __rv_max;

}

static int __g748(unsigned int& id, conf* current)
{
  return (current->p50==9);
}
static void __a748(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p50 = 10;
    }
  __rv_min = __rv_max;

}

static int __g749(unsigned int& id, conf* current)
{
  return (current->p50==10);
}
static void __a749(unsigned int& id, conf* current)
{
  double __rv, __rv_min, __rv_max;

  __rv = probability(id);
  __rv_min = 0.0;
  __rv_max = 0.0;
  __rv_max += 1.0;
  if( (__rv >= __rv_min) && (__rv < __rv_max) )
    {
      current->p50 = 0;
    }
  __rv_min = __rv_max;

}

#define NBRULES 750
static struct rule rules[750] = {
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
  { __g124, __a124 },
  { __g125, __a125 },
  { __g126, __a126 },
  { __g127, __a127 },
  { __g128, __a128 },
  { __g129, __a129 },
  { __g130, __a130 },
  { __g131, __a131 },
  { __g132, __a132 },
  { __g133, __a133 },
  { __g134, __a134 },
  { __g135, __a135 },
  { __g136, __a136 },
  { __g137, __a137 },
  { __g138, __a138 },
  { __g139, __a139 },
  { __g140, __a140 },
  { __g141, __a141 },
  { __g142, __a142 },
  { __g143, __a143 },
  { __g144, __a144 },
  { __g145, __a145 },
  { __g146, __a146 },
  { __g147, __a147 },
  { __g148, __a148 },
  { __g149, __a149 },
  { __g150, __a150 },
  { __g151, __a151 },
  { __g152, __a152 },
  { __g153, __a153 },
  { __g154, __a154 },
  { __g155, __a155 },
  { __g156, __a156 },
  { __g157, __a157 },
  { __g158, __a158 },
  { __g159, __a159 },
  { __g160, __a160 },
  { __g161, __a161 },
  { __g162, __a162 },
  { __g163, __a163 },
  { __g164, __a164 },
  { __g165, __a165 },
  { __g166, __a166 },
  { __g167, __a167 },
  { __g168, __a168 },
  { __g169, __a169 },
  { __g170, __a170 },
  { __g171, __a171 },
  { __g172, __a172 },
  { __g173, __a173 },
  { __g174, __a174 },
  { __g175, __a175 },
  { __g176, __a176 },
  { __g177, __a177 },
  { __g178, __a178 },
  { __g179, __a179 },
  { __g180, __a180 },
  { __g181, __a181 },
  { __g182, __a182 },
  { __g183, __a183 },
  { __g184, __a184 },
  { __g185, __a185 },
  { __g186, __a186 },
  { __g187, __a187 },
  { __g188, __a188 },
  { __g189, __a189 },
  { __g190, __a190 },
  { __g191, __a191 },
  { __g192, __a192 },
  { __g193, __a193 },
  { __g194, __a194 },
  { __g195, __a195 },
  { __g196, __a196 },
  { __g197, __a197 },
  { __g198, __a198 },
  { __g199, __a199 },
  { __g200, __a200 },
  { __g201, __a201 },
  { __g202, __a202 },
  { __g203, __a203 },
  { __g204, __a204 },
  { __g205, __a205 },
  { __g206, __a206 },
  { __g207, __a207 },
  { __g208, __a208 },
  { __g209, __a209 },
  { __g210, __a210 },
  { __g211, __a211 },
  { __g212, __a212 },
  { __g213, __a213 },
  { __g214, __a214 },
  { __g215, __a215 },
  { __g216, __a216 },
  { __g217, __a217 },
  { __g218, __a218 },
  { __g219, __a219 },
  { __g220, __a220 },
  { __g221, __a221 },
  { __g222, __a222 },
  { __g223, __a223 },
  { __g224, __a224 },
  { __g225, __a225 },
  { __g226, __a226 },
  { __g227, __a227 },
  { __g228, __a228 },
  { __g229, __a229 },
  { __g230, __a230 },
  { __g231, __a231 },
  { __g232, __a232 },
  { __g233, __a233 },
  { __g234, __a234 },
  { __g235, __a235 },
  { __g236, __a236 },
  { __g237, __a237 },
  { __g238, __a238 },
  { __g239, __a239 },
  { __g240, __a240 },
  { __g241, __a241 },
  { __g242, __a242 },
  { __g243, __a243 },
  { __g244, __a244 },
  { __g245, __a245 },
  { __g246, __a246 },
  { __g247, __a247 },
  { __g248, __a248 },
  { __g249, __a249 },
  { __g250, __a250 },
  { __g251, __a251 },
  { __g252, __a252 },
  { __g253, __a253 },
  { __g254, __a254 },
  { __g255, __a255 },
  { __g256, __a256 },
  { __g257, __a257 },
  { __g258, __a258 },
  { __g259, __a259 },
  { __g260, __a260 },
  { __g261, __a261 },
  { __g262, __a262 },
  { __g263, __a263 },
  { __g264, __a264 },
  { __g265, __a265 },
  { __g266, __a266 },
  { __g267, __a267 },
  { __g268, __a268 },
  { __g269, __a269 },
  { __g270, __a270 },
  { __g271, __a271 },
  { __g272, __a272 },
  { __g273, __a273 },
  { __g274, __a274 },
  { __g275, __a275 },
  { __g276, __a276 },
  { __g277, __a277 },
  { __g278, __a278 },
  { __g279, __a279 },
  { __g280, __a280 },
  { __g281, __a281 },
  { __g282, __a282 },
  { __g283, __a283 },
  { __g284, __a284 },
  { __g285, __a285 },
  { __g286, __a286 },
  { __g287, __a287 },
  { __g288, __a288 },
  { __g289, __a289 },
  { __g290, __a290 },
  { __g291, __a291 },
  { __g292, __a292 },
  { __g293, __a293 },
  { __g294, __a294 },
  { __g295, __a295 },
  { __g296, __a296 },
  { __g297, __a297 },
  { __g298, __a298 },
  { __g299, __a299 },
  { __g300, __a300 },
  { __g301, __a301 },
  { __g302, __a302 },
  { __g303, __a303 },
  { __g304, __a304 },
  { __g305, __a305 },
  { __g306, __a306 },
  { __g307, __a307 },
  { __g308, __a308 },
  { __g309, __a309 },
  { __g310, __a310 },
  { __g311, __a311 },
  { __g312, __a312 },
  { __g313, __a313 },
  { __g314, __a314 },
  { __g315, __a315 },
  { __g316, __a316 },
  { __g317, __a317 },
  { __g318, __a318 },
  { __g319, __a319 },
  { __g320, __a320 },
  { __g321, __a321 },
  { __g322, __a322 },
  { __g323, __a323 },
  { __g324, __a324 },
  { __g325, __a325 },
  { __g326, __a326 },
  { __g327, __a327 },
  { __g328, __a328 },
  { __g329, __a329 },
  { __g330, __a330 },
  { __g331, __a331 },
  { __g332, __a332 },
  { __g333, __a333 },
  { __g334, __a334 },
  { __g335, __a335 },
  { __g336, __a336 },
  { __g337, __a337 },
  { __g338, __a338 },
  { __g339, __a339 },
  { __g340, __a340 },
  { __g341, __a341 },
  { __g342, __a342 },
  { __g343, __a343 },
  { __g344, __a344 },
  { __g345, __a345 },
  { __g346, __a346 },
  { __g347, __a347 },
  { __g348, __a348 },
  { __g349, __a349 },
  { __g350, __a350 },
  { __g351, __a351 },
  { __g352, __a352 },
  { __g353, __a353 },
  { __g354, __a354 },
  { __g355, __a355 },
  { __g356, __a356 },
  { __g357, __a357 },
  { __g358, __a358 },
  { __g359, __a359 },
  { __g360, __a360 },
  { __g361, __a361 },
  { __g362, __a362 },
  { __g363, __a363 },
  { __g364, __a364 },
  { __g365, __a365 },
  { __g366, __a366 },
  { __g367, __a367 },
  { __g368, __a368 },
  { __g369, __a369 },
  { __g370, __a370 },
  { __g371, __a371 },
  { __g372, __a372 },
  { __g373, __a373 },
  { __g374, __a374 },
  { __g375, __a375 },
  { __g376, __a376 },
  { __g377, __a377 },
  { __g378, __a378 },
  { __g379, __a379 },
  { __g380, __a380 },
  { __g381, __a381 },
  { __g382, __a382 },
  { __g383, __a383 },
  { __g384, __a384 },
  { __g385, __a385 },
  { __g386, __a386 },
  { __g387, __a387 },
  { __g388, __a388 },
  { __g389, __a389 },
  { __g390, __a390 },
  { __g391, __a391 },
  { __g392, __a392 },
  { __g393, __a393 },
  { __g394, __a394 },
  { __g395, __a395 },
  { __g396, __a396 },
  { __g397, __a397 },
  { __g398, __a398 },
  { __g399, __a399 },
  { __g400, __a400 },
  { __g401, __a401 },
  { __g402, __a402 },
  { __g403, __a403 },
  { __g404, __a404 },
  { __g405, __a405 },
  { __g406, __a406 },
  { __g407, __a407 },
  { __g408, __a408 },
  { __g409, __a409 },
  { __g410, __a410 },
  { __g411, __a411 },
  { __g412, __a412 },
  { __g413, __a413 },
  { __g414, __a414 },
  { __g415, __a415 },
  { __g416, __a416 },
  { __g417, __a417 },
  { __g418, __a418 },
  { __g419, __a419 },
  { __g420, __a420 },
  { __g421, __a421 },
  { __g422, __a422 },
  { __g423, __a423 },
  { __g424, __a424 },
  { __g425, __a425 },
  { __g426, __a426 },
  { __g427, __a427 },
  { __g428, __a428 },
  { __g429, __a429 },
  { __g430, __a430 },
  { __g431, __a431 },
  { __g432, __a432 },
  { __g433, __a433 },
  { __g434, __a434 },
  { __g435, __a435 },
  { __g436, __a436 },
  { __g437, __a437 },
  { __g438, __a438 },
  { __g439, __a439 },
  { __g440, __a440 },
  { __g441, __a441 },
  { __g442, __a442 },
  { __g443, __a443 },
  { __g444, __a444 },
  { __g445, __a445 },
  { __g446, __a446 },
  { __g447, __a447 },
  { __g448, __a448 },
  { __g449, __a449 },
  { __g450, __a450 },
  { __g451, __a451 },
  { __g452, __a452 },
  { __g453, __a453 },
  { __g454, __a454 },
  { __g455, __a455 },
  { __g456, __a456 },
  { __g457, __a457 },
  { __g458, __a458 },
  { __g459, __a459 },
  { __g460, __a460 },
  { __g461, __a461 },
  { __g462, __a462 },
  { __g463, __a463 },
  { __g464, __a464 },
  { __g465, __a465 },
  { __g466, __a466 },
  { __g467, __a467 },
  { __g468, __a468 },
  { __g469, __a469 },
  { __g470, __a470 },
  { __g471, __a471 },
  { __g472, __a472 },
  { __g473, __a473 },
  { __g474, __a474 },
  { __g475, __a475 },
  { __g476, __a476 },
  { __g477, __a477 },
  { __g478, __a478 },
  { __g479, __a479 },
  { __g480, __a480 },
  { __g481, __a481 },
  { __g482, __a482 },
  { __g483, __a483 },
  { __g484, __a484 },
  { __g485, __a485 },
  { __g486, __a486 },
  { __g487, __a487 },
  { __g488, __a488 },
  { __g489, __a489 },
  { __g490, __a490 },
  { __g491, __a491 },
  { __g492, __a492 },
  { __g493, __a493 },
  { __g494, __a494 },
  { __g495, __a495 },
  { __g496, __a496 },
  { __g497, __a497 },
  { __g498, __a498 },
  { __g499, __a499 },
  { __g500, __a500 },
  { __g501, __a501 },
  { __g502, __a502 },
  { __g503, __a503 },
  { __g504, __a504 },
  { __g505, __a505 },
  { __g506, __a506 },
  { __g507, __a507 },
  { __g508, __a508 },
  { __g509, __a509 },
  { __g510, __a510 },
  { __g511, __a511 },
  { __g512, __a512 },
  { __g513, __a513 },
  { __g514, __a514 },
  { __g515, __a515 },
  { __g516, __a516 },
  { __g517, __a517 },
  { __g518, __a518 },
  { __g519, __a519 },
  { __g520, __a520 },
  { __g521, __a521 },
  { __g522, __a522 },
  { __g523, __a523 },
  { __g524, __a524 },
  { __g525, __a525 },
  { __g526, __a526 },
  { __g527, __a527 },
  { __g528, __a528 },
  { __g529, __a529 },
  { __g530, __a530 },
  { __g531, __a531 },
  { __g532, __a532 },
  { __g533, __a533 },
  { __g534, __a534 },
  { __g535, __a535 },
  { __g536, __a536 },
  { __g537, __a537 },
  { __g538, __a538 },
  { __g539, __a539 },
  { __g540, __a540 },
  { __g541, __a541 },
  { __g542, __a542 },
  { __g543, __a543 },
  { __g544, __a544 },
  { __g545, __a545 },
  { __g546, __a546 },
  { __g547, __a547 },
  { __g548, __a548 },
  { __g549, __a549 },
  { __g550, __a550 },
  { __g551, __a551 },
  { __g552, __a552 },
  { __g553, __a553 },
  { __g554, __a554 },
  { __g555, __a555 },
  { __g556, __a556 },
  { __g557, __a557 },
  { __g558, __a558 },
  { __g559, __a559 },
  { __g560, __a560 },
  { __g561, __a561 },
  { __g562, __a562 },
  { __g563, __a563 },
  { __g564, __a564 },
  { __g565, __a565 },
  { __g566, __a566 },
  { __g567, __a567 },
  { __g568, __a568 },
  { __g569, __a569 },
  { __g570, __a570 },
  { __g571, __a571 },
  { __g572, __a572 },
  { __g573, __a573 },
  { __g574, __a574 },
  { __g575, __a575 },
  { __g576, __a576 },
  { __g577, __a577 },
  { __g578, __a578 },
  { __g579, __a579 },
  { __g580, __a580 },
  { __g581, __a581 },
  { __g582, __a582 },
  { __g583, __a583 },
  { __g584, __a584 },
  { __g585, __a585 },
  { __g586, __a586 },
  { __g587, __a587 },
  { __g588, __a588 },
  { __g589, __a589 },
  { __g590, __a590 },
  { __g591, __a591 },
  { __g592, __a592 },
  { __g593, __a593 },
  { __g594, __a594 },
  { __g595, __a595 },
  { __g596, __a596 },
  { __g597, __a597 },
  { __g598, __a598 },
  { __g599, __a599 },
  { __g600, __a600 },
  { __g601, __a601 },
  { __g602, __a602 },
  { __g603, __a603 },
  { __g604, __a604 },
  { __g605, __a605 },
  { __g606, __a606 },
  { __g607, __a607 },
  { __g608, __a608 },
  { __g609, __a609 },
  { __g610, __a610 },
  { __g611, __a611 },
  { __g612, __a612 },
  { __g613, __a613 },
  { __g614, __a614 },
  { __g615, __a615 },
  { __g616, __a616 },
  { __g617, __a617 },
  { __g618, __a618 },
  { __g619, __a619 },
  { __g620, __a620 },
  { __g621, __a621 },
  { __g622, __a622 },
  { __g623, __a623 },
  { __g624, __a624 },
  { __g625, __a625 },
  { __g626, __a626 },
  { __g627, __a627 },
  { __g628, __a628 },
  { __g629, __a629 },
  { __g630, __a630 },
  { __g631, __a631 },
  { __g632, __a632 },
  { __g633, __a633 },
  { __g634, __a634 },
  { __g635, __a635 },
  { __g636, __a636 },
  { __g637, __a637 },
  { __g638, __a638 },
  { __g639, __a639 },
  { __g640, __a640 },
  { __g641, __a641 },
  { __g642, __a642 },
  { __g643, __a643 },
  { __g644, __a644 },
  { __g645, __a645 },
  { __g646, __a646 },
  { __g647, __a647 },
  { __g648, __a648 },
  { __g649, __a649 },
  { __g650, __a650 },
  { __g651, __a651 },
  { __g652, __a652 },
  { __g653, __a653 },
  { __g654, __a654 },
  { __g655, __a655 },
  { __g656, __a656 },
  { __g657, __a657 },
  { __g658, __a658 },
  { __g659, __a659 },
  { __g660, __a660 },
  { __g661, __a661 },
  { __g662, __a662 },
  { __g663, __a663 },
  { __g664, __a664 },
  { __g665, __a665 },
  { __g666, __a666 },
  { __g667, __a667 },
  { __g668, __a668 },
  { __g669, __a669 },
  { __g670, __a670 },
  { __g671, __a671 },
  { __g672, __a672 },
  { __g673, __a673 },
  { __g674, __a674 },
  { __g675, __a675 },
  { __g676, __a676 },
  { __g677, __a677 },
  { __g678, __a678 },
  { __g679, __a679 },
  { __g680, __a680 },
  { __g681, __a681 },
  { __g682, __a682 },
  { __g683, __a683 },
  { __g684, __a684 },
  { __g685, __a685 },
  { __g686, __a686 },
  { __g687, __a687 },
  { __g688, __a688 },
  { __g689, __a689 },
  { __g690, __a690 },
  { __g691, __a691 },
  { __g692, __a692 },
  { __g693, __a693 },
  { __g694, __a694 },
  { __g695, __a695 },
  { __g696, __a696 },
  { __g697, __a697 },
  { __g698, __a698 },
  { __g699, __a699 },
  { __g700, __a700 },
  { __g701, __a701 },
  { __g702, __a702 },
  { __g703, __a703 },
  { __g704, __a704 },
  { __g705, __a705 },
  { __g706, __a706 },
  { __g707, __a707 },
  { __g708, __a708 },
  { __g709, __a709 },
  { __g710, __a710 },
  { __g711, __a711 },
  { __g712, __a712 },
  { __g713, __a713 },
  { __g714, __a714 },
  { __g715, __a715 },
  { __g716, __a716 },
  { __g717, __a717 },
  { __g718, __a718 },
  { __g719, __a719 },
  { __g720, __a720 },
  { __g721, __a721 },
  { __g722, __a722 },
  { __g723, __a723 },
  { __g724, __a724 },
  { __g725, __a725 },
  { __g726, __a726 },
  { __g727, __a727 },
  { __g728, __a728 },
  { __g729, __a729 },
  { __g730, __a730 },
  { __g731, __a731 },
  { __g732, __a732 },
  { __g733, __a733 },
  { __g734, __a734 },
  { __g735, __a735 },
  { __g736, __a736 },
  { __g737, __a737 },
  { __g738, __a738 },
  { __g739, __a739 },
  { __g740, __a740 },
  { __g741, __a741 },
  { __g742, __a742 },
  { __g743, __a743 },
  { __g744, __a744 },
  { __g745, __a745 },
  { __g746, __a746 },
  { __g747, __a747 },
  { __g748, __a748 },
  { __g749, __a749 }
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
  return ((__p->p1>7)||(__p->p2>7)||(__p->p3>7)||(__p->p4>7)||(__p->p5>7)||(__p->p6>7)||(__p->p7>7)||(__p->p8>7)||(__p->p9>7)||(__p->p10>7)||(__p->p11>7)||(__p->p12>7)||(__p->p13>7)||(__p->p14>7)||(__p->p15>7)||(__p->p16>7)||(__p->p17>7)||(__p->p18>7)||(__p->p19>7)||(__p->p20>7)||(__p->p21>7)||(__p->p22>7)||(__p->p23>7)||(__p->p24>7)||(__p->p25>7)||(__p->p26>7)||(__p->p27>7)||(__p->p28>7)||(__p->p29>7)||(__p->p30>7)||(__p->p31>7)||(__p->p32>7)||(__p->p33>7)||(__p->p34>7)||(__p->p35>7)||(__p->p36>7)||(__p->p37>7)||(__p->p38>7)||(__p->p39>7)||(__p->p40>7)||(__p->p41>7)||(__p->p42>7)||(__p->p43>7)||(__p->p44>7)||(__p->p45>7)||(__p->p46>7)||(__p->p47>7)||(__p->p48>7)||(__p->p49>7)||(__p->p50>7));
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

