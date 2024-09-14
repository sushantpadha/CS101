#include <simplecpp>

#define dbg(x) cout << #x << "=" << x << " ";
#define nl cout << '\n';

const int SCALE = 10;

void smart_forward(double ds_sq, double dth, double& s_sq, double& th) {
    s_sq += ds_sq;
    th += dth;

    if (s_sq >= 1) {
        // ! wrong
        left(th);
        forward(sqrt(s_sq));
        s_sq = th= 0;
    }
}

void draw_fx(double f(double), double start = 0, double stop = 10, double dx = 1e-3) {
    double dy, dth, prevm, m = 0, s_sq = 0, th = 0;
    double& rs_sq = s_sq;
    double& rth = th;

    dx *= SCALE;

    turtleSim();

    penUp(); forward(-240); left(90); forward(-240); right(90); penDown();

    for (double x = start; x < stop; x += dx) {
        dy = (f(x + dx) - f(x)) * SCALE;
        m = dy / dx;
        // dbg(x);
        // dbg(dy);
        // dbg(m);
        // dbg(dth);
        // nl;

        smart_forward(dx * dx + dy * dy, arctangent2(m - prevm, 1 + m * prevm),
                      rs, rth);

        prevm = m;
    }
    getClick();
}

double fx(const double x) { return sqrt(x); }

int main() {
    int start = 0, stop = 100;
    double dx = 1e-5;
    draw_fx(&fx, start, stop, dx);
}
