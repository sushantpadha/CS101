#include <iostream>
using std::cout; using std::cin; using std::endl; 

// returns an approximation of square-root of x, when called as isqrt(x)
double sqrt(double x, double delta = 1e-12, double left=0, double right=0) {
	if(x<0)
		throw std::domain_error("No real square roots for negative numbers!");

	if(right==0) right = x; // initialize range to [0,x] if called without a range

	if (right < left + delta)  // small enough interval
		return left;   

	double mid = (left+right)/2;
	double sqr = mid*mid;
	if (x < sqr)
		return sqrt(x,delta,left,mid);
	else if (x > sqr)
		return sqrt(x,delta,mid,right);
	else // sqr == x
		return mid;
}

int main() {
	unsigned n;
	cout << "n = "; cin >> n;
	cout << "sqrt n =  " << sqrt(n) << endl;
}
