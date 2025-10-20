#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x, y;
    cin >> n;
    vector<bool> dis(n + 1);
    vector<vector<int>> G(n + 1), leaf(2);
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    vector<int> fa(n + 1);
    function<void(int)> dfs = [&](int u) {
        for (int v : G[u]) {
            if (v == fa[u]) continue;
            dis[v] = dis[u] ^ 1;
            fa[v] = u;
            dfs(v);
        }
    };
    dfs(1);
    int now = n;
    vector<bool> mk(n + 1), vis(n + 1);
    vector<int> tmp;
    while (now) {
        mk[now] = 1;
        tmp.push_back(now);
        now = fa[now];
    }
    now = 0;
    for (int i = 1; i <= n; i++) {
        if (mk[i]) continue;
        if (G[i].size() <= 1) leaf[dis[i]].push_back(i), vis[i] = 1;
    }
    vector<int> ans;
    while (leaf[0].size() || leaf[1].size()) {
        // for (auto i : leaf[0]) cout << ":" << i;
        // cout << '\n';
        // for (auto i : leaf[1]) cout << ":" << i;
        // cout << "\n\n";
        ans.push_back(0);
        now ^= 1;
        if (leaf[0].size()) {
            if (now == 0) ans.push_back(0), now ^= 1;
            ans.push_back(leaf[0].back());
            for (int v : G[leaf[0].back()]) {
                if (mk[v] || vis[v]) continue;
                leaf[dis[v]].push_back(v), vis[v] = 1;
            }
            leaf[0].pop_back();
        } else {
            if (now == 1) ans.push_back(0), now ^= 1;
            ans.push_back(leaf[1].back());
            for (int v : G[leaf[1].back()]) {
                if (mk[v] || vis[v]) continue;
                leaf[dis[v]].push_back(v), vis[v] = 1;
            }
            leaf[1].pop_back();
        }
    }
    reverse(tmp.begin(), tmp.end());
    while (tmp.back() != 1) {
        ans.push_back(0); now ^= 1;
        if ((dis[tmp.back() & 1]) == now) ans.push_back(0), now ^= 1;
        ans.push_back(tmp.back());
        tmp.pop_back();
    }
    cout << ans.size() << '\n';
    for (auto i : ans) {
        if (i) cout << "2 " << i << '\n';
        else cout << "1\n";
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}