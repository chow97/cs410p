#include "FPToolkit.c"
#include <stdio.h>
#include <math.h>

double mid(double p0, double p1){
    return (p0+p1) / 2;
}

void triangle(double x0, double y0,double x1,double y1,double x2,double y2,int level){
    
    double x01,y01, x02,y02, x12,y12;
    x01 = mid(x0,x1);
    y01 = mid(y0,y1);
    x02 = mid(x0,x2);
    y02 = mid(y0,y2);
    x12 = mid(x1,x2);
    y12 = mid(y1,y2);
    G_triangle(x01,y01, x12,y12, x02,y02);
    if(level > 1){
        triangle(x0,y0, x01,y01, x02,y02, level - 1);
        triangle(x01,y01, x1,y1, x12,y12, level - 1);
        triangle(x02,y02, x12,y12, x2,y2, level - 1);
    }
}

int main(){

    int level;

    printf("Enter the number of level: ");
    scanf("%d", &level);

    int swidth, sheight;
    swidth = 600,  sheight = 600;
    G_init_graphics(swidth, sheight);


    double p0[2], p1[2], p2[2];
    p0[0] = 10, p0[1] = 100;
    p1[0] = 590, p1[1] = 100;

    double base = p1[0] - p0[0];

    double rbase = mid(p0[0], p1[0]) - p0[0];

    p2[0] = mid(p0[0],p1[0]);
    p2[1] = sqrt(base*base - rbase*rbase);
    
    G_rgb(0,0,0);

    G_triangle(p0[0],p0[1], p1[0],p1[1], p2[0],p2[1]);
    triangle(p0[0],p0[1], p1[0],p1[1], p2[0],p2[1] ,level);

    int key;
    key = G_wait_key();

    return 0;
}
