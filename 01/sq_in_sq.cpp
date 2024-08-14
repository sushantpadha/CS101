#include <simplecpp>

main_program
{
    int a = 100;
    double b = a / sqrt(2);

    turtleSim();
    // larger square
    repeat(4)
    {
        forward(a);
        right(90);
    }
    forward(a / 2);
    right(45);
    // smaller square
    repeat(4)
    {
        forward(b);
        right(90);
    }
    hide(true);
    getClick();
}