#include <iostream>
using namespace std;

int main() {
	unsigned int num;
	cin >> num;
	unsigned int d = 1; // number of digits (d>0) s.t. num<10**d
	unsigned int tpd = 10; // tpd = 10**d
	while (!(num < tpd)){
		d++;
		tpd *= 10;
	}
	cout << "Number of digits: " << d << endl;
}
