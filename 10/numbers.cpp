#include "numbers.h"
#include <cmath>    // provides std::abs

///////// computing GCD using Euclid's Algorithm /////////
// if a==0 && b==0, returns 0 (GCD(0,0) is not well-defined)
int num::GCD(int a, int b) {
	if (a<0) a = -a;
	if (b<0) a = -b;
	for (int r = a%b; r>0; r = a%b) {
		a = b; b = r; 
	}
	return b;
}

int num::LCM(int a, int b) {
	return std::abs(a*b)/GCD(a,b); // GCD here is num::GCD
}

bool num::coprimes(int a, int b) {
	return GCD(a,b) == 1;
}

/////////////////////////////
// Remove from x all its common factors with w;
// if x is 0, return 0 (cannot really remove factors from 0)
int num::reduce(int w, int x) {
	if (x==0) return 0;
	for (int g = GCD(w,x); g>1; x/=g, g = GCD(w,x)) { }
	return x;
}


bool num::PFE(int w, int x) {
	return covers(w,x) && covers(x,w);
}

///////////////////////// 
// check if w covers x: i.e., all prime factors of x are present in w.
bool num::covers(int w, int x) {
	return w==0 || reduce(w,x)==1;
}
