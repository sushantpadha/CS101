#include <cmath>
#include <iostream>
using std::cout, std::endl, std::sin, std::cos;

// g = ma + nb, for m,n in Z, a >= b >= 0
// gcd(a,0) = |a|, else, gcd(a, b) = (b, a%b)
int gcd(int a, int b, int& m, int& n) {
    if (b >= a)
        return gcd(b, a, m, n);

    // base case
    if (!b) {
        n = 0;
        m = (a > 0) ? 1 : -1;
        return abs(a);
    }

    // recurse
    int g = gcd(b, a % b, m, n);
    // g = ma + nb = m'b + n'(a%b) = m'b + n'(a - (a/b)*b)
    // m = n', n = m' - (a/b)n'
    // this is the formula for getting actual m, n from reduced m', n'
    int tmp = m;
    m = n;
    n = tmp - (a / b) * n;

    return g;
}

int main(int argc, char** argv) {
    int m, n;
    int a, b;

    if (argc != 3)
    {
        cout << "Usage: " << argv[0] << " a b, where a >= b are non-negative ints\n";
        exit(1);
    }
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    

    cout << gcd(a, b, m, n) << " = " << m << " * " << a << " + " << n << " * " << b
         << '\n';
}