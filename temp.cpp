#include <iostream>

using namespace std;

#define DEBUG_ENABLED
#define nl cout << endl

#ifdef DEBUG_ENABLED
#define DBG(x) cout << #x << "=" << x << " "
#else
#define DBG(X)
#endif

int main() {
    int x = 3;
    int y = x*x;

    cout << "This is line: " << __LINE__ << " at time: " << __TIME__ << " on date: " << __DATE__ << " in file: " __FILE__ << endl;

    DBG(x); nl;
    DBG(y-1); nl;

    return 0;
}

