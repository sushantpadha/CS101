#include <iostream>
using namespace std;

/*
number of ways of counting target using some combination of coins (without permutations)
f(<0, coins) = 0
f(0, coins) = 1
f(target, coins) = Σ f(target - c,
coins'), where, coins' = {x in coins and x >= c}
*/
int countComb(int coins[], int n, int target, int start = 0) {
    if (!target)
        return 1;
    int num = 0;
    int coin;
    for (int i = start; i < n; i++) {
        coin = coins[i];
        if (target - coin < 0)
            continue;
        num += countComb(coins, n, target - coin, i);
    }
    return num;
}

// build a DP table where a_i = countComb(i)
int countCombBottomUp(int coins[], int n, int target) {
    int dp[target + 1] = {0};
    dp[0] = 1;

    int m;

    for (int i = 0; i <= target; i++) {
        for (int j = 0; j < n; j++) {
            if ((m = i + coins[j]) <= target)
                dp[m] += 1;
        }
    }
    for (int i = 0; i <= target; i++)
    {
        cout << dp[i] << ' ';
    }
    cout << "; ";
    
    return dp[target];
}

int main() {
    int n;
    cin >> n;  // <= 100
    int coins[100];
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    int target;
    cin >> target;  // <= 1000

    cout << countComb(coins, n, target) << endl;
    cout << countCombBottomUp(coins, n, target) << endl;
}