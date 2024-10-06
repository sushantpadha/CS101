#include<iostream>
using namespace std;

#define RETURN_FALSE cout << "False\n"; return 1;
#define RETURN_TRUE cout << "True\n"; return 0;

const int STACK_LIMIT = 256;

struct CharStack {
    char st[STACK_LIMIT];
    int count;

    CharStack() : count(0) {
        // fill st with null chars
        for(int i = 0; i < STACK_LIMIT; i++) st[i] = '\0';
    }

    // push c to top of stack; return false if fails else true
    bool push(char c) {
        if (count >= STACK_LIMIT) {
            cerr << "Stack is full with " << STACK_LIMIT << " elements!\n";
            return false;
        }
        st[count] = c;
        count++;
        return true;
    }

    // pop c from top of stack; return false if fails else true
    bool pop(char& c) {
        if (count == 0) {
            cerr << "Stack is empty, cannot pop!\n";
            return false;
        }
        count--;
        c = st[count];
        return true;
    }
};


int main() {
    char c, d;
    CharStack cs;
    cin >> noskipws;
    // terminate when newline found
    for(int i = 1; cin >> c, c != '\n' ; i++) {
        // opening bracket
        if(c == '(' || c == '[' || c == '{') {
            if( ! cs.push(c) ) { cerr << "StackOverflow ;)\n"; return 1; }
        }

        // closing bracket
        if( c==')' || c==']' || c== '}') {
            if( !cs.pop(d) || !((c==')' && d=='(') || (c==']' && d=='[') || (c=='}' && d=='{')) ) { RETURN_FALSE }
        } 
    }
    
    // check if stack empty now
    if( cs.count == 0 ) { RETURN_TRUE }
    else { RETURN_FALSE }
}
