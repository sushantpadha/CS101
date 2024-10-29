#include <iostream>

std::string to_string(short x) { return x==0 ? "zero" : "non-zero"; }

int main() {
	short a = 1; int b = 1;
	std::cout << ::to_string(a) << " vs. " << to_string(b) << std::endl;
}
