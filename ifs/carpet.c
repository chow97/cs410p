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

int main(){
    // canvas heght and width
    sheight = canvas;
    swidth = canvas;
    G_init_graphics(sheight,swidth);
    G_clear();
    G_rgb(0,1,0);

    int i;
    double n;

    for(i = 0; i < ITER; ++i){
        n = drand48();
        if(n < 1.0/9.0) { rule1(); }
        else if(n > 1.0/9.0 && n < 2.0/9.0) { rule2(); }
        else if(n > 2.0/9.0 && n < 3.0/9.0) { rule3(); }
        else if(n > 3.0/9.0 && n < 4.0/9.0) { rule4(); }
        else if(n > 4.0/9.0 && n < 5.0/9.0) { rule5(); }
        else if(n > 5.0/9.0 && n < 6.0/9.0) { rule6(); }
        else if(n > 6.0/9.0 && n < 7.0/9.0) { rule7(); }
        // else if(n > 7.0/9.0 && n < 8.0/9.0) { rule8(); }
        else { rule8(); }
        G_point(x*swidth, y*sheight);
    }
//    for (int i = 0; i < 10000000; ++i) {
//       double n = drand48();
//       if (n < 0.25) rule1();
//       else if (n > 0.25 && n < 0.5) rule2();
//       else if (n > 0.5 && n < 0.75) rule3();

//       else rule4();
//       G_point(x*swidth, y*sheight);
//    }


    G_wait_key();

    return 0;
}