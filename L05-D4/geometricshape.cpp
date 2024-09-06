#include <iomanip>
#include <simplecpp>

const double EPS = 1e-3;

struct Point {
    double x, y, z;
};

struct Cube {
    Point center;
    double side;
};

struct Sphere {
    Point center;
    double radius;
};

void calculateVolume(Cube &cube, Sphere &sphere) {
    cout << cube.side * cube.side * cube.side << " "
         << 4 * PI / 3.0 * sphere.radius * sphere.radius * sphere.radius << endl;
}
void calculateSurfaceArea(Cube &cube, Sphere &sphere) {
    cout << 6 * cube.side * cube.side << " " << 4 * PI * sphere.radius * sphere.radius
         << endl;
}
bool willOverlap(Cube &cube, Sphere &sphere {
    Point c1 = cube.center;
    Point c2 = sphere.center;
    double s = cube.side;
    double r = sphere.radius;
    return sqrt((c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y) +
                (c1.z - c2.z) * (c1.z - c2.z)) -
               sqrt(3) / 2.0 * s - r <
           0;
}

int main() {
    cout << std::fixed << std::setprecision;
    double x1, y1, z1, s, x2, y2, z2, r;
    cin >> x1 >> y1 >> z1 >> s >> x2 >> y2 >> z2 >> r;
    Cube cube = {{x1, y1, z1}, s};
    Sphere sphere = {{x2, y2, z2}, r};
    calculateVolume(cube, sphere);
    calculateSurfaceArea(cube, sphere);
    cout << willOverlap(cube, sphere) << endl;
}
