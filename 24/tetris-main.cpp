#include <iostream>
using std::cout; 
using std::cerr; 
using std::cin; 
using std::endl; 
#include "tetris-game.h"


int main() {
	game G;
	int s = G.play();
	cout << "Score = " << s << endl;
}
