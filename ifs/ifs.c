#include  "FPToolkit.c"
// int canvas_size = 800;

// void rule1(double x, double y);
// void rule2(double x, double y);


// void rule1(double x, double y){
//     x = x/2;
//     y = y/2;
// }
// void rule2(double x, double y){
//     x = x/2+0.5;
//     y = y/2+0.5;
// }

// int main(){

//     int swidth, sheight;
//     swidth = canvas_size ;  sheight = canvas_size ;

//     double n;
//     n = drand48();

// }

void rule1 ();
void rule2 ();
void rule3 ();
void rule4 ();

int ITER = 1000000;

int canvas_size = 800;
int swidth;
int sheight;
double x = 0.0;
double y = 0.0;

#include  "FPToolkit.c"

void half(double *x ,double *y){
    *x /= 2.0;
    *y /= 2.0;
}
int main() {
   swidth = canvas_size;
   sheight = canvas_size;
   G_init_graphics(swidth, sheight);
   G_rgb (0.3, 0.3, 0.3);
   G_clear();

   G_rgb(0.0, 1.0, 0.0);
    
   
   
   for (int i = 0; i < ITER; ++i) {
      double n = drand48();
      if (n < 1.0/4.0) rule1();
      else if (n > 1.0/4.0 && n < 2.0/4.0) rule2();
      else if (n > 2.0/4.0 && n < 3.0/4.0) rule3();

      else rule4();
   }

   int key;
   key = G_wait_key();

   return 0;
}

void rule1 () {
   // x = x/2.0;
   // y = y/2.0;
   half(&x,&y);
   G_point (swidth*x, sheight*y);
}

void rule2 () {
   // x = x/2.0 + 0.5;
   // y = y/2.0 + 0.5;
   half(&x,&y);
   x += 0.5;
   y += 0.5;
   G_point (swidth*x, sheight*y);
}

void rule3 () {
   // x = x/2.0 + 0.5;
   // y = y/2.0;
   half(&x,&y);
   x += 0.5;
   G_point (swidth*x, sheight*y);
}

void rule4 () {
   // x = x/2.0;
   // y = y/2.0 + 0.5;
   // half(&x,&y);
   // y += 0.5;
   // G_point (swidth*x, sheight*y);
}
