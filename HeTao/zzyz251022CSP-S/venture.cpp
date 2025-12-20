#include <bits/stdc++.h>

using namespace std;
constexpr int N = 2e3 + 10;
int n, v[N], c[N], m;
long long dp[N];
template<typename T>
void dmin(T& x, const T& y) { if (y < x) x = y; }
int main() {
    freopen("venture.in", "r", stdin);
    freopen("venture.out", "w", stdout);
    memset(dp, 0x3f, sizeof dp);
    const auto INF = dp[0];
    dp[0] = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> c[i];
        for (int k = 0; k <= __lg(m); k++) {
            for (int j = 0; j < m; j++)
                dmin(dp[j], dp[((j - v[i] * (1ll << k)) % m + m) % m] + c[i] * (1ll << k));
        }
    }
    for (int i = 0; i < m; i++) cout << (dp[i] >= INF ? -1 : dp[i]) << ' ';
    return 0;
}