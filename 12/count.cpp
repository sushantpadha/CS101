#include <iostream>
using std::cout; using std::cin; using std::endl;
int main() {
	int N[26] = {};
	char c;
	for(cin >> c; c >= 'a' && c <= 'z'; cin >> c)
		N[c-'a'] ++;
	for (int i=0; i<26; i++)
		cout << "#" << char('a' + i) << " = " << N[i] << endl; 
}
