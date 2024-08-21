#include <simplecpp>

main_program
{
    turtleSim();
    repeat(5)
    {
        forward(200);
        right(720 / 5);
    }
    wait(100);
}