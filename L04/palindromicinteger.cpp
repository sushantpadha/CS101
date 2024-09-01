#include <simplecpp>

int largestPalindromeSubnumber(int n) {
    int numDigits = 1;
    for (; numDigits <= n; numDigits *= 10) {
    }
    numDigits /= 10;

    for (int q = n; n > 0; n %= numDigits, n /= 10, numDigits /= 100) {
        q = n;
        int r;
        for (r = 0; q > 0; q /= 10) {
            r = r * 10 + q % 10;
        }
        if (n == r)
            return n;
    }
    return -1;
}

main_program {
    while (true) {
        int n;
        cin >> n;
        cout << largestPalindromeSubnumber(n) << endl;
    }
}
