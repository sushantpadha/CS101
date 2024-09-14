#include <string.h>
#include <iostream>
using std::cout, std::cin, std::endl, std::min, std::max;

// using fixed size for all arrays throughout the program
const int SIZE = 10;

void print_array(int* arr);
int* get_array_copy(int* arr);
bool is_sorted(int* arr);
void test_sort_func(int* arr, int* f(int*), string f_name);
#define TEST_SORT(x, y) test_sort_func(x, y, #y)
int* dumbsort(int* arr);
int* swapsort(int* arr);

// =============================================================================

int main() {
    int arr[SIZE];
    cout << "Enter 10 integers to sort: ";
    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }

    TEST_SORT(arr, dumbsort);
    TEST_SORT(arr, swapsort);
}

// ============================= UTILITY FUNCTIONS =============================
void print_array(int* arr) {
    cout << "[ ";
    for (int i = 0; i < SIZE - 1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[SIZE - 1] << " ] ";
}

int* get_array_copy(int* arr) {
    int* newarr = new int[SIZE];
    for (size_t i = 0; i < SIZE; i++) newarr[i] = arr[i];
    return newarr;
}

// check if array is sorted
bool is_sorted(int* arr) {
    for (size_t i = 0; i < SIZE - 1; i++)
        if (arr[i] > arr[i + 1])
            return false;
    return true;
}

// test the sorting function and display its output
void test_sort_func(int* arr, int* f(int*), string f_name) {
    int* sorted = f(arr);
    cout << f_name << ": ";
    print_array(sorted);
    cout << (is_sorted(sorted) ? "✅" : "❌") << '\n';
    delete[] sorted;
}
// =============================================================================

// ============================== SORT FUNCTIONS ===============================

// two pointers; swap i-th el with min el in i -> n
int* dumbsort(int* arr) {
    int* sorted = get_array_copy(arr);

    // 2 pointers

    // 0 -> SIZE; to put minimum element
    for (size_t i = 0; i < SIZE; i++) {
        int mn_idx = i;

        // i -> SIZE; to scan remaning elements
        size_t j;
        for (j = i; j < SIZE; j++) {
            mn_idx = ((sorted[j] < sorted[mn_idx]) ? j : mn_idx);
        }

        swap(sorted[i], sorted[mn_idx]);
    }

    return sorted;
}

// n swaps from 0->n (n times n)
int* swapsort(int* arr) {
    int* sorted = get_array_copy(arr);

    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE - 1; j++) {
            if (sorted[j] > sorted[j + 1])
                swap(sorted[j], sorted[j + 1]);
        }
    }

    return sorted;
}

// =============================================================================