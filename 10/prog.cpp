/*** commented out. Uncomment to see #error in action ***
#if __cplusplus < 201103
#error Please use -std=c++11 option while compiling // Error
#endif
**********************************************************/

#include <iostream>
#include "numbers.h"
using std::cout; using std::cin; using std::cerr; using std::endl;

int main() {
	cout << "Enter two non-negative numbers: ";
	int a, b; cin >> a >> b;
	if (cin.fail() || a<0 || b<0) { cerr << "Bad input!" << endl; return -1; }
	cout << a << " and " << b << " are " << (num::PFE(a,b) ? "":"not ") << "PFE!\n";
	if(a==0 && b==0) {cout << "GCD(0,0) is not well-defined!\n"; return 0; }
	cout << "Their GCD is " << num::GCD(a,b) << endl;
}


