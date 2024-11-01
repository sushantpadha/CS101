#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

using std::swap, std::vector, std::cout, std::endl, std::cerr;

#define __DBG 1
#define LOG    \
    if (__DBG) \
    cerr
#define TRACK                                                            \
    LOG << __LINE__ << ": *begin = " << *(begin) << " *end = " << *(end) \
        << " end-begin = " << (end) - (begin) << endl

typedef int* it;

// * REVIEW LOGIC USING LOOP INVARIANTS
// -------------------------------------------------------------
// * LOOP INVARIANT is the "Induction Hypothesis"
// LOOP INVARIANTS:
// 1. Elements <begin and >end must be pivoted
// 2. end-begin strictly decreases after each loop (to ensure loop termination)

it pivot(it begin, it end) {
    if (begin >= end)
        throw std::invalid_argument("cannot pivot an empty range!");

    // value to compare against
    auto pivot = *begin;

    end--;    // move pointer to within container bounds
    begin++;  // can be advanced eagerly
    TRACK;

    // use weak inequality to deal with the case of pointers
    // equalling but not incrementing to the right position
    while (begin <= end) {
        if (*begin <= pivot)
            begin++;
        if (*end > pivot)
            end--;
        TRACK;

        if (*begin > pivot && *end <= pivot && begin < end) {
            // after swapping advance pointers eagerly
            // * can actually "not advance" pointers here
            // * Invariant still holds since in next iteration
            // * both will advanced accordingly

            swap(*begin++, *end--);
            TRACK;
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
    // int A[8] = {99, 8, 7, 120, 300, 6, 99, 13};
    int A[8] = {7, 2, 3, 4, 5, 6, 1, 8};
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

int main() { unittest_pivot(); }
