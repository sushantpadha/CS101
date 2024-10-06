#include <iostream>

struct Fibonacci {
  int f1, f2;
  void init() { f1=0; f2=1; }
  int next() { int f = f1; std::swap(f1,f2); f2 += f1; return f;}
};


struct intInputs {
  int toRead; // how many to read
  void init() { std::cin >> toRead; }
  bool read(int& x) {
    if (toRead <= 0) return false;
    std::cin >> x; toRead --;
    return true;
  }
};

int main(){
  intInputs in; in.init();
  Fibonacci f; f.init();
  int x, y; 
  bool read_ok = in.read(x); // read input; returns false if inputs over
  for( y = f.next(); read_ok; y = f.next() ) { // for each y in fib. seq 
	if(x==y)                 // if y matched with input
		read_ok = in.read(x);// read next input; exit loop if input over
	else if (x<y)            // if y overshoots input
		break;               // then exit loop, leaving read_ok true
  }
  std::cout << (!read_ok?"true":"false") << std::endl;
}
