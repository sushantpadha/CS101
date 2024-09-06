#include <iostream>
using namespace std;

int sqdistance(int x1, int x2, int y1, int y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main() {
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    bool b = (y2 - y1)*(x3- x2) == (y3 - y2)*(x2 - x1);
    b = b || ((y3 - y2)*(x4- x3) == (y4 - y3)*(x3 - x2));
    b = b || ((y4 - y3)*(x1- x4) == (y1 - y4)*(x4 - x3));
    b = b || ((y1 - y4)*(x2- x1) == (y2 - y1)*(x1 - x4));

    // if any 3 collinear
    if (b) {
        cout << "Not a Quadrilateral" << endl;
        return 0;
    }

    // if diagonals equal and diagonal midpoints coincide then rectangle
    int d1 = sqdistance(x1,x3,y1,y3);
    int d2 = sqdistance(x2,x4,y2,y4);
    if((d1 == d2) && (x1 + x3 == x2 + x4) && (y1 + y3 == y2 + y4)) {
        int a1 = sqdistance(x1,x2,y1,y2);
        int a2 = sqdistance(x2,x3,y2,y3);
        int a3 = sqdistance(x3,x4,y3,y4);
        int a4 = sqdistance(x4,x1,y4,y1);

        // only 1 required but writing 3 conditions for clarity
        if ((a1 == a2) && (a2 == a3) && (a3 == a4)) {
            cout << "Square" << endl; return 0;
        }
        cout << "Rectangle" << endl; return 0;
    }

    cout << "Other" << endl; return 0;
}