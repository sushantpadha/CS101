#include <iostream>
using std::cout; using std::cin; using std::endl; 

// returns integer part of square-root of x, when called as isqrt(x)
unsigned isqrt(unsigned x, unsigned left=0, unsigned right=0) {
	if(right==0) right = x; // if called without a range
	if (right < left) { // we just passed the square-root
		return right;   // right has the smaller number
	}
	unsigned mid = (left+right)/2;
	int sqr = mid*mid;
	if (x < sqr)
		return isqrt(x,left,mid-1);
	else if (x > sqr)
		return isqrt(x,mid+1,right);
	else // sqr == x
		return mid;
}

int main() {
	unsigned n;
	cout << "n = "; cin >> n;
	cout << "sqrt n (rounded down) =  " << isqrt(n) << endl;
}
