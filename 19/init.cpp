#include <iostream>
using std::cout; using std::cin; using std::endl;

class box {
	const int h = 100, w = 100;
public:
	box() {  // h, w get set to 100
		cout << "No args: Created a box with h = " << h << ", w = " << w << endl;
	}
	box(int a) : h(a) {  // w gets set to 100
		cout << "1 arg: Created a box with h = " << h << ", w = " << w << endl;
	}
	box(int a, int b) : h{a}, w(b) { // can use list syntax {a} or argument syntax (b)
		cout << "2 args: Created a box with h = " << h << ", w = " << w << endl;
	}
	box(bool x, int a=500, int b=500) : h(a), w(b) {
		cout << "3 args: Created a box with h = " << h << ", w = " << w << endl;
	}
};

class boxes {
	box A = 22; // calls constructor with single argument. can also write box A = {22}; or, box A{22};
	box B = {33,44}; // calls constructor with two arguments. can also write box B{33,44};
	box C{true,55}; // can also write box C = {true,55};
public:
	boxes() :  B{true} {}
};

int main() {
	box A;
	box B(20);
	box C(30,40);
	box D(true,12);
	boxes BB;
}


