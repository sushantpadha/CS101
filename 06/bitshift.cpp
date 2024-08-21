#include <simplecpp>

main_program {
	const int nbits = sizeof(int)*8;
    cout << hex << showbase; // incantations to make it print numbers in hexadecimal
	int x = 1;
	cout << "\nLeft shifting signed positive int" << endl;
	cout << "Shifting by 4 bits (one hex digit) is the same as multiplying by 16 = 0x10" << endl;
	for (int i=0; i < sizeof(int)*2; i++, x <<= 4)  { // half a byte at a time
		cout <<  x << " << 4 = " << (x<<4) << " and " << x << " * 0x10 " << x*16 << endl;
	}

	cout << dec; // printing in decimal
	cout << "\nLeft shifting by " << nbits-1 << " bits makes 1 negative!" << endl;
	cout <<  "1 << " << nbits-1 << " = " << (1<<(nbits-1));
	cout << hex; // back to hexadecimal
	cout << " (" << (1<<(nbits-1)) << " in hex)" << endl;

	cout << "\nRight shifting signed negative int" << endl;
	cout << "Shifting by 1 position is not the same as dividing 2, if the number is odd" << endl;
	x = -1;
	cout <<  x << " >> 1 = " << (x>>1) << " and " << x << "/2 = " << x/2 << endl;
	x = -3;
	cout <<  x << " >> 1 = " << (x>>1) << " and " << x << "/2 = " << x/2 << endl;
	cout << "Shifting by 1 position is the same as dividing 2, if the number is even" << endl;
	x = -2;
	cout <<  x << " >> 1 = " << (x>>1) << " and " << x << "/2 = " << x/2 << endl;
	x = -4;
	cout <<  x << " >> 1 = " << (x>>1) << " and " << x << "/2 = " << x/2 << endl;

	cout << "\nRight shifting signed positive int" << endl;
	cout << "Shifting by 4 bits (one hex digit) is the same as dividing by 16 = 0x10" << endl;
	x = 1<<(nbits-1); // the bit pattern 10000...0 = 0x80000000
	for (int i=0; i < sizeof(int)*2; i++, x >>= 4)  {
		cout <<  x << " >> 4 = " << (x>>4) << " and " << x << " / 0x10 " << x/16 << endl;
	}
	cout << "\nRight shifting unsigned int" << endl;
	unsigned int z = 1<<(sizeof(int)*8-1);
	for (int i=0; i < sizeof(int)*2; i++, z >>= 4)  {
		cout <<  z << " >> 4 = " << (z>>4) << " and " << z << " / 0x10 " << z/16 << endl;
	}

}
	
