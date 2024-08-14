#include <iostream>
using namespace std;

int main()
{
	cin >> noskipws; // dont skip whitespace
	char c;
	unsigned int n = 0;
	// using multiple expressions inside for definition
	// can be concise but unreadable
	for (cin >> c; c < '0' || c > '9'; cin >> c)
		for (n = 0; c >= '0' && c <= '9'; n = n * 10 + (c - '0'), cin >> c)
			;
	cout << "The number is: " << n << endl;
}
