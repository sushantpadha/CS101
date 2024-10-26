#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Leetcode 1143
// ChatGPT explanation https://chatgpt.com/c/67095980-5c48-8003-99ec-d3eae34d3406

// can be done time efficiently with DP

//                              TIME            SPACE
// Brute Force Recursion        O(m^2+n^2)      O(min(m,n)) recursion call stack
//   uses DFS with nested loops
// Divide-n-Conquer Recursion   O(2^(m+n))      O(m + n) recursion call stack
//   uses binary tree divide n conquer
// DP                           O(m*n)          O(m*n) DP table

void LCS_brute_force_recursion(string s1, string s2, int& n, int& mx, int i1 = 0, int i2 = 0) {
    for (int j1 = i1; j1 < s1.length(); j1++) {
        for (int j2 = i2; j2 < s2.length(); j2++) {
            // if a common char is found, ++n and call recursively
            if (s1[j1] == s2[j2]) {
                // cout << s1[j1] << ": j1=" << j1 << ", j2=" << j2 << ", n=" << n << ",
                // mx=" << mx << endl;
                ++n;
                LCS_brute_force_recursion(s1, s2, n, mx, j1 + 1, j2 + 1);
            }
        }
    }
    mx = max(mx, n);
    n = 0;
}

int LCS_DnC_recursion(string s1, string s2, int i1 = 0, int i2 = 0) {
    // Base case: if either string is fully traversed
    if (i1 == s1.length() || i2 == s2.length()) {
        return 0;
    }

    // Case 1: If characters match, include this character in the subsequence
    if (s1[i1] == s2[i2]) {
        return 1 + LCS_DnC_recursion(s1, s2, i1 + 1, i2 + 1);
    }

    // Case 2: If they don't match, explore both possibilities:
    // a) Skip a character in s1 or b) Skip a character in s2
    return max(LCS_DnC_recursion(s1, s2, i1 + 1, i2), LCS_DnC_recursion(s1, s2, i1, i2 + 1));
}

int LCS_DP(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();

    // Create a DP table with (n1+1) rows and (n2+1) columns
    // dp[i][j] = length of LCS upto at s1[i-1] and s2[j-1]
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    // Fill the DP table using the recurrence relation
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s1[i-1] == s2[j-1]) {
                // Characters match, so increment the LCS length
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                // Characters don't match, take the maximum of the two options
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // The bottom-right cell contains the length of the LCS
    return dp[n1][n2];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = 0, mx = 0;
    // LCS(s1, s2, n, mx);
    // cout << mx;
    cout << LCS_DP(s1, s2);
}