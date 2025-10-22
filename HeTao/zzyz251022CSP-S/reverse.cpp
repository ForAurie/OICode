#include <bits/stdc++.h>

using namespace std;
constexpr int N = 5e2 + 10, mod = 1e9 + 7;
int dp[N][N], n, k, pre[N][N], a[N], b[N];
int main() {
    freopen("reverse.in", "r", stdin);
    freopen("reverse.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            reverse(a + i, a + j + 1);
            for (int k = i; k <= j; k++) pre[i][j] += (a[k] == b[k]);
            reverse(a + i, a + j + 1);
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (j) dp[i][j] = dp[i - 1][j - 1];
            for (int k = 1; k <= i; k++) {
                if (j - pre[k][i] >= 0) (dp[i][j] += dp[k - 1][j - pre[k][i]]) %= mod;
            }
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}