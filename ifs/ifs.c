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
int canvas_size = 800;
int swidth;
int sheight;
double x = 0.5;
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
      if (n > 0.5) rule1();
      else rule2();
   }

   int key;
   key = G_wait_key();

   return 0;
 
   
}

void rule1 () {
   x = x/2;
   y = y/2;
   G_point (swidth*x, sheight*y);
}

void rule2 () {
   x = x/2 + 0.5;
   y = y/2 + 0.5;
   G_point (swidth*x, sheight*y);
}
