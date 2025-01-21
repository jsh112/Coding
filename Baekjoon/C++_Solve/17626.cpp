#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, n);
    dp[0] = 0;

    vector<int> squares;
    for (int i = 1; i * i <= n; i++) {
        squares.push_back(i * i);
    }

    for (int i = 1; i <= n; i++) {
        for (int square : squares) {
            if (i < square)
                break;
            dp[i] = min(dp[i], dp[i - square] + 1);
        }
    }

    cout << dp[n];

    int remaining = n;
    while (remaining > 0) {
        for (int square : squares) {
            if (remaining >= square && dp[remaining] == dp[remaining - square] + 1) {
                cout << square << " ";
                remaining -= square;
                break;
            }
        }
    }
    return 0;
}
