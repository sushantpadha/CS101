#include <simplecpp>

main_program {
    const int num_bits = sizeof(int)*8;
    unsigned int a, b;
    cin >> a >> b;
    unsigned int c = a ^ b;
    int count = 0;
    // alternate method of counting set bits
    // rshift d by one and & instead of lshifting c
    for (int i = 0, d = 1; i < num_bits; i++, d <<= 1) {
        if (c & d)
            count++;
    }
    cout << count << endl;

    for (int i = 0; c > 0; c >>= 1, i++) {
        if (c & 1U)
            cout << i << " ";
    }
    cout << endl;
}