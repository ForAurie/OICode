    #include <bits/stdc++.h>

    using namespace std;

    void solve() {
        int n, x, y;
        cin >> n;
        vector<bool> dis(n + 1);
        vector<vector<int>> G(n + 1);
        array<stack<int>, 2> leaf;
        vector<int> d(n + 1);
        for (int i = 1; i < n; i++) {
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
            ++d[x], ++d[y];
        }
        function<void(int, int)> dfs = [&](int u, int fa) {
            for (int v : G[u]) {
                if (v == fa) continue;
                dis[v] = dis[u] ^ 1;
                dfs(v, u);
            }
        };
        dfs(1, 1);
        int now = 0;
        for (int i = 1; i < n; i++)
            if (d[i] == 1) leaf[dis[i]].push(i), d[i] = 0;
        vector<int> ans;
        while (leaf[0].size() || leaf[1].size()) {
            ans.push_back(0);
            now ^= 1;
            if (leaf[0].size()) {
                if (now == 0) ans.push_back(0), now ^= 1;
                ans.push_back(leaf[0].top());
                for (int v : G[leaf[0].top()]) {
                    if (v == n || d[v] == 0) continue;
                    if (--d[v] == 1) leaf[dis[v]].push(v), d[v] = 0;
                }
                leaf[0].pop();
            } else {
                if (now == 1) ans.push_back(0), now ^= 1;
                ans.push_back(leaf[1].top());
                for (int v : G[leaf[1].top()]) {
                    if (v == n || d[v] == 0) continue;
                    if (--d[v] == 1) leaf[dis[v]].push(v), d[v] = 0;
                }
                leaf[1].pop();
            }
        }
        cout << ans.size() << '\n';
        for (auto i : ans) {
            if (i) cout << "2 " << i << '\n';
            else cout << "1\n";
        }
        cout << '\n';
    }

    int main() {
        ios::sync_with_stdio(false); cin.tie(nullptr);
        int t;
        cin >> t;
        while (t--) solve();
        return 0;
    }