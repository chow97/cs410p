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

int main () {

    G_init_graphics (Wsize, Wsize) ;  // interactive graphics
    // clear the screen in a given color
    G_rgb (0, 0, 0) ; // black screen
    G_clear () ;

    double unit = 4/800;

    a is the real part, b is the coefficient
    for (double a = -2.0; a < 2; a = a + unit) {
        for (double b = -2.0; b < 2; a = b + unit) {
            if (check(a + b*I) == 1) {
                G_rgb(0,1,0);
                G_point ((a+2)*800, (b+2)*800);
            } else {
                G_rgb(0,0,1);
                G_point ((a+2)*800, (b+2)*800);
            } 
        }
    }

    G_wait_key();
    return 0;

}