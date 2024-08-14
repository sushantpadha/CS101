#include <simplecpp>

int main()
{
    const float SQRT2 = sqrt(2);
    float side = 400, step = 5;
    int nsqr;

    cout << "Number of squares: ";
    cin >> nsqr;

    turtleSim();
    penUp();
    forward(-side / 2);
    left(90);
    forward(-side / 2);
    right(90);
    penDown();

    for (int k = 0; k < nsqr; k++, side /= SQRT2)
    {
        for (int it = 1, nsteps = side / step; it <= nsteps * 4; it++)
        {
            // alternate pen position
            if (it % 2 == 1)
                penDown();
            else
                penUp();
            forward(step);
            // turn
            if (it % nsteps == 0)
                left(90);
        }
        // prepare for next square
        penUp();
        forward(side / 2);
        left(45);
    }
    hide();
    getClick();
}
