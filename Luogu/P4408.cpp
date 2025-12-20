<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
constexpr long long INF = 0x3f3f3f3f3f3f3f3f;
constexpr int N = 2e5 + 10;
pair<long long, int> dp[N];
int d[N], fa[N], lb[N], hd[N], nxt[N << 1], ed[N << 1], val[N << 1], idx;
void add(int x, int y, int v) {
    ed[++idx] = y;
    nxt[idx] = hd[x];
    hd[x] = idx;
    val[idx] = v;
}
long long c[N];
void dfs(int u) {
    int p = lb[fa[u]], q = lb[p];
    lb[u] = lb[q] - lb[p] == lb[p] - lb[fa[u]] ? q : fa[u];
    dp[u] = make_pair(0, u);
    for (int i = hd[u]; i; i = nxt[i]) {
        int v = ed[i];
        if (v == fa[u]) continue;
        d[v] = d[u] + 1;
        c[v] = c[u] + val[i];
        fa[v] = u;
        dfs(v);
        dp[u] = max(dp[u], make_pair(dp[v].first + val[i], dp[v].second));
    }
}
int lca(int x, int y) {
    if (d[x] < d[y]) swap(x, y);
    while (d[x] > d[y]) {
        if (d[lb[x]] >= d[y]) x = lb[x];
        else x = fa[x];
    }
    while (x != y) {
        if (lb[x] != lb[y]) x = lb[x], y = lb[y];
        else x = fa[x], y = fa[y];
    }
    return x;
}
void dfs1(int u, int fa) {
    dp[u] = make_pair(0, u);
    for (int i = hd[u]; i; i = nxt[i]) {
        int v = ed[i];
        if (v == fa) continue;
        dfs1(v, u);
        dp[u] = max(dp[u], make_pair(dp[v].first + val[i], dp[v].second));
    }
}
long long len(int x, int y) {
    return c[x] + c[y] - 2 * c[lca(x, y)];
}
int main() {
    int n, m;
    cin >> n >> m;
    int x, y, v;
    for (int i = 1; i < n; i++) {
        cin >> x >> y >> v;
        add(x, y, v), add(y, x, v);
    }
    d[1] = 1;
    dfs(1);
    dfs1(x = dp[1].second, 0);
    y = dp[x].second;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (x == i || y == i) continue;
        long long t1 = len(i, y), t2 = len(i, x);
        ans = max(ans, min(t1, t2));
    }
    cout << ans + len(x, y) << endl;
    return 0;
=======
#include <bits/stdc++.h>
using namespace std;
constexpr long long INF = 0x3f3f3f3f3f3f3f3f;
constexpr int N = 2e5 + 10;
pair<long long, int> dp[N];
int d[N], fa[N], lb[N], hd[N], nxt[N << 1], ed[N << 1], val[N << 1], idx;
void add(int x, int y, int v) {
    ed[++idx] = y;
    nxt[idx] = hd[x];
    hd[x] = idx;
    val[idx] = v;
}
long long c[N];
void dfs(int u) {
    int p = lb[fa[u]], q = lb[p];
    lb[u] = lb[q] - lb[p] == lb[p] - lb[fa[u]] ? q : fa[u];
    dp[u] = make_pair(0, u);
    for (int i = hd[u]; i; i = nxt[i]) {
        int v = ed[i];
        if (v == fa[u]) continue;
        d[v] = d[u] + 1;
        c[v] = c[u] + val[i];
        fa[v] = u;
        dfs(v);
        dp[u] = max(dp[u], make_pair(dp[v].first + val[i], dp[v].second));
    }
}
int lca(int x, int y) {
    if (d[x] < d[y]) swap(x, y);
    while (d[x] > d[y]) {
        if (d[lb[x]] >= d[y]) x = lb[x];
        else x = fa[x];
    }
    while (x != y) {
        if (lb[x] != lb[y]) x = lb[x], y = lb[y];
        else x = fa[x], y = fa[y];
    }
    return x;
}
void dfs1(int u, int fa) {
    dp[u] = make_pair(0, u);
    for (int i = hd[u]; i; i = nxt[i]) {
        int v = ed[i];
        if (v == fa) continue;
        dfs1(v, u);
        dp[u] = max(dp[u], make_pair(dp[v].first + val[i], dp[v].second));
    }
}
long long len(int x, int y) {
    return c[x] + c[y] - 2 * c[lca(x, y)];
}
int main() {
    int n, m;
    cin >> n >> m;
    int x, y, v;
    for (int i = 1; i < n; i++) {
        cin >> x >> y >> v;
        add(x, y, v), add(y, x, v);
    }
    d[1] = 1;
    dfs(1);
    dfs1(x = dp[1].second, 0);
    y = dp[x].second;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (x == i || y == i) continue;
        long long t1 = len(i, y), t2 = len(i, x);
        ans = max(ans, min(t1, t2));
    }
    cout << ans + len(x, y) << endl;
    return 0;
>>>>>>> origin/main
}