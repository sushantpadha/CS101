#include <simplecpp>

int main() {
    float D, T, S;
    cin >> D >> T;
    while (true) {
        cin >> S;
        if (abs(D - S) > T) {
            cout << "false" << endl;
            return false;
        }
        cout << "true" << endl;
    }
}