#include "FPToolkit.c"
#include <stdio.h>


double length = 100.0;
void rotate(double a) {
   double temp;
   temp = x_value*cos(a) - y_value*sin(a) ;
   y_value = x_value*sin(a) + y_value*cos(a) ;
   x_value = temp ;
}
void line(double *p, double angle){
    double x,y;
    if(angle == 90){
        x = length;
        y = 0;
    }else if(angle == 0){
        x = 0;
        y = length;
    }else if(angle == -90){
        x = -length;
        y = 0;
    }
    G_line(p[0],p[1], p[0]+x,p[1]+y);
    p[0] = p[0] + x;
    p[1] = p[1] + y;
}
int main(){
    double swidth , sheight ;
    swidth = 800 ;   sheight = 800 ;
    G_init_graphics(swidth,sheight) ;

    double p[2];
    p[0] = 400.0;
    p[1] = 400.0;

    double angle = 90.0;

    int n = 8;
    char u[n];
    strcpy(u, "F+F+FF-F");

    // scanf("%s", u);
    G_rgb(0,0,0);
    for(int i = 0; i < strlen(u); i++){
        printf("%c\n", u[i]);
        if(u[i] != 'F'){
            line(p, angle);
        }
        else if(u[i] == '+'){
            line(p, angle+90.0);
        }
        else if(u[i] == '-'){
            line(p, angle-90.0);
        }
    }
    G_wait_key();
}