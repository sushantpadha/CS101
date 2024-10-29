#include <iostream>
#include <vector>
#include "dice.h"
using std::vector;
using std::cout; using std::endl;

#define DBG 0
#define LOG if(DBG) std::cerr


// we will allow sorting vectors of any type T
// which supports comparison operator <=
// and has an std::swap(&T,&T) function
template<class T> 
using it = typename vector<T>::iterator;

template<class T> 
it<T> pivot(it<T> begin, it<T> end) {
  auto pivot = *begin;
  begin++; // since the first element is already at a proper position
  end--;   // now end points to  the last element rather than beyond it
  while(begin<=end) {
    if (*begin<=pivot)  begin++;
    if (!(*end<=pivot))  end--;
    if (begin<end && !(*begin<=pivot) && *end<=pivot)
      std::swap(*begin++,*end--);
  }
  return begin;
}


// this version accepts a dice which will be used by all recursive calls
template<class T> 
void quicksort(it<T> begin, it<T> end, dice<T>& D) {
  if(begin + 1 >= end) return; // empty range or one element
  T R = D.roll(end-begin);
  std::swap(*begin,*(begin+R-1)); // move a random element to the front
  auto mid = pivot<T>(begin,end);
  // move pivoting element to the right end of the left part.
  std::swap(*begin,*(mid-1));
  quicksort<T>(begin, mid-1, D);
  quicksort<T>(mid, end, D);
}

template<class T> 
vector<T>& quicksort(vector<T>& A) {
	// create a dice and pass it on for quicksort to use
	dice<T> D;
	quicksort<T>(A.begin(),A.end(),D);
	return A;
}
  

/********** unit tests *********/
template <class T>
bool check_pivot(it<T> begin, it<T> end, it<T> mid) {
  auto pivot = *begin;
  for(auto a = begin; a < mid; a++)
    if(*a > pivot) return false;
  for(auto a = mid; a < end; a++)
    if(*a <= pivot) return false;
  return true;
}

template <class T>
bool check_sort(vector<T> A) {
  // compare *a against *(a-1), where begin <= a-1 < a < end.
  for(auto a = A.begin()+1; a < A.end(); a++)
    if(*(a-1) > *a) return false;
  return true;
}


template <class T>
void rand_unittest_pivot(int ntimes=100, int maxlen=100, int maxval=100) {
	vector<T> A;
	dice<T> Dlen(maxlen), Dval(maxval);
	for (int i=0; i<ntimes; ++i) {
		A.resize(Dlen.roll());
		for (int j=0; j<A.size(); ++j) 
			A[j] = Dval.roll();
		LOG << "Pivoting " << A.size() << " elements" << endl;
		if(!check_pivot(A.begin(),A.end(),pivot(A.begin(),A.end())))
			throw std::logic_error("pivot failed");
	}
}

template <class T>
void rand_unittest_quicksort(int ntimes=100, int maxlen=100, int maxval=100) {
	vector<T> A (maxlen);
	dice<T> Dlen(maxlen), Dval(maxval);
	for (int i=0; i<ntimes; ++i) {
		A.resize(Dlen.roll());
		for (int j=0; j<A.size(); ++j) 
			A[j] = Dval.roll();
		LOG << "Sorting " << A.size() << " elements" << endl;
		if(!check_sort<T>(quicksort<T>(A)))
			throw std::logic_error("pivot failed");
	}
}

/*******************/

int main() {
	vector<short> A;
	dice<short> r(365);
	for(int i=0; i<20; i++)
		A.push_back(r.roll());
	quicksort<short>(A);
	for(auto a: A) cout << a << " ";
	cout << endl;
	rand_unittest_quicksort<short>();
}
