#include <simplecpp>

main_program {
    unsigned int a, b;
    cin >> a >> b;
    unsigned int c = a ^ b;
    unsigned int _c = c;
    unsigned int one = 1;
    int count = 0;
    for (; c > 0; c >>= 1) {
        if (c & one)
            count++;
    }
    cout << count << endl;

    for (int i = 0; _c > 0; _c >>= 1, i++) {
        if (_c & one)
            cout << i << " ";
    }
    cout << endl;
}