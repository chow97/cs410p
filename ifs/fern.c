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
    scale(2.0/8.0, 1.0/5.0);
    translate(1.0/8.0,1.0/5.0);
}
void rule2(){
    scale(2.0/8.0, 1.0/5.0);
    rotate(90.0);

    translate(1.0/8.0,1.0/5.0);
}
void rule3(){
    scale(2.0/8.0, 1.0/5.0);
    translate(7.0/8.0,1.0/5.0);
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
        if(n < 1.0/3.0) { rule1(); }
        else if(n > 1.0/3.0 && n < 2.0/3.0) { rule2(); }
        else { rule3(); }
        G_point(x*swidth, y*sheight);
    }


    G_wait_key();

    return 0;
}
