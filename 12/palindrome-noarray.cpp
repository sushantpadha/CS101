#include <iostream>
using std::cout; using std::cin; using std::endl;
int main() {
  char c1, c2, c3, c4, next;
  bool palindrome = true;
  cin >> c1 >> c2 >> c3 >> c4;
  if ( (cin >> next, next != c4) 
		  ||  (cin >> next, next != c3)
		  ||  (cin >> next, next != c2)
		  ||  (cin >> next, next != c1) )
	  cout << "Not a palindrome!" << endl;
  else
	  cout << "Palindrome!" << endl;
}
