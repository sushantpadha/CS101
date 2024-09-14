#include <iostream>
using namespace std;

bool genFib(int& a0, int& a1, int target) {
    static int tmp = a1;
    do {
        tmp = a1;
        a1 += a0;
        a0 = tmp;
    } while (a0 < target);

    if (a0 == target)
        return true;
    return false;
}

int main() {
    int m, n;
    cin >> m;

    int a0 = 0, a1 = 1;

    for (int i = 0; i < m; i++) {
        cin >> n;

        if (n == 0)
            continue;

        if (!genFib(a0, a1, n)) {
            cout << "false";
            return;
        }
    }

    cout << "true";
}
