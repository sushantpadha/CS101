#include <iostream>
using std::cout; using std::endl; using std::swap;

void printArray(char A[], int n) {
	for(int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << endl;
}

// print all permutations of A[fixed]..A[n-1], prefixed with A[0]..A[fixed-1]
// leave the array A in the same order as it was received
void permute(char A[], int n, int fixed=0) {
	if(fixed == n-1) {
		printArray(A,n);
		return;
	}

	for(int i=fixed; i < n; i++) {
		swap(A[i], A[fixed]); // pick A[i] to be the first in the permuted part
		permute(A, n, fixed+1);   // print all perms after fixing one more element; return array unchanged
		swap(A[i], A[fixed]); // to return array unchanged, undo each time we swap
	}
}

int main() {
	int n = 6;
	char alphabet[n];
	for(int i=0; i<n; i++) alphabet[i] = 'a' + i;
	permute(alphabet,n);
}
