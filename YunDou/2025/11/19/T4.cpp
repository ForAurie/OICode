#include <bits/stdc++.h>
using namespace std;
constexpr int N = 410;
int n, a[N], v[N];
long long dp[N][N], f[N][N], g[N][N];
template<typename T>
void dmax(T& x, const T& y) { if (x < y) x = y; }
int main() {
    freopen("good.in", "r", stdin);
    freopen("good.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(dp, -0x3f, sizeof dp);
    memset(f, -0x3f, sizeof f);
    memset(g, -0x3f, sizeof g);
    for (int i = 1; i <= n; i++) dp[i][i] = v[1], f[i][i] = g[i][i] = dp[i][i - 1] = 0;
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len <= n + 1; i++) {
            const int j = i + len - 1;
            for (int k = i; k < j; k++) {
                if (a[k] + 1 == a[j]) dmax(f[i][j], f[i][k] + dp[k + 1][j - 1]);
                if (a[k + 1] + 1 == a[i]) dmax(g[i][j], g[k + 1][j] + dp[i + 1][k]);
                dmax(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
            for (int k = i; k <= j; k++) {
                if (a[k] >= a[i] && a[k] >= a[j]) dmax(dp[i][j], f[i][k] + g[k][j] + v[a[k] - a[i] + a[k] - a[j] + 1]);
            }
        }
    }
    for (int i = 1; i <= n; i++) dmax(dp[i][i], 0ll);
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len <= n + 1; i++) {
            const int j = i + len - 1;
            if (i + 1 <= j - 1) dmax(dp[i][j], dp[i + 1][j - 1]);
            dmax(dp[i][j], dp[i][j - 1]);
            dmax(dp[i][j], dp[i + 1][j]);
            for (int k = i; k < j; k++) {
                dmax(dp[i][j], dp[i][k] + dp[k + 1][j]);
                dmax(dp[i][j], dp[k + 1][j] + dp[i][k]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}