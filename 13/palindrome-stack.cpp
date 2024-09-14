#include <iostream>
using std::cout; using std::cin;
using std::cerr; using std::endl; 

const int stCap = 1000;

struct charStack { 
    char St[stCap]; int top; /* top = -1 for empty stack */ 
    bool pop(char& i) { 
        if (top==-1) return false;
        i = St[top--];
        return true;
    }
    bool push(char i) {
        if (top==stCap-1) return false;
        St[++top] = i;
        return true;
    }
    void clear() { top = -1; }
};

int main() {
  charStack st; st.clear();
  char x, y;
  cout << "Number of characters: ";
  int n; cin >> n;
  cout << "Enter text to check for being a palindrome (whitespace will be ignored): ";
  for (int i=0; i<n/2; i++) if(cin >> x, !st.push(x)) {cerr << "Stack overflow!\n"; return -1; }
  if (n%2) cin >> x; // if n odd, ignore the middle character
  for (int i=n/2-1; i>=0; i--) { // compare stored characters with rest
    if (cin >> x, st.pop(y), x != y) {
      cout << "Not a palindrome!" << endl;  return 1;
    }
  }
  cout << "Palindrome!" << endl;
}

