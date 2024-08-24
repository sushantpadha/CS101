#include <simplecpp>

main_program {
    // --------- LOGIC ---------
    // loop { if LSB == 1, count++; i++
    //        right shift p by one }
    // i = position of bit being read (LSB is 0)
    // exit when i=12
    // add the remaining amount as p*2 or p<<1
    unsigned int p;
    cin >> p;
    int count = 0;
    for (int i = 0; p > 0 && i < 12 ; p >>= 1, i++) {
        if (p & 1U) count++;
    }
    count += (p << 1);
    cout << count << endl;
}