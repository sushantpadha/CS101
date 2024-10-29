#include <iostream>
using std::cout; using std::cin; using std::endl;
int main() {
  int Na=0, Ne=0, Ni=0, No=0, Nu=0; char c;
  for(cin >> c; c >= 'a' && c <= 'z'; cin >> c) {
    if (c == 'a') ++Na;
    else if (c == 'e') ++Ne;
    else if (c == 'i') ++Ni;
    else if (c == 'o') ++No;
    else if (c == 'u') ++Nu;
  }
  cout << "#a = " << Na << ", #e = " << Ne << ", #i = " << Ni
	                    << ", #o = " << No << ", #u = " << Nu << endl;
}
