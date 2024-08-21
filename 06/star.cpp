#include <simplecpp>

main_program{
	turtleSim();
	int n = 6;
	int b = 80;
	float sharpness = 0.75; // a number in the range 0 to 1
	// d1 is the angle to turn at the point, and d2 the other angle. we need d1-d2 = 360.0/n
	float d2 = sharpness*(180-360.0/n); // sharpness=1 makes d1 below 180; 0 makes it 360./n
	float d1 = d2+360.0/n; // in the range [360.0/n,180]. 
	repeat(n) {
		forward(b);
		left(d1);
		forward(b);
		right(d2);
	}
	hide(true);
	getClick();
}

