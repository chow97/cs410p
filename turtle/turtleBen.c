

/*
If this file and the file, FPToolkit.c, are in the
same directory that you are trying to compile in,  
do the following :

cc  FPToolkitDemoB.c   -lm  -lX11

note : the 'X' in -X11 is capitalized
*/


#include  "FPToolkit.c"
#include  "string_builder.c"

int strleng = 2000000;
double angle = 30.0;
double angle_current = 0;
double length = 1.0;
double x_value, y_value;
double x_current = 100.0;
double y_current = 10.0;
void rotate(double a);
void step();
void values_reset();

void positive_rot() { angle_current += angle; };
void negative_rot() { angle_current -= angle; };
void draw(char str []);
double auto_placer (char str []);

int canvas_size = 800;
int margin = 50;


int main()
{
   char str [strleng];
   // string_builder(str);
   // if you want to use external file, comment out the line above and uncomment the line below:
   scanf("%s", str); 

   int    swidth, sheight ;

   
   // must do this before you do 'almost' any other graphical tasks 
   swidth = canvas_size ;  sheight = canvas_size ;
   G_init_graphics (swidth,sheight) ;  // interactive graphics

   
   // clear the screen in a given color
   G_rgb (0.3, 0.3, 0.3) ; // dark gray
   G_clear () ;
   
   // draw a line
   G_rgb (0.0, 1.0, 0.0) ; // green
//   G_line (0,0, swidth-1, sheight-1) ;


   //===============================================
   

   G_rgb(1,0,0) ;
   
   length = auto_placer(str); 
   // printf("x: %f, y: %f, scale: %f", x_current, y_current, length);
   draw(str); 


   int key ;   
   key =  G_wait_key() ; // pause so user can see results

   //   G_save_image_to_file("demo.xwd") ;
   G_save_to_bmp_file("demo.bmp") ;
}

double auto_placer(char str []) {
   double top_y = 0.0;
   double bot_y = 0.0;
   double right_x = 0.0;
   double left_x = 0.0;

   int i = 0; 
   while (str[i] != '\0' && i < strleng) {
   
   	if (str[i] >= 'A' && str[i] <= 'Z') {
   	   values_reset();
   	   rotate(angle_current);
   	   x_current += x_value;
   	   y_current += y_value;
   	   if (x_current >= right_x) right_x = x_current; 
   	   if (x_current < left_x)   left_x = x_current; 
   	   if (y_current >= top_y)   top_y = y_current; 
   	   if (y_current < bot_y)    bot_y = y_current; 
	   values_reset();
   	}
	else if (str[i] == '+') positive_rot();
        else negative_rot();
	++i;
   }
   
   // finding the height of image:
   double image_height = top_y - bot_y;
   // finding the width of image: 
   double image_width = right_x - left_x;
   
   // the scale:
   double scale;
   if (image_height >= image_width) 
      scale = (canvas_size-(margin*2))/image_height;
   else
      scale = (canvas_size-(margin*2))/image_width;
       
   // finding the center of mass
   double x_center = (right_x + left_x)/2;
   double y_center = (top_y + bot_y)/2;
   
   // setting starting point based on scale and center of mass:
   x_current = (canvas_size/2) - x_center*scale;
   y_current = (canvas_size/2) - y_center*scale;

   return scale;
    
}

void draw (char str[]) {
   int i = 0; 
   while (str[i] != '\0' && i < strleng) {
   	if (str[i] >= 'A' && str[i] <= 'Z') step();
	else if (str[i] == '+') positive_rot();
        else negative_rot();
	++i;
   }	

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
