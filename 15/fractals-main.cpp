#include <simplecpp>
#include "fractals.h"

int main() {
	cout << "Fractals available:\n"
		    "1. Koch curve\n"
		    "2. Koch curve (alternating)\n"
		    "3. Sierpiński Triangle\n"
		    "4. Binary Tree Canopy\n"
		    "5. Binary Tree (CS style)\n"
		    "6. Hilbert Curve\n"
		    "Choose the fractal to draw: ";
	int choice; cin >> choice;

	const double width = 800, height = 800, margin = 10;
	turtleSim("Fractal", width+2*margin, height+2*margin);

	hide(true);

	if(choice==1) {
		penUp(); forward(-width/2);
		penDown(); fract::kochCurve(width,6);
	} else if(choice==2) {
		penUp(); forward(-width/2);
		penDown(); fract::kochCurveAlt(width,1,6);
	} else if(choice==3) {
		double side = min(width,height*cosine(30));
		penUp(); right(150); forward(side/(2*cosine(30))); left(150);
		penDown(); fract::sTriangle(side,6); 
	} else if(choice == 4) {
		penUp(); left(90); forward(-height/2);
		penDown(); fract::canopy(height/4,10);
	} else if(choice == 5) {
		penUp(); right(90); forward(-height/2);
		penDown(); fract::binaryTree(height,width,7);
	} else if(choice==6) {
		int level = 3;
		double box = min(min(height,width),20*(pow(2,level+1)-1));
		double step = box/(pow(2,level+1)-1);
		penUp(); forward(-box/2); right(90); forward(box/2); left(90); 
		penDown(); fract::hilbertCurve(step,1,level);
	}
	cout << "Click to exit" << endl;
	getClick();
}

