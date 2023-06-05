#include <stdio.h>
#include <complex.h>
#include "FPToolkit.c"

int Wsize = 800;

void prcmx (char *control, complex c)
//print complex number
{
  double a,b ;
  a = creal(c) ;
  b = cimag(c) ;

  printf(control,a) ;
  if (b >= 0) {
    printf("+") ;
  } else {
    printf("-") ;
  }
  printf(control,fabs(b)) ;  
  printf("I") ;
}

complex check (complex c) {
    // return 1 if diverge - return 0 if converge
    complex z = 0 + 0*I;
    // printf("Entered check function with "); prcmx("%20.16lf",c) ; printf("\n") ;
    for (int i = 0; i < 100; ++i) {
        z = z*z + c;
        if (cabs(z) > 2)
            // { printf ("Diverge\n"); 
            return cabs(z); 
    }


    // printf ("Converge\n");
    return 0;
}

void mandel (double a, double b, int click) {
    double range = 4.0 / pow(2, click);
    double unit = range / Wsize;

    // a is the real part, b is the coefficient

    for (double a_sub = a - range/2; a_sub < a + range/2; a_sub += unit) {
        for (double b_sub = b - range/2; b_sub < b + range/2; b_sub += unit) {
            complex i = check(a_sub + b_sub*I);
            if (i == 0) {
                G_rgb(0,0,0);
            // if (check(a_sub + b_sub*I) == 1) {
                // G_rgb(0.82,0.54,0.82);
            } else {
                G_rgb(0.8/creal(i),0.6/creal(i), 0.4/creal(i) );
                // G_rgb(0.61,0.84,0.93);
            } 
                G_point ((a_sub - a + range/2)*Wsize/range, (b_sub - b + range/2)*Wsize/range);
        }
         
        // for (int i = 0; i < 500000; ++i) {
        //     if (i % 10000 == 0)    {
        //         G_display_image();
        //         usleep(100);
        //     }
        // } 
    }

}

int main () {

    G_init_graphics (Wsize, Wsize) ;  // interactive graphics
    // clear the screen in a given color
    G_rgb (0, 0, 0) ; // black screen
    G_clear () ;

    double a, b;  
    a = 0.0; b = 0.0; // starting a, b
    mandel(0.0, 0.0, 0);
    // mandel(-0.5, -0.5, 5);
    
    double point[2];
    point[0] = 0;
    point[1] = 0;
    double temp[2];
    int click = 0;
    double range = 4.0;
    while (1) {
        G_wait_click(temp);
        ++click;
        // printf("Point: %lf, %lf - click = %d", p[0], p[1], click);
        range = 4.0 / pow(2, click);
        G_rgb (0, 0, 0) ; // black screen
        G_clear () ;
        point[0] += (temp[0]-400)/Wsize*range;
        point[1] += (temp[1]-400)/Wsize*range;
        printf("Point: %lf, %lf - click = %d\n", point[0], point[1], click);

        // mandel(0, 0, click);
        mandel(point[0], point[1], click);
    }
 

    G_wait_key();
    return 0;

}