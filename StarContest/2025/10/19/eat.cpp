#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 998244353, N = 2e3 + 10;
typedef long long ll;
int n, dp[N][N << 1], pre[N * 3];
ll fp(ll x, int n) {
    ll r = 1;
    while (n) {
        if (n & 1) (r *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return r;
}
ll frac(int a, int b) { return (ll) a * pre[b] % mod; }
int main() {
    // freopen("eat3.in", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n * 2; i++) dp[0][i] = 0;
    for (int i = 1; i <= n * 3 + 3; i++) pre[i] = fp(i, mod - 2);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n * 2; j++) {
            if (j) (dp[i][j] += dp[i][j - 1] * frac(j, i + j) % mod) %= mod;
            (dp[i][j] += dp[i - 1][j + 2] * frac(i, i + j) % mod + 1) %= mod;
        }
    }
    cout << dp[n][0] << endl;
    return 0;
}