#include "FPToolkit.c"

void square(double x0, double y0, double x1, double y1){
    double distance = x1 - x0;
    double x2,y2, x3,y3;
    x2 = x0;
    y2 = y0 + distance;
    x3 = x1;
    y3 = y1 + distance;
    G_line(x0,y0, x1,y1);
    G_line(x0,y0, x2,y2);
    G_line(x2,y2, x3,y3);
    G_line(x3,y3, x1,y1);
}

void triangle(double x0, double y0, double x1, double y1){

}

int main(){
    int swidth, sheight;
    swidth = 600,  sheight = 600;
    G_init_graphics(swidth, sheight);

    double p0[2], p1[2];
    p0[0] = 10;
    p0[1] = 10;
    p1[0] = 40;
    p1[1] = 10;


    G_rgb(0,0,0);
    square(p0[0],p0[1], p1[0],p1[1]);

    G_wait_key();
}