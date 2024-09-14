#include <simplecpp>

const int stCap = 100;

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

bool docommand(char c, charStack& history) {
  if (c == 'f' || c == 'r' || c == 'l') {
    if(!history.push(c)) {
      cerr << "Out of space in undo stack! Clearing it!" << endl;
      history.clear();
      history.push(c);
    }

    if (c == 'f') forward(10);
    else if (c == 'r') right(90);
    else /* (c == 'l') */ left(90);
    return true;
  }
  return false;
}

bool undo(charStack& history) {
  char c;
  if(!history.pop(c)) {
    return false;
  } else {
    if (c == 'f') forward(-10);
    else if (c == 'r') right(-90);
    else /* (c == 'l') */ left(-90);
    return true;
  }
}

int main() {
  charStack history; history.clear();
  turtleSim();
  cout << "Enter f for forward, r for right, l for left, u to undo, q to quit: ";
  char input;
  for(cin >> input; !cin.fail(); cin >> input) {
    if(input == 'q')
      break;
    else if (input == 'u') {
      if(!undo(history)) // pop the history stack and reverse the popped comand
		cerr << "Undo stack empty!\n";
	} else if (!docommand(input,history)) // add valid commands to history
      cerr << "Unrecognized command" << endl;
  }
}
