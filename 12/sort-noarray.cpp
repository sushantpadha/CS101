#include <iostream>
using std::cout; using std::cin; using std::endl; using std::swap;
int main() {
  int a1, a2, a3;
  cin >> a1 >> a2 >> a3;

  if (a1 > a2)
	  swap(a1,a2);
  if (a2 > a3)
	  swap (a2,a3);
  if (a1 > a2)
	  swap (a1,a2);
  cout << a1 << ", " << a2 << ", " << a3 << endl;
}

  /*
  if (a1 <= a2 && a2 <= a3)
	  cout << a1 << ", " << a2 << ", " << a3 << endl;
  else if (a1 <= a3 && a3 <= a2)
	  cout << a1 << ", " << a3 << ", " << a2 << endl;
  else if (a2 <= a3 && a3 <= a1)
	  cout << a2 << ", " << a3 << ", " << a1 << endl;
  else if (a2 <= a1 && a1 <= a3)
	  cout << a2 << ", " << a1 << ", " << a3 << endl;
  else if (a3 <= a1 && a1 <= a2)
	  cout << a3 << ", " << a1 << ", " << a2 << endl;
  else if (a3 <= a2 && a2 <= a1)
	  cout << a3 << ", " << a2 << ", " << a1 << endl;
  */
