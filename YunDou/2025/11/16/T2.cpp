#include <bits/stdc++.h>
constexpr int mod = 1e9 + 7;
using namespace std;
typedef long long ll;
constexpr int N = 310;
int dp[2][N][N];
void solve() {
    int n, l, r;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> l >> r;
        const int cur = i & 1, pre = cur ^ 1;
        memset(dp[cur], 0, sizeof(dp[cur]));
        for (int son = l; son <= r; son++) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= n; k++) {
                    if (son == 0) {
                        (dp[cur][j + 1][k] += dp[pre][j][k]) %= mod; // fa 往后
                        if (k) (dp[cur][j][k - 1] += (ll) k * dp[pre][j][k] % mod) %= mod; // fa 往前
                    } else if (son == 1) {
                        (dp[cur][j][k] += 2ll * k * dp[pre][j][k] % mod) %= mod; // fa 往前
                        (dp[cur][j + 1][k + 1] += 2 * dp[pre][j][k] % mod) %= mod; // fa 往后
                    } else if (son == 2) {
                        (dp[cur][j][k + 1] += (ll) k * dp[pre][j][k] % mod) %= mod; // son 全往后，fa 往前
                        (dp[cur][j + 1][k + 2] += dp[pre][j][k] % mod) %= mod; // son 全往后，fa 往后
                        (dp[cur][j][k + 1] += 2ll * j * dp[pre][j][k] % mod) %= mod; // son 一前一后，fa 往后
                        if (j) (dp[cur][j - 1][k] += 2ll * k * (j - 1ll) % mod * dp[pre][j][k] % mod) %= mod; // son 一前一后，fa 往前
                    }
                }
            }
        }
    }
    cout << dp[n & 1][1][0] << "\n";
}

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tid, t;
    cin >> tid >> t;
    while (t--) solve();
}
