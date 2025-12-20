#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10, K = 8;
int n, k, a[N][K];
typedef long long ll;
ll dp[2][1 << K][K];
void dmin(ll& x, const ll& y) { if (y < x) x = y; }
int main() {
    freopen("orochi.in", "r", stdin);
    freopen("orochi.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[j][i];
    memset(dp, 0x3f, sizeof dp);
    for (int i = 0; i < k; i++) dp[0][0][i] = 0;
    for (int i = 0; i < n; i++) {
        int cur = i & 1, nxt = cur ^ 1;
        memset(dp[nxt], 0x3f, sizeof dp[nxt]);
        for (int S = 0; S < (1 << k); S++) {
            ll mn = 0x3f3f3f3f3f3f3f3f;
            for (int j = 0; j < k; j++) {
                dmin(mn, dp[cur][S][j]);
                if ((S >> j) & 1) {
                    dmin(dp[nxt][S][j], dp[cur][S][j] + a[i + 1][j]);
                }
            }
            for (int j = 0; j < k; j++) {
                if ((S >> j) & 1) continue;
                dmin(dp[nxt][S | (1 << j)][j], mn + a[i + 1][j]);
            }
        }
    }
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = 0; i < k; i++) dmin(ans, dp[n & 1][(1 << k) - 1][i]);
    cout << ans << endl;
    cerr << (double) clock() / CLOCKS_PER_SEC << endl; 
    return 0;
}