#include "FPToolkit.c"
#include <math.h>

// Canvas size
double canvas = 800.0;
double sheight;
double swidth;

// Starting point
double x = 0.0;
double y = 0.0;

/*
Transformation matrix:

    |a   b| |x|   |e|
    |     | | | + | |
    |c   d| |y|   |f|
    
    ax + by = x' + e
    cx + dy = y' + f
*/
void transformation(double a, double b, double c, double d, double e, double f){
    double newx = (a*x + b*y) + e;
    double newy = (c*x + d*y) + f;
    x = newx;
    y = newy;
}

void rule1() {
    transformation(1.0/2.0,-1.0/2.0,1.0/2.0,1.0/2.0, 0,0);
}

void rule2() {
    transformation(-1.0/2.0,-1.0/2.0,1.0/2.0,-1.0/2.0, 2.0,0);
}

void dragon(int c){

    int ITER = 10000000;

    for (int i = 0; i < ITER; ++i) {
        double n = drand48();
        if (n < 1.0/2.0) {
            rule1();
        }
        else{
            rule2();
        }
        double t = (double)c / 100.0; // Normalize iteration count
        // Define the color gradient
        double red = sin(2 * M_PI * t);
        double green = sin(2 * M_PI * (t + 1.0 / 3.0));
        double blue = sin(2 * M_PI * (t + 2.0 / 3.0));
        G_rgb((red + 1.0) / 2.0, (green + 1.0) / 2.0, (blue + 1.0) / 2.0);
        G_point((200*x+200),(200*y+200));
    }
}

int main() {
    // Canvas height and width
    sheight = canvas;
    swidth = canvas;

    G_init_graphics(sheight, swidth);
    G_rgb(0, 0, 0); 
    G_clear();

    for (int c = 1; c < 360; ++c) {
        G_rgb(0, 0, 0);  // Set color to black
        G_clear();
        x = 0.0;
        y = 0.0;
        dragon(c);
        for (int i = 0; i < 500000; ++i) {
            if (i % 100000000 == 0) {
                G_display_image();
                usleep(100);
            }
        }
    }

    G_wait_key();

    return 0;
}
