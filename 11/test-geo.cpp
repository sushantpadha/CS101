#include "geo.h"
#include <iostream>

// here we are in the global namespace (empty name)

int P; // a global variable
       // can be referred to as ::P if necessary

int main() {
    P = 10;  // P in the global namespace
    geo::P p1 = {P, P}, delta = {0, 1};
	geo::move(p1,delta);
    std::cout << p1.to_string() << std::endl;
}
