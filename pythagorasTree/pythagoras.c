#include "FPToolkit.c"

typedef struct {
    double x,y;
} point;

void tree (point p1, point p2, int level){
    point p3, p4, p5;    

    p4.x = p1.x - (p2.y -  p1.y);
    p4.y = p1.y - (p1.x -  p2.x);
	
    p3.x = p2.x - (p2.y -  p1.y);
    p3.y = p2.y - (p1.x -  p2.x);
	
    p5.x = p3.x +  ( p1.x - p2.x - (p2.y -  p1.y) ) / 2;
    p5.y = p3.y -  ( p1.x - p2.x +  p2.y -  p1.y  ) / 2;
	 
    if(level > 0){
	G_rgb(drand48(), drand48(), drand48());
		
	G_line(p1.x,p1.y,p2.x,p2.y);
	G_line(p3.x,p3.y,p2.x,p2.y);
	G_line(p3.x,p3.y,p4.x,p4.y);
	G_line(p1.x,p1.y,p4.x,p4.y);
	
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

int main(){
    int swidth, sheight;
    swidth = 800,  sheight = 800;
    
    G_init_graphics(swidth, sheight);
    
    G_rgb(0,0,0);
    G_clear();

    point p1, p2;
    p1.x = swidth *3.6/8;
    p1.y = sheight/10;
    p2.x = swidth - p1.x;
    p2.y = p1.y;
    
    point p3, p4;
    p3.x = swidth *3.7/8;
    p3.y = p1.y + 200;
    p4.x = swidth - p3.x;
    p4.y = p3.y;
    
    point p5, p6;
    p5.x = swidth *3.8/8;
    p5.y = p1.y + 400;
    p6.x = swidth - p5.x;
    p6.y = p5.y;

    point p7, p8;
    p7.x = swidth *3.9/8;
    p7.y = p1.y + 550;
    p8.x = swidth - p7.x;
    p8.y = p7.y;

    // tree(p1, p2, 12);
    // tree(p3, p4, 12);
    // tree(p5, p6, 12);
    // tree(p7, p8, 12);
    // tree_trunk(p1, p2);

    double x[1000];
    double y[1000];
    for (int i = 0; i < 1000; ++i) {
        x[i] = swidth * drand48();
        y[i] = sheight * 6 * drand48() + sheight;
    }

    while (1) {
    //    G_wait_key();
       G_rgb(0,0,0);
       G_clear();

       tree(p1, p2, 12);
       tree(p3, p4, 12);
       tree(p5, p6, 12);
       tree(p7, p8, 12);
       tree_trunk(p1, p2);
       
       for (int i = 0; i < 1000; ++i) {
            G_rgb(1,1,1);
    	    G_fill_circle(x[i], y[i], 2);
       }
       for (int i = 0; i < 1000; ++i) {
            y[i] -= 1;
       }

       for (int i = 0; i < 500000; ++i) {
            if (i % 10000 == 0)    {
                G_display_image();
                usleep(100);
            }
        }

    }   
    
    G_wait_key();
    G_save_to_bmp_file("xmas_tree.bmp");
    
    return 0;
}
