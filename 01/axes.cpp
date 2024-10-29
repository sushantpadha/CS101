#include <simplecpp>

main_program{  
  turtleSim();
  repeat(4) { // one for each axis
	  repeat(5) { // will mark 5 big steps  
		  // big tick
		  right(90); forward(8); forward(-16); forward(8); right(-90);
		  repeat(9) {// 10 small steps form one big step. 9 small ticks
			  forward(5); // small step
			  // small tick
			  right(90); forward(4); forward(-8); forward(4); right(-90);
		  }
		  forward(5); // 10th step
	  }
	  forward(-250); // come back to the origin
	  right(90);     // and turn to the next axis
  }
  hide(true);
  getClick();
}

