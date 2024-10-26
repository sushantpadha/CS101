#include<iostream>
#include<string>
using namespace std;

void patternMatching(string s, string words[], int n) {
    //
}

int main() {
    string s;
    int n;
    string words[100];
    cin >> s >> n;

    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }

    patternMatching(s, words, n);
}