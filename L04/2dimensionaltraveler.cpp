#include <simplecpp>

int updatePositionY(int y, char d, int s) {
    return ((d == 'N') ? (y + s) : ((d == 'S') ? (y - s) : (y)));
}

int updatePositionX(int x, char d, int s) {
    return ((d == 'E') ? (x + s) : ((d == 'W') ? (x - s) : (x)));
}

main_program {
    int x, y;
    cin >> x >> y;
    char d;
    int s, prevx, prevy;

    cout << x << " " << y << endl;

    while (true) {
        cin >> d >> s;
        prevx = x;
        prevy = y;
        x = updatePositionX(x, d, s);
        y = updatePositionY(y, d, s);

        if (x > 0 && y > 0 && prevx * prevy < 0)
            cout << "Quadrant changed to 1" << endl;
        else if (x < 0 && y > 0 && prevx * prevy > 0)
            cout << "Quadrant changed to 2" << endl;
        else if (x < 0 && y < 0 && prevx * prevy < 0)
            cout << "Quadrant changed to 3" << endl;
        else if (x > 0 && y < 0 && prevx * prevy > 0)
            cout << "Quadrant changed to 4" << endl;

        cout << x << " " << y << endl;

        if (x == 0 && y == 0) {
            cout << "Home" << endl;
            break;
        }
    }
}
