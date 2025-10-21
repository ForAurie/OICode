#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 10;
int n, a[N], b[N], hd[N], nxt[N << 1], ed[N << 1], idx, num, d[N];
void add(int u, int v) {
    nxt[++idx] = hd[u];
    hd[u] = idx;
    ed[idx] = v;
    d[v]++;
}
bitset<N> mk;
vector<int> col[N];
void bfs(int s) {
    ++num;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int u = q.front(); q.pop();
        if (mk[u]) continue;
        mk[u] = 1;
        col[num].push_back(u);
        for (int i = hd[u]; i; i = nxt[i]) {
            int v = ed[i];
            if (mk[v]) continue;
            q.push(v);
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i], add(a[i], b[i]), add(b[i], a[i]);
    for (int i = 1; i <= n * 2; i++) {
        if (mk[i]) continue;
        bfs(i);
    }
    for (int i = 1; i <= num; i++) {
        int sum = 0;
        for (auto u : col[i]) sum += d[u];
        sum >>= 1;
        if (sum > col[i].size()) {
            cout << "-1 -1\n";
            return 0;
        } else if (sum == col[i].size()) {

        } else {
            
        }
    }
    return 0;
}