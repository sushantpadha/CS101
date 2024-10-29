#include <iostream>
using std::cout; using std::endl; using std::string;

int g, x; // global variables

void f(int g)  { // local parameter g 
	cout << __LINE__ << "\tf\t###\t" << g << " (p)\t" << x << "\t-\n";
	for (int g=x/2; g>0; g--, x++) { // a new local g
		cout << __LINE__ << "\tfor\t###\t" << g << "\t" << x; // can see global x still
		string x = "CS 101" ; // local x, shadows global x
		cout << "\t" << x << endl;
	} // local g goes out of scope
	cout << __LINE__ << "\tf\t###\t" << g << " (p)\t" << x << "\t-\n";
	int x = g; // a new local x
	while (x++, g--) {
		cout << __LINE__ << "\twhile\t###\t" << g << " (p)\t###\t" << x << "\n";
	}
}


int main() {
	x = 6; g = 25;
	cout << "Line\tWhere\tg(glo)\tg(loc)\tx(glo)\tx(loc)\n";
	cout << "-------------------------------------------------------\n";
	cout << __LINE__ << "\tmain\t" << g << "\t-\t" << x << "\t-\n";
	f(x);
	cout << __LINE__ << "\tmain\t" << g << "\t-\t" << x << "\t-\n";
	cout << "-------------------------------------------------------\n";
	cout << "###: shadowed. (p): function parameter. -: None\n";
}
