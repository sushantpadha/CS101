#include <simplecpp>

main_program {
    // n: number of bits
    // m: number of codewords
    // k: number of bit flips to tolerate
    // x: received vector
    // <list of ints>: set of known codewords

    unsigned int one = 1;
    unsigned int n, x, codeword, xorword;
    int m, k, count;
    bool done;
    cin >> n >> m >> k >> x;

    for (int i = 0; i < m; i++) {
        count = 0;
        done = false;

        cin >> codeword;
        xorword = x ^ codeword;

        for (; xorword > 0; xorword >>= 1) {
            if (xorword & one)
                count++;
            if (count > k) {
                done = true;
                break;
            }
        }
        if (done) continue;
        cout << codeword << endl;
    }
}