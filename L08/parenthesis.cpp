#include <iostream>
#include <string>
using namespace std;

// Leetcode 22: https://leetcode.com/problems/generate-parentheses/
// ChatGPT explanation: https://chatgpt.com/c/67095980-5c48-8003-99ec-d3eae34d3406

void generateParentheses(int open, int close, string s) {
    // handle base case
    if (open == 0 && close == 0) {
        cout << s << '\n';
        return;
    }

    // if opening '(' brackets can be added
    // add more nested brackets first
    if (open > 0) {
        generateParentheses(open - 1, close, s + "(");
    }

    // if closing ')' brackets can be added
    if (close > open) {
        generateParentheses(open, close - 1, s + ")");
    }
}

int main() {
    int n;
    cin >> n;
    generateParentheses(n, n, "");
}
