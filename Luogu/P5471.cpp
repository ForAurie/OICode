#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
int dis[N], n, m;
struct edge {
    int l, r, d, u, t;
};
set<pair<int, int>> tr[N << 2];
#define ls p << 1
#define rs p << 1 | 1
void insert(int p, int x, int y, int id, int nl = 1, int nr = n) {
    tr[p].insert(make_pair(y, id));
    if (nl == nr) return;
    int mid = (nl + nr) >> 1;
    if (x <= mid) insert(ls, x, y, id, nl, mid);
    else insert(rs, x, y, id, mid + 1, nr);
}
vector<edge> es;
vector<int> G[N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
void update(int p, int id, int val, int nl = 1, int nr = n) {
    // if (st == ed) return;
    if (es[id].l <= nl && nr <= es[id].r) {
        auto st = tr[p].lower_bound(make_pair(es[id].d, 0)), ed = tr[p].upper_bound(make_pair(es[id].u, 0x3f3f3f3f));
        for (auto it = st; it != ed; it++) {
            if (dis[it->second] < 1e9) continue;
            dis[it->second] = val;
            for (int i : G[it->second]) {
                // cerr << i << endl;
                q.push(make_pair(val + es[i].t, i));
            }
        }
        tr[p].erase(st, ed);
        return;
    }
    int mid = (nl + nr) >> 1;
    if (es[id].l <= mid) update(ls, id, val, nl, mid);
    if (es[id].r > mid) update(rs, id, val, mid + 1, nr);
}

int main() {
    freopen("jump2.in", "r", stdin); 
    freopen("jump.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int x, y, m, w, h;
    cin >> n >> m >> w >> h;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        insert(1, x, y, i);
    }
    int p, t, l, r, d, u;
    for (int i = 0; i < m; i++) {
        cin >> p >> t >> l >> r >> d >> u;
        es.push_back({l, r, d, u, t});
        G[p].push_back(i);
    }
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    for (int i : G[1])
        q.push(make_pair(es[i].t, i));
    while (q.size()) {
        int u = q.top().second;
        int val = q.top().first;
        q.pop();
        update(1, u, val);
    }
    for (int i = 2; i <= n; i++) cout << dis[i] << '\n';
    return 0;
}
/*
5 3 5 5
1 1
3 1
4 1
2 2
3 3
1 123 1 5 1 5
1 50 1 5 1 1
3 10 2 2 2 2
*/