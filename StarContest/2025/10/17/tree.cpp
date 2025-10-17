#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 10;
typedef long long ll;
int c[N], n, hd[N], nxt[N << 1], ed[N << 1], idx, cnt[N], sz[N], rt[N];
ll ans;
void add(int x, int y) {
    ed[++idx] = y;
    nxt[idx] = hd[x];
    hd[x] = idx;
}
stack<int> mk[N];
void dfs(int u, int fa) {
    sz[u] = 1;
    for (int i = hd[u]; i; i = nxt[i]) {
        int v = ed[i];
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
    cnt[u] = sz[u];
}
void dfs1(int u, int fa) {
    if (mk[c[u]].top() != 1) {
        cnt[mk[c[u]].top()] -= sz[u];
    } else rt[c[u]] -= sz[u];
    for (int i = hd[u]; i; i = nxt[i]) {
        int v = ed[i];
        if (v == fa) continue;
        mk[c[u]].push(v);
        dfs1(v, u);
        mk[c[u]].pop();
    }
}
int main() {
    cin >> n;
    ans = n;
    ans *= (n - 1);
    ans >>= 1;
    ans *= n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    int x, y;
    for (int i = 1; i < n; i++) cin >> x >> y, add(x, y), add(y, x);
    dfs(1, 1);
    for (int i = 0; i <= n; i++) mk[i].push(1), rt[i] = n;
    dfs1(1, 1);
    for (int i = 2; i <= n; i++)
        ans -= cnt[i] * (cnt[i] - 1ll) / 2;
    for (int i = 0; i <= n; i++)
        ans -= rt[i] * (rt[i] - 1ll) / 2;
    cout << ans << endl;
    return 0;
}
