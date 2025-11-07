#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, x, y, w;
    cin >> n >> m;
    vector<int> f(n + m + 1), d(n + m + 1), val(n + m + 1), ls(n + m + 1), rs(n + m + 1);
    for (int i = 1; i <= n + m; i++) f[i] = i;
    function<int(int)> find = [&](int x) { return f[x] == x ? x : (f[x] = find(f[x])); };
    int tot = n;
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> w;
        ans += w;
        d[x]++, d[y]++;
        x = find(x), y = find(y);
        if (x == y) {
            val[x] = min(val[x], w);
            continue;
        }
        val[++tot] = w;
        f[x] = tot;
        f[y] = tot;
        ls[tot] = x, rs[tot] = y;
    }
    function<void(int)> dfs = [&](int u) {
        d[u] &= 1;
        if (!ls[u]) return;
        val[ls[u]] = min(val[ls[u]], val[u]);
        val[rs[u]] = min(val[rs[u]], val[u]);
        dfs(ls[u]), dfs(rs[u]);
        const int tmp = min(d[ls[u]], d[rs[u]]);
        ans += tmp * val[u];
        d[ls[u]] -= tmp;
        d[rs[u]] -= tmp;
        d[u] += d[ls[u]], d[u] += d[rs[u]];
    };
    dfs(tot);
    cout << ans << '\n';
}

int main() {
    int t;
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while (t--) solve();
    return 0;
}