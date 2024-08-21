#include <simplecpp>

main_program {
    const double MY_PI = 3.141592653589793;
    double x1, y1, x2, y2, eps, ref;
    cin >> x1 >> y1 >> x2 >> y2 >> eps >> ref;

    double deg =
        acos((x1 * x2 + y1 * y2) / (sqrt(x1 * x1 + y1 * y1) * sqrt(x2 * x2 + y2 * y2)));
    deg *= 180.0 / MY_PI;

    cout << ((abs(deg - ref) < eps) ? '1' : '0') << endl;
}
