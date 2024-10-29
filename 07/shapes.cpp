#include <simplecpp>

void move(double dx, double dy) { // interpreting current orientation as 0 degrees
	penUp(); forward(dx); left(90); forward(dy); right(90);
}

void movex(double dx) { move(dx,0); }
void movey(double dy) { move(0,dy); }

// draw a regular polygon centred at the starting point and return to the same point/orientation
// one vertex will be at the top point
// assumes trutleSim has been initialized
void polygon (double radius, int n) {
	left(90);
	penUp();
	forward(radius); left(90); penDown();
	double delta = 360.0/n; // angle to turn in each side in degree
	double side = 2*radius*sin(PI/n);
	left(delta/2);
	for(int i=0; i<n-1; i++) {
		forward(side);
		left(delta);
	}
	forward(side);
	left(delta/2);
	penUp(); left(-90); forward(-radius);
	right(90);
}


void circle(double radius) {
	const int NUMSTEPS = 200;
	polygon(radius, NUMSTEPS);
}

int main() {
	turtleSim();
	int r = 50, s = 5, d = 10;
	polygon(4*r,5);
	circle(r); movex(-2*r-s); circle(r); movex(4*r+2*s); circle(r);
	movex(-r-s/2); movey(-r-d); circle(r); movex(-2*r-s); circle(r);
	hide(true);
	getClick();
}
