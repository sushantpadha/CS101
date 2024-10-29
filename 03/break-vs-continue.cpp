#include <simplecpp>

main_program {
	int i=0;
	cout << "Using break: " << endl;
	while (i<10) { if (++i == 4) break;  cout << i << endl; }
	i=0;
	cout << "Using continue: " << endl;
	while (i<10) { if (++i == 4) continue;  cout << i << endl; }
}
