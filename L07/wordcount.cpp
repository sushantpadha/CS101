#include <iostream>
using namespace std;

int numWordsRecursive(char s[], int N, int i = 0) {
    int num = 0;

    // dont even consider i = N-1 as valid since that is full stop by definition
    if (i == N - 1)
        return num;

    for (; i < N - 1 && s[i] == ' '; i++) {
        continue;
    }

    for (; i < N - 1 && s[i] != ' '; i++) {
        num = 1;
    }

    num += numWordsRecursive(s, N, i);
    return num;
}

int numWordsIterative(char s[], int N) {
    int num = 0;
    bool word = false;

    for (int i = 0; i < N; i++) {
        if (s[i] == ' ' || s[i] == '.') {
            num += word;
            word = false;
        } else {
            word = true;
        }
    }

    return num;
}

int main() {
    char s[100];
    char c;
    int N;
    cin >> N;
    cin >> noskipws;
    cin >> c;  // read in newline character
    for (int i = 0; i < N; i++) {
        cin >> c;
        s[i] = c;
    }
    cout << numWordsRecursive(s, N) << ' ' << numWordsIterative(s, N);
}
