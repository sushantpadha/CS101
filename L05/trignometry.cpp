#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct TrigExpression { double a, b; };

void convertForm(TrigExpression t) {
    double r = sqrt(t.a*t.a + t.b*t.b);
    double th = atan2(t.b, t.a);
    cout << t.a << "*sin(x) + " << t.b << "*cos(x)" << endl;
    // acc to problem statement only printing theta upto 3 dec places
    // ! does not match the desired output shown on site but fk it
    cout << r << "*sin(x + " << fixed << setprecision(3) << th << ")" << endl;
}

int main() {
    double a, b;
    cin >> a >> b;
    convertForm(TrigExpression{a, b});
}
