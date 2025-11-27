#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1e5 + 10;
vector<int> G[N];
int d[N], fa[N], ans[N];
vector<int> lis;

void lca(int x, int y) {
    if (d[x] < d[y]) swap(x, y);
    while (d[x] > d[y]) lis.push_back(x), x = fa[x];
    while (x != y) lis.push_back(x), lis.push_back(y), x = fa[x], y = fa[y];
    lis.push_back(x);
}
void dfs(int u) {
    for (int v : G[u]) {
        if (v == fa[u]) continue;
        d[v] = d[u] + 1;
        fa[v] = u;
        dfs(v);
    }
}
void dfs1(int u, int f, int r) {
    ans[u] = r;
    for (int v : G[u]) {
        if (v == f) continue;
        dfs1(v, u, r);
    }
}
int main() {
    freopen("lca.in", "r", stdin);
    freopen("lca.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q, x, y;
    cin >> n >> q >> x >> y;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    d[1] = 1;
    dfs(1);
    lca(x, y);
    for (int i : lis) ans[i] = i;
    for (int i : lis) {
        for (int v : G[i]) {
            if (ans[v] == 0) dfs1(v, i, i);
        }
    }
    while (q--) {
        int u;
        cin >> u;
        cout << ans[u] << "\n";
    }
    return 0;
}