#include <iostream>
#include <ctime>
using std::cout; using std::cin; using std::cerr;
using std::endl; using std::flush;
using std::clock; using std::clock_t;

// to store NMAX integers, indexed 0 to NMAX-1
struct Memo {
	static const int NMAX = 94; // beyond this Fibonacci(n) overflows unsigned long long
	bool usememo;
	bool filled[NMAX] = {};  // this initializes the array to all false
	unsigned long long memo[NMAX];  

	void init(bool use) { usememo = use; }
	bool has(unsigned i) { return usememo && filled[i]; }
	unsigned long long get(unsigned i) { return memo[i]; }
	void add(unsigned i, unsigned long long val) {
		if(!usememo) return;
		if(i>=NMAX) throw std::invalid_argument("Out of memo-ization range!");
		memo[i] = val; filled[i] = true;
	}
};


unsigned long long fib(int n, Memo& memo) {

	// if memo has it, do not recurse
	if(memo.has(n))
		return memo.get(n);

	// the actual recursive computation
	// fib(n)=n for n=0,1; for n>1, fib(n)=fib(n-1)+fib(n-2)
	unsigned long long ans =  (n<=1) ? n : fib(n-1,memo) + fib(n-2,memo);

	// upate memo
	memo.add(n,ans);

	// a progress bar : prints n after computing fib(n) for the first time
	static int maxfound = -1;
	if (n > maxfound) 
		cerr << (maxfound = n) << " " << flush;

	return ans;
}

int main() {
	Memo memo; memo.init(false);
	unsigned n;
	cout << "n (max is " << memo.NMAX << ") "; cin >> n;
	clock_t t1 = clock();
	unsigned long long f = fib(n,memo);
	clock_t t2 = clock();
	cout << "\nFib(n) = " << f << ". Time taken = "
		 << double(t2-t1)/CLOCKS_PER_SEC << "s" << endl;
}
