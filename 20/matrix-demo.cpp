#include <iostream>
#include <cmath>
#include "matrix.h"
using std::cout; using std::endl;

int main() {
	int m=3, n=10;
	matrix<int> M(m,n);
	matrix<int> C = { {1,2,3}, {}, {1,2,3,4}};
	for(int i=0; i<C.rows(); i++) {
		for(int j=0; j< C.cols(); j++)
			cout << C[i][j] << " ";
		cout << endl;
	}
	matrix<int> D;
	D = M;
	for(int i=0; i< m; i++)
		for(int j=0; j< n; j++)
			D.at(i,j) = (i+j)%4;
	for(int i=0; i< m; i++) {
		for(int j=0; j< n; j++)
			cout << D[i][j] << " ";
		cout << endl;
	}
}

