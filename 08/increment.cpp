#include <simplecpp>

int inc(int x) {
	return ++x; // works like return x+1;
				// local x is incremented too, but not used
}

int badinc(int x) {
	return x++; // this increments the local x, but returns the unincremented x
}

int& preinc(int&x) {
	return ++x; // this increments x (by reference) and also returns it by reference
}

int postinc(int&x) {
	return x++; // equivalent to: int oldx = x; x = x+1; return oldx;
				// this increments x
}

main_program {
	int x=1;
	cout << "x == " << x; cout << ".  inc(x) == " << inc(x);         cout << ". x == " << x << endl;
	cout << "x == " << x; cout << ".  badinc(x) == " << badinc(x);   cout << ". x == " << x << endl;
	cout << "x == " << x; cout << ".  postinc(x) == " << postinc(x); cout << ". x == " << x << endl;
	cout << "x == " << x; cout << ".  preinc(x) == " << preinc(x);   cout << ". x == " << x << endl;
}
