#include <simplecpp>

main_program {  
  turtleSim();
  cout << "Enter f for forward, r for right, l for left, q to quit: ";
  bool done=false;
  repeat(20) {
	  if (!done) {
		  char input;
		  cin >> input;
		  if (input == 'f') forward(10);
		  else if (input == 'r') right(90);
		  else if (input == 'l') left(90);
		  else if (input == 'q') {
			  done = true;
			  hide(true);
		  }
		  else {
			  cout << "Invalid input. Ignoring." << endl;
		  }
	  }
  }
  cout << (done ? "Finished." : "Ran out of turns.")
       << " Click to exit" << endl;
  getClick();
}
