/* A Reverse Polish Notation Calculator */
#include <iostream>
#include <exception>
#include <stack>
using std::string;
using std::ostream; using std::istream; 
using std::cout; using std::cerr;
using std::cin; using std::endl;

#define DBG 0
#define LOG if(DBG) std::cerr

class rational {
	int N, D;
	int gcd(int a, int b) {
		return (b==0)? abs(a) : gcd(b,a%b);
	}

	void reduce() { // remove gcd from N, D
		int g = gcd(N,D);
		if(g) { N /= g; D/= g; }
	}

public:
	rational(int num=0, int den=1);

	rational& operator+= (const rational& other) {
		N = N * other.D + other.N * D;
		D *= other.D;
		reduce();
		return *this;
	}
	rational& operator-= (const rational& other) {
		N = N * other.D - other.N * D;
		D *= other.D;
		reduce();
		return *this;
	}
	rational& operator*= (const rational& other) {
		N *= other.N;
		D *= other.D;
		reduce();
		return *this;
	}
	rational& operator/= (const rational& other) {
		if(other.N==0)
			throw std::domain_error("Division by zero");
		int sign = (other.N < 0) ? -1 : 1; //
		N *= other.D * sign;
		D *= other.N * sign; // keep denominator positive
		reduce();
		return *this;
	}

	friend ostream& operator<< (ostream& out, const rational& r) {
		out << r.N;
		if(r.D!=1) 
			out << "/" << r.D;
		return out;
	}
};

rational::rational(int num, int den) : N(num), D(den) {
	if(D==0) throw std::domain_error("Zero Denominator");
}

class RPNcalc {
	bool working = true;
	std::stack<rational> stk;
	void op(rational& a, rational b, char c) {
		LOG << "Operating: " << a << c << b;
		if(c=='+')       a+=b;
		else if(c=='-')  a-=b;
		else if(c=='*')  a*=b;
		else if(c=='/')  a/=b;
		else throw std::invalid_argument(string("Invalid operator: ") += c);
		LOG << " = " << a << endl;
	}

public:
	RPNcalc& operator<< (const char& c) {
		if(!working)
			throw std::invalid_argument("Input to closed stack");
		// check if it is a stack inspection/manipulation command
		if(c=='?')
			(stk.empty()? cout << "Nothing" : cout << stk.top()) << " is at the top of the stack. Stack size = " << stk.size() << endl;
		else if(c=='.')
			working = false;
		else {
			LOG << "Operating with " << c << endl;
			if(stk.size() < 2)
				throw std::invalid_argument(string("Stack underflow on operator ") += c);
			rational b = stk.top();
			stk.pop(); 
			op(stk.top(),b,c);
			LOG << stk.top() << " is at the top of the stack. Stack size = " << stk.size() << endl;
		}
		return *this;
	}

	RPNcalc& operator<< (const int& n) {
		if(!working)
			throw std::invalid_argument("Input to closed stack");
		stk.push(rational(n));
		LOG << "Inserted " << n << ". Stack size = " << stk.size()  << endl;
		return *this;
	}

	operator bool() { return working; }

	// output the top of the stack (without popping)
	friend ostream& operator<< (ostream& out, RPNcalc& calc) {
		if(calc.stk.empty())
			throw std::invalid_argument("Cannot output from empty stack");
		return out << calc.stk.top() << (calc.stk.size()!=1? " (unfinished)" : "");
	}

};

// a function to read from input stream into the calculator
istream& operator>> (istream& in, RPNcalc& calc) {
	// peek a character, then try to read a number. 
	// if it fails, use the peeked character as operator.
	char c = (in >> std::ws).peek();

	// if c is a digit, or is plus/minus followed by a digit, read a number
	// else use c as the command
	bool plusminus = (c=='+' || c=='-');
	bool number = (c>='0' && c<='9');
	if(!number) {
		in >> c; // read the non-digit symbol
		char next = in.peek(); // peek without skipping whitespace
		number = plusminus && next >= '0' && next <= '9';
	}

	if(number) {
		int x; in >> x; // read the number 
		if(plusminus && c=='-') x = -x;
		if(in) calc << x; // use x only if no input errors
	} else 
		if(in) calc << c; // use c only if no input errors

	return in;
}


bool quit(const string& prompt, char match) {
	cout << prompt;
	char c = (cin>>std::ws).peek();
	return (!cin || (c==match));
}

int main() {
	const string prompt = ">>> Expression to evaluate (q to quit): ";
	while(!quit(prompt,'q')) {
		try {
			RPNcalc C;
			while(cin && C) {cin >> C;}
			cout << "Output: " << C << endl;
		}
		catch (const std::exception& e) {
			cerr << "ERROR: " << e.what() << ". Skipping till '.'" << endl;
			cin.clear(); cin.ignore(std::numeric_limits<std::streamsize>::max(),'.');
		}
	}
}
