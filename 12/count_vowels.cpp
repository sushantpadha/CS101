#include <iostream>
using std::cout; using std::cin; using std::endl;
int main() {
  char c, vowels[] = {'a', 'e', 'i', 'o', 'u'}; 
  int N[5] = {};
  for(cin >> c; c >= 'a' && c <= 'z'; cin >> c)
    for (int i=0; i<5; i++)
      if(c == vowels[i]) {N[i]++; break;}
  for (int i=0; i<5; i++)
    cout << "#" << vowels[i] << " = " << N[i] << (i==4?"":", ");
  cout << endl;
}
