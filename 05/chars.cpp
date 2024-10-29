#include <simplecpp>

main_program {
	cout << endl << "----------------- char Examples -----------------" << endl;
	cout << "printable chars print as expected: " << 'a' << 'A' << "<--" << endl;
	cout << "some special characters: \\n: " << '\n' << "<--" << endl;
	cout << "some special characters: \\t: " << '\t' << "<--" << endl;
	cout << "some special characters: \\r: " << '\r' << "<--" << endl;
	cout << "if you know your ASCII: \\x5a: " << '\x5a' << "<--" << endl;
	cout << "char arithmetic yields integers: " << ('A' + ' ') << endl;
	cout << "integers can be cast to characters: 'A' + ' ' is " << char('A' + ' ') << endl;
	cout << "integers can be cast to characters and back: char(1096) is " << char(1096) << " and as int: " << int(char(1096)) << endl;
	cout << "--------------------------------------------------" << endl;

	cout << endl << "--------------- Signed vs. Unsigned --------------" << endl;
	int i; unsigned int ui;
	char c; unsigned char uc; signed char sc;
	uc = 255;
	ui = uc; i = uc;
	cout << "Unsigned char " << uc << " as unsigned int: " << ui
		 << " and int: " << i << endl;
	c = 255;
	ui = c; i = c;
	cout << "char " << c << " as unsigned int: " << ui
		 << " and int: " << i << endl;

	sc = 255;
	ui = c; i = c;
	cout << "signed char " << c << " as unsigned int: " << ui
		 << " and int: " << i << endl;


	// case toggling, exploiting more ASCII specifics
	cout << endl << "------------------- Case switch ------------------" << endl;
	cout << "Enter text for case toggling: ";
	cin >> noskipws; // We don't want to skip whitespace. Newline will end input.
	for (cin >> c; c != '\n' ; cin >> c) {
		if ((c|32) >= 'a' && (c|32) <= 'z') // Setting 6th LSB makes uppercase lowercase
			c ^= 32; // Toggle 6th LSB to switch case
		cout << c;
	}
	cout << endl;
}
