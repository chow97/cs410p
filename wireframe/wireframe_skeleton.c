#include "FPToolkit.c"

/*

       Y+
       |
       |    * (y,z)
       |  
<------+--------Z+
   D   |
       |
       |


y'    y
- =  ---
D    D+z

H = D*tan(halfangle) ;

with the x-axis perpendicular to this plane.

*/

#define M 700000
double Wsize = 800  ; // window size ... choose 600 for repl
double X[M],Y[M],Z[M] ;
double Xplot[M],Yplot[M] ;
int N = 0 ;


int translate(double dx, double dy, double dz) 
{
  int i ;

  for (i = 0 ; i < N ; i++) {
    X[i] += dx ;
    Y[i] += dy ;
    Z[i] += dz ;    
  }
}



int rotate_x(double degrees)
// Y[] and Z[] will change but X[] will be unchanged
{
  double radians,c,s,temp ;
  int i ;
  
  radians = degrees*M_PI/180 ;
  c = cos(radians) ;
  s = sin(radians) ;
  for (i = 0 ; i < N ; i++) {
    temp =  c*Y[i] - s*Z[i] ;
    Z[i] =  s*Y[i] + c*Z[i] ;
    Y[i] = temp ;
  }
}




int rotate_y(double degrees)
// X[] and Z[] will change but Y[] will be unchanged
{
  double radians,c,s,temp ;
  int i ;
  
  radians = degrees*M_PI/180 ;
  c = cos(radians) ;
  s = sin(radians) ;
  for (i = 0 ; i < N ; i++) {
    temp =  c*X[i] + s*Z[i] ;
    Z[i] = -s*X[i] + c*Z[i] ;
    X[i] = temp ;
  }
}



int rotate_z(double degrees)
// X[] and Y[] will change but Z[] will be unchanged
{
  double radians,c,s,temp ;
  int i ;
  
  radians = degrees*M_PI/180 ;
  c = cos(radians) ;
  s = sin(radians) ;
  for (i = 0 ; i < N ; i++) {
    temp =  c*X[i] - s*Y[i] ;
    Y[i] =  s*X[i] + c*Y[i] ;
    X[i] = temp ;
  }
}



int project(double observer_distance, double halfangle_degrees)
{

  // student work goes here
  for (int i = 0; i < M; ++i) {
	Xplot[i] = (X[i] * Wsize)/(observer_distance * tan(halfangle_degrees)) + Wsize/2; 
	Yplot[i] = (Y[i] * Wsize)/(observer_distance * tan(halfangle_degrees)) + Wsize/2;
  } 
  rotate_x(2);
  
}


int draw()
{
  int i ;
  for (i = 0 ; i < N ; i=i+2) {
    G_line(Xplot[i],Yplot[i],  Xplot[i+1],Yplot[i+1]) ;
  }

}



int print_object()
{
  int i ;
  for (i = 0 ; i < N ; i=i+2) {
    printf("(%lf, %lf, %lf)   (%lf, %lf, %lf)\n", 
	   X[i],Y[i],Z[i],  X[i+1],Y[i+1],Z[i+1]) ;
  }

  printf("===============================\n") ;
  
  for (i = 0 ; i < N ; i=i+2) {
    printf("(%lf, %lf)   (%lf, %lf)\n", 
	   Xplot[i],Yplot[i],  Xplot[i+1],Yplot[i+1]) ;
  }  
}



int save_line(double xs, double ys, double zs,
	      double xe, double ye, double ze)
{
  // about to add items at slots N and N+1 :
  if (N+1 >= M) {
    printf("full\n") ;
    return 0 ;
  }
  
  X[N] = xs ; Y[N] = ys ; Z[N] = zs ; N++ ;
  X[N] = xe ; Y[N] = ye ; Z[N] = ze ; N++ ;

  return 1 ;
}




int build_pyramid()
{
  int n,k ;
  double a,x[100],z[100],yv ;

  N = 0 ; // global
  
  n = 4 ;
  for (k = 0; k <= n ; k++) {
    a = k * 2*M_PI/n ; 
    x[k] = cos(a) ;
    z[k] = sin(a) ;
  }

  yv = -1 ;
  for (k = 0; k < n ; k++) {
    save_line(0,2,0,  x[k],yv,z[k]) ;
    save_line(x[k],yv,z[k],    x[k+1],yv,z[k+1]) ;
  }  
  
}


int build_cube() {

  double x[100], z[100], y[100];
  
  x[0] = 0; y[0] = 0; z[0] = 0;
  x[1] = 2; y[1] = 0; z[1] = 0;
  x[2] = 2; y[2] = 0; z[2] = 2;
  x[3] = 0; y[3] = 0; z[3] = 2;
  
  x[4] = 0; y[4] = 2; z[4] = 0;
  x[5] = 2; y[5] = 2; z[5] = 0;
  x[6] = 2; y[6] = 2; z[6] = 2;
  x[7] = 0; y[7] = 2; z[7] = 2;
  
  save_line(x[0],y[0],z[0], x[1],y[1],z[1]);
  save_line(x[0],y[0],z[0], x[3],y[3],z[3]);
  save_line(x[1],y[1],z[1], x[2],y[2],z[2]);
  save_line(x[2],y[2],z[2], x[3],y[3],z[3]);
  
  save_line(x[4],y[4],z[4], x[5],y[5],z[5]);
  save_line(x[5],y[5],z[5], x[6],y[6],z[6]);
  save_line(x[6],y[6],z[6], x[7],y[7],z[7]);
  save_line(x[7],y[7],z[7], x[4],y[4],z[4]);


  save_line(x[0],y[0],z[0], x[4],y[4],z[4]);
  save_line(x[1],y[1],z[1], x[5],y[5],z[5]);
  save_line(x[2],y[2],z[2], x[6],y[6],z[6]);
  save_line(x[3],y[3],z[3], x[7],y[7],z[7]);
}





int test_pyramid()
{
  G_init_graphics(Wsize,Wsize) ;
  G_rgb(0,0,0) ;
  G_clear() ;
  G_rgb(0,1,0) ;

  build_pyramid() ;
  project(5,45) ;
  draw() ;
  print_object() ;
  
  G_wait_key() ;
}

int test_cube()
{
  G_init_graphics(Wsize,Wsize) ;
  G_rgb(0,0,0) ;
  G_clear() ;
  G_rgb(0,1,0) ;

  build_cube() ;
  project(5,45) ;
  draw() ;
  print_object() ;
  
  G_wait_key() ;

}


int test_pyramid_rotate()
{
  //  G_choose_repl_display() ; // not too bad as a repl movie
  G_init_graphics(Wsize,Wsize) ;

  build_pyramid() ;
  
  while (1) {
    G_rgb(0,0,0) ;
    G_clear() ;
    G_rgb(0,1,0) ;
    project(3,45) ;
    draw() ;
    rotate_y(2) ;
//    rotate_x(2);  
    if (G_wait_key() == 'q') { break ; }
  }
  
}

int test_cube_rotate()
{
  //  G_choose_repl_display() ; // not too bad as a repl movie
  G_init_graphics(Wsize,Wsize) ;

  build_cube() ;
  
  while (1) {
    G_rgb(0,0,0) ;
    G_clear() ;
    G_rgb(0,1,0) ;
    project(3,45) ;
    draw() ;
    rotate_y(2) ;
    rotate_x(2);  
    if (G_wait_key() == 'q') { break ; }
  }
  
}




int main()
{
   // test_pyramid() ;
   // test_pyramid_rotate() ;
   test_cube_rotate();

}
