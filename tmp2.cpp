#include <iostream>
#include <string>
using namespace std;

#define dbg(x) cout << #x << " = " << x << "    "
#define nl cout << '\n'

int main() {
    int A[5] = {2, 3, 5, 7, 11};

    // p is a pointer to first element of A
    int* p = A;

    // it supports subscript
    // p[i] is same as *(p+i)
    // i.e., increment p by i steps then dereference it
    dbg(p);
    nl;
    dbg(p[1]);
    dbg(*(p + 1));
    nl;
    nl;

    ++p;

    // since sizeof(int) = 4, now address that p points to will be
    // incremented by 4
    dbg(p);
    nl;
    dbg(p[1]);
    dbg(*(p + 1));
    nl;
}
