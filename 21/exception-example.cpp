#include <iostream>
#include <exception>

int main(int argc, char** argv) {
	try{
		typedef double DT[100000000];
		DT* d = new DT[100000000];
	} catch(const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
		exit(1);
	}
}

  
