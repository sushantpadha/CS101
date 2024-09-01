#include <simplecpp>

void generateReversedFibonacci(int n) {
    int a = 0, b = 1, tmp;

    // generate upto n and n+1 th fibonacci
    // so that will reversing, n = 1 case is handled gracefully
    for (int i = 0; i < n - 1; i++) {
        tmp = b;
        b += a;
        a = tmp;
    }

    for (int i = 0; i < n; i++) {
        cout << a << endl;
        tmp = a;
        a = b - a;
        b = tmp;
    }
}

main_program {
    int n;
    cin >> n;
    generateReversedFibonacci(n);
}
