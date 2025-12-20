#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e5 + 10, M = N * 2;
int hd_[N], nxt_[M << 1], ed_[M << 1], idx_, n, m, a[N];
void add_(int x, int y) {
    ed_[++idx_] = y;
    nxt_[idx_] = hd_[x];
    hd_[x] = idx_;
}

int dfn[N], low[N], col[N], timer, cols;
long long val[N];
stack<int> s;

void paint() {
    val[cols] += a[s.top()];
    col[s.top()] = cols;
    s.pop();
}

void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++timer;
    s.push(u);
    for (int i = hd_[u]; i; i = nxt_[i]) {
        int v = ed_[i];
        if (fa == v) continue;
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        ++cols;
        while (s.top() != u) paint();
        paint();
    }
}
int hd[N], nxt[N << 1], ed[N << 1], idx;
void add(int x, int y) {
    ed[++idx] = y;
    nxt[idx] = hd[x];
    hd[x] = idx;
}

long long mx[N]; // sec[N];

void dfs(int u, int fa) {
    int cnt = 0;
    for (int i = hd[u]; i; i = nxt[i]) {
        int v = ed[i];
        if (v == fa) continue;
        cnt++;
        dfs(v, u);
        mx[u] = max(mx[u], mx[v]);
        // if (mx[v] >= mx[u]) sec[u] = mx[u], mx[u] = mx[v];
        // else if (mx[v] > sec[u]) sec[u] = mx[v];

        // if (sec[v] >= mx[u]) sec[u] = mx[u], mx[u] = sec[v];
        // else if (mx[v] > sec[u]) sec[u] = sec[v];
    }
    mx[u] += val[u];
    // if (!cnt) mx[u] = val[u], sec[u] = -0x3f3f3f3f3f3f3f3f;
    // else mx[u] += val[u], sec[u] += val[u];
}

int main() {
    freopen("play2.in", "r", stdin);
    freopen("play.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int x, y;
    for (int i = 1; i <= m; i++) cin >> x >> y, add_(x, y), add_(y, x);
    for (int i = 1; i <= n; i++) {
        if (dfn[i]) continue;
        tarjan(i, i);
    }
    for (int u = 1; u <= n; u++) {
        for (int i = hd_[u]; i; i = nxt_[i]) {
            int v = ed_[i];
            if (col[u] != col[v]) add(col[u], col[v]);
        }
    }
    dfs(col[1], col[1]);
    long long fir = 0, sec = 0;
    for (int i = hd[col[1]]; i; i = nxt[i]) {
        int v = ed[i];
        if (mx[v] >= fir) sec = fir, fir = mx[v];
        else if (mx[v] > sec) sec = mx[v];
    }
    // dfs(col[1], col[1]);
    cout << fir + sec + val[col[1]] << endl;
    return 0;
}