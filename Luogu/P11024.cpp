#include <bits/stdc++.h>

using namespace std;
constexpr int N = 5e5 + 10, INF = 0x3f3f3f3f;

// -1 不合法
// INF ?
// x -> x

struct opt {
    int l, r, c;
    opt(int l = 0, int r = 0, int c = 0) : l(l), r(r), c(c) {}
} a[N];
struct node {
    int l, r, c;
    vector<int> opts;
    node(int l = 0, int r = 0, int c = -1) : l(l), r(r), c(c), opts() {}
} tr[N << 2];
#define ls p << 1
#define rs p << 1 | 1
inline void pushup(int p) {
    if (tr[ls].c == INF) { tr[p].c = tr[rs].c; return; }
    if (tr[rs].c == INF) { tr[p].c = tr[ls].c; return; }
    if ((~tr[ls].c) && (~tr[rs].c)) tr[p].c = (tr[ls].c == tr[rs].c ? tr[ls].c  : -1);
    else tr[p].c = -1;
}
void build(int p, int l, int r) {
    tr[p] = node(l, r);
    if (l == r) {
        cin >> tr[p].c;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(p);
}
int n, m, cnt[N];
bitset<N> mk;
inline bool check(int id, int c) {
    if (~c) return (c == INF ? true : (c == a[id].c));
    else return false;
}
void insert(int p, int id) {
    if (a[id].l <= tr[p].l && tr[p].r <= a[id].r) {
        tr[p].opts.push_back(id);
        cnt[id] += !check(id, tr[p].c);
        return;
    }
    int mid = (tr[p].l + tr[p].r) >> 1;
    if (a[id].l <= mid) insert(ls, id);
    if (a[id].r > mid) insert(rs, id);
}
queue<int> q;
void del(int p, int l, int r) {
    if (tr[p].c == INF) return;
    if (l <= tr[p].l && tr[p].r <= r) {
        for (const auto& i : tr[p].opts) {
            if (mk[i]) continue;
            cnt[i] -= !check(i, tr[p].c);
            if (cnt[i] == 0) q.push(i), mk[i] = 1;
        }
        tr[p].c = INF;
        if (tr[p].l == tr[p].r) return;
    }
    int mid = (tr[p].l + tr[p].r) >> 1;
    if (l <= mid) del(ls, l, r);
    if (r > mid) del(rs, l, r);
    const int pc = tr[p].c;
    pushup(p);
    if ((pc == -1 && ((bool)~tr[p].c)) || (pc != INF && tr[p].c == INF)) {
        for (const auto& i : tr[p].opts) {
            if (mk[i]) continue;
            if (check(i, tr[p].c)) cnt[i] -= !check(i, pc);
            if (cnt[i] == 0) q.push(i), mk[i] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i].l >> a[i].r >> a[i].c;
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
        insert(1, i);
    for (int i = 1; i <= m; i++)
        if (!cnt[i]) q.push(i), mk[i] = 1;
    vector<int> ans;
    while (m--) {
        if (q.empty()) {
            cout << "NE\n";
            return 0;
        }
        del(1, a[q.front()].l, a[q.front()].r);
        ans.push_back(q.front());
        q.pop();
    }
    cout << "DA\n";
    reverse(ans.begin(), ans.end());
    for (const auto& i : ans) cout << i << ' ';
    return 0;
}