#include <simplecpp>

main_program
{
    const int N = 100;
    const int MIN_X = -250, MIN_Y = -250, MAX_X = 250, MAX_Y = 250;

    cout << "Drive using f, l, r followed by a number (pixels/degrees). "
         << "q to Quit (ends after " << N << " moves)" << endl;

    char cmd;
    float arg;
    double x = 0, y = 0;
    double ang = 0;
    bool done = false;

    turtleSim();

    repeat(N)
    {
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

        cin >> arg;

        switch (cmd)
        {
        case 'f':
            // update coords
            x += arg * cosine(ang);
            y += arg * sine(ang);

            // check if within bounds
            if ((x >= MIN_X) && (x <= MAX_X) && (y >= MIN_Y) && (y <= MAX_Y))
            {
                // move
                forward(arg);
            }
            else
            {
                cout << "Selected command will drive the turtle out of bounds. "
                     << "Try again." << endl;

                // reset
                x -= arg * cosine(ang);
                y -= arg * sine(ang);
            }
            break;

        case 'r':
            ang += arg;
            right(arg);
            break;

        case 'l':
            ang -= arg;
            left(arg);
            break;

        default:
            cout << "Invalid input, try again." << endl;
            break;
        }
    }
    cout << "Click to exit." << endl;
    getClick();
}