#include  "FPToolkit.c"
#include  "string_builder.c"
#include "stack.c"

struct bracket{
	double angle;
	double x, y;
};

int strleng = 2000000;
double angle = 60.0;
double angle_current = 0;
double length = 25.0;
double x_value, y_value;
double x_current = 300.0;
double y_current = 300.0;
void rotate(double a);
void step();
void values_reset();

void positive_rot() { angle_current += angle; };
void negative_rot() { angle_current -= angle; };

int main()
{
   char str [strleng];
   string_builder(str);
   // if you want to use external file, comment out the line above and uncomment the line below:
//   scanf("%s", str); 

   int    swidth, sheight ;
   double lowleftx, lowlefty, width, height ;
   double x[10], y[10] ;
   double numxy ;
   double a[20], b[20] ;
   double numab ;
   bracket point;

   
   // must do this before you do 'almost' any other graphical tasks 
   swidth = 400 ;  sheight = 600 ;
   G_init_graphics (swidth,sheight) ;  // interactive graphics

   
   // clear the screen in a given color
   G_rgb (0.3, 0.3, 0.3) ; // dark gray
   G_clear () ;
   
   // draw a line
   G_rgb (0.0, 1.0, 0.0) ; // green
//   G_line (0,0, swidth-1, sheight-1) ;


   //===============================================
   

   G_rgb(1,0,0) ;
   
    int i = 0;
    while (str[i] != '\0' && i < strleng) {
    if (str[i] >= 'A' && str[i] <= 'Z') step();
    else if (str[i] == '+') positive_rot();
    else if (str[i] == '-') negative_rot();
    else if (str[i] == '[') {
        point.angle = angle_current;
        point.x = x_current;
        point.y = y_current;
        push(&stack, &point);
    }
    else if (str[i] == ']') {
        pop(&stack, &point);
        angle_current = point.angle;
        x_current = point.x;
        y_current = point.y;
    }
    ++i;
    }	
   


   int key ;   
   key =  G_wait_key() ; // pause so user can see results

   //   G_save_image_to_file("demo.xwd") ;
   G_save_to_bmp_file("demo.bmp") ;
}

void rotate(double a) {
   x_value = length*cos(a*M_PI/180);
   y_value = length*sin(a*M_PI/180);
}

void step() {
   values_reset();
   rotate(angle_current);
   G_line (x_current, y_current,  x_current+ x_value, y_current + y_value);
   x_current += x_value;
   y_current += y_value;
   values_reset();
}

void values_reset() {
   x_value = length;
   y_value = 0;
}


    int i = 0;
    while (str[i] != '\0' && i < strleng) {
    if (str[i] >= 'A' && str[i] <= 'Z') step();
    else if (str[i] == '+') positive_rot();
    else if (str[i] == '-') negative_rot();
    else if (str[i] == '[') {
        point.angle = angle_current;
        point.x = x_current;
        point.y = y_current;
        push(&stack, &point);
    }
    else if (str[i] == ']') {
        pop(&stack, &point);
        angle_current = point.angle;
        x_current = point.x;
        y_current = point.y;
    }
    ++i;
    }	