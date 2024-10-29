#include <iostream>
#include <cassert>
using std::cout; using std::cin; using std::cerr; using std::endl; 

typedef std::string T;

void merge(const T ** X, const T ** Y, int left, int right);

// assumes not called with left > right, and maintains that invariant
// in, out, scratch are arrays, all with left,...,right as valid indices.
void msort (const T in[], const T * out[], int left, int right, const T * scratch[]) {
	assert(left <= right);

	if (left==right) {
		out[left] = &in[left];
		return;
	}
	// here left < right. then left <= mid and mid+1 <= right
	int mid = (left+right)/2;
	msort(in,scratch,left,mid,out);   // get sorted outputs in scratch
	msort(in,scratch,mid+1,right,out);
	merge(scratch,out,left,right);   // merge from scratch into out
}


void merge(const T * X[], const T * Y[], int left, int right) {
	// merge X[left..mid] and X[mid+1..right] into Y
	int mid = (left+right)/2, lp = left, rp = mid+1;
	for(int i=left; i <= right; i++) {
		if(lp <= mid && (rp > right || *X[lp] < *X[rp]))
			Y[i] = X[lp++];
		else
			Y[i] = X[rp++];
	}
}


int main() {
	const unsigned MAXN = 300;
	T A[MAXN];
	T * B[MAXN], * C[MAXN];
	unsigned n = 0;
	cout << "Input a list of words to sort, followed by \".\"\n";
	do cin >> A[n]; while (A[n] != "." && (++n)<MAXN);
	cerr << "Sorting " << n << " strings" << endl;
	msort(A,(const T **)(B),0,n-1,(const T **)(C));
	for(int i=0; i<n; i++)
		cout << *B[i] << " ";
	cout << endl;
}

