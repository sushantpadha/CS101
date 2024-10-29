#include <simplecpp>

main_program {
	int x, d;
	cin >> x;
	if (x == 1 || x == -1) {
		cout << x << " has no prime factors!" << endl;
	} else {
		d = 2;
		while(true) {
			if (x%d == 0)
				break; // found d to be a factor of x
			++d;
		}
		cout << "Smallest prime factor of " << x << " is " << d << endl;
	}
}
