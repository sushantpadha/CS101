#include <simplecpp>

main_program
{
    const int side = 50; // =side length
    const int dashgap = 5;  // =dash =gap length
    int m = (side / dashgap) / 2;    // number of dash-gap pairs
    int n;
    cin >> n;
    float extangle = 360.0 / n;  // exterior angle
    turtleSim();
    repeat(n)
    {
        // draw dashed side
        repeat(m)
        {
            forward(dashgap);
            penUp();
            forward(dashgap);
            penDown();
        }
        // draw repeating unit of shape (solid outline)
        repeat(n) {
            forward(side);
            left(extangle);
        }
        // turn
        left(extangle);
    }
    wait(100);
}