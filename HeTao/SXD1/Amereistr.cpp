#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
template<typename T>
void dmin(T& x, const T& y) { if (y < x) x = y; }
void times(vector<ll>& a, const vector<ll>& b) {
    vector<ll> res(a.size(), INF);
    for (int i = 0; i < (int) a.size(); i++) {
        for (int j = 0; j < (int) b.size(); j++) {
            dmin(res[i | j], max(a[i], b[j]));
        }
    }
    swap(a, res);
}
void dijkstra(int s, const vector<vector<pair<int, int>>>& G, vector<ll>& dis, int n) {
    dis.assign(n + 1, INF);
    vector<bool> mk(n + 1);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push(make_pair(0, s));
    dis[s] = 0;
    while (q.size()) {
        int u = q.top().second; q.pop();
        if (mk[u]) continue;
        mk[u] = true;
        for (auto i : G[u]) {
            int v = i.first;
            ll w = i.second + dis[u];
            if (dis[v] > w) q.push(make_pair(dis[v] = w, v));
        }
    }
}
void solve() {
    int n, m, k, q;
    cin >> n >> m;
    vector<vector<pair<int, int>>> G(n + 1);
    while (m--) {
        static int x, y, v;
        cin >> x >> y >> v;
        G[x].push_back(make_pair(y, v));
        G[y].push_back(make_pair(x, v));
    }
    cin >> k >> q;
    vector<vector<pair<int, int>>> c(k + 1);
    vector<int> ps;
    while (q--) {
        static int x, y, z;
        cin >> x >> y >> z;
        c[z].push_back(make_pair(x, y)); // 时间 点
        ps.push_back(y);
    }
    ps.push_back(1);
    sort(ps.begin(), ps.end());
    ps.erase(unique(ps.begin(), ps.end()), ps.end());
    vector<vector<ll>> dis(n + 1);
    for (int i = 1; i <= k; i++)
        sort(c[i].begin(), c[i].end(), greater<pair<int, int>>());
    vector<vector<ll>> dp(1 << k, vector<ll>(n + 1, INF)); // 1e7
    dp[0][1] = 0;
    for (int S = 0; S < (1 << k); S++) {
        for (int p : ps) {
            for (int i = 0; i < k; i++) {
                if ((S >> i) & 1) continue;
                for (auto j : c[i + 1]) {
                    if (j.first < dp[S][p]) break;
                    if (dis[j.second].empty()) dijkstra(j.second, G, dis[j.second], n);
                    ll w = dp[S][p] + dis[j.second][p];
                    if (j.first >= w) dmin(dp[S ^ (1 << i)][j.second], max((ll) j.first, w));
                }
            }
        }
    }
    vector<ll> base(1 << k, INF);
    for (int S = 0; S < (1 << k); S++)
        for (int i = 1; i <= n; i++) dmin(base[S], dp[S][i]);
    vector<ll> ans(base);
    for (int i = 1; i <= k; i++) { // 1024 * 1024 * (k = 10) = 1e7
        if (ans[(1 << k) - 1] >= INF) cout << -1 << ' ';
        else cout << ans[(1 << k) - 1] << ' ';
        if (i != k) times(ans, base);
    }
    cout << '\n';
}
int main() {
    // freopen("..\\HeTao\\SXD1\\amereistr5.in", "r", stdin);
    // freopen("..\\HeTao\\SXD1\\amereistr.out", "w", stdout);
    freopen("amereistr.in", "r", stdin);
    freopen("amereistr.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    // cerr << clock() << endl;
    return 0;
}