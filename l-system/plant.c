#include "FPToolkit.c"
#include "string_builder.c"
#include "stack.c"

int strleng = 2000000;
// set angle to move
double angle = 22.5;

double angle_current = 90.0;

const int Wsize = 800;
// unit to draw
double length = 0.5;
double x_value, y_value;
// start drawing from this point
double x_current = Wsize/2;
double y_current = 50.0;
double y_max = 0.0;

void rotate(double a);
void step();
void values_reset();

void positive_rot() { angle_current += angle; };
void negative_rot() { angle_current -= angle; };

void draw(char * str);

double red_plant = 0.73;
double green_plant = 0.39;
double blue_plant = 0.05;

double red_leaf = 0.64;
double green_leaf = 0.71;
double blue_leaf = 0.17;

int main()
{
   char str [strleng];
   string_builder_level(str, 9);
   strleng = strlen(str);

   // if you want to use external file, comment out the line above and uncomment the line below:
   //   scanf("%s", str); 
 
   G_init_graphics (Wsize,Wsize) ;  // interactive graphics
   // clear the screen in a given color
    G_rgb (0, 0, 0) ; // black
   G_clear () ;
   
   //===============================================

   
   draw(str);
   

   G_save_to_bmp_file("fall-plant.bmp") ;

   return 0;
}

void rotate(double a) {
   x_value = length*cos(a*M_PI/180);
   y_value = length*sin(a*M_PI/180);
}

void step() {
   values_reset();
   rotate(angle_current);
 
   G_rgb(red_plant,green_plant,blue_plant) ;
   
   G_line (x_current, y_current,  x_current+ x_value, y_current + y_value);
   x_current += x_value;
   y_current += y_value;

   values_reset();
}

void values_reset() {
   x_value = length;
   y_value = 0;
}


void draw(char * str) {
   struct stack* stack = createStack(100);
      int i = 0;
      while (str[i] != '\0' && i < strleng) {
         if (str[i] >= 'A' && str[i] <= 'Z') step();
         else if (str[i] == '+') positive_rot();
         else if (str[i] == '-') negative_rot();
         else if (str[i] == '[') {
            struct bracket point;
            point.angle = angle_current;
            point.x = x_current;
            point.y = y_current;
            push(stack, point);
         }
         else if (str[i] == ']') {
            double leaf_shade = (0.1 + i) / strleng / 30000;
            red_leaf += leaf_shade/2.5;
            green_leaf -= leaf_shade/2;
            blue_leaf -= leaf_shade;
            G_rgb(red_leaf, green_leaf, blue_leaf);
            G_fill_circle(x_current,y_current,length) ;
            struct bracket point;
            point = peek(stack);
            angle_current = point.angle;
            x_current = point.x;
            y_current = point.y;
            pop(stack);
         }
         ++i;
      }	
}
