#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> es(n + 1);
    vector<int> rd(n + 1), dp(n + 1);
    for (int i = 1; i <= m; i++) {
        static int x, y;
        cin >> x >> y;
        es[x].push_back(y);
    }
    queue<int> q;
    q.push(1);
    vector<bool> mk(n + 1);
    while (q.size()) {
        int u = q.front(); q.pop();
        if (mk[u]) continue;
        mk[u] = true;
        for (int v : es[u])
            q.push(v);
    }
    for (int u = 1; u <= n; u++) {
        if (mk[u]) {
            for (int v : es[u]) {
                rd[v]++;
            }
        }
    }
    while (q.size()) q.pop();
    q.push(1);
    dp[1] = 1;
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int v : es[u]) {
            if (--rd[v] == 0) q.push(v);
            (dp[v] += dp[u]) %= 998244353;
        }
    }
    cout << dp[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}