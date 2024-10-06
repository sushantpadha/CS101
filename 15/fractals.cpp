#include <simplecpp>
#include "fractals.h"

void fract::kochCurve(double len, int level) {
	if(level==0) {
		forward(len); return;
	}
	kochCurve(len/3,level-1);
	left(60);
	kochCurve(len/3, level-1);
	right(120);
	kochCurve(len/3, level-1);
	left(60);
	kochCurve(len/3, level-1);
}

void fract::kochCurveAlt(double len, int sign, int level) {
	if(level==0) {
		forward(len); return;
	}
	kochCurveAlt(len/3, -sign, level-1);
	left(sign*60);
	kochCurveAlt(len/3, sign, level-1);
	right(sign*120);
	kochCurveAlt(len/3, sign, level-1);
	left(sign*60);
	kochCurveAlt(len/3, -sign, level-1);
}

void fract::sTriangle(double side, int level) {
	for(int i=0; i<3; i++) {
		forward(side); left(120);
	}
	if(level==0) return;
	sTriangle(side/2, level-1);
	penUp(); forward(side/2); penDown();
	sTriangle(side/2, level-1);
	penUp(); left(120); forward(side/2); right(120); penDown(); 
	sTriangle(side/2, level-1);
	penUp(); right(120); forward(side/2); left(120); penDown();
}

void fract::canopy(double step, int level, double angle, double ratio) {
	if (level == 0)
		return;
	forward(step);
	left(angle/2);
	canopy(step*ratio,level-1,angle,ratio);
	right(angle);
	canopy(step*ratio,level-1,angle,ratio);
	left(angle/2);
	forward(-step);
}


void fract::binaryTree(double boxHeight, double boxWidth, int levels) {
	if (levels == 0)
		return;

	double edgeHeight = boxHeight/levels;
	double angle = arctangent((boxWidth/4)/edgeHeight);
	double edgeLen = edgeHeight/cosine(angle);

	double childBoxHeight = boxHeight - edgeHeight;
	double childBoxWidth = boxWidth/2;

	// draw a line to the left child, draw tree there and come back
	// then repeat on the right side
	for(int i=0; i<2; i++, angle = -angle) {
		left(angle); forward(edgeLen); left(-angle);
		binaryTree(childBoxHeight, childBoxWidth, levels-1);
		left(angle); forward(-edgeLen); left(-angle);
	}
}

void fract::hilbertCurve(double step, int sign, int level) {
	int deg = sign*90;
	double len = (pow(2,level+1)-1)*step;
	if(level==0) {
		left(deg);  forward(len); 
		right(deg); forward(len); 
		right(deg); forward(len); 
		left(deg);
		return;
	}
	
	left(deg);
	hilbertCurve(step,-sign,level-1); forward(step);
	right(deg);
	hilbertCurve(step,sign,level-1); forward(step);
	hilbertCurve(step,sign,level-1); 
	right(deg); forward(step);
	hilbertCurve(step,-sign,level-1); 
	left(deg);
}

