#include <iostream>
using std::cout; using std::cin;
using std::cerr; using std::endl;
void maxend(int list[], int n) {
	int maxindex=0;
	for(int i=1; i<n; i++)
		if(list[i] > list[maxindex])
			maxindex = i;
	std::swap(list[maxindex],list[n-1]);
}

int main() {
	const int Nmax = 100;
	int numbers[Nmax];
	cout << "How many numbers to sort? ";
	int n; cin >> n;
	if (n>Nmax) {
	  cerr << "Cannot sort more than " << Nmax << "numbers!" << endl;
	  return -1;
	}
	for (int i=0; i<n; i++)
		cin >> numbers[i];

	for (int i=n; i>0; i--)
		maxend(numbers,i);

	for (int i=0; i<n; i++)
		cout << numbers[i] << " ";
	cout << endl;
  }


