#include <simplecpp>
#include <vector>

const int LENGTH = 50;
const int PUSH_GAP = 50;
const int POP_GAP = 10;

class Stack {
public:
    // max size of stack
    int size;

    // number of pushed elements
    // 0 <= count <= size
    int count;

    // (position of topmost pushed element ie active element) + 1
    // 1 + max(i) where filled[i] in {'+', '-'}
    int actv;

    // (position of topmost pushed/popped element) + 1
    // 1 + max(i) where filled[i] == '+'
    int top;

    // string representing pushed elements as '+'
    // popped as '-', and uninitialized as ' '
    string filled;

    // full and empty flags
    bool full;
    bool empty;

    // move UP/down by PUSH_GAP/pop_gap and do it n times
    // true values are capitalized
    void shift(bool up, bool push, int n = 1) {
        for (int i = 0; i < n; i++) {
            penUp();
            left(90);
            forward((up ? 1 : -1) * (push ? PUSH_GAP : POP_GAP));
            right(90);
            penDown();
        }
    }

    // draw PUSH LENGTH/pop length (true values are capitalized)
    void drawLine(bool push) {
        forward((push ? 1 : 2) * LENGTH);
        forward((push ? 1 : 2) * -1 * LENGTH);
    }

    // initialize all position and counts as 0, set default flags
    // `filled` as string of `s` ' 's (can be expanded later)
    Stack(int s)
        : size(s),
          count(0),
          actv(0),
          top(0),
          filled(string(' ', s)),
          full(false),
          empty(true) {
        // move one step down
        // for uniformity :)
        shift(0, 0);
    }

    // INVARIANT: turtle is at start of topmost pushed line, facing right

    void push() {
        if (full) {
            cout << "Stack Full\n";
            return;
        }

        count++;  // increment push count
        top++;    // increment position of topmost defined el

        // shift UP by PUSH_STACK length to new `top` from `actv` and draw
        shift(1, 1, top - actv);
        drawLine(1);

        // update filled and actv
        filled[top] = '+';
        actv = top;

        // set flags
        if (empty)
            empty = false;

        if (count == size)
            full = true;
    }

    void pop() {
        if (empty) {
            cout << "Stack Empty\n";
            return;
        }

        // `top` remains unchanged
        count--;  // decrement push count

        // pop the current element
        shift(1, 0);
        drawLine(0);
        shift(0, 0);

        filled[actv] = '-';

        // deal with case of popping first element
        // actv == 1 <-> count == 0
        if (!count) {
            empty = true;
            return;
        }
        
        // * ALTERNATE:
        // compute this "gap" to shift down in case of pop
        // at the tail of push itself, by adding another pointer
        // would that be better???

        // move to immediate preceeding pushed element
        // ! assumes that we do not start at actv == 0 and enter infinite loop
        for (; filled[actv] != '+'; actv--) shift(0, 1);


        // set flags
        if (full)
            full = false;
    }
};

int main() {
    int size;
    int n;
    char c;

    cin >> size >> n;

    turtleSim();

    Stack st(size);

    while (n--) {
        cin >> c;

        if (c == 'a')
            st.push();

        if (c == 'b')
            st.pop();

        cout << st.filled << " actv=" << st.actv << " top=" << st.top << " count=" << st.count << " " << st.empty << st.full << '\n';
    }

    wait(10);
}
