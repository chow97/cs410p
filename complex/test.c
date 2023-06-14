#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#include <ctype.h>
#include "FPToolkit.c"

int Wsize = 800;

void draw(double x, double y, complex c) {
    complex z = 0;

    for (int i = 0; i < 100; ++i) {
        z = z * z + c;
        if (cabs(z) > 2.0) {
            // Diverged, assign color based on iteration count
            double t = (double)i / 100.0; // Normalize iteration count
            // Define the color gradient
            double red = sin(5 * M_PI * t);
            double green = sin(5 * M_PI * (t + 1.0 / 3.0));
            double blue = sin(5 * M_PI * (t + 2.0 / 3.0));
            G_rgb((red + 1.0) / 2.0, (green + 1.0) / 2.0, (blue + 1.0) / 2.0);
            G_point(x, y);
            return;
        }
    }

    // Converged, assign black color
    G_rgb(0, 0, 0);
    G_point(x, y);
}

void zoom(double x, double y, double zoomFactor) {
    double click_x = (x / Wsize) * 4.0 - 2.0;
    double click_y = (y / Wsize) * 4.0 - 2.0;
    printf("%lf, %lf\n", click_x, click_y);

    double zoomedXmin = click_x - (2.0 / zoomFactor);
    double zoomedXmax = click_x + (2.0 / zoomFactor);
    double zoomedYmin = click_y - (2.0 / zoomFactor);
    double zoomedYmax = click_y + (2.0 / zoomFactor);
    double range = zoomedXmax - zoomedXmin;

    G_clear();

    double unit = range / Wsize;
    for (double cy = zoomedYmin; cy <= zoomedYmax; cy += unit) {
        for (double cx = zoomedXmin; cx <= zoomedXmax; cx += unit) {
            // draw((cx + 2) * Wsize / range, (cy + 2) * Wsize / range, cx + cy * I);
            // draw((cx + (range/4)) * Wsize / range, (cy + (range/4)) * Wsize / range, cx + cy * I);
            draw((cx  + range/2)*Wsize/range, (cy  + range/2)*Wsize/range, cx + cy * I);
        }
    }
}

int main() {
    G_init_graphics(Wsize, Wsize);
    G_rgb(0, 0, 0);
    G_clear();
    double unit = 4.0 / Wsize;

    for (double y = -2.0; y <= 2.0; y += unit) {
        for (double x = -2.0; x <= 2.0; x += unit) {
            draw((x + 2) * Wsize / 4, (y + 2) * Wsize / 4, x + y * I);
        }
    }

    double zoomLevel = 1.0;
    double zoomFactor = 1.1; // Adjust the zoom factor as desired

    while (1) {
        double temp[2];
        G_wait_click(temp);

        zoomLevel *= zoomFactor;
        zoom(temp[0], temp[1], zoomLevel);
    }

    G_wait_key();
    return 0;
}
