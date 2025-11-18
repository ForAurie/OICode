#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("three.in", "r", stdin);
    freopen("three.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, mod;
    cin >> n >> mod;
    vector<vector<int>> dp(3 * n + 10, vector<int>(6 * n + 10));
    const int D = 3 * n + 5;
    dp[0][D] = 1;
    for (int i = 0; i < 3 * n; i++) {
        for (int j = -i; j <= i; j++) {
            (dp[i + 1][j + 1 + D] += dp[i][j + D]) %= mod;
            (dp[i + 2][j - 1 + D] += dp[i][j + D] * (i + 1ll) % mod) %= mod;
            (dp[i + 3][j + D] += (i + 1ll) * (i + 2ll) % mod * dp[i][j + D] % mod) %= mod;
        }
    }
    int ans = 0;
    for (int i = 0; i <= 3 * n; i++) (ans += dp[3 * n][i + D]) %= mod;
    cout << ans << endl;
    return 0;
}