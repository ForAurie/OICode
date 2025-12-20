#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 10;
using ll = long long;
ll ans;
int n, fa[N], f[N];
struct node {
    int cnt0, cnt1, id;
    bool operator<(const node& o) const {
        bool inf1 = (id == 1 || cnt0 == 0);
        bool inf2 = (o.id == 1 || o.cnt0 == 0);
        if (inf1 != inf2) return inf1;
        if (inf1 && inf2) return false;
        return (ll) cnt1 * o.cnt0 > (ll) cnt0 * o.cnt1;
    }
    node operator+(const node& o) const {
        return {cnt0 + o.cnt0, cnt1 + o.cnt1, id};
    }
} a[N];
int find(int x) { return x == f[x] ? x : (f[x] = find(f[x])); }
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        cin >> fa[i];
        f[i] = i;
    }
    priority_queue<node> q;
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        if (v) a[i] = {0, 1, i};
        else a[i] = {1, 0, i};
        q.push(a[i]);
    }
    while (q.size() > 1) {
        auto u = q.top(); q.pop();
        int r = find(u.id);
        if (u.cnt0 != a[r].cnt0 || u.cnt1 != a[r].cnt1) continue;
        if (fa[r] == 0) continue;
        int pr = find(fa[r]);
        ans += (ll) a[pr].cnt1 * a[r].cnt0;
        a[pr] = a[pr] + a[r];
        f[r] = pr;
        q.push(a[pr]);
    }

    cout << ans << "\n";
    return 0;
}
