#include <simplecpp>

main_program {
    // n: number of bits
    // m: number of codewords
    // k: number of bit flips to tolerate
    // x: received bitstring
    // <list of ints>: set of known codewords

    // to ensure added MSB are set to 0
    unsigned int x, codeword, xorword;
    int n, m, k, count;
    cin >> n >> m >> k >> x;

    for (int i = 0; i < m; i++) {
        count = 0;

        cin >> codeword;
        xorword = x ^ codeword;

        // same logic for reading set bits
        // AND only loop over n LSB
        for (int j = 0; xorword > 0 && j < n; xorword >>= 1, j++) {
            if (xorword & 1U)
                count++;
        }
        // can be optimized by adding `done` bool and breaking from for conditionally
        // but this is shorter and perf is nearly same
        if (count > k)
            continue;
        cout << codeword << " ";
    }
    cout << endl;
}