#include <simplecpp>

main_program {
	cin >> noskipws; // don't skip whitespace (will do it ourselves)
	char c;
	for (cin >> c; c<'0' || c>'9'; cin >> c); // c has a digit now
	unsigned int n; // accumulate digits from cin into n
	for(n=0; c>='0' && c<='9'; n = n*10+(c-'0'), cin >> c); 
	cout << "Read number " << n << endl;
}

