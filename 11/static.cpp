#include <simplecpp>

// forward step, optionally after turning by turn degrees
// update static variables to keep track of the position
// and orientation
struct posn { double x, y, deg; };

posn move_and_track(double step, double turn=0) {
	left(turn); forward(step); 
	static posn p = {0, 0, 0}; // initialisation only done once across all calls
	p.deg += turn;
	p.x += step*cosine(p.deg);
	p.y += step*sine(p.deg);
	return p;
}



int main() {
	const double limit = 600;
	const int step = 100;
	turtleSim("",limit+10,limit+10);
	while(1) {
		char command; cin >> command;
		posn p;
		if(command == 'f')
			p = move_and_track(step,0);
		else if (command == 'l')
			p = move_and_track(0,45);
		else if (command == 'r')
			p = move_and_track(0,-45);
		// else ignore
		if(abs(p.x) > limit/2 || abs(p.y) > limit/2) 
			return 0;
	}
}
