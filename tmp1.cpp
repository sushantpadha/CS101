#include <iostream>
#include <string>
using namespace std;

void printArray(int A[], const int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << ' ';
    }
}

bool lessThanEqualTo(int a, int b) { return (a <= b); }

bool greaterThanEqualTo(int a, int b) { return (a >= b); }

// Sorts array of three integers based on a function pointer which is used to compare
// two integers at a time Function should return true if first input <= second input
void sort(int A[], int n, bool (*compare)(int, int)) {
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n - 1; j++) {
            if (!compare(A[j], A[j + 1]))
                swap(A[j], A[j + 1]);
        }
    }
}

int main() {
    constexpr int n = 5;

    int A[n] = {9, 5, 2, 7, 0};
    int B[n] = {9, 5, 2, 7, 0};

    // sort using <= order
    sort(A, n, &lessThanEqualTo);
    
    // sort using >= order
    sort(B, n, &greaterThanEqualTo);

    printArray(A, n); cout << '\n';
    printArray(B, n); cout << '\n';
}
