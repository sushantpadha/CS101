#include <simplecpp>

bool isPerfect(int n) {
    int m = n;
    for (int i = 1; i < n; i++) {
        if (n % i == 0)
            m -= i;
    }
    return (!m);
}

main_program {
    int n;
    cin >> n;
    cout << (isPerfect(n) ? "true" : "false") << endl;
}
