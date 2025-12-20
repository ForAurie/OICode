#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
int n, fa[N], c[N];
vector<int> son[N];
bitset<N> oncircle;
typedef long long ll;
ll dp[N];
void dfs(int u, int fa) {
    dp[u] = 0;
    ll sum = 0;
    int mx = 0;
    for (int v : son[u]) {
        if (v == fa || oncircle[v]) continue;
        dfs(v, u);
        dp[u] += dp[v];
        sum += c[v];
        mx = max(mx, c[v]);
    }
    dp[u] += sum - mx;
}
bitset<N> mk;
void bfs(int s) {
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int u = q.front(); q.pop();
        if (mk[u]) continue;
        mk[u] = 1;
        for (int v : son[u])
            if (!mk[v]) q.push(v);
        int v = fa[u];
        if (!mk[v]) q.push(v);
    }
}
bitset<N> fic;
int main() {
    freopen("cost.in", "r", stdin);
    freopen("cost.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> fa[i] >> c[i];
        son[fa[i]].push_back(i);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (mk[i]) continue;
        bfs(i);
        int now = i;
        stack<int> s;
        while (!fic[now]) {
            s.push(now);
            fic[now] = 1;
            now = fa[now];
        }
        vector<int> cycle;
        while (s.top() != now) {
            oncircle[s.top()] = 1;
            cycle.push_back(s.top());
            s.pop();
        }
        oncircle[now] = 1;
        cycle.push_back(now);
        if ((int) cycle.size() == n) {
            cout << 0 << endl;
            return 0;
        }
        ll tmp = 0x3f3f3f3f3f3f3f3f;
        ll sum = 0;
        for (int rt : cycle) {
            int mx = 0;
            for (int v : son[rt]) {
                sum += c[v];
                mx = max(mx, c[v]);
                if (oncircle[v]) continue;
                dfs(v, rt);
                sum += dp[v];
            }
            sum -= mx;
        }
        for (int i = 0; i < (int)cycle.size(); i++) {
            int u = cycle[i];
            int v = cycle[(i + 1) % cycle.size()];
            ll nsum = sum + c[v];
            int mx = 0, mx2 = 0;
            for (int vv : son[u]) {
                nsum -= c[vv];
                mx = max(mx, c[vv]);
                if (vv != v) {
                    mx2 = max(mx2, c[vv]);
                    nsum += c[vv];
                }
            }
            nsum += mx;
            nsum -= mx2;
            tmp = min(tmp, nsum);
        }
        // for (int i = 0; i < (int)cycle.size(); i++) {
        //     // int u = cycle[i];
        //     // int v = cycle[(i + 1) % cycle.size()];
        //     oncircle[cycle[i]] = 1;
        //     dfs(cycle[i], 0);
        //     oncircle[cycle[i]] = 0;
        //     tmp = min(tmp, dp[cycle[i]] + c[cycle[i]]);
        // }
        ans += tmp;
    }
    cout << ans << endl;
    return 0;
}