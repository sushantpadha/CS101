#include <cmath>
#include <iostream>
using namespace std;

int main() {
    // length breadth height(depth) -> m
    // hole diameter -> cm
    double l, b, h, d;
    cin >> l >> b >> h >> d;

    // c * pi * d^2 / 4 / 100^2 * sqrt(2*g) / AREA_CONTAINER
    const double c = 0.98;
    const double g = 9.8;
    const double STEP = 1;
    const double EPS = 1e-7;
    // ! needed for final testcase 2 3 4 2 -> 17601
    // ! without this we get 17603

    double factor = c * M_PI * d * d / 4 / 10000 * sqrt(2 * g) / (l * b);

    double t;
    for (t = 0; h > EPS; t+=STEP) {
        // cout << "t=" << t << ", " << "h=" << h << endl;
        h -= factor * sqrt(h) * STEP;
    }

    cout << int(t) << endl;
}