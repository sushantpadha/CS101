#include <iostream>
using namespace std;

struct Time { int Hours, Minutes; };

Time fixTime(Time t) {
    Time t1;
    if (t.Minutes < 0) {
        t.Hours -= 1;
        t.Minutes += 60;
    }
    t1.Hours = t.Hours + t.Minutes / 60;
    t1.Minutes = t.Minutes % 60;
    return t1;
}

Time addTime(Time t1, Time t2) {
    return fixTime({t1.Hours + t2.Hours, t1.Minutes + t2.Minutes});
}

Time subTime(Time t1, Time t2) {
    return fixTime({t1.Hours - t2.Hours, t1.Minutes - t2.Minutes});
}

void addMinutes(Time& t, int m) {
    t.Minutes += m;
    t = fixTime(t);
}

void subtractMinutes(Time& t, int m) {
    t.Minutes -= m;
    t = fixTime(t);
}

void printTime(Time t) {
    cout << t.Hours << " " << t.Minutes << endl;
}

int main() {
    char cmd;
    int a, b, c, d;
    cin >> cmd;
    if (cmd == 'A') {
        cin >> a >> b >> c >> d;
        printTime(addTime({a, b}, {c, d}));
    }
    else if (cmd == 'S') {
        cin >> a >> b >> c >> d;
        printTime(subTime({a, b}, {c, d}));
    }
    else if (cmd == 'X') {
        cin >> a >> b >> c;
        Time t = {a, b};
        addMinutes(t, c);
        printTime(t);
    }
    else if (cmd == 'Y') {
        cin >> a >> b >> c;
        Time t = {a, b};
        subtractMinutes(t, c);
        printTime(t);
    }
}
