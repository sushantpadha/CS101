#include "rpn-stack.h"

#include <cmath>
#include <iostream>
#include <ostream>

using namespace std;

int main() {
    rational r(5, 10);
    rational s(-6, -18);
    // cout << r << " " << s << "\n";
    r += s;
    // cout << r;
}

void rational::reduce() {
    for (int f = min(N, D); f > 1; f--) {
        if (!(N % f) && !(D % f)) {
            N /= f;
            D /= f;
        }
    }

    if (D < 0) {
        N *= -1;
        D *= -1;
    }
}

rational::rational(int n, int d) {
    N = n;
    if (!d) {
        throw std::domain_error("Denominator must be non-zero.");
    }
    D = d;
}

rational::rational(int n) {
    N = n;
    D = 1;
}

rational::rational(const rational& r) {
    N = r.N;
    D = r.D;
}

rational& rational::operator+=(const rational& r) {
    N = N * r.D + D * r.N;
    D *= r.D;
    reduce();
    return *this;
}

rational& rational::operator-=(const rational& r) {
    rational tmp = r;
    tmp *= -1;
    this += tmp;
    return *this;
}

rational& rational::operator*=(const rational& r) {
    N *= r.N;
    D *= r.D;
    reduce();
    return *this;
}

rational& rational::operator/=(const rational& r) {
    N *= r.D;
    D = r.N;
    reduce();
    return *this;
}

rational& rational::operator<<(const int& n) {
    N = pow(N, n);
    D = pow(D, n);
    return *this;
}

// ostream& operator<<(ostream& out, const rational& r) {
//     out << r.N << "/" << r.D;
//     return out;
// }
