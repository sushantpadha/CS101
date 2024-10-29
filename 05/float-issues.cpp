#include <simplecpp>
main_program {
	// Order of operations matters

	float f = 2e7; // 20 million > 2^24
	cout << "1 + 2e7f - 2e7f = " << 1 + f - f << "\tWrong!" << endl;
	cout << "2e7f - 2e7f + 1 = " << f - f + 1 << "\tFine." << endl;

	// internal representation being binary matters
	cout << "1 + 0.01f - 1  = " << 1 + 0.01f - 1 << endl;  // float
	cout << "1 + 0.01 - 1 = " << 1 + 0.01 - 1 << " \tDouble works? " << endl;  // 0.01 is double by default
	if (1+0.01-1 != 0.01)
		cout << "Actually doesn't work for double either. The error is " << 1+0.01-1-0.01 << endl;

	f = 1.f/16;
	if (f-1 == (f*f-1)/(f+1) )
		cout << "Well-behaved if no overflow as a binary number." << endl;

}
