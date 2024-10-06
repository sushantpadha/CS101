#include <iostream>

struct Fibonacci {
  int f1, f2;
  void init() { f1=0; f2=1; }
  int next() { int f = f1; std::swap(f1,f2); f2 += f1; return f;}
};

int main(){
  Fibonacci f; f.init(); // initialise the struct before accessing
  int i, M; std::cin >> M;
  for(i=0; i < M; i++) {        // for each input
    int x, y;
    std::cin >> x;              // read next input
    do y=f.next(); while (y<x); // seek a match in fib. seq
	if(x!=y) break; // if fib. seq overshoots, leave i<M, to output false
  }
  std::cout << (i==M?"true":"false") << std::endl;
}
