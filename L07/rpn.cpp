#include <iostream>
using namespace std;


int main() {
    int m;
    cin >> m;
    char c;
    int arr[1024];
    int k = 0;

    double result;
    bool first = true;

    for (int i = 0; i < m; i++) {
        cin >> c;
        if (c >= '0' && c <= '9')
            arr[k++] = c - '0';
        else {
            if (--k < 0) {
                cout << "Invalid"; return 1;
            }
            int a = arr[k];
            
            // for first instance of operator set result to penultimate int
            if (first) {
                if (--k < 0) {
                    cout << "Invalid"; return 1;
                }
                result = arr[k];
                first = false;
            }

            if (c == '+')
                result += a;
            else if (c == '-')
                result = a - result;
            else if (c == '*')
                result *= a;
            else if (c == '/') {
                if (!a) {cout << "Invalid division by 0"; return 1;}
                result /= a;
            }
        }
    }

    cout << result;
}