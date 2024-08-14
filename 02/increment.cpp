#include <simplecpp>

main_program
{
    turtleSim();
    double x = 5; // x is assigned an initial value
    repeat(1000)
    {
        forward(x);
        right(60.0);
        x = x + 5;
    }
    hide();
    getClick();
}