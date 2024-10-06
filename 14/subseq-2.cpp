#include <iostream>
int next();  // Each call to this will return the next element in the sequence.
int main(){
  int i, M; std::cin >> M;
  for(i=0; i < M; i++) {      // for each input
    int x, y;
    std::cin >> x;            // read next input
    do y=next(); while (y<x); // seek a match in fib. seq
	if(x!=y) break; // if fib. seq overshoots, leave i<M, to output false
  }
  std::cout << (i==M?"true":"false") << std::endl;
}

int next() {                  // implements fibonacci sequence
  static int f1 = 1, f2 = 0;  // initialize f1 to be "F(-1)"
  std::swap(f1,f2); f2 += f1; // (f1, f2) ← (f2, sum)
  return f1; 
}
