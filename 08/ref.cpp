#include <simplecpp>


// returns a reference to the max; to y if they are equal
int& refMax (int& x, int& y) {
	return (x>y)? x : y;
}

int valMax(int& x, int& y) {
	return (x>y)? x : y;
}

// returns a const reference to the max; to y if they are equal
const int& constrefMax (int& x, int& y) {
	return (x>y)? x : y;
}

// bad: returning reference to a local variable (x or y)
int& refMaxBad (int x, int y) {
	return (x>=y)? x : y; // compiler can warn
}

// again bad, but the compiler may not see that z will be a reference to local x or y
int& refBad2 (int x, int y) {
	int& z = refMax(x,y);
	return z;
}


main_program {
	int x=1,y=10;

	int& z = refMax(x,y);
	int& zbad = refMaxBad(x,y);

	cout << "(x,y) == (" << x << "," << y << "). z = refMax(x,y); z ==  " << z << endl;
	cout << "(x,y) == (" << x << "," << y << "). zbad = refMaxBad(x,y); zbad ==  " << zbad << endl;
	x = 20;
	cout << "But it may seem to work if stack not overwritten.\n(x,y) == ("
		 << x << "," << y << "). refMaxBad(x,y) ==  " << refMaxBad(x,y) << endl;

	cout << "Checking z and zbad now: z == " << z << ", zbad == " << zbad << endl;

	cout << "(x,y) == (" <<  x << "," << y << "), ++z == " << ++z 
		 << ", and (x,y) == (" <<  x << "," << y << ").\n";

	// refMax(x,y)++ will have the value of y (since x>y), and will increment it
	cout << "(x,y) == (" << x << "," << y << "). refMax(x,y)++ ==  "
		<< refMax(x,y)++ 
		<< ". And now (x,y) == (" << x << "," << y << ")." << endl;
	// refMaxCrash(x,y)++ will return reference to a variable whose frame will be deleted
	cout << "(x,y) == (" << x << "," << y << "). refMax(x,y)++ ==  "
		<< refMax(x,y)++ 
		<< ". And now (x,y) == (" << x << "," << y << ")." << endl;
	// valMax(x,y) ++; // This gives a compiler error. Try it!
	// constrefMax(x,y) ++; // This also gives a compiler error. Try it too!
}
