#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100;
int n, m, cnt = 0, a[N], v[N];
long long dp[N][N], f[N][N], g[N][N];
template<typename T>
void dmax(T& x, const T& y) { if (x < y) x = y; }
int main() {
    freopen("r.in", "r", stdin);
    freopen("r.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) dp[i][i] = v[1];
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len <= n + 1; i++) {
            const int j = i + len - 1;
            for (int k = i; k < j; k++) {
                dmax(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
            for (int k = i; k <= j; k++) {
                ;
            }
        }
    }
    return 0;
}