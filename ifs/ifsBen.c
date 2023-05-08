
/*
If this file and the file, FPToolkit.c, are in the
same directory that you are trying to compile in,  
do the following :

cc  FPToolkitDemoB.c   -lm  -lX11

note : the 'X' in -X11 is capitalized
*/

void rule1 ();
void rule2 ();
void rule3 ();
void rule4 ();
void rule5 ();
void rule6 ();
void rule7 ();
void rule8 ();
void rule9 ();

int canvas_size = 800;
int swidth;
int sheight;
double x = 0.3;
double y = 0.5;

#include  "FPToolkit.c"

int main() {
   swidth = canvas_size;
   sheight = canvas_size;
   G_init_graphics(swidth, sheight);
   G_rgb (0.3, 0.3, 0.3);
   G_clear();

   G_rgb(0.0, 1.0, 0.0);
    
   
   
   for (int i = 0; i < 1000000; ++i) {
      double n = drand48();
      if (n < 0.11) rule1();
      else if (n > 0.11 && n < 0.22) rule2();
      else if (n > 0.22 && n < 0.33) rule3();
      else if (n > 0.33 && n < 0.44) rule4();
      else if (n > 0.44 && n < 0.55) rule5();
      else if (n > 0.55 && n < 0.66) rule6();
      else if (n > 0.66 && n < 0.77) rule7();
      else if (n > 0.77 && n < 0.88) rule8();
      else rule9();
   }

   int key;
   key = G_wait_key();

   return 0;
 
   
}

void rule1 () {
   x = x/2.0;
   y = y/2.0;
   G_point (swidth*x, sheight*y);
}

void rule2 () {
//   x = x/2.0 + 1/3;
//   y = y/2.0 + 1/3;
//   G_point (swidth*x, sheight*y);
}

void rule3 () {
   x = x/2.0 + 2/3;
   y = y/2.0 + 2/3;
   G_point (swidth*x, sheight*y);
}

void rule4 () {
   x = x/2.0 + 1/3;
   y = y/2.0;
   G_point (swidth*x, sheight*y);
}

void rule5 () {
   x = x/2.0 + 2/3;
   y = y/2.0;
   G_point (swidth*x, sheight*y);
}

void rule6 () {
   x = x/2.0;
   y = y/2.0 + 1/3;
   G_point (swidth*x, sheight*y);
}

void rule7 () {
   x = x/2.0;
   y = y/2.0 + 2/3;
   G_point (swidth*x, sheight*y);
}

void rule8 () {
   x = x/2.0 + 1/3;
   y = y/2.0 + 2/3;
   G_point (swidth*x, sheight*y);
}
void rule9 () {
   x = x/2.0 + 2/3;
   y = y/2.0 + 1/3;
   G_point (swidth*x, sheight*y);
}
