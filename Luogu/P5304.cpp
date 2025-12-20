#include <bits/stdc++.h>

using namespace std;

using ll = long long;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
void solve() {
    int n, m, k, x, y, v, idx = 0;
    cin >> n >> m >> k;
    vector<int> hd(n + 10), nxt(m + 10), val(m + 10), ed(m + 10);
    function<void(int, int, int)> add = [&](int x, int y, int) -> void {
        ed[++idx] = y;
        nxt[idx] = hd[x];
        hd[x] = idx;
        val[idx] = v;
    };
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> v;
        add(x, y, v);
    }
    const int s = n + 1, t = n + 2;
    vector<vector<int>> G(n + 10);
    function<ll()> dijkstra = [&]() -> ll {
        vector<ll> dis(n + 10, INF);
        vector<bool> mk(n + 10, false);
        priority_queue<pair<int, ll>, vector<pair<int, ll>>, greater<pair<int, ll>>> q;
        q.push(make_pair(0, s));
        dis[s] = 0;
        while (q.size()) {
            int u = q.top().second; q.pop();
            if (mk[u]) continue;
            mk[u] = true;
            for (int i = hd[u]; i; i = nxt[i]) {
                int v = ed[i];
                if (dis[v] > dis[u] + val[i]) q.push(make_pair(dis[v] = dis[u] + val[i], v));
            }
            for (int v : G[u]) {
                if (dis[v] > dis[u]) q.push(make_pair(dis[v] = dis[u], v)); 
            }
        }
        return dis[t];
    };
    ll ans = INF;
    vector<int> ps(k);
    for (int& i : ps) cin >> i;
    for (int i = 0; i <= __lg(n); i++) {
        G.assign(n + 10, vector<int>());
        for (int j : ps) {
            if ((j >> i) & 1) G[s].push_back(j);
            else G[j].push_back(t);
        }
        ans = min(ans, dijkstra());
        G.assign(n + 10, vector<int>());
        for (int j : ps) {
            if ((j >> i) & 1) G[j].push_back(t);
            else G[s].push_back(j);
        }
        ans = min(ans, dijkstra());
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}