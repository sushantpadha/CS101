#include <iostream>
using namespace std;

int main() {
	char cmd, c, lowerc, upperc;

	cout << "Enter which mode to use: lowercase (l), uppercase (u), switch case (s): ";
	cin >> cmd;

	// cin >> noskipws;

	const char casebit = 0x20;

	for (cin >> c; c != '\n'; cin >> c){
		lowerc = c|casebit;
		if (lowerc >= 'a' && lowerc <= 'z') {
			c = c ^ casebit;
			upperc = c & (~casebit);
			c = (cmd == 'l' ? lowerc :
			     cmd == 'u' ? upperc :
			     cmd == 's' ? c : c);
			cout << c;
		}
	}
}

