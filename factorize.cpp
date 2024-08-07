#include <iostream>
using namespace std;

int main()
{
	unsigned int x;
	unsigned int d;
	while (true)
	{
		cout << "enter a non-neg number (0 to exit): ";
		cin >> x;
		if (x == 0)
			break;
		if (x == 1)
		{
			cout << "1 has no prime factors!" << endl;
			continue;
		}
		cout << "Prime factors of " << x << " are: ";
		// iterate by removing prime factors from x iteratively
		for (d = 2; x > 1; d++)
		{
			// check if d is prime factor; remove it; cout
			for (; x % d == 0; x /= d, cout << d << " ")
				;
		}
		cout << endl;
	}
}
