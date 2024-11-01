#include "matrix.h"

void add(matrix<int>& A, matrix<int>& B, matrix<int>& C) {
    if (!(A.rows() == B.rows() && B.rows() == C.rows() && A.cols() == B.cols() &&
          B.cols() == C.cols()))
        return;

    for (int i = 0; i < C.rows(); i++) {
        auto r = C[i];
        for (int j = 0; j < r.size(); j++) {
            C.at(i, j) = A.at(i, j) + B.at(i, j);
        }
    }
}

void multiply(matrix<int>& A, matrix<int>& B, matrix<int>& C) {
    int n = A.cols();  // = B.rows()

    for (int i = 0; i < A.rows(); i++) {
        for(int j = 0; j < B.cols(); j++) {
            C.at(i, j) = 0;
            for(int k = 0; k < n; k++) {
                C.at(i, j) += A.at(i, k) * B.at(k, j);
            }
        }
    }
}
