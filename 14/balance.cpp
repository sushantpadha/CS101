#include <iostream>

////////// Stack implementation //////////////////
const int stCap = 1000;  // capacity
struct charStack { 
    char St[stCap]; 
    int top; // top = -1 for empty stack 
    bool pop(char& i) { // if stack is empty, return false
        if (top == -1) return false;
        i = St[top--];
        return true;
    }
    bool push(char i) { // if stack is full, return false
        if (top == stCap-1) return false;
        St[++top] = i;
        return true;
    }
    void clear() { top = -1; }
};
////////// Stack implementation over /////////////

int main() {
	char ch; charStack S; S.clear();
	bool valid = true;  // In a left-right scan, no imbalance so far
	int n; std::cin >> n;  // number of symbols to read
	for (int i=0; i < n; i++){
		std::cin >> ch;
		if(ch=='(' || ch=='[') S.push(ch);  // TODO: handle overflow
		else {
			char top; 
			if(!S.pop(top) || !( (top=='[' && ch==']') || (top=='(' && ch==')') ))
				valid = false;  // mismatch at this point
		}
	}
	if(S.pop(ch)) valid = false;  // stack not empty
	std::cout << (valid?"VALID":"INVALID") << std::endl;
}
