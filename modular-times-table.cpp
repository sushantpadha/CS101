#include <cassert>
#include <simplecpp>

// #define __DEBUG_ENABLED
#define dbg(x)
#define nl

#ifdef __DEBUG_ENABLED
#define dbg(x) cout << #x << "=" << x << " "
#define nl cout << '\n'
#undef __DEBUG_ENABLED
#endif

const int SIZE = 900;
const int RADIUS = 400;
const int CIRCLE_SIDES = 90;  // must be a factor of 180
const double eps = 1e-4;
double EXT_ANGLE;
double INT_ANGLE;
double SIDE;
char c;

// take anticlockwise as positive
void connect(int a, int b) {
    // * INVARIANT: turtle is facing centre of circle
    if (a == b) return;

    const double alpha = 90 - EXT_ANGLE * (b - a) / 2;
    const double r = 2 * RADIUS * cosine(alpha);

    dbg(b-a);
    dbg(alpha);
    dbg(r);
    nl;

    wait(0.5);

    // cin >> c;
    right(alpha);
    forward(r);
    forward(-r);
    left(alpha);
}

// define geometrical constants
void setupGeometry(int n) {
    // define geometry
    EXT_ANGLE = 360 / n;
    INT_ANGLE = 90 - 180 / n;
    SIDE = 2 * RADIUS * sin(PI / n);
}

// draw circle and end at x = +RADIUS
void setupTurtle() {
    penUp();
    forward(RADIUS);
    right(90);
    penDown();

    // define geometry
    // int _ext_angle = 360 / CIRCLE_SIDES;
    // double _side = 2 * RADIUS * sin(PI / CIRCLE_SIDES);
    int _ext_angle = 1;
    double _side = (RADIUS) * PI / 180.0;

    right(_ext_angle / 2);

    double net_rotation = 0;

    // draw each side
    while (net_rotation - 360.0 < eps) {
        forward(_side);
        right(_ext_angle);
        net_rotation += _ext_angle;
    }

    // end facing center
    left(_ext_angle / 2);
    right(90);
    wait(1);
}

// in anticlockwise direction
void stepAhead() {
    penUp();
    right(INT_ANGLE);
    forward(SIDE);
    left(EXT_ANGLE);
    left(INT_ANGLE);
    penDown();
}

int main() {
    int n;
    int m;
    cin >> n >> m;

    assert(n >= 3);
    assert(m > 1);
    assert(m < n);

    // setup
    turtleSim("Modular Times Table", SIZE, SIZE);
    setupTurtle();
    setupGeometry(n);

    for (int i = 0; i < n; i++) {
        connect(i, i * m % n);
        stepAhead();
    }

    hide();
    getClick();
}
