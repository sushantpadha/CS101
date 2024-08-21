#include <simplecpp>

main_program {
	int input, numbits = sizeof(int)*8;
	cout << "Enter integer to be printed in binary: ";
	cin >> input;
	cout << input << " in binary: ";
	for (int i=0, x = input; i<numbits; i++) {
		unsigned int y = (1 << (numbits-1));
		y &= x;
		cout << (y?'1':'0');
		x <<= 1;
	}
	cout << endl;
	cout << input << " in hex: ";
	cout << hex << showbase; // incantations to make it print numbers in hexadecimal
	cout << input << endl;
}
	
