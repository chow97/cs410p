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
    double t = angle * (M_PI/180);
    double temp;

    temp = (x * cos(t)) - (y * sin(t));
    y = (y * cos(t)) + (x * sin(t));
    x = temp;
}
// Babies
//P
void rule1(){
    scale(5.0/13.0, 1.0/7.0);
    rotate(90.0);
    translate(2.0/13.0,1.0/13.0);
}
void rule2(){
    scale(2.0/13.0, 1.0/7.0);
    translate(2.0/13.0,5.0/13.0);
}
void rule3(){
    scale(2.0/13.0, 1.0/7.0);
    translate(2.0/13.0,3.0/13.0);
}
void rule4(){
    scale(1.0/13.0, 1.0/7.0);
    translate(3.0/13.0,4.0/13.0);
}
//S
void rule5(){
    scale(3.0/13.0, 1.0/7.0);
    translate(5.0/13.0,5.0/13.0);
}
void rule6(){
    scale(3.0/13.0, 1.0/7.0);
    translate(5.0/13.0,3.0/13.0);
}
void rule7(){
    scale(3.0/13.0, 1.0/7.0);
    translate(5.0/13.0,1.0/13.0);
}
void rule8(){
    scale(1.0/13.0, 1.0/7.0);
    translate(5.0/13.0,4.0/13.0);
}
void rule9(){
    scale(1.0/13.0, 1.0/7.0);
    translate(7.0/13.0,2.0/13.0);
}
//U
void rule10(){
    scale(5.0/13.0, 1.0/7.0);
    rotate(90.0);
    translate(10.0/13.0,1.0/13.0);
}
void rule11(){
    scale(5.0/13.0, 1.0/7.0);
    rotate(90.0);
    translate(12.0/13.0,1.0/13.0);
}
void rule12(){
    scale(1.0/13.0, 1.0/7.0);
    translate(10.0/13.0, 1.0/13.0);
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
        if(n < 1.0/12.0) { rule1(); }
        else if(n > 1.0/12.0 && n < 2.0/12.0) { rule2(); }
        else if(n > 2.0/12.0 && n < 3.0/12.0) { rule3(); }
        else if(n > 3.0/12.0 && n < 4.0/12.0) { rule4(); }
        else if(n > 4.0/12.0 && n < 5.0/12.0) { rule5(); }
        else if(n > 5.0/12.0 && n < 6.0/12.0) { rule6(); }
        else if(n > 6.0/12.0 && n < 7.0/12.0) { rule7(); }
        else if(n > 7.0/12.0 && n < 8.0/12.0) { rule8(); }
        else if(n > 8.0/12.0 && n < 9.0/12.0) { rule9(); }
        else if(n > 9.0/12.0 && n < 10.0/12.0) { rule10(); }
        else if(n > 10.0/12.0 && n < 11.0/12.0) { rule11(); }
        else { rule12(); }
        G_point(x*swidth, y*sheight);
    }


    G_wait_key();
    G_save_to_bmp_file("PSU.bmp");
    return 0;
}
