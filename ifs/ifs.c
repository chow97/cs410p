#include  "FPToolkit.c"
int canvas_size = 800;

void rule1(double x, double y);
void rule2(double x, double y);


void rule1(double x, double y){
    x = x/2;
    y = y/2;
}
void rule2(double x, double y){
    x = x/2+0.5;
    y = y/2+0.5;
}

int main(){

    int swidth, sheight;
    swidth = canvas_size ;  sheight = canvas_size ;

    double n;
    n = drand48();

}
