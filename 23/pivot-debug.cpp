#include <iostream>

#include "dice.h"

using std::cout;
using std::endl;

// VERSION 4 is the debugged version. 1, 2, 3 have bugs
#define VERSION 4

// set DBG to 1 to see log messages
#define DBG 0
#define LOG  \
    if (DBG) \
    std::cerr
#define TRACK(x, y)                                                \
    LOG << __LINE__ << ": *begin = " << *(x) << " *end = " << *(y) \
        << " end-begin = " << (y) - (x) << endl;

typedef int* it;
it pivot(it begin, it end) {
    auto pivot = *begin;
#if VERSION > 3
    begin++;
#endif
#if VERSION > 1
    end--;
#endif
    TRACK(begin, end);
#if VERSION > 2
    while (begin <= end) {
#else
    while (begin < end) {
#endif
        if (*begin <= pivot)
            begin++;
        if (*end > pivot)
            end--;
        TRACK(begin, end);
#if VERSION > 3
        if (begin < end && *begin > pivot && *end <= pivot) {
#else
        if (*begin > pivot && *end <= pivot) {
#endif
#if VERSION > 3
            std::swap(*begin++, *end--);
#else
            std::swap(*begin, *end);
#endif
            TRACK(begin, end);
        }
    }
    return begin;
}

bool check_pivot(it begin, it end, it mid) {
    auto pivot = *begin;
    for (auto a = begin; a < mid; a++)
        if (*a > pivot)
            return false;
    for (auto a = mid; a < end; a++)
        if (*a <= pivot)
            return false;
    return true;
}

// a simple unit-test
void unittest_pivot() {
    int A[8] = {99, 8, 7, 120, 300, 6, 99, 13};
    cout << "Before: ";
    for (int a : A) {
        cout << a << " ";
    }
    cout << endl;
    it mid = pivot(A, A + 8);
    cout << "After: ";
    for (it a = A; a < mid; a++) {
        cout << *a << " ";
    }
    cout << " | ";
    for (it a = mid; a < A + 8; a++) {
        cout << *a << " ";
    }
    cout << endl;
    if (!check_pivot(A, A + 8, mid))
        throw std::logic_error("pivot failed");
}

// a more elaborate unit-test with randomly generated inputs
void rand_unittest_pivot(int ntimes = 100, int maxval = 365) {
    const int maxlen = 100;  // maximum size of the array to sort
    int A[maxlen];
    dice<int> Dlen(maxlen), Dval(maxval);
    for (int i = 0; i < ntimes; ++i) {
        int n = Dlen.roll();
        for (int j = 0; j < n; ++j) A[j] = Dval.roll();
        LOG << "Pivoting " << n << " elements" << endl;
        if (!check_pivot(A, A + n, pivot(A, A + n)))
            throw std::logic_error("pivot failed");
    }
}

int main() {
    unittest_pivot();
    rand_unittest_pivot();
}
