#include <iostream>
using namespace std;

int main() {
    int n, sp = 0; cin >> n;
    for(int i = 1; i <= n; i++) cout << i;
    cout << endl;

    for(int i = 2; i <= n-1; i++)
        sp += ((i < 10) ? 1 : 2);

    for(int r = 0; r < n-2; r++) {
        cout << 1;
        // wtf? bodhitree uses non-monospace font. using "  " for one numeric character
        for(int j = 0; j < sp; j++) cout << "  ";
        cout << n << endl;
    }

    for(int i = 1; i <= n; i++) cout << i;
    cout << endl;
}