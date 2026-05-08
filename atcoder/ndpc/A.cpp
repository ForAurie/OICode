#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int N = 100;
ll dp[N][3];
int n;
int main() {
    cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] = dp[i - 1][2] + dp[i - 2][0];
        dp[i][2] = dp[i - 1][1] + dp[i - 2][0];
        dp[i][0] += dp[i - 2][0];
    }
    cout << dp[n][0] << endl;
    return 0;
}