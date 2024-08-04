#include <simplecpp>

main_program {
	turtleSim();
	repeat(4) {
		forward(150);
		right(90);
	}
	getClick();
}

