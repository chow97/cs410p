#include "FPToolkit.c"

typedef struct {
    double x,y;
} point;

void tree (point p1, point p2, int level){
    point p3, p4, p5;    

    p3.x = p2.x - (p2.y -  p1.y);
    p3.y = p2.y - (p1.x -  p2.x);

    p4.x = p1.x - (p2.y -  p1.y);
    p4.y = p1.y - (p1.x -  p2.x);
	
    p5.x = p3.x +  ( p1.x - p2.x - (p2.y -  p1.y) ) / 2;
    p5.y = p3.y -  ( p1.x - p2.x +  p2.y -  p1.y  ) / 2;
	 
    if(level > 0){
	G_rgb(drand48(), drand48(), drand48());
		
	G_line(p1.x,p1.y,p2.x,p2.y);
	G_line(p2.x,p2.y,p3.x,p3.y);
	G_line(p3.x,p3.y,p4.x,p4.y);
	G_line(p4.x,p4.y,p1.x,p1.y);
	
	tree(p4,p5,level-1);
	tree(p5,p3,level-1);
    }
}

void tree_trunk(point p1, point p2) {
    int height = p2.x - p1.x;
    for (int i = 0; i + 10 < height; i += 10) {
           G_rgb (1, 1, 1);
        for (int white = 0; white < 5; ++ white) {
           int y = p1.y + i + white;
           G_line(p1.x, y, p2.x, y);
        }
           G_rgb (1, 0, 0);
        for (int red = 5; red < 10; ++ red) {
           int y = p1.y + i + red;
           G_line(p1.x, y, p2.x, y);
        
        }
    }
}

void star (double x, double y, double size) {

    G_rgb(0.94,0.77,0.38);

    int a = 30;  // angle
    double c = cos(a*M_PI/180) * size;
    double s = sin(a*M_PI/180) * size;

    G_fill_triangle(c + x, s + y, -c + x, s + y, x, y - size);
    G_fill_triangle(c + x, -s + y, -c + x, -s + y, x, y + size);

}

int main(){
    int swidth, sheight;
    swidth = 800,  sheight = 800;
    
    G_init_graphics(swidth, sheight);
    
    G_rgb(0,0,0);
    G_clear();

    // parameters for tree 1
    point p1, p2;
    p1.x = swidth *3.6/8;
    p1.y = sheight/10;
    p2.x = swidth - p1.x;
    p2.y = p1.y;

    // parameters for tree 2
    point p3, p4;
    p3.x = swidth *3.7/8;
    p3.y = p1.y + 200;
    p4.x = swidth - p3.x;
    p4.y = p3.y;
    
    // parameters for tree 3
    point p5, p6;
    p5.x = swidth *3.8/8;
    p5.y = p1.y + 400;
    p6.x = swidth - p5.x;
    p6.y = p5.y;

    // parameters for tree 4
    point p7, p8;
    p7.x = swidth *3.9/8;
    p7.y = p1.y + 550;
    p8.x = swidth - p7.x;
    p8.y = p7.y;

    // coordinates for snow
    double x[1000];
    double y[1000];

    // giving snow random initial coordinates but above the screen
    for (int i = 0; i < 1000; ++i) {
        x[i] = swidth * drand48();
        y[i] = sheight * 6 * drand48() + sheight;
    }

    int frames = 1000;
    for (int i = 1; i < frames; ++i) {
       G_rgb(0,0,0);
       G_clear();

       tree(p1, p2, 12);
       tree(p3, p4, 12);
       tree(p5, p6, 12);
       tree(p7, p8, 12);
       tree_trunk(p1, p2);
       
       double star_size = 40.0;
       star (swidth/2, p7.y + star_size * 3, star_size);

       for (int i = 0; i < 1000; ++i) {
            G_rgb(1,1,1);
    	    G_fill_circle(x[i], y[i], 2);
       }

       // snow falling down 2 pixels each frame
       for (int i = 0; i < 1000; ++i) {
            y[i] -= 2;
       }

        // drawing the ground that is fading from black to white
        G_rgb((double)i/frames, (double)i/frames, (double)i/frames);
        // G_rgb(1,1,1);
        G_fill_rectangle(0.0, 0.0, swidth, p1.y);
        

       for (int i = 0; i < 500000; ++i) {
            if (i % 10000 == 0)    {
                G_display_image();
                usleep(100);
            }
        }

        // saving a bmp file for this frame
        char fname[100];
        sprintf(fname, "./xmas%04d.bmp", i);
        G_save_to_bmp_file(fname); 

    }   
    return 0;
}
