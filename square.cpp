#include <simplecpp>

// draw a square
main_program {
	// create window + turtle @ center facing right
	turtleSim();
	repeat(4) {
		forward(100); right(90);
	}
	getClick(); // wait for click
}
