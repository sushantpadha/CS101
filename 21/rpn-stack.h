#include <ostream>

class rational {
    int N, D;
    void reduce();

public:
    // default constructor
    rational(int n = 0, int d = 1);
    rational(int n = 0;

    // copy constructor
    rational(const rational& r);

    // arithmetic operators
    rational& operator+= (const rational& r);
    rational& operator-= (const rational& r);
    rational& operator*= (const rational& r);
    rational& operator/= (const rational& r);

    // exponentiation
    rational& operator<< (const int& n);

    // logical operators
    rational& operator< (const rational& r);
    rational& operator<= (const rational& r);
    rational& operator> (const rational& r);
    rational& operator>= (const rational& r);
    rational& operator== (const rational& r);
    rational& operator!= (const rational& r);

    friend ostream& operator<<(ostream& out, const rational& r);
}