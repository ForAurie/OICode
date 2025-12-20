#include <bits/stdc++.h>

using namespace std;
template <typename T>
void dmin(T& x, T y) {
    if (y < x) x = y;
}
template <typename T>
void dmax(T& x, T y) {
    if (x < y) x = y;
}
constexpr int D = 1;
void solve() {
    int n, top = 0;
    cin >> n;
    vector<long long> a(n + D), b(n + D);
    vector<int> ls(n + D), rs(n + D), stk(n + D);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    // rs[0] is root
    for (int i = 1; i <= n; i++) {
        while (top && b[stk[top]] >= b[i]) --top;
        ls[i] = rs[stk[top]], rs[stk[top]] = i;
        stk[++top] = i;
    }
    constexpr int MX = 64;
    vector<vector<long long>> dp(n + D, vector<long long>(MX, 0x3f3f3f3f3f3f3f3f));
    function<void(int)> dfs = [&](int u) -> void {
        if (ls[u]) dfs(ls[u]);
        if (rs[u]) dfs(rs[u]);
        if (ls[u] && rs[u]) {
            dp[u].resize(MX + MX);
            merge(dp[ls[u]].begin(), dp[ls[u]].end(), dp[rs[u]].begin(), dp[rs[u]].end(), dp[u].begin(), greater<long long>());
            dp[u].resize(MX);
            // for (int i = 0; i < MX; i++)
            //     for (int j = 0; i + j < MX; j++)
            //         dmin(dp[u][i + j], max(dp[ls[u]][i], dp[rs[u]][j]));
        } else if (ls[u]) dp[u] = dp[ls[u]];
        else if (rs[u]) dp[u] = dp[rs[u]];
        else dp[u][0] = a[u];
        for (int i = 0; i < MX; i++) dmax(dp[u][i], a[u]);
        for (int i = 0; i + 1 < MX; i++) dmin(dp[u][i + 1], (dp[u][i] + b[u] - 1) / b[u]);
    };
    dfs(rs[0]);
    for (int i = 0; i < MX; i++) {
        if (dp[rs[0]][i] < 2) {
            cout << i << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}