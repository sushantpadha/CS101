#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int n, N, M;
    cin >> N >> M;
    int arr1[N + 1], arr2[M + 1];  // * see reason below

    // read in arrays
    for (int i = 0; i < N; i++) {
        cin >> n;
        arr1[i] = n;
    }
    for (int i = 0; i < M; i++) {
        cin >> n;
        arr2[i] = n;
    }

    // * similar to merge sort
    // create two pointers to start from 0 on both arrays
    // compare values at both pointers
    // 1. if unequal, add the lesser value and increment its pointer
    // 2. if equal, add either and increment both pointers

    // to fix the case of one pointer reaching end of array and incrementing beyond it,
    //   we append INT_MAX to the end of each array
    arr1[N] = arr2[M] = INT32_MAX;

    int i = 0, j = 0;
    int arr[N + M];
    int k = 0;  // pointer for answer array

    while (i <= N && j <= M) {
        int n1 = arr1[i];
        int n2 = arr2[j];

        if (n1 < n2) {
            arr[k++] = n1;
            i++;
        } else if (n1 > n2) {
            arr[k++] = n2;
            j++;
        } else {
            // dont add INT_MAX
            if (i != N && j != M)
                arr[k++] = n1;
            i++;
            j++;
        }
    }

    // size - 1 + 1 = k
    for (int i = 0; i < k; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n' << k;
}
