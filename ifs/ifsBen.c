
/*
If this file and the file, FPToolkit.c, are in the
same directory that you are trying to compile in,  
do the following :

cc  FPToolkitDemoB.c   -lm  -lX11

note : the 'X' in -X11 is capitalized
*/

void rule1 (double x, double y);
void rule2 (double x, double y);
int canvas_size = 800;
int swidth;
int sheight;

#include  "FPToolkit.c"

int main() {
   G_init_graphics(swidth, sheight);
   G_rgb (0.3, 0.3, 0.3);
   G_clear();

   G_rgb(0.0, 1.0, 0.0);
    
   int swidth = canvas_size;
   int sheight = canvas_size;
   
   double x = 0.3;
   double y = 0.5;
   
   for (int n = 0; n < 1000000; ++n) {
      double n = drand48();
      if (n < 0.5) rule1(x, y);
      else rule2(x,y);
   }

   int key;
   key = G_wait_key();

   return 0;
 
   
}

void rule1 (double x, double y) {
   x = x/2;
   y = y/2;
   G_point (swidth*x, sheight*y);
}

void rule2 (double x, double y) {
   x = x/2 + 0.5;
   y = y/2 + 0.5;
   G_point (swidth*x, sheight*y);
}
