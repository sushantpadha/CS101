#include <simplecpp>

main_program {
	int n;
	int count = 0;
	int j;
	bool done = false;
	int limit;
	cin >> n;
	for(int i = 2; count < n; i++){
		done = false;
		limit = sqrt(i);
		for (j = 2; j <= limit; j++) {
			if (i % j == 0) {
				done = true;
				break;
			}
		}
		if (done) continue;
		count++;
		cout << i << endl;
	}
}

