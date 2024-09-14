#include <iostream>
using std::cout, std::cin, std::max, std::noskipws;

const char FILL_CHAR = '#';

int main() {
    cout << "Enter some text (press enter to stop): ";
    cin >> noskipws;

    char c;

    int vowelCounts[5] = {0, 0, 0, 0, 0};

    while (cin >> c, c != '\n') {
        if (c == 'a')
            ++vowelCounts[0];
        else if (c == 'e')
            ++vowelCounts[1];
        else if (c == 'i')
            ++vowelCounts[2];
        else if (c == 'o')
            ++vowelCounts[3];
        else if (c == 'u')
            ++vowelCounts[4];
    }

    cout << "\nVowel counts:\na\te\ti\to\tu\n";
    cout << vowelCounts[0] << '\t' << vowelCounts[1] << '\t' << vowelCounts[2] << '\t'
         << vowelCounts[3] << '\t' << vowelCounts[4] << '\n';

    int maxCount = 0;
    for (size_t i = 0; i < 5; i++) maxCount = max(maxCount, vowelCounts[i]);

    for (size_t i = 0; i < maxCount; i++) {
        for (size_t vi = 0; vi < 5; vi++) {
            if (vowelCounts[vi]) {
                cout << FILL_CHAR << "\t";
                --vowelCounts[vi];
            }
            else {
                cout << " \t";
            }
        }
        cout << '\n';
    }
}
