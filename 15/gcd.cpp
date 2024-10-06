#include <iostream>
using std::cout; using std::cin; using std::endl;

// returns gcd(a,b) and sets m,n so that ma+nb=gcd(a,b)
int gcd (int a, int b, int& m, int& n) {
	if(b==0) {
		n = 0; m = a<0? -1 : 1;
		return abs(a);  // keep gcd non-negative
	}
	// Recurse: gcd(a,b) = gcd(b,a-qb), where q=a/b
	// If g = m'b + n'(a-qb) = n'a + (m'-qt)b, set m=n', n=n'-m'q
	int g = gcd(b,a%b,n,m);
	n -= m*(a/b);
	return g;
}


int main() {
	int a, b, m, n, g;
	cout << "Enter two numbers: ";
	cin >> a >> b;
	g = gcd(a,b,m,n);
	cout << g << " = (" << m << ") * (" << a << ") + (" << n << ") * (" << b << ")" << endl;
}


