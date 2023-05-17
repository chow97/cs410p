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
//    x = cos(angle*M_PI/180);
//    y = sin(angle*M_PI/180);
    double r, a;
    double t = angle * (M_PI/180);
    double temp;
    double c,s;
    c= cos(t);
    s = sin(t);

    temp = (x*c) - (y*s);
    y = (y*c) + (x*s);
    x = temp;
}
void rule1(){
    scale(1.0/13.0, 1.0/5.0);
    translate(2.0/13.0,2.0/13.0);
}
void rule2(){
    scale(3.0/13.0, 1.0/5.0);
    rotate(90.0);
    translate(2.0/13.0,1.0/13.0);
}
void rule3(){
    scale(3.0/13.0, 1.0/5.0);
    rotate(90.0);
    translate(4.0/13.0,1.0/13.0);
}
void rule4(){
    scale(3.0/13.0, 1.0/5.0);
    translate(5.0/13.0,3.0/13.0);
}
void rule5(){
    scale(2.0/13.0, 1.0/5.0);
    rotate(90.0);
    translate(7.0/13.0,1.0/13.0);
}
void rule6(){
    scale(3.0/13.0, 1.0/5.0);
    rotate(90.0);
    translate(10.0/13.0,1.0/13.0);
}
void rule7(){
    scale(2.0/13.0, 1.0/5.0);
    translate(10.0/13.0,3.0/13.0);
}
void rule8(){
    scale(2.0/13.0, 1.0/5.0);
    translate(10.0/13.0,1.0/13.0);
}

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
        if(n < 1.0/8.0) { rule1(); }
        else if(n > 1.0/8.0 && n < 2.0/8.0) { rule2(); }
        else if(n > 2.0/8.0 && n < 3.0/8.0) { rule3(); }
        else if(n > 3.0/8.0 && n < 4.0/8.0) { rule4(); }
        else if(n > 4.0/8.0 && n < 5.0/8.0) { rule5(); }
        else if(n > 5.0/8.0 && n < 6.0/8.0) { rule6(); }
        else if(n > 6.0/8.0 && n < 7.0/8.0) { rule7(); }
        else { rule8(); }
        G_point(x*swidth, y*sheight);
    }


    G_wait_key();
    G_save_to_bmp_file("HTC.bmp");

    return 0;
}
