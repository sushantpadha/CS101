#include <simplecpp>

main_program {
    unsigned int p;
    cin >> p;
    unsigned int one = 1;
    int count = 0;
    for (int i = 0; p > 0; p >>= 1, i++) {
        if (p & one) {
            if (i < 12)
                count++;
            else {
                int j = i - 11;
                count += pow(2, j);
            }
        }
    }
    cout << count << endl;
}