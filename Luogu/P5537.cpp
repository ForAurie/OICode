#include <bits/stdc++.h>
using namespace std;
// 3846711
constexpr int N = 5e5 + 10, P = 3846711, D = 123;
int n, m, q, rt, a[N];
vector<int> G[N];
typedef unsigned long long ull;
ull powP[N], val[N];
unordered_map<ull, int> s;
void dfs(int u) {
    s[val[u]] = u;
    sort(G[u].begin(), G[u].end());
    for (int i = 0; i < (int) G[u].size(); i++) {
        const int v = G[u][i];
        val[v] = val[u] * P + i + 1 + D;
        dfs(v);
    }
}
struct node {
    int l, r;
    ull v;
    node operator+(const node& o) const {
        return {l, o.r, v * powP[o.r - o.l + 1] + o.v};
    }
} tr[N << 2];
#define ls p << 1
#define rs p << 1 | 1
void build(int p, int l, int r) {
    tr[p].l = l; tr[p].r = r;
    if (l == r) {
        tr[p].v = (ull)a[l] + D;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    tr[p] = tr[ls] + tr[rs];
}
void update(int p, int x, int v) {
    if (tr[p].l == tr[p].r) {
        tr[p].v = (ull) v + D; return;
    }
    int mid = (tr[p].l + tr[p].r) >> 1;
    if (x <= mid) update(ls, x, v);
    else update(rs, x, v);
    tr[p] = tr[ls] + tr[rs];
}
node query(int p, int l, int r) {
    if (l > r) return {0, 0, 0};
    if (l <= tr[p].l && tr[p].r <= r) {
        return tr[p];
    }
    int mid = (tr[p].l + tr[p].r) >> 1;
    node res;
    bool flag = false;
    if (l <= mid) res = query(ls, l, r), flag = true;
    if (r > mid) {
        if (flag) res = res + query(rs, l, r);
        else res = query(rs, l, r);
    }
    return res;
}
int ask(int p, int l, int r, ull del, ull now, int x) { // 找到 a 序列中第一个操作不到的位置
    if (tr[p].l == tr[p].r) return tr[p].l;
    if (tr[ls].r < l) {
        return ask(rs, l, r, del, now * powP[tr[ls].r - tr[ls].l + 1] + tr[ls].v, x);
    } else if (tr[ls].r > r) {
        return ask(ls, l, r, del, now, x);
    }
    ull tmp = now * powP[tr[ls].r - tr[ls].l + 1] + tr[ls].v - del * powP[tr[ls].r - l + 1] + val[x] * powP[tr[ls].r - l + 1];
    if (s.count(tmp)) return ask(rs, l, r, del, now * powP[tr[ls].r - tr[ls].l + 1] + tr[ls].v, x);
    else return ask(ls, l, r, del, now, x);
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    powP[0] = 1;
    for (int i = 1; i < N; i++) powP[i] = powP[i - 1] * P;
    cin >> n >> m >> q;
    int f;
    for (int i = 1; i <= n; i++) {
        cin >> f;
        if (f == 0) {
            rt = i;
            continue;
        }
        G[f].push_back(i);
    }
    dfs(rt);
    for (int i = 1; i <= m; i++) cin >> a[i];
    build(1, 1, m);
    int op, x, v, l, r;
    while (q--) {
        cin >> op >> x;
        if (op == 1) {
            cin >> l >> r;
            const ull del = query(1, 1, l - 1).v;
            const int p = ask(1, l, r, del, 0, x) - 1;
            cout << s[val[x] * powP[p - l + 1] + query(1, l, p).v] << '\n';
        } else {
            cin >> v;
            update(1, x, v);
        }
    }
    return 0;
}