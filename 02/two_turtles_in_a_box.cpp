#include <simplecpp>

/*
Two turtles move within a box, in a grid with steps of constant size.
Collisions may only occur at lattice points.
*/

main_program
{
    const int LIMIT = 300;
    const int DEG_STEP = 90;
    const int STEP = 25;
    int x = 100, y = 0, deg = 0;
    int xp = -100, yp = 0, degp = 0;
    int tmp;

    int dx = 0, dy = 0;
    char cmd;
    turtleSim();
    while (true)
    {
        // move origin -> active turtle
        penUp();
        forward(x);
        left(90);
        forward(y);
        right(90);
        penDown();
        // take input
        cin >> cmd;
        if (cmd == 'f')
        {
            int dx = deg == 0 ? STEP : (deg == 180 ? -STEP : 0);
            int dy = deg == 90 ? STEP : (deg == 270 ? -STEP : 0);
            if (abs(x + dx) >= LIMIT || abs(y + dy) >= LIMIT)
                cout << "Can't hit the box!" << endl;
            else if (x + dx == xp && y + dy == yp)
                cout << "Can't collide!" << endl;
            else
            {
                forward(STEP);
                x += dx;
                y += dy;
            }
        }
        else if (cmd == 'l' || cmd == 'r')
        {
            int op = (cmd == 'l') ? 1 : -1;
            left(op * DEG_STEP);
            deg = (deg + op * DEG_STEP) % 360;
        }

        else if (cmd == 'q')
        {
            cout << "Quitting." << endl;
            break;
        }

        // move active -> origin
        penUp();
        forward(-x);
        left(90);
        forward(-y);
        right(90);
        penDown();
        // switch variables
        tmp = x;
        x = xp;
        xp = tmp;
        tmp = y;
        y = yp;
        yp = tmp;
        tmp = deg;
        deg = degp;
        degp = tmp;
    }
    hide();
    getClick();
}
