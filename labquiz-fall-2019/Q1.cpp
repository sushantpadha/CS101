#include <iostream>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    
    unsigned int mask = 0b10;

    for(int i = 0; i < k; i++) {
        n ^= mask;
        mask <<= 2;
    }

    cout << n << endl;
}