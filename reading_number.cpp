#include <iostream>
using namespace std;

int main() {
	cin >> noskipws; // dont skip whitespace
	char c;
	unsigned int n = 0;
	bool gotDigit = false;
	while(true) {
		cin >> c;
		if (c >= '0' && c <= '9') {
			// compiler converts (c - '0') to int
			n = n*10 + (c - '0');
			gotDigit = true;
		} else if (gotDigit) {
			break;
		}

	}
	cout << "The number is: " << n << endl;
}

