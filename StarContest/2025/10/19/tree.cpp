#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e5 + 10;
int n, x, y, hd[N], nxt[N << 1], ed[N << 1], idx, dp[N][3];
void add(int x, int y) {
    ed[++idx] = y;
    nxt[idx] = hd[x];
    hd[x] = idx;
}
vector<pair<int, int>> tmp;
inline void push(int v, int u) {
    dp[u][2] = max(dp[u][2], dp[u][1] + dp[v][1]);
    dp[u][1] = max(dp[u][1], dp[v][1] + 1);
    dp[u][0] = max({dp[u][0], dp[v][0], dp[u][1], dp[u][2]});
}
void dfs(int u, int fa) {
    dp[u][0] = dp[u][1] = dp[u][2] = 1;
    for (int i = hd[u]; i; i = nxt[i]) {
        int v = ed[i];
        if (v == fa) continue;
        push(v, u);
    }
}
void dfs(int u, int fa) {
    ;
}
int main() {
    cin >> n;
    for (int i = 1; i < n; i++) cin >> x >> y, add(x, y), add(y, x);
    dfs(1, 1); 
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

    return 0;
}