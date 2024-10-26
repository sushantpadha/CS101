#include <iostream>
// #include<iomanip>
// #include<string>
// #include<algorithm>

using namespace std;

// merge X[left...mid] and X[mid+1...right] in Y[left...right]
void merge(const int X[], int Y[], int left, int right) {
    // right is included
    // L, R = pointers in each subarray for next element to compare
    int mid = (left + right) / 2, L = left, R = mid + 1;

    for (int i = left; i <= right; i++) {
        // add element from X if arr1 is not fully traversed and either:
        // arr2 is fully traversed, or, arr2 el < arr1 el
        if (L <= mid && (R > right || X[L] < X[R]))
            Y[i] = X[L++];
        else
            Y[i] = X[R++];
    }
}

// sort in[left...right] in out[left...right]
void sort(const int in[], int out[], int left, int right, int scratch[]) {
    // handle base case: left == right, ie, one element array
    if (left == right) {
        out[left] = in[left];
        return;
    }

    int mid = (left + right) / 2;

    // sort left...mid and mid+1...right seperately in scratch
    sort(in, scratch, left, mid, out);
    sort(in, scratch, mid + 1, right, out);

    // merge them from scratch into out
    merge(scratch, out, left, right);
}

int main() {
    int N = 6;
    int arr[N] = {6, 0, 4, 1, 9, 3};
    int sorted[N];
    int scratch[N];

    sort(arr, sorted, 0, 5, scratch);

    for (int i = 0; i < N; i++) {
        cout << sorted[i] << ' ';
    }
}
