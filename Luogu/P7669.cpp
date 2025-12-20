#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10, M = 2e5 + 10;
int n, m, s, t, u, v;
int hd[N], nxt[M << 1], ed[M << 1], val[M << 1];
void add(int x, int y, int v) {
    static int idx = 0;
    ed[++idx] = y;
    nxt[idx] = hd[x];
    hd[x] = idx;
    val[idx] = v;
}
typedef long long ll;
void dijkstra(int s, vector<ll>& dis) {
    dis.assign(n + 1, 0x3f3f3f3f3f3f3f3f);
    dis[s] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push(make_pair(0, s));
    bitset<N> mk;
    while (q.size()) {
        int u = q.top().second; q.pop();
        if (mk[u]) continue;
        mk[u] = 1;
        for (int i = hd[u]; i; i = nxt[i]) {
            int v = ed[i];
            if (dis[v] > dis[u] + val[i]) {
                q.push(make_pair(dis[v] = dis[u] + val[i], v));
            }
        }
    }
}
vector<ll> disu, disv, diss;
int rd[N];
ll dpu[N], dpv[N], mn[N];
int main() {
    memset(dpu, 0x3f, sizeof dpu);
    memset(dpv, 0x3f, sizeof dpv);
    cin >> n >> m >> s >> t >> u >> v;
    int x, y, w;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> w;
        add(x, y, w);
        add(y, x, w);
    }
    dijkstra(u, disu);
    dijkstra(v, disv);
    dijkstra(s, diss);
    ll ans = 0x3f3f3f3f3f3f3f3f;
    queue<int> q;
    q.push(t);
    bitset<N> mk;
    while (q.size()) {
        int u = q.front(); q.pop();
        if (mk[u]) continue;
        mk[u] = 1;
        for (int i = hd[u]; i; i = nxt[i]) {
            int v = ed[i];
            if (diss[v] + val[i] != diss[u]) continue;
            q.push(v);
            rd[v]++;
        }
    }
    while (q.size()) q.pop();
    for (int i = 1; i <= n; i++)
        if (mk[i] && rd[i] == 0) q.push(i);
    while (q.size()) {
        int u = q.front(); q.pop();
        dpu[u] = min(dpu[u], disu[u]);
        dpv[u] = min(dpv[u], disv[u]);
        ans = min({ans, dpu[u] + disv[u], dpv[u] + disu[u]});
        for (int i = hd[u]; i; i = nxt[i]) {
            int v = ed[i];
            if (diss[v] + val[i] != diss[u]) continue;
            dpu[v] = min(dpu[v], dpu[u]);
            dpv[v] = min(dpv[v], dpv[u]);
            if (--rd[v] == 0) q.push(v);
        }
    }
    cout << min(ans, disu[v]) << endl;
    return 0;
}