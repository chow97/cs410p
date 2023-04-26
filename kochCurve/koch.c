#include "FPToolkit.c"
#include <stdio.h>
#include <math.h>

double one_third(double x, double y){
    double len = y-x;
    return len * (1.0 / 3.0);
}
double two_third(double x, double y){
    double len = y-x;
    return len * (2.0 / 3.0);
}
double mid(double x, double y){
    return (x+y) / 2;
}

void line(double x0,double y0, double x1,double y1 ,double x2,double y2){
    G_rgb(0,0,0);
    G_line(x0,y0, x2,y2);
    G_line(x2,y2, x1,y1);
    //draw white line to erase base of triangle
    G_rgb(1,1,1);
    G_line(x0+1,y0, x1-1,y1);
    G_rgb(0,0,0);
}

void koch(double x0, double y0, double x1, double y1, double level){

    double x01,y01, x02,y02, x12,y12;
    x01 = x0 + one_third(x0, x1);
    y01 = y0 + one_third(y0, y1);
    x02 = x0 + two_third(x0, x1);
    y02 = y0 + two_third(y0, y1);
    x12 = mid(x0,x1);
    double base, rbase;
    base = x02 - x01;
    rbase = x12 - x01;
    y12 = y0 + sqrt(base*base - rbase*rbase);
    line(x01,y01, x02,y02, x12,y12);
    if(level > 1){
        koch(x0,y0, x01,y01, level - 1);
        koch(x01,y01, x12,y12, level - 1);
        koch(x12,y12, x02,y02, level - 1);
        koch(x02,y02, x1,y1, level - 1);
    }

}


int main(){

    // int level;

    // printf("Enter the number of level: ");
    // scanf("%d", &level);

    int swidth, sheight;
    swidth = 600,  sheight = 600;
    G_init_graphics(swidth, sheight);

    double p0[2], p1[2], p2[2], m[2];
    // p0[0] = 10, p0[1] = 100;
    // p1[0] = 590, p1[1] = 100;
    p0[0] = 10, p0[1] = 100;
    p1[0] = 590, p1[1] = 200;

    G_line(p0[0],p0[1], p1[0],p1[1]);
    double x0, x1, y0, y1, x2, y2, mx, my;
    x0 = p0[0];
    x1 = p1[0];
    y0 = p0[1];
    y1 = p1[1];

    // koch(x0,y0, x1,y1, 2);

    x0 = p0[0] + one_third(p0[0], p1[0]);
    y0 = p0[1] + one_third(p0[1], p1[1]);

    x1 = p0[0] + two_third(p0[0], p1[0]);
    y1 = p0[1] + two_third(p0[1], p1[1]);
    
    G_wait_key();
    return 0;
}