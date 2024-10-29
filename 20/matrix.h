#include <vector>
#if __cplusplus >= 202002L
#include <span>
#endif
using std::vector;
using std::initializer_list;

template<class T>
class matrix {
	unsigned nrows;
	unsigned ncols;
	vector<vector<T>> R;
public:
	// a constructor which takes the dimensions
	matrix(unsigned m, unsigned n) : nrows(m), ncols(n), R(m,std::vector<T>(n)) {}

	// a constructor using a nested initializer_list
	matrix(initializer_list<initializer_list<T>> list) : R(list.begin(),list.end()) {
		nrows = R.size();
		ncols = 0;  // expand each column to be max
		for (auto& r : R)
			if(r.size() > ncols) ncols = r.size();
		for (auto& r : R)
			r.resize(ncols);
	}


	matrix() = default; // reinstate the default constructor

	/* The intention of operator[] below is to allow accessing an entry in the
	 * matrix M as M[i][j]. (M[i] would be the vector corresponding to the i-th
	 * row, and then the vector's operator[] will be invoked on input j.)
	 * Caution: This kind of access allows outside code to resize each row
	 * arbitrarily. To prevent that instead of returning a vector, it should be
	 * wrapped in an object which disallows such modifications, while allowing
	 * access through operator[]. C++20 onwards, std::span can be used for this
	 * purpose.  */


#if __cplusplus >= 202002L
	auto operator[] (unsigned i) {
		return std::span(R[i]);
	}
#else
	vector<T>& operator[] (unsigned i) {
		return R[i];
	}
#endif

	T& at(unsigned i, unsigned j) {return (R.at(i)).at(j); }
	unsigned rows() {return nrows;}
	unsigned cols() {return ncols;}
};
