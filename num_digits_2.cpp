#include <iostream>
using namespace std;

int main() {
	unsigned int num; 
	cin >> num;
	unsigned int d = 1; // number of digits (d>0) s.t. num<10**d
	
	while ((num /= 10) != 0){
		d++;
	}
	cout << "Number of digits: " << d << endl;
}
