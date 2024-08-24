#include <simplecpp>

main_program {
    unsigned int a;
    cin >> a;
    // since num_set_bits < 32, no need to define long long count to avoid overflow
    unsigned int count = 0;
    // O(nlogn) loop over all n from 1 to a and bit shift to count set bits
    for (unsigned int i = 1; i <= a; i++) {
        // shortened version of set bit counting algo
        for (unsigned int j = i; j > 0; ((j & 1U) ? count++ : 0), j >>= 1);
        count %= 1000000007;
    }
    cout << count << endl;
}