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

int check (complex c) {
    // return 1 if diverge - return 0 if converge
    complex z = 0 + 0*I;
    printf("Entered check function with "); prcmx("%20.16lf",c) ; printf("\n") ;
    for (int i = 0; i < 100; ++i) {
        z = z*z + c;
        if (cabs(z) > 2)
            { printf ("Diverge\n"); return 1; }
    }

    printf ("Converge\n");
    return 0;
}

void mandel (double a, double b, int click) {
    double range = 4.0 / pow(2, click);
    double unit = range / Wsize;

    // a is the real part, b is the coefficient

    for (double a_sub = a - range/2; a_sub < a + range/2; a_sub += unit) {
        for (double b_sub = b - range/2; b_sub < b + range/2; b_sub += unit) {
            if (check(a_sub + b_sub*I) == 1) {
                G_rgb(0.82,0.54,0.82);
                G_point ((a_sub - a + range/2)*Wsize/range, (b_sub - b + range/2)*Wsize/range);
            } else {
                G_rgb(0.61,0.84,0.93);
                G_point ((a_sub - a + range/2)*Wsize/range, (b_sub - b + range/2)*Wsize/range);
            } 
        }
         
        for (int i = 0; i < 500000; ++i) {
            if (i % 10000 == 0)    {
                G_display_image();
                usleep(100);
            }
        }
    }

}

int main () {

    G_init_graphics (Wsize, Wsize) ;  // interactive graphics
    // clear the screen in a given color
    G_rgb (0, 0, 0) ; // black screen
    G_clear () ;

    double a, b;  
    a = 0.0; b = 0.0; // starting a, b
    // mandel(0.0, 0.0, 0);
    mandel(-0.6, -0.6, 7);
    
    // double p[2];
    // while (1) {
    //     G_wait_click(p);

    // }
    

    G_wait_key();
    return 0;

}