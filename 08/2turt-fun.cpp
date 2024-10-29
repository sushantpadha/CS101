#include <simplecpp>


//draw a box centred at the current position. 
//return to original pos/angle and keep pen up.
void drawBox(int limit) {
  penUp(); forward(limit); left(90); penDown();
  for(int i=0; i<4; i++) { forward(limit); left(90); forward(limit); }
  penUp(); left(-90); forward(-limit); 
}

// move by (dx,dy) without changing orientation.
// keep pen up.
void move(int dx, int dy, int deg) {
	  penUp(); left(-deg); forward(dx); left(90); forward(dy); left(deg-90);
}

// check if move (dx,dy) hits the box or if causes collision
bool isValidMove(int x, int y, int xp, int yp, int dx, int dy, int limit, string& msg) {
	if (abs(x+dx) >= limit || abs(y+dy) >= limit) {
		msg = "Can't hit the box!";
		return false;
	} 
	// It is assumed that |xp-x| and |yp-y| are multiples of step. 
	// Collision check is simplified as follows under this assumption.
	if (x+dx==xp && y+dy==yp) {
		msg = "Can't collide!";
		return false;
	}
	return true;
}

// move the turtle forward by distance, either in a straight
// line (if squigglep==0) or by squiggling
void squiggleDraw(double distance, double squigstep) {
	penDown();
	if (squigstep==0) {
		forward(distance);
		return;
	}
	double squight = squigstep; // height of a squiggle
	int squignum = distance/squigstep;
	squigstep = distance/squignum;
	for(int i=0, T=90; i<squignum; i++, T = -T) {
		//after each loop, return to original orientation
		right(T); forward(squight); left(T); 
		forward(squigstep); 
		left(T);  forward(squight); right(T);
	}
}

// in case of error returns a non-empty msg, without changing x,y
string handle_forward(int& x, int& y, int deg, 
		int xp, int yp, int limit, int step, bool squiggle) {
	const int NSQUIGS = 6; // number of squiggles in a step
	int dx = deg==0? step : (deg==180 ? -step : 0);
	int dy = deg==90? step : (deg==270 ? -step : 0);
	string msg = "";
	if (isValidMove(x,y,xp,yp,dx,dy,limit,msg)) {
		double squigstep = squiggle? (step/NSQUIGS) : 0;
		squiggleDraw(step, squigstep); 
		x += dx; y += dy;
	}
	return msg;
}

void swp(int& x, int& y) {
	int tmp = x; 
	x=y; y=tmp;
	//cerr << "int swap!" << endl;
}

// overloading the function swp to work for boolean inputs
void swp(bool& x, bool& y) {
	bool tmp = x; x=y; y=tmp;
	//cerr << "bool swap!" << endl;
}

main_program {  
  turtleSim();
  const int limit=240;
  const int step = 40;

  // Initial positions. 
  int x=-100, y=0, deg=0;  // active turtle's position and orientation (deg is 0, 90, 180 or 270
  int xp=100, yp=0, degp=180; // the other turtle's position and orientation
  bool squiggle = false, squigglep = false;
  // It is assumed that |xp-x| and |yp-y| are multiples of step. 
  // (Collision check is simplified under this assumption.)
  if ((xp-x)%step != 0 || (yp-y)%step != 0) {
	  cerr << "Initial positions not on the grid. Exiting" << endl;
	  return -1;
  }

  // Draw the box
  drawBox(limit);

  // move from (0,0,0) to (x,y,deg)
  move(x,y,0); left(deg);


  cout << "Enter f/r/l (forward/right/left), p (print position), or q (quit): ";
  while(true) {
	  char input; cin >> input;
	  // process the command and update x,y,deg
	  string msg = "";
	  if (input == 'f') { 
		  msg = handle_forward(x,y,deg,xp,yp,limit,step,squiggle);
	  } else if (input == 'l' || input == 'r') {
		  int angle = (input=='l'? 90: 270);
		  left(angle);
		  deg = (deg + angle) % 360;
	  } else if (input == 'q') {
		  cout << "Finished!" << endl;
		  break;
	  } else if (input == 'p') {
		  msg = "Current Position: (" + to_string(x) + "," + to_string(y) + "). Angle: " + to_string(deg);
	  } else if (input == 's') { // hidden feature!
		  squiggle = !squiggle;
		  msg = "Squiggle turned " + string(squiggle? "on" : "off");
		  continue; // don't swap turtles
	  } else {
		  msg = "Invalid input. Ignoring.";
	  }
	  if (msg != "") cout << msg << endl;

	  wait(0.2);
	  // move from (x,y,deg) to (xp,yp,degp) 
	  move(xp-x,yp-y,deg); left(degp-deg);
	  swp(x,xp); swp(y,yp); swp(deg,degp);
	  swp(squiggle,squigglep);
  }
}
