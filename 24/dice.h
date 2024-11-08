#include <random>

// T should be an integer type
template<class T>
class dice {
  std::default_random_engine source;
  std::uniform_int_distribution<T> sampler;
public:
  // construct by passing a, b. samples will be in the range [a,b]
  dice(T a, T b) 
     : source(std::random_device()()), sampler(a,b) {}
  dice(T N=2) : dice(1,N) {} // a constructor for N-sided dice
  // get the next sample using get()
  T roll() { return sampler(source); }
  // a version of roll that ignores the original (a,b)
  T roll(T n) { return std::uniform_int_distribution<T>(1,n)(source); }
};

