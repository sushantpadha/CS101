#include <iostream>

#include "matrix.h"
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    matrix<int> A(m, n);
    matrix<int> B(m, n);

    // Input elements for matrix A
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    // Input elements for matrix B
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> B[i][j];
        }
    }

    matrix<int> C(m, n);

    // Perform addition
    add(A, B, C);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    // Perform multiplication (assuming A.cols() == B.rows())
    if (n == m) {             // Assuming square matrices for simplicity
        matrix<int> E(m, m);  // Adjust size as needed
        multiply(A, B, E);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {  // Adjust size accordingly
                cout << E[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "-1" << endl;
    }
}
