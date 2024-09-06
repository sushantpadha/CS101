#include <iostream>
using std::cout, std::cin, std::endl;

#define DBG(x) cout << #x << "=" << x << '\n';

int i = 0;

namespace N {
	int i = 1;
}

int main() {
	using namespace N;
	DBG(N::i);
	DBG(::i);
	DBG(i);
}
