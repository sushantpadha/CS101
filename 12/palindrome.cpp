#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
int main() {
    int Nmax = 100;
    char text[Nmax], tmp;
    cout << "Number of characters: ";
    int n;
    cin >> n;
    if (n > 2 * Nmax + 1) {
        cerr << "Text too long!" << endl;
        return -1;
    }
    cout << "Enter text to check for being a palindrome (whitespace will be ignored): ";

    // read the first half
    for (int i = 0; i < n / 2; i++) cin >> text[i];

    // if n is odd, ignore the middle character
    if (n % 2)
        cin >> tmp;

    // check if the second half matches the first half
    for (int i = n / 2 - 1; i >= 0; i--) {
        if (cin >> tmp, tmp != text[i]) {
            cout << "Not a palindrome!" << endl;
            return 1;
        }
    }
    cout << "Palindrome!" << endl;
}
