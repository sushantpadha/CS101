#include <iostream>
using namespace std;

/*
> Solution using one for loop
> Do I get extra marks for this???
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣀⣀⣀⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣤⣴⣶⣾⣿⢿⠿⠿⠿⠿⠿⡿⠿⣿⣶⣶⣤⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣾⣿⠿⠛⠉⠉⢀⣠⣾⡆⠀⠀⠀⠀⣿⣦⠀⠈⠉⠙⠻⢿⣿⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠀⣠⣴⣿⡿⠟⠉⠀⠀⠀⠀⣶⠿⠟⠉⠀⠀⠀⠀⠀⠙⢿⣿⠀⠀⠀⠀⠀⠈⠻⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⣠⣾⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⣿⣷⡄⠀⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⠀⣴⣿⡿⠉⠀⠀⠀⠀⠀⣀⣤⣤⣤⣤⣀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣤⣤⣦⣤⣄⡀⠀⠀⠀⠀⠙⣿⣿⣆⠀⠀⠀⠀⠀
    ⠀⠀⠀⠀⣸⣿⠟⠀⠀⠀⠀⣠⣶⣿⣿⠿⠛⠛⣿⣿⣷⡀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣄⠀⠀⠈⢿⣿⣆⠀⠀⠀⠀
    ⠀⠀⠀⢰⣿⡏⠀⠀⠀⣠⣾⣿⣿⣿⣿⣂⣤⡼⠿⢿⣿⣷⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⠋⠉⢻⣿⣿⣷⣄⠀⠈⢿⣿⡄⠀⠀⠀
    ⠀⠀⠀⣿⡿⠀⠀⠀⣰⣿⣿⠟⠛⠛⠛⠛⠁⠀⠀⠀⢸⣿⠀⠀⢸⣿⣿⣿⠁⠀⠈⠹⣿⣤⣦⣸⣿⣿⡟⣿⣦⠀⠘⣿⣷⠀⠀⠀
    ⠀⠀⢸⣿⠇⠀⠀⢰⣿⠙⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⠀⠀⣿⣿⣿⣷⠀⠀⠀⠀⠉⠉⠁⠈⢹⣿⡇⠈⢿⣇⠀⢹⣿⡄⠀⠀
    ⠀⠀⢸⣿⠀⠀⠀⣼⡇⠀⣿⣦⣀⠀⠀⠀⠀⠀⢀⣼⣿⣿⠀⠀⣿⣿⣿⣿⣦⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠘⣿⠀⠘⣿⡇⠀⠀
    ⠀⠀⢸⣿⠀⠀⠸⣿⡇⠀⠘⢿⣿⣟⠛⢳⣶⣾⣿⣿⣿⡏⠀⠀⢻⣿⣿⠿⠻⣷⡄⠀⠀⣀⣠⣴⣿⠟⠀⠀⢀⣿⠀⠀⣿⡇⠀⠀
    ⠀⠀⢸⣿⡀⠀⠀⢹⣿⡀⠀⠀⠉⠛⠿⠿⠿⠿⢟⣿⣿⠁⠀⠀⠘⣿⣿⣷⣦⣿⣿⣿⣿⣿⡿⠛⠁⠀⠀⣠⣾⡿⠀⢀⣿⡇⠀⠀
    ⠀⠀⠈⣿⣇⠀⠀⠈⢿⣿⣤⣄⣀⣀⣀⣀⣠⣶⣿⠟⠁⠀⠀⠀⠀⠈⠻⣿⣦⣍⣉⠉⠉⠀⢀⣀⣠⣴⣾⣿⠟⠁⠀⣸⣿⠃⠀⠀
    ⠀⠀⠀⢻⣿⡄⠀⠀⣰⣾⣿⣿⣿⡛⠛⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⠛⠛⠻⠛⢻⣿⣿⣯⣭⡀⠀⠀⢠⣿⡟⠀⠀⠀
    ⠀⠀⠀⠀⢿⣿⣄⣰⣿⡟⠉⠻⣿⣷⠀⠀⠀⠀⠀⠀⣀⣠⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⡿⠋⠙⢿⣿⣧⣤⣿⡿⠁⠀⠀⠀
    ⠀⠀⠀⠀⢀⣿⣿⡿⠋⠀⠀⢀⣿⡟⠀⠀⠀⠀⠀⠸⠿⠛⠻⣿⣷⡄⠀⠀⠀⠀⠀⠀⠀⢸⣿⣧⠀⠀⠀⠙⢿⣿⣿⠁⠀⠀⠀⠀
    ⠀⠀⣠⣾⣿⠟⠋⠀⠀⠀⣠⣾⡿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠃⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣷⣄⠀⠀⠀⠹⣿⣷⣄⠀⠀⠀
    ⢀⣾⣿⠟⠁⠀⠀⠀⣶⣴⣿⣿⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣀⣠⣤⣤⣤⣤⣼⣿⡿⠀⠀⠀⠀⠈⠻⣿⣷⡀⠀
    ⣼⣿⠃⠀⠀⠀⠀⠀⠈⠉⠙⠛⠛⠻⠿⠿⠿⣷⣶⣶⣦⣶⣶⡿⠿⠿⠟⠛⠛⠛⠉⠉⠉⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠘⣿⣷⠀
    ⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇
    ⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣷⣶⣦⣤⣤⣀⣀⣀⣼⣿⣿⣦⣤⣠⣤⣤⣤⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇
    ⣿⣿⡀⠀⠀⠀⠀⠀⠀⢀⣤⣄⡀⠉⢻⣿⡏⠉⠙⠛⠉⠉⠉⠉⠉⠉⠉⠉⠉⢻⣿⣶⣦⣤⣶⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇
    ⠘⣿⣿⣆⠀⠀⠀⠀⠀⠈⠛⠛⠿⠿⢶⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣦⡀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⡏
    ⠀⠈⠻⣿⣷⣄⡀⠀⠀⢿⣶⣤⣄⣀⣾⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣿⣷⣶⣤⣶⣆⠀⠀⠀⠀⢀⣠⣶⣿⡿⠋⠀
    ⠀⠀⠀⠈⠙⠿⢿⣷⣶⣤⣽⣿⣿⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠿⣿⣯⣤⣤⣤⣶⣿⡿⠟⠋⠁⠀⠀⠀
    ⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠙⠋⠉⠉⠀⠀⠀⠀⠀⠀⠀
*/

// #define __DBG_ENABLED

#ifdef __DBG_ENABLED
#define dbg(x) cout << #x << "=" << x << " "
#define nl cout << '\n'
#undef __DBG_ENABLED
#else
#define dbg(x)
#define nl
#endif

int main() {
    int n, sum = 0;
    int A[100];
    int pSums[100];  // a_i = A_0 + ... + A_{i-1} (i > 0)
    int tSums[100];  // a_i = pSums_i-1 + pSums_i (i > 0)
    cin >> n;

    int j = 0;

    pSums[0] = tSums[0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
        sum += A[i];
        pSums[i + 1] = sum;
        tSums[i + 1] = pSums[i + 1] + pSums[i];

        dbg(pSums[i + 1]);
        dbg(tSums[i + 1]);
        dbg(tSums[j + 1]);

        while (tSums[j + 1] < sum && j < i)
            j++;

        dbg(j);
        nl;
    }

    // Uncomment the lines 6-12 below this for aghastly two-for loop code to work
    // And comment next 4 lines
    if (tSums[j + 1] == sum) {
        cout << (j);
        return 0;
    }

    // i = 1 ... n-2
    // for (int i = 1; i < n - 1; i++) {
    //     if (sum == pSums[i] + pSums[i + 1]) {
    //         cout << i;
    //         return 0;
    //     }
    // }

    cout << -1;
}