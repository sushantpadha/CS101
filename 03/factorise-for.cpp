#include <simplecpp>

main_program {
	const string prompt = "Enter a non-negative number (0 to exit) : ";
	unsigned int x;
	for(cout << prompt, cin >> x; x!=0; cout << prompt, cin >> x ) {
		cout << "Prime factors of " << x << ": ";
		if (x == 1) 
			cout << "1 has no prime factors!" << endl;
		else { 
			for (int d=2; x > 1; d++) // for each d >= 2, until x has no factors left
				for(; x%d == 0; x /= d) // find and remove all factors of d from x
					cout << d << " "; 
			cout << endl;
		}
	}
}
