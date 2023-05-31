#include <stdio.h>

int main () {

    double z = 0;
    double r;

    printf("Please enter number r: ");
    scanf("%lf", &r);
    for (int i = 0; i < 100000; ++i) {
        z = z*z + r;
        // printf("z: %lf\n", z);
        if (z > 1) { printf("Diverge\n"); return 1; }
    }

    printf ("Converge\n");

    return 0;

}