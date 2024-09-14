#include <simplecpp>

struct Turt {
	int x, y, deg;
	bool squiggle;
};

struct TurtSet {
	Turt t1, t2, t3;
	int actv; // which one is active (1, 2, or 3).

	Turt& getActv() {
		return actv<=1 ? t1 : (actv==2 ? t2: t3) ;
	}

	// check that x and y distances between turtles are multiples of step. 
	bool gridCheck(int step) {
		return (t2.x - t1.x)%step == 0 && (t2.y - t1.y)%step == 0
			   && (t3.x - t1.x)%step == 0 && (t3.y - t1.y)%step == 0 ;
	}
};

////////////// Declaring functions used by main ////////////////
void drawBox(int limit);
void moveTo(const Turt& toTurt, const Turt& fromTurt = {0,0,0});
string handle_forward(TurtSet& tset, int limit, int step);
void turtSim(int size=500, string title="Turtle Window");
////////////////////////////////////////////////////////////////

int main() {  
  const int limit=400;
  const int step = 50;
  turtSim(2*limit+10); // make a big enough window
  drawBox(limit); // Draw the box
  // Initialize our turtle set
  TurtSet tset = { .t1 = { -200, 0, 0, false},
	               .t2 = { 0, 0, 90, false},
				   .t3 = { 200, 0, 180, false},
				   .actv = 1 };

  if (!tset.gridCheck(step) ) {
	  cerr << "Initial positions not on the grid. Exiting" << endl;
	  return -1;
  }

  moveTo(tset.getActv()); 

  cout << "1/2/3 to select turtle, f/r/l/s (forward/right/left/squiggle toggle),\np (print position), or q (quit).\nEnter a command: ";
  while(true) { // invariant: the pen will be at the active turtle's position

	  // read the command and process it below
	  char input; cin >> input;

	  // first select the active turtle from the set
	  Turt& turt = tset.getActv();

	  if (input >= '1' && input <= '3') { // selecting a turtle
		  tset.actv = input - '1' + 1;
		  Turt& newturt = tset.getActv();
		  moveTo(newturt,turt); // move to newturt from turt
	  } else if (input == 'f') { 
		  cout << handle_forward(tset,limit,step);
	  } else if (input == 'l' || input == 'r') {
		  int angle = (input=='l'? 90: 270);
		  turt.deg = (turt.deg + angle) % 360;
		  left(angle);
	  } else if (input == 'q') {
		  cout << "Finished!" << endl;
		  return 0;
	  } else if (input == 'p') {
		  cout << "Current Position: (" << turt.x << "," << turt.y << "). Angle: " << turt.deg << endl;
	  } else if (input == 's') { 
		  turt.squiggle = !turt.squiggle;
		  cout << "Squiggle turned " <<  string(turt.squiggle? "on" : "off") << endl;
	  } else {
		  cout << "Invalid input. Ignoring." << endl;
	  }
	  wait(0.01);
  }
}

////////////// Defining the remaining functions ////////////////

//draw a (2*limit)x(2*limit) box centred at the current position. 
//return to original pos/angle and keep pen up.
void drawBox(int limit) {
  penUp(); forward(limit); left(90); penDown();
  for(int i=0; i<4; i++) { forward(limit); left(90); forward(limit); }
  penUp(); left(-90); forward(-limit); 
}

// move to a turtle's (x,y,deg) starting from a given turtle, by default (0,0,0).
// keep pen up.
void moveTo(const Turt& turt, const Turt& turtold) {
	  penUp(); 
	  left(-turtold.deg); 
	  forward(turt.x-turtold.x); left(90); 
	  forward(turt.y-turtold.y); 
	  left(turt.deg-90);
}

// check if by moving by (dx,dy) active turtle will hit the box or another turtle
bool isValidMove(TurtSet& tset, int dx, int dy, int limit, string& msg) {
	if (dx==0 && dy==0) return true; // no move
	const Turt& turt = tset.getActv(); 
	if (abs(turt.x+dx) >= limit || abs(turt.y+dy) >= limit) {
		msg = "Can't hit the box!";
		return false;
	} 
	// one of the following checks, which compares the active turtle with
	// itself, is redundant but harmless (since one of dx, dy is non-zero)
	if ( (turt.x+dx==tset.t1.x && turt.y+dy==tset.t1.y) 
	   ||(turt.x+dx==tset.t2.x && turt.y+dy==tset.t2.y) 
	   ||(turt.x+dx==tset.t3.x && turt.y+dy==tset.t3.y) ) {
		msg = "Can't collide!";
		return false;
	}
	return true;
}

// this is where the actual turtleSim drawing happens. the pen will be at
// the active turtle before the call, and at the new position after the call
// move the turtle forward by distance, either in a straight
// line (if !squiggle) or by squiggling
void squiggleDraw(const Turt& turt, double distance, const int NSQUIGS = 6) {
	penDown();
	if (!turt.squiggle) {
		forward(distance);
	}
	else {
		double squigstep = distance/NSQUIGS; 
		double squight = squigstep; // height of a squiggle
		for(int i=0, T=90; i<NSQUIGS; i++, T = -T) {
			//after each loop, return to original orientation
			right(T); forward(squight); left(T); 
			forward(squigstep); 
			left(T);  forward(squight); right(T);
		}
	}
	return;
}

// in case of error, return a non-empty msg, without affecting any of the turtles
// otherwise, draw it and update the turtle's coordinates
string handle_forward(TurtSet& tset, int limit, int step) {
	Turt& turt = tset.getActv();
	int dx = turt.deg==0? step : (turt.deg==180 ? -step : 0);
	int dy = turt.deg==90? step : (turt.deg==270 ? -step : 0);
	string msg = "";
	if (isValidMove(tset,dx,dy,limit,msg)) {
		squiggleDraw(turt, step); 
		turt.x += dx; turt.y += dy;
	}
	return msg==""?"":msg+"\n";  // ready to print message
}

// turtleSim() requires specifying a title, if specifying window size.
// tutSim() allows specifying only one side (square window), with or without
// specifying a title
void turtSim(int size, string title) {
	turtleSim(title.c_str(),size,size);
}
