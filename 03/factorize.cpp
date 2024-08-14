#include <iostream>
#include <string>
using namespace std;

int main()
{
	unsigned int x;
	unsigned int d;
	const string prompt = "enter a non-neg number (0 to exit): ";
	for (cout << prompt, cin >> x; x != 0; cout << prompt, cin >> x)
	{
		if (x == 1)
		{
			cout << "1 has no prime factors!" << endl;
			continue;
		}
		cout << "Prime factors of " << x << " are: ";
		// remove prime factors from x iteratively
		for (d = 2; x > 1; d++)
			// check if d is prime factor; remove it; cout
			for (; x % d == 0; x /= d, cout << d << " ")
			{
			}
		cout << endl;
	}
}
