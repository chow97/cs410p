#include  "FPToolkit.c"

int ITER = 10000000;
// canvas size
double canvas = 800.0;
double sheight;
double swidth;

//starting point
double x = 0.0;
double y = 0.0;

void scale(double sfx, double sfy){
    x *= sfx;
    y *= sfy;
}
void translate(double tfx, double tfy){
    x += tfx;
    y += tfy;
}
void rotate(double angle) {
   x = cos(angle*M_PI/180);
   y = sin(angle*M_PI/180);
}
// Babies
void rule1(){
    scale(1.0/3.0, 1.0/3.0);
}
void rule2(){
    scale(1.0/3.0, 1.0/3.0);
    translate(1.0/3.0, 0);
}
void rule3(){
    scale(1.0/3.0, 1.0/3.0);
    translate(2.0/3.0, 0);
}
void rule4(){
    scale(1.0/3.0, 1.0/3.0);
    translate(0, 1.0/3.0);
}
void rule5(){
    scale(1.0/3.0, 1.0/3.0);
    translate(0, 2.0/3.0);
}
void rule6(){
    scale(1.0/3.0, 1.0/3.0);
    translate(1.0/3.0, 2.0/3.0);
}
void rule7(){
    scale(1.0/3.0, 1.0/3.0);
    translate(2.0/3.0, 2.0/3.0);
}
void rule8(){
    scale(1.0/3.0, 1.0/3.0);
    translate(2.0/3.0, 1.0/3.0);
}

void do_nothing() {return;};

int main(){
    // canvas heght and width
    sheight = canvas;
    swidth = canvas;
    G_init_graphics(sheight,swidth);
    G_clear();
    // set color to green
    G_rgb(0,1,0);

    int i;
    double n;

    for(i = 0; i < ITER; ++i){
        n = drand48();
        /* if(n < 1.0/9.0) { rule1(); }
        else if(n > 1.0/9.0 && n < 2.0/9.0) { rule2(); }
        else if(n > 2.0/9.0 && n < 3.0/9.0) { rule3(); }
        else if(n > 3.0/9.0 && n < 4.0/9.0) { rule4(); }
        else if(n > 4.0/9.0 && n < 5.0/9.0) { rule5(); }
        else if(n > 5.0/9.0 && n < 6.0/9.0) { rule6(); }
        else if(n > 6.0/9.0 && n < 7.0/9.0) { rule7(); }
        // else if(n > 7.0/9.0 && n < 8.0/9.0) { rule8(); }
        else { rule8(); }
        */

        	
        if (n < 1.0/4.0) { 
           scale(0.9, 0.9);
	   rotate(10.0);
	   translate(x*0.1, y*0.1);	   
	}
        // else if (n > 1.0/4.0 && n < 2.0/4.0) do_nothing();
        // else if(n > 2.0/4.0 && n < 3.0/4.0) do_nothing();
        // else (n > 3.0/4.0 && n < 4.0/4.0) do_nothing();
	G_point(x*swidth, y*sheight);
    }


    G_wait_key();

    return 0;
}
