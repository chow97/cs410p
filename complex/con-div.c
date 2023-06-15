#include <stdio.h>
#include <complex.h>
#include "FPToolkit.c"

int Wsize = 800;
int Hsize = 800;

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
    // return a complex if diverge - return 0 if converge
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

int julia_check (complex z, complex c) {
    // return a complex number if diverge - return 0 if converge
    // printf("Entered check function with "); prcmx("%20.16lf",c) ; printf("\n") ;
    
    for (int i = 0; i < 100; ++i) {
        if (cabs(z) > 2)
            // { printf ("Diverge\n"); 
            // return cabs(z);
            return i; 
        z = z*z + c;
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
            } else {
                G_rgb(0.9/creal(i),0.7/creal(i), 0.6/creal(i) );
            } 
                G_point ((a_sub - a + range/2)*Wsize/range, (b_sub - b + range/2)*Wsize/range);
        } 
    }

}

void mandel_zoom (double a, double b, int times) {
    
    
    double range = 4.0;
    for (int i = 0; i < times; ++i) {
    double unit = range / Wsize;

    // a is the real part, b is the coefficient

    for (double a_sub = a - range/2; a_sub < a + range/2; a_sub += unit) {
        for (double b_sub = b - range/2; b_sub < b + range/2; b_sub += unit) {
            complex i = check(a_sub + b_sub*I);
            if (i == 0) {
                G_rgb(0,0,0);
            } else {
                G_rgb(0.9/creal(i),0.7/creal(i), 0.6/creal(i) );
            } 
                G_point ((a_sub - a + range/2)*Wsize/range, (b_sub - b + range/2)*Wsize/range);
        } 
    }
    range -= 0.05;
   for (int i = 0; i < 500000; ++i) {
            if (i % 100000 == 0)    {
                G_display_image();
                usleep(100);
            }
        }
    }

}

void julia (double a, double b) {
    double range = 4.0;
    double unit = range / Wsize;

    // a is the real part, b is the coefficient
    complex c = a + b*I;

    for (double a_sub = -2.0; a_sub < 2.0; a_sub += unit) {
        for (double b_sub = -2.0; b_sub < 2.0; b_sub += unit) {
            complex z = a_sub + b_sub*I;
            int result = julia_check(z, c);
            if (result == 0) {
                G_rgb(0,0,0);
            } else {
                double t = (double)result / 100.0; // Normalize iteration count
                // Define the color gradient
                double red = sin(5 * M_PI * t);
                double green = sin(5 * M_PI * (t + 1.0 / 3.0));
                double blue = sin(5 * M_PI * (t + 2.0 / 3.0));
                G_rgb((red + 1.0) / 2.0, (green + 1.0) / 2.0, (blue + 1.0) / 2.0);
                // G_rgb(  
                //         1/creal(result), // + 0.6/cimag(result),
                //         2/creal(result), // + 0.3/cimag(result), 
                //         3/creal(result)  // + 0.1/cimag(result)
                //     );
            } 
            G_point ((a_sub + 2.0)*Wsize/range, (b_sub + 2.0)*Wsize/range + Hsize/2);
        } 
    }

}

void mandel_set() {
    
    G_init_graphics (Wsize, Wsize) ;  // interactive graphics
    // clear the screen in a given color
    G_rgb (0, 0, 0) ; // black screen
    G_clear () ;
    
    double a, b;  
    a = 0.0; b = 0.0; // starting a, b
    mandel(0.0, 0.0, 0);
    
    double point[2];
    point[0] = 0;
    point[1] = 0;
    double temp[2];
    int click = 0;
    double range = 4.0;
    while (1) {
        G_wait_click(temp);
        ++click;
        range = 4.0 / pow(2, click);
        G_rgb (0, 0, 0) ; // black screen
        G_clear () ;
        point[0] += (temp[0]-400)/Wsize*range;
        point[1] += (temp[1]-400)/Wsize*range;
        printf("Point: %lf, %lf - click = %d\n", point[0], point[1], click);

        // mandel(0, 0, click);
        mandel(point[0], point[1], click);
    }
}

void julia_set() {

    Wsize = 400;
    Hsize = Wsize * 2;

    G_init_graphics (Wsize, Hsize) ;  // interactive graphics
    // clear the screen in a given color
    G_rgb (0, 0, 0) ; // black screen
    G_clear () ;
    
    double point[2];
    point[0] = 0;
    point[1] = 0;
    
    while (1) {
        julia(point[0], point[1]);
        mandel(0.0, 0.0, 0);
        G_wait_click(point);
        point[0] = point[0] * 4.0 / Wsize - 2.0;
        point[1] = point[1] * 4.0 / Wsize - 2.0;
        G_rgb (0, 0, 0) ; // black screen
        G_clear () ;
        
        printf("Point: %lf, %lf\n", point[0], point[1]);
        
    }
}

void julia_set_circle() {

    Wsize = 400;
    Hsize = Wsize * 2;

    G_init_graphics (Wsize, Hsize) ;  // interactive graphics
    // clear the screen in a given color
    G_rgb (0, 0, 0) ; // black screen
    G_clear () ;
    
    double point[2];
    point[0] = 0;
    point[1] = 0;
    
    for (int angle = 0; angle < 360; ++angle) {
        point[0] = cos(angle*M_PI/180) * 0.75;
        point[1] = sin(angle*M_PI/180) * 0.75;
        julia(point[0], point[1]);
        mandel(0.0, 0.0, 0);
        // G_wait_click(point);
        // point[0] = point[0] * 4.0 / Wsize - 2.0;
        // point[1] = point[1] * 4.0 / Wsize - 2.0;
        // G_rgb (0, 0, 0) ; // black screen
        // G_clear () ;
        
        G_rgb(1,1,1);
        G_fill_circle(point[0]*Wsize/4 + Wsize/2, point[1]*Wsize/4 + Wsize/2, 1);

        printf("Point: %lf, %lf\n", point[0], point[1]);
        for (int i = 0; i < 500000; ++i) {
            if (i % 100000 == 0)    {
                G_display_image();
                usleep(100);
            }
        }
        // char fname[100];
        // sprintf(fname, "./directory/plant/plant%04d.bmp", i);
        // G_save_to_bmp_file(fname);

        G_rgb (0, 0, 0) ; // black screen
        G_clear () ;
    }
}

int main () {

    // G_init_graphics (Wsize, Wsize) ;  // interactive graphics
    // clear the screen in a given color
    // G_rgb (0, 0, 0) ; // black screen
    // G_clear () ;

    // mandel_set();
    
    // julia_set();

    julia_set_circle();
    // mandel_zoom(0.39, 0.35, 300);

    // mandel(0.39, 0.35, 2);

    // G_wait_key();
    return 0;

}