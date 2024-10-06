#include <iostream>
int main(){
  int i, M; std::cin >> M;
  int fib1 = 1, fib2 = 0;     // initializing fib1 = F(-1), fib2 = F(0)
  for(i=0; i < M; i++) {      // for each input 
    int x; std::cin >> x;     // read next input
    do {                      // seek a match in fib. seq
        std::swap(fib1,fib2); fib2 += fib1; // advance fib1, fib2
    } while (fib1 < x);       // until input found or overshot
    if(fib1 != x) // if fib. seq overshoots (no match)
        break;    // then leave i<M, to output false
  }
  std::cout << (i==M?"true":"false") << std::endl;
}
