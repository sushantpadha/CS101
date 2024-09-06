#include <iostream>
using namespace std;

int reduce(int n) {
    if (n % 4 == 0)
        return n / 4;
    else if (n % 3 == 0)
        return n - 6;
    else
        return n + 5;
}

int main() {
    int n; cin >> n;
    for(int i = 0; n > 0; i++) {
        if (n == 1) {
            cout << i << endl;
            return 0;
        }
        n = reduce(n);
    }
    cout << -1 << endl;
}
