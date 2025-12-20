#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, cnt = 0, x, y;
    cin >> n >> m;
    vector<vector<int>> G(n + 1);
    vector<int> rd(n + 1), f(n + 1), cd(n + 1);
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        G[x].push_back(y);
        ++rd[y];
        if (x != y) cd[x]++;
    }
    if (n == 1) {
        cout << "Let's play\n" << 0 << '\n';
        return;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) if (rd[i] == 0) q.push(i);
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int v : G[u]) {
            f[v] = max(f[u] + 1, f[v]);
            if (--rd[v] == 0) q.push(v);
        }
    }
    for (int i = 1; i <= n; i++)
        if (rd[i]) ++cnt;
    if (cnt > 1) {
        cout << "Poor cx\n";
        return;
    }
    int mx = 0, cmx = 0;
    for (int i = 1; i <= n; i++) mx = max(mx, f[i]);
    for (int i = 1; i <= n; i++) cmx += (mx == f[i]);
    if (cnt == 1) {
        int tmp = 0;
        for (int i = 1; i <= n; i++) {
            if (rd[i]) continue;
            tmp = max(tmp, f[i]);
        }
        cout << "Let's play\n" << tmp + 1 << '\n';
        return;
    } else if (cmx > 1) {
        cout << "Poor cx\n";
        return;
    }
    cout << "Let's play\n" << mx << '\n';
}

int main() {
    freopen("xcx.in", "r", stdin);
    freopen("xcx.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}