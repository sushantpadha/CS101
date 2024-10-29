#include <simplecpp>

main_program {  
  turtleSim();
  const int limit=240;
  const int step = 40;

  // Draw the box and return to origin
  penUp(); forward(limit); left(90); penDown();
  for(int i=0; i<4; i++) { forward(limit); left(90); forward(limit); }
  penUp(); left(-90); forward(-limit); penDown();

  // Initial positions. It is assumed that |xp-x| and |yp-y| are multiples of step. (Collision
  // check is simplified under this assumption.)
  int x=-100, y=0, deg=0;  // active turtle's position and orientation (deg is 0, 90, 180 or 270
  int xp=100, yp=0, degp=180; // the other turtle's position and orientation
  bool squiggle = false, squigglep = false;

  // move from (0,0,0) to (x,y,deg)
  penUp(); forward(x); left(90); forward(y); left(deg-90); penDown();

  cout << "Enter f/r/l (forward/right/left), p (print position), or q (quit): ";
  while(true) {
	  char input; cin >> input;
	  // process the command and update x,y,deg
	  if (input == 'f') { 
		  int dx = deg==0? step : (deg==180 ? -step : 0);
		  int dy = deg==90? step : (deg==270 ? -step : 0);
		  if (abs(x+dx) >= limit || abs(y+dy) >= limit) {
			  cout << "Can't hit the box!" << endl;
		  } else if (x+dx==xp && y+dy==yp) {
			  cout << "Can't collide!" << endl;
		  } else {
			  if (!squiggle) forward(step);
			  else { // squiggle step forward
				  for(int i=0, T=90; i<6; i++, T = -T) {
					  forward(step/6.0); left(T); forward(step/3); right(T);
				  }
			  }
			  x += dx; y += dy;
		  }
	  } else if (input == 'l') {
		  left(90);
		  deg = (deg + 90) % 360;
	  } else if (input == 'r') {
		  left(270);
		  deg = (deg + 270) % 360;
	  } else if (input == 'q') {
		  break;
	  } else if (input == 'p') {
		  cout << "Current Position: (" << x << "," << y << ") angle: " << deg << endl;
	  } else if (input == 's') { // hidden feature!
		  squiggle = !squiggle;
		  cout << "Squiggle turned " << (squiggle? "on" : "off") << endl;
		  continue; // don't swap turtles
	  } else {
		  cout << "Invalid input. Ignoring." << endl;
	  }

	  wait(0.2);
	  // move from (x,y,deg) to (xp,yp,degp) 
	  penUp(); left(-deg); forward(xp-x); left(90); forward(yp-y); left(degp-90); penDown();

	  // swap active and inactive turtle states
	  int tmp;
	  tmp = x; x = xp; xp = tmp;
	  tmp = y; y = yp; yp = tmp;
	  tmp = deg; deg = degp; degp = tmp;
	  bool stmp = squiggle; squiggle = squigglep; squigglep = stmp;
  }
}
