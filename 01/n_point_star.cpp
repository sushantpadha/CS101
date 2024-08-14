#include <simplecpp>

main_program
{
    // should be fixed
    // n1 = a * cos((inner_angle) / 2);
    double n1 = 50.0;
    double n2 = 100.0;

    cout << "How many sides: ";
    int n;
    cin >> n;

    float ideal_deg = 2 * 360.0 / n;

    cout << "Outer angle of rotation (in degrees, ideally >=";
    cout << ideal_deg << "): ";
    float deg;
    cin >> deg;

    double side = n1 / cosine((360.0 - deg) / 2);
    double gap = n2;

    turtleSim();

    penUp();
    forward(-gap);
    left(90);
    forward(-gap);
    right(90);
    penDown();

    repeat(n)
    {
        forward(side);
        right(deg);
        forward(side);
        left(deg - 360.0 / n);
    }

    hide(true);

    getClick();
}