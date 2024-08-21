#include <simplecpp>

main_program {
    unsigned int a;
    cin >> a;
    unsigned int one = 1;
    unsigned int count = 0;
    for (unsigned int i = 1; i <= a; i++) {
        for (unsigned int _i = i; _i > 0; _i >>= 1) {
            if (_i & one)
                count++;
        }
        count %= 1000000007;
    }
    cout << count << endl;
}