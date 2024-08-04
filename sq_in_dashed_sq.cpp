#include <simplecpp>

main_program
{
    double a = 100.0;
    double b = a / sqrt(2);

    double dash = 6.0;
    double gap = 4.0;
    double unit = dash + gap;

    int num_units = a / unit;
    double rem = a - num_units * unit;

    turtleSim();
    // larger square
    repeat(4)
    {
        repeat(num_units)
        {
            penDown();
            forward(dash);
            penUp();
            forward(gap);
        }
        penDown();
        if (rem <= dash)
        {
            forward(rem);
        }
        else
        {
            forward(dash);
            penUp();
            forward(rem - dash);
            penDown();
        }

        right(90);
    }
    penUp();
    forward(a / 2);
    right(45);
    penDown();
    // smaller square
    repeat(4)
    {
        forward(b);
        right(90);
    }
    hide(true);
    getClick();
}