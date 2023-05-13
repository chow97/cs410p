#include "FPToolkit.c"

typedef struct {
    double x,y;
} point;

void tree (point p1, point p2, int level){
    point p3, p4, p5;    

    p3.x = p2.x - (p1.y -  p2.y);
    p3.y = p2.y - (p2.x -  p1.x);
	
    p4.x = p1.x - (p1.y -  p2.y);
    p4.y = p1.y - (p2.x -  p1.x);
	
    p5.x = p4.x +  ( p2.x - p1.x - (p1.y -  p2.y) ) / 2;
    p5.y = p4.y -  ( p2.x - p1.x +  p1.y -  p2.y  ) / 2;
	 
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
    p1.x = swidth/2 - 50;
    p1.y = sheight/5;
    p2.x = p1.x + 100;
    p2.y = p1.y;
    

    tree(p2, p1, 12);
    tree_trunk(p1, p2);

    G_wait_key();
    G_save_to_bmp_file("xmas_tree.bmp");
    
    return 0;
}
