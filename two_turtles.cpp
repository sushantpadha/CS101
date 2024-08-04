#include <simplecpp>

/*
    Simulates two turtles each starting at different positions.

    Each turtle can be individually called and issued commands in the form:
    `(f|l|r) (1|2) (pixels|degrees)`
    or `q` to quit.
*/

main_program
{
    const int N = 100;
    const int MIN_X = -250, MIN_Y = -250, MAX_X = 250, MAX_Y = 250;

    cout << "Drive using f, l, r followed by 1/2 to select turtle, "
         << "followed by a number (pixels/degrees). "
         << "q to Quit (ends after " << N << " moves)" << endl
         << endl;

    // initialize variables
    // left or acw is taken to be +ve angle
    char cmd;
    int choice = 1;
    int _choice = 1;
    double arg;
    double x1 = -100, y1 = 0, x2 = 100, y2 = 0;
    double _x1 = x1, _y1 = y1, _x2 = x2, _y2 = y2;
    double ang1 = 90, ang2 = 90;
    double _ang = ang1;

    cout << "Starting configuration: 1: (" << x1 << ", " << y1
         << "; " << ang1 << "°), 2: (" << x2 << ", " << y2
         << "; " << ang2 << "°)." << endl
         << endl;

    double del_x = _x2 - _x1, del_y = _y2 - _y1;

    bool is_within_bounds1 = true, is_within_bounds2 = true;
    int op;

    bool done = false;

    // setup position for turtle 1
    // hardcoded for now
    turtleSim();
    penUp();
    left(0);
    forward(x1);
    left(ang1);
    penDown();

    repeat(N)
    {
        // read one char in case of 'q'
        cin >> cmd;
        switch (cmd)
        {
        case 'q':
            done = true;
            cout << "Quitting now." << endl;
            break;

        default:
            break;
        }

        if (done)
            break;

        // read choice
        cin >> choice;

        if ((choice != 1) && (choice != 2))
        {
            cout << "Invalid choice. Must be either 1 or 2." << endl;
            continue;
        }

        // read arg
        cin >> arg;

        switch (cmd)
        {
        case 'f':
            // update coords
            if (choice == 1)
            {
                x1 += arg * cosine(ang1);
                y1 += arg * sine(ang1);
            }
            else if (choice == 2)
            {
                x2 += arg * cosine(ang2);
                y2 += arg * sine(ang2);
            }

            // check if within bounds
            is_within_bounds1 = ((x1 >= MIN_X) && (x1 <= MAX_X) && (y1 >= MIN_Y) && (y1 <= MAX_Y));
            is_within_bounds2 = ((x2 >= MIN_X) && (x2 <= MAX_X) && (y2 >= MIN_Y) && (y2 <= MAX_Y));

            if (is_within_bounds1 && is_within_bounds2)
            {
                // change turtle pos
                if (_choice != choice)
                {
                    cout << "(switching turtles)" << endl;
                    // calculate abs diff b/w turtles' old/starting positions
                    // assume going 1 -> 2
                    del_x = _x2 - _x1;
                    del_y = _y2 - _y1;

                    // negate displacement in case it is 2 -> 1
                    if (choice == 1)
                    {
                        del_x *= -1;
                        del_y *= -1;
                    }
                }
                else
                {
                    del_x = (del_y = 0);
                }

                // move to new starting pos
                penUp();
                right(_ang); // reset angle, move along x
                forward(del_x);
                left(90); // set angle and move along y
                forward(del_y);
                right(90); // reset angle along x

                // change angle to new starting angle
                if (choice == 1)
                {
                    left(ang1);
                }
                else if (choice == 2)
                {
                    left(ang2);
                }
                penDown();

                // move
                forward(arg);
            }
            else
            {
                cout << "Selected command will drive turtle " << choice
                     << " out of bounds. " << "Try again." << endl;

                // reset
                if (choice == 1)
                {
                    x1 -= arg * cosine(ang1);
                    y1 -= arg * sine(ang1);
                }
                else if (choice == 2)
                {
                    x2 -= arg * cosine(ang2);
                    y2 -= arg * sine(ang2);
                }
            }

            // set underscored variables
            // * old values for previous turtle cmd
            _choice = choice;
            _x1 = x1;
            _x2 = x2;
            _y1 = y1;
            _y2 = y2;
            if (choice == 1)
            {
                _ang = ang1;
            }
            else if (choice == 2)
            {
                _ang = ang2;
            }
            break;

        case 'r':
        case 'l':
            op = ((cmd == 'l') ? 1 : -1);

            // update angle variables
            if (choice == 1)
            {
                ang1 += op * arg;
            }
            else if (choice == 2)
            {
                ang2 += op * arg;
            }

            // activate turtle
            // * no need to implement this rn
            cout << "(turtle orientation changed. will take effect on next move)." << endl;
            break;

        default:
            cout << "Invalid input, try again." << endl;
            break;
        }

        // take mod 360 of `_ang`
        _ang -= 360 * floor(_ang / 360);
    }
    cout << "Click to exit." << endl;
    getClick();
}