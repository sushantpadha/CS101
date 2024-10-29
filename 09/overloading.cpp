#include<simplecpp>

template<typename T>
void swp(T& x, T& y) {
	T tmp = x; x = y; y = tmp;
}

void swp(bool& x, bool& y) {
	bool tmp = x; x = y; y = tmp;
	cout << "Breaking the template!\n";
}

int main() {
	int a = 1, b = 20;
	string s = "OK", t = "Bye";
	cout << "Before swaps: " << a << " " << b << " " << s << " " << t <<endl;
	swp(a,b);
	swp(s,t);
	cout << "After swaps: "  << a << " " << b << " " << s << " " << t <<endl;
	bool p = true, q = false;
	swp(p,q);
}
