#include <simplecpp>

main_program {  
  turtleSim();
  cout << "Enter s for square, d for diamond: ";
  char input;
  cin >> input;
  if (input == 'd') {
	  right(45);
	  // cout << "Click to proceed" << endl;
	  // getClick();
  }
  if (input == 'd' || input == 's') {
	  // draw a square in the direction the turtle is facing
	  repeat(4) { forward(100); right(90); }
	  hide(true);
	  getClick();
  }
  else {
	  cout << "Invalid input. Exiting.";
  }
}
