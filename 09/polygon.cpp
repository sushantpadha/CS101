#include <simplecpp>

// We will create a function for drawing a polygon that accepts several parameters:
// radius: the polygon is inscribed in a circle of radius (before aspect scaling is applied)
//
// n: number of sides
// tilt: degree to be tilted anti-clockwise. tilt=0 keeps a vertex on top centre
// aspect: aspect ratio (width/height). 
// tiltaspect: whether width and height for aspect ratio are defined w.r.t. tilted axes
// centX, centY: move the centre here
//
// After drawing the polygon, the pen is returned to the starting position/orientation
// assumes trutleSim has been initialized


// To illustrate that default arguments can be added right to left in subsequent declarations
void polygon (double radius, int n, double tilt, double aspect, bool tiltaspect, double centX=0, double centY=0);
void polygon (double radius, int n, double tilt, double aspect=1, bool tiltaspect=1, double centX, double centY);
// The function definition will introduce a few more defaults.
// Note that a default argument can be declared only once, and by then all
// arguments to its right must have defaults


// A utility function to handle movement when there is an aspect ratio
// different from 1. This projects the movement of a turtle according to the aspect ratio.
// Original movement is a forward movement of side followed by turn by deg,
// starting by facing towards angle. In the projection it starts by facing
// anglep. The function updates angle and anglep passed by reference.
void project_turn_move(double aspect, double& angle, double& anglep, double deg, double side=0) {
		// instead of moving (dx,dy), move (aspect*dx,dy)
		// anglep such that: tangent(anglep) = tangent(angle)/aspect (and both in the same quadrant)
		// sidep such that: dy = sidep*sine(anglep) = side*sine(angle).
		// if sine(angle)==0, sine(anglep)==0, take sidep = side*aspect
		double sidep = (abs(anglep)<=1E-6 || abs(anglep-180)<=1E-6)? side*aspect: side*sine(angle)/sine(anglep);
		forward(sidep);
		angle += deg;
		if (angle>360) angle -= 360;
		double anglepold = anglep;
		anglep = arctangent( tangent(angle)/aspect );
		if (angle>90 && angle<270) anglep += 180; // arctangent in the range -90 to +90. If angle points left, flip anglep.
		left(anglep - anglepold);
}

void polygon (double radius, int n=3, double tilt=0, double aspect, bool tiltaspect, double centX, double centY) {
	// angle to turn in degrees and length to move, per side (for aspect=1)
	double delta = 360.0/n; 
	double side = 2*radius*sin(PI/n);

	// Go to the centre, then go vertically up (tilted from vertical) to a vertex,
	// and point orthogonal to the radius 
	penUp();
	forward(centX); left(90); forward(centY); 
	left(tilt);
	forward(radius); left(90); 
	penDown();

	// ready to draw now. angle keeps track of the aspect=1 orientation, anglep the actual one
	double angle, anglep;
	// if tiltaspect is true, pretend we start in 180 deg. else use the actual orientation
	angle=anglep=tiltaspect? 180 : 180+tilt;

	project_turn_move(aspect,angle,anglep,delta/2); // turn delta/2, no move
	for(int i=0; i<n-1; i++) {
		project_turn_move(aspect,angle,anglep,delta,side); // n-1 times: one side, turn delta
	}
	project_turn_move(aspect,angle,anglep,delta/2,side); // last side, turn delta/2
	penUp(); 
	left(angle-anglep);  // Turtle returns to starting point. But it has turned to anglep; bring it to angle. 
	left(-90); forward(-radius);
	left(-tilt);
	forward(-centY); left(-90); forward(-centX); 
}


void circle(double radius) {
	const int NUMSTEPS = 100;
	polygon(radius, NUMSTEPS);
}

int main() {
	turtleSim(); hide(true);
	int r = 80, n = 4, d = 45, x = 160, y = 160;
	double a = 0.5;

	polygon(r);                 getClick();		
	polygon(r,n);               getClick();
	polygon(r,n,d);             getClick();
	polygon(r,n,d,a);           getClick();
	polygon(r,n,d,a,0);         getClick();
	polygon(r,n,d,a,1,x);       getClick();
	polygon(r,n,d,a,1,x,y);     getClick();


	closeTurtleSim();
	turtleSim("",800,800);

	for (double asp=1, i=0; i< 5; i++, asp /= 1.1) {
		polygon(r,6,0,asp,1,-200,100);
		polygon(r,6,0,1/asp,1,-200,100);
	}

	for (int i=3; i< 10; i++)
		polygon(r,i,0,1,1,200,100);

	for (int tilt=0; tilt < 180; tilt+=15)
		polygon(r,6,tilt,1,0,1,200);

	for (int tilt=0; tilt < 360; tilt+=15) {
		polygon(r,4,tilt,1.5,0,-200,-100);
		polygon(r,4,tilt,1.5,1,200,-100);
	}
	polygon(r/2,4,45,1.5,0,-200,-300);
	polygon(r/2,4,45,1.5,1,200,-300);

	circle(400);
	polygon(410,50); // 50 sides also works like a circle
	getClick();
}
