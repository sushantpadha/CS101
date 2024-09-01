#include <iomanip>
#include <simplecpp>

void computeShapeArea(int shapeType, double a, double b, double& area) {
    if (shapeType == 1)
        area = a * b / 2.0;
    else if (shapeType == 2)
        area = a * b;
    else if (shapeType == 3)
        area = a * b / 2.0;
}

main_program {
    int shapeType;
    double a, b, area;
    cin >> shapeType >> a >> b;
    double& refArea = area;

    computeShapeArea(shapeType, a, b, refArea);

    cout << setprecision(2) << fixed << area << endl;
}
