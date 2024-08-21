#include <bits/stdc++.h>
using namespace std;

int main() {
    int input, numbits = sizeof(int) * 8;
    cin >> input;
    // first print out 31 spaces (placeholders for all but LSB)
    for (int j = 0; j < numbits - 1; j++) cout << " ";
    for (int i = 0, x = input; i < numbits; i++) {
        bool y = 1;
        y &= x;
        cout << (y ? '1' : '0');
        // ANSI code to move cursor back two columns
        printf("%c[%dD", 0x1B, 2);
        x >>= 1;
    }
    cout << endl;

    return 0;
}
