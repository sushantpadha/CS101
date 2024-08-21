#include <simplecpp>
#include <iomanip>

main_program {

	int i1, i2;
	char c1, c2;
	float f1, f2;
	double d1, d2;
	bool b1, b2;

	// In each exercise, explain why the output is the way it is
	
	//-----------------------------------
	// Integer Exercises
	//-----------------------------------
	cout <<  "\nExercise 1" << endl;
	i1= 2000000000; // 2 billion
	f1=i1;
	i1 += 10; f1 += 10;
	i2 = i1* 2; f2 = f1*2;
	cout << "Two billion and ten: integer: " << i1 << "\tfloat: " << f1 << " (after subtracting 2e09: " << f1-2e09f << ")" << endl;
	cout << "Four billion and twenty: integer: " << i2 << "\tfloat: " << f2 << endl;

	//-----------------------------------
	cout <<  "\nExercise 2" << endl;
	i1= 032; i2 = 0x32;
	cout << "032 == " << i1 << "\t0x32 == " << i2 << endl;
	
	//-----------------------------------
	cout <<  "\nExercise 3" << endl;
	i1=32;
	cout << "!" << i1 << " is " << (!i1) << endl;

	//-----------------------------------
	cout <<  "\nExercise 4" << endl;
	i1 = INT_MAX; i2 = INT_MIN;
	cout << i1 << " + 1 == " << i1+1 << endl;
	cout << i2 << " - 1 == " << i2-1 << endl;
	cout << "-1 as unsigned int: " << (unsigned int)(-1) << endl;
	cout << "-129 as char and then int: " << (unsigned int)(char(-129)) << endl;



	
	//-----------------------------------
	// Boolean Exercises
	//-----------------------------------
	cout <<  "\nExercise 5" << endl;
	i1=b1=32;
	cout << "Boolean 32: " << b1 << "\tInteger 32? " << i1 << endl;

	//-----------------------------------
	cout <<  "\nExercise 6" << endl;
	b1=1; b2=-1;
	cout << "bool(1) + bool(-1) = " << b1+b2 << endl;
	cout << "What is happening here? " << (b1+b2) << ", ";
	cout << (b1+=b2) << " and "; 
	cout << (b1+=-1) << endl;


	//-----------------------------------
	// Character Exercises
	//-----------------------------------
	cout <<  "\nExercise 7" << endl;
	c1 = char(2660); c2 = -50;
	i1 = int(c1); i2 = int(c2);
	cout << "2660 as char: " << c1 << " and back as int: " << i1 << endl;
	cout << "-50 as char: " << c2 << " and back as int: " << i2 << endl;
	cout << "2660*3 using char: " << c1*3 << endl;

	//-----------------------------------
	cout <<  "\nExercise 8" << endl;
	c1 = '9' + '9' - '0';
	c2 = '9' + '9' - '0' - '0'; 
	cout << "'9' +'9' - '0' = " << int(c1) << " but '9' + '9' - '0' - '0' = " << int(c2) << endl; 

	//-----------------------------------
	// Floating Point Exercises
	//-----------------------------------
	cout <<  "\nExercise 9" << endl;
	f1 = 2e7; // 20 million > 2^24
	f2 = .07; 
	d2 = 1e-20; 
	cout << "x + 1 - x = " << f1 + 1 - f1 << "\t 1 - x + x = " << 1 - f1 + f1 << endl;
	cout << "1 + y - 1 = " << 1 + f2 - 1  << "\t 1 - 1 + y = " << 1 - 1 + f2 << endl;
	cout << "1 + y - 1 = " << 1 + d2 - 1  << "\t 1 - 1 + y = " << 1 - 1 + d2 << endl;

	//---------------
	cout <<  "\nExercise 10" << endl;
	f1 = d1 = 2E06;
	f2 = d2 = 2E-06;
	if (f1+f2-f1)
		cout << "float: 2E06 + 2E-06 - 2E06 is not zero." << endl;
	else
		cout << "float: 2E06 + 2E-06 - 2E06 is equal to zero!!" << endl;
	if (d1+d2-d1)
		cout << "double: 2E06 + 2E-06 - 2E06 is not zero." << endl;
	else
		cout << "double: 2E06 + 2E-06 - 2E06 is equal to zero!!" << endl;
}