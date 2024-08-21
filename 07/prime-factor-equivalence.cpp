#include <simplecpp>

// A function to check if two numbers have the same set of prime factors
bool PFE(int w, int x);  // this is just the declaration. definition follows later.

main_program {
	cout << "Enter two positive numbers to check for prime-factor equivalence: ";
	unsigned int a, b;
	cin >> a >> b;
	// the function PFE gets called as part of evaluating an expression below
	string outcome =  PFE(a,b) ? "":"not ";
	cout << a << " and " << b << " are " << outcome << "equivalent!" << endl;
}

///// Below we are going to define PFE declared above (and various other functions).



//////////////////////////////
// a global string to help with indenting log messages
// and two functions to increase and decrease the indentation
string indent = "";
void indentplus() { indent += "\t"; }
void indentminus() { if (indent != "") indent.pop_back(); }
/////////////////////////////////

///////// computing GCD using Euclid's Algorithm /////////
int gcd(int a, int b) {
	if (a<0 || b<0) return gcd(abs(a),abs(b));
	if (a<b) return gcd(b,a);
	indentplus();
	cerr << indent << "> called gcd(" << a <<"," << b << ")" << endl;
	for (int r = a%b; r>0; r=a%b) {
		a = b; b = r; 
	}
	cerr << indent << "< gcd returning " << b << endl;
	indentminus();
	return b;
}


/////////////////////////////
// Remove from x all its common factors with w;
// if x is 0, return 0 (cannot really remove factors from 0)
int reduce(int w, int x) {
	if (x==0) return 0;
	indentplus();
	cerr << indent << "> called reduce(" << w << "," << x << ")" << endl;
	for (int g = gcd(w,x); g>1; x/=g, g = gcd(w,x)) { }
	cerr << indent << "< reduce returning " << x << endl;
	indentminus();
	return x;
}

///////////////////////// 
// check if w covers x: i.e., all prime factors of x are present in w.
bool covers(int w, int x) {
	indentplus();
	cerr << indent << "> called covers(" << w << "," << x << ")" << endl;
	int reduced = reduce(w,x);
	cerr << indent << "< covers returning " << (reduced==1) << endl;
	indentminus();
	return (reduced==1);
}

///////////////////////////
// This function was declared earlier.
// Below is the definition
bool PFE(int w, int x) {
	return covers(w,x) && covers(x,w);
}

