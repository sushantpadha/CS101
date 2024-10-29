#include <simplecpp>
main_program {  
  turtleSim();
  int length = 200;
  int nsquig = 10;

  int toothwidth = length/nsquig;
  int toothheight = 2*toothwidth;

  // we start facing parallel to the direction of drawing
  for(int i=0, T=90; i < nsquig; i++, T = -T) {
	  hide(false); getClick(); // pause to let us inspect

	  forward(toothwidth); 
	  left(T);    // turn perpendicular, alternating left/right
	  forward(toothheight);  
	  right(T);   // turn parallel

	  hide(true); wait(1); // inspect without the turtle
  }
}


