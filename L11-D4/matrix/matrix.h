#include <vector>
#if __cplusplus >= 202002L
#include <span>
#endif
using std::initializer_list;
using std::vector;

template <class T>
class matrix {
    int nrows;
    int ncols;
    vector<vector<T>> R;

public:
    // a constructor which takes the dimensions
    matrix(int m, int n) : nrows(m), ncols(n), R(m, std::vector<T>(n)) {}

    // a constructor using a nested initializer_list
    matrix(initializer_list<initializer_list<T>> list) : R(list.begin(), list.end()) {
        nrows = R.size();
        ncols = 0;  // expand each column to be max
        for (auto& r : R)
            if (r.size() > ncols)
                ncols = r.size();
        for (auto& r : R) r.resize(ncols);
    }

    matrix() = default;  // reinstate the default constructor

    /* The intention of operator[] below is to allow accessing an entry in the
     * matrix M as M[i][j]. (M[i] would be the vector corresponding to the i-th
     * row, and then the vector's operator[] will be invoked on input j.)
     * Caution: This kind of access allows outside code to resize each row
     * arbitrarily. To prevent that instead of returning a vector, it should be
     * wrapped in an object which disallows such modifications, while allowing
     * access through operator[]. C++20 onwards, std::span can be used for this
     * purpose.  */

#if __cplusplus >= 202002L
    auto operator[](int i) { return std::span(R[i]); }
#else
    vector<T>& operator[](int i) { return R[i]; }
#endif

    T& at(int i, int j) { return (R.at(i)).at(j); }
    int rows() { return nrows; }
    int cols() { return ncols; }
};
void add(matrix<int>& A, matrix<int>& B, matrix<int>& C);
void multiply(matrix<int>& A, matrix<int>& B, matrix<int>& C);
