#include <iostream>
#include <cassert>

using std::cout; using std::cin; using std::endl;

int gcd_loop (int a, int b) {
	while(b!=0) {
		std::swap(a,b); b %= a;
	}
	return abs(a); 
}

int gcd (int a, int b) {
	return (b==0)? abs(a) : gcd(b,a%b);
}

int main() {
	int a, b, g1, g2;
	cout << "Enter two numbers: ";
	cin >> a >> b;
	g1 = gcd(a,b);
	g2 = gcd_loop(a,b);
	assert(g1==g2);
	cout << "GCD = " << g1 << endl;
}


