#include <simplecpp>

// program to inscribe squares inside squares, drawn using dashed lines.
// the number and attributes of the squares are hard-coded.
main_program {
	turtleSim();
	int nsqr = 4; // number of squares to draw
	float side = 400, step = 5; // length of a side of the square, and of a dash (approx)

	//move turtle so that square will have origin at centre
	penUp();
	forward(-side/2); left(90); forward(side/2); right(90);
	penDown();
	
	for (int k = 0; k < nsqr; ++k, side /= sqrt(2)) { // for each square, with side length decreasing
		for (int it = 1, nsteps = side/step; it <= nsteps*4; ++it) { // for each step around the square
			// counting from 1: no turn at the beginning, turn at the end
			if (it%2==0) penDown(); else penUp(); // dashed line
			forward(side/nsteps);  // move approximately step long
			if (it%nsteps == 0) right(90); // at the 4 corners we will turn
		}
		// prepare for the next inner square
		penUp(); forward(side/2); right(45); penDown();
	}
	hide(true);
	getClick();
}
