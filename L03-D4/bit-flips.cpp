#include <simplecpp>

int main() {
    int a, b;
    cin >> a >> b;
    // bitstring of c has 1's where bits of a, b differ
    int c = a ^ b;
    // count number of 1's in c's bitstring and print it
    unsigned int count = 0, one = 1;
    for (; c > 0; c >>= 1) {
        if (one & c)
            count++;
    }
    cout << count << '\n';
}