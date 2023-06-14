#include "FPToolkit.c"
#include <math.h>

// Canvas size
double canvas = 800.0;
double sheight;
double swidth;

// Starting point
double x = 0.0;
double y = 0.0;

void scale(double sfx, double sfy) {
    x *= sfx;
    y *= sfy;
}

void translate(double tfx, double tfy) {
    x += tfx;
    y += tfy;
}

void rule1() {
    double newx = 0.85 * x + 0.04 * y;
    double newy = -0.04 * x + 0.85 * y + 1.6;
    x = newx;
    y = newy;
}

void rule2() {
    double newx = 0.2 * x - 0.26 * y;
    double newy = 0.23 * x + 0.22 * y + 1.6;
    x = newx;
    y = newy;
}

void rule3() {
    double newx = -0.15 * x + 0.28 * y;
    double newy = 0.26 * x + 0.24 * y + 0.44;
    x = newx;
    y = newy;
}

void rule4() {
    scale(0, 0.16);
}

int main() {
    // Canvas height and width
    sheight = canvas;
    swidth = canvas;

    G_init_graphics(sheight, swidth);
    G_rgb(0, 1, 0);  // Set color to green

    int ITER = 1000000;

    for (int i = 0; i < ITER; ++i) {
        double n = drand48();
        if (n < 0.85) {
            rule1();
        } else if (n < 0.92) {
            rule2();
        } else if (n < 0.99) {
            rule3();
        } else {
            rule4();
        }

        G_point(40 * x + swidth / 2, 40 * y);
    }

    G_wait_key();
    G_save_to_bmp_file("BarnsleyFern.bmp");

    return 0;
}
