#include <simplecpp>

/*
    Simulates two turtles each starting at different positions.

    Each turtle can be individually called and issued commands in the form:
    `(f|l|r) (1|2) (pixels|degrees)`
    or `q` to quit.

    Alerts the user if the turtles are about to collide.

    Features:
    - Provides 4 commands
    - Provides complete freedom of motion for two turtles
    - Alerts user and aborts any command that causes turtles to either collide, or go out of bounds
    - Implements robust error handling (for wrong input)
    - Prints useful help messages
*/

main_program
{
    // number of program iterations
    const int N = 100;
    // range of accuracy for detecting collisions
    const double RANGE = 0.001;
    // size of bounds
    const int MIN_X = -250, MIN_Y = -250, MAX_X = 250, MAX_Y = 250;

    cout << "Drive using f, l, r followed by 1/2 to select turtle, "
         << "followed by a number (pixels/degrees). " << endl
         << "q to Quit (ends after " << N << " moves)" << endl
         << "g followed by 1/2 to get coordinates of corressponding turtle." << endl
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
    bool is_coll = false, is_invalid = false;
    double da, dxa, dya, db, dxb, dyb, dc, dxc, dyc;
    int op;

    bool done = false;

    // show 3x3 square for turtle 2 then 1
    // leave at its centre
    // hardcoded for now
    turtleSim();

    penUp();
    forward(x2);
    forward(-1);
    left(90);
    penDown();

    forward(1);
    repeat(3)
    {
        right(90);
        forward(3);
    }
    right(90);
    forward(2);

    penUp();
    right(90);
    forward(1);
    forward(-x2);
    forward(x1);
    forward(-1);
    left(90);
    penDown();

    forward(1);
    repeat(3)
    {
        right(90);
        forward(3);
    }
    right(90);
    forward(2);

    penUp();
    right(90);
    forward(1);

    left(ang1);

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

        case 'f':
        case 'l':
        case 'r':
        case 'g':
            break;

        default:
            cout << "Invalid command. Must be one of q/f/l/r/g." << endl;
            continue;
        }

        if (done)
            break;

        // read choice
        cin >> choice;

        if ((choice != 1) && (choice != 2))
        {
            cout << "### choice: " << choice << " cmd: " << cmd << endl;
            cout << "Invalid choice. Must be either 1 or 2." << endl;
            continue;
        }

        if (cmd == 'g')
        {
            cout << "turtle " << choice << " is: ";
            switch (choice)
            {
            case 1:
                cout << "(" << x1 << ", " << y1
                     << "; " << ang1 << "°)" << endl;
                break;
            case 2:
                cout << "(" << x2 << ", " << y2
                     << "; " << ang2 << "°)" << endl;
                break;

            default:
                break;
            }
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
                dxa = arg * cosine(ang1);
                dya = arg * sine(ang1);
                x1 += dxa;
                y1 += dya;
            }
            else if (choice == 2)
            {
                dxa = arg * cosine(ang2);
                dya = arg * sine(ang2);
                x2 += dxa;
                y2 += dya;
            }

            // check if colliding
            if (choice == 1)
            {
                dxb = x2 - _x1;
                dyb = y2 - _y1;
                dxc = x1 - x2;
                dyc = y1 - y2;
            }
            else if (choice == 2)
            {
                dxb = x1 - _x2;
                dyb = y1 - _y2;
                dxc = x2 - x1;
                dyc = y2 - y1;
            }

            da = arg; // directly use user input `arg`
            db = sqrt(dxb * dxb + dyb * dyb);
            dc = sqrt(dxc * dxc + dyc * dyc);

            is_coll = (abs(da - (db + dc)) <= RANGE);

            if (is_coll)
            {
                cout << "Selected command will cause turtle " << choice
                     << " to collide with the other turtle. Try again." << endl;
            }
            else
            {
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
                }
            }

            // reset
            is_invalid = (is_coll || !is_within_bounds1 || !is_within_bounds2);
            if (is_invalid)
            {
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