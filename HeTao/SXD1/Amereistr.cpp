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
using ull = unsigned long long;
inline ull make(ll x, int y) { return (x << 20) | y; };
class ZKW {
private:
    int n, size;
    vector<ull> tree;
public:
    ZKW(int _n) {
        n = _n;
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(size << 1, INF);
    }
    void build(const vector<ll>& arr) {
        for (int i = 0; i < arr.size(); i++)
            tree[size + i] = make(arr[i], i);
        for (int i = size - 1; i > 0; i--)
            tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
    }
    void update(int index, ull value) {
        int pos = size + index;
        tree[pos] = value;
        pos >>= 1;
        while (pos) {
            tree[pos] = min(tree[pos << 1], tree[pos << 1 | 1]);
            pos >>= 1;
        }
    }
    ull query_min() {
        return tree[1];
    }
};
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
    vector<vector<pair<int, int>>> c(n + 1);
    while (q--) {
        static int x, y, z;
        cin >> x >> y >> z;
        c[y].push_back(make_pair(x, z)); // 时间 种类
    }
    using ull = unsigned long long;
    
    vector<vector<ull>> pre(1 << k);
    vector<bool> mk;
    pre[0].push_back(make(0, 1));
    vector<ll> dis;
    vector<ll> base(1 << k, INF);
    for (int S = 0; S < (1 << k); S++) {
        mk.assign(n + 1, false);
        dis.assign(n + 1, INF);
        for (ull i : pre[S]) dmin(dis[i & ((1ull << 20) - 1)], (ll) i >> 20);
        ZKW pq(dis.size());
        pq.build(dis);
        while ((pq.query_min() >> 20) < (INF >> 20)) {
            int u = pq.query_min() & ((1ull << 20) - 1);
            pq.update(u, make(INF, n + 1));
            if (mk[u]) continue;
            mk[u] = 1;
            for (auto [v, w] : G[u]) {
                if (dis[v] > dis[u] + w)
                    pq.update(v, make(dis[v] = dis[u] + w, v));
            }
            for (auto [t, i] : c[u]) {
                if ((S >> (i - 1)) & 1) continue;
                if (t < dis[u]) continue;
                ll w = max((ll) t, dis[u]);
                pre[S | (1 << (i - 1))].push_back(make(w, u));
            }
        }
        for (int i = 1; i <= n; i++) dmin(base[S], dis[i]);
    }
    vector<ll> ans(base);
    for (int i = 1; i <= k; i++) {
        if (ans[(1 << k) - 1] >= INF) cout << -1 << ' ';
        else cout << ans[(1 << k) - 1] << ' ';
        if (i != k) times(ans, base);
    }
    cout << '\n';
}
int main() {
    freopen("amereistr.in", "r", stdin);
    freopen("amereistr.out", "w" , stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}