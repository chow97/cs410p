#include <stdio.h>
#include <complex.h>
#include "FPToolkit.c"

int Wsize = 800;
int Hsize = 800;

int check (complex c) {
    // return a complex if diverge - return 0 if converge
    complex z = 0 + 0*I;
    for (int i = 0; i < 100; ++i) {
        z = z*z + c;
        if (cabs(z) > 2)
            // { printf ("Diverge\n"); 
            return i; 
    }
    // printf ("Converge\n");
    return 0;
}


void mandel_zoom (double a, double b, int times) {
    double range = 4.0;
    for (int i = 0; i < times; ++i) {
    double unit = range / Wsize;
    // a is the real part, b is the coefficient
        for (double a_sub = a - range/2; a_sub < a + range/2; a_sub += unit) {
            for (double b_sub = b - range/2; b_sub < b + range/2; b_sub += unit) {
                int i = check(a_sub + b_sub*I);
                if (i == 0) {
                    G_rgb(0,0,0);
                } else {
                    double t = (double)i / 100.0; // Normalize iteration count
                    // Define the color gradient
                    double red = sin(5 * M_PI * t);
                    double green = sin(5 * M_PI * (t + 1.0 / 3.0));
                    double blue = sin(5 * M_PI * (t + 2.0 / 3.0));
                    G_rgb((red + 1.0) / 2.0, (green + 1.0) / 2.0, (blue + 1.0) / 2.0);
                } 
                G_point((a_sub - a + range/2)*Wsize/range, (b_sub - b + range/2)*Wsize/range);
            } 
        }
            // Change this number for zoom factor
            range -= 0.01*range;
            // uncomment/comment this for live view of code
            for (int i = 0; i < 500000; ++i) {
                if (i % 100000 == 0)    {
                    G_display_image();
                    usleep(100);
                }
            }

            // uncomment/comment this for making movie bmp
            // char fname[400];
            // sprintf(fname, "img%04d.bmp", i);
            // G_save_to_bmp_file(fname);

    }

}


int main () {

    G_init_graphics (Wsize, Wsize) ;  // interactive graphics
    // clear the screen in a given color
    G_rgb (0, 0, 0) ; // black screen
    G_clear () ;

    // set the desired coordinates to zoom into and the number of clicks on that point.
    int click = 400;
    double zoomx, zoomy;
    zoomx =-0.743643135;
    zoomy = 0.131825963; 
    mandel_zoom(zoomx, zoomy, click);

    // mandel_zoom(-0.730000, 0.280000, 800);

    return 0;

}