#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#include <ctype.h>
#include "FPToolkit.c"

int Wsize = 800;

// void prcmx (char *control, complex c)
// //print complex number
// {
//   double a,b ;
//   a = creal(c) ;
//   b = cimag(c) ;

//   printf(control,a) ;
//   if (b >= 0) {
//     printf("+") ;
//   } else {
//     printf("-") ;
//   }
//   printf(control,fabs(b)) ;  
//   printf("I") ;
// }

int check (complex c) {
    // return 1 if diverge - return 0 if converge
    complex z = 0;
    // printf("Entered check function with "); prcmx("%20.16lf",c) ; printf("\n") ;
    for (int i = 0; i < 100; ++i) {
        z = z*z + c;
        if (cabs(z) > 2) {return 1; } //diverge
    }

    return 0; //converge
}
void draw(double x, double y, complex c){
    // return 1 if diverge - return 0 if converge
    complex z = 0;
    // printf("Entered check function with "); prcmx("%20.16lf",c) ; printf("\n") ;
    for (int i = 0; i < 100; ++i) {
        z = z*z + c;
        if (cabs(z) > 2.5) {
            G_rgb(0,0,1);
            G_point((x+2)*Wsize/4, (y+2)*Wsize/4);
        } //diverge
        else{
            G_rgb(1,0,1);
            G_point((x+2)*Wsize/4, (y+2)*Wsize/4);
        }
    }
    // double n = drand48();
    // if(n < 1.0/3.0){
    //     G_rgb(0,0,1);
    //     G_point((x+2)*Wsize/4, (y+2)*Wsize/4);
    // }
    // else if(n < 2.0/3.0){
    //     G_rgb(0,0,0);
    //     G_point((x+2)*Wsize/4, (y+2)*Wsize/4);
    // }
    // else{
    //     G_rgb(1,0,0);
    //     G_point((x+2)*Wsize/4, (y+2)*Wsize/4);
    // }
}

int main () {

    G_init_graphics (Wsize, Wsize) ;  // interactive graphics
    // clear the screen in a given color
    G_rgb (0, 0, 0) ; // black screen
    G_clear () ;
    double unit = 4.0/800.0;
    for(double y = -2.0; y <= 2.0; y += unit){
        for(double x = -2.0; x <= 2.0; x += unit){
            if(check(x+y*I) == 1){
                G_rgb(0,0,1);
                G_point((x+2)*Wsize/4, (y+2)*Wsize/4);
                // draw(x,y,x+y*I);
            }
            else{
                G_rgb(0,0,0);
                G_point((x+2)*Wsize/4, (y+2)*Wsize/4);
                // draw(x,y,x+y*I);
            }

        }
    }



    G_wait_key();
    return 0;
}