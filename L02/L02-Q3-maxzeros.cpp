#include <simplecpp>

main_program {
    int n, n1, n2, count, max_count, digit;
    cin >> n1 >> n2;
    n = n1 + n2;
    count = max_count = 0;

    // iteratively remove digits from right of n
    for (; n > 0; n /= 10) {
        // get leftmost digit
        digit = n % 10;
        if (digit) {
            if (count) {
                // non-zero digit found after some non-zero count
				// set max_count
                max_count = (count > max_count) ? count : max_count;
                count = 0;
            }
            continue;
        }
		// if zero digit found, increment count
        count++;
    }
    cout << max_count << endl;
}
