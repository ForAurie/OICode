#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
constexpr int N = 2.5e5 + 10;
int t, n, a[N], b[N], q;
ull ans[N];

struct node {
    int l, r;
    ull v, x, y, xy, axy, ax, ay, a;
    int cx, cy;
} tr[N << 2];
#define ls p << 1
#define rs p << 1 | 1
void pushup(int p) {
    tr[p].v = tr[ls].v + tr[rs].v;
    tr[p].x = tr[ls].x + tr[rs].x;
    tr[p].y = tr[ls].y + tr[rs].y;
    tr[p].xy = tr[ls].xy + tr[rs].xy;
}

void upd(int p, ull axy, ull ax, ull ay, ull a, int cx, int cy) {
    if (tr[p].cx && tr[p].cy) {
        tr[p].a += tr[p].cx * ax + tr[p].cy * ay + (ull) tr[p].cx * tr[p].cy * axy + a;
    } else if (tr[p].cx) {
        tr[p].a += tr[p].cx * ax + a;
        tr[p].ay += tr[p].cx * axy + ay;
    } else if (tr[p].cy) {
        tr[p].a += tr[p].cy * ay + a;
        tr[p].ax += tr[p].cy * axy + ax;
    } else {
        tr[p].ax += ax;
        tr[p].ay += ay;
        tr[p].axy += axy;
        tr[p].a += a;
    }
    if (cx) tr[p].cx = cx;
    if (cy) tr[p].cy = cy;
    tr[p].v += ax * tr[p].x + ay * tr[p].y + axy * tr[p].xy + a * (tr[p].r - tr[p].l + 1);
    if (cx && cy) {
        tr[p].xy = (tr[p].r - tr[p].l + 1ull) * cx * cy;
        tr[p].x = (tr[p].r - tr[p].l + 1ull) * cx;
        tr[p].y = (tr[p].r - tr[p].l + 1ull) * cy;
    } else if (cx) {
        tr[p].x = (tr[p].r - tr[p].l + 1ull) * cx;
        tr[p].xy = cx * tr[p].y;
    } else if (cy) {
        tr[p].y = (tr[p].r - tr[p].l + 1ull) * cy;
        tr[p].xy = cy * tr[p].x;
    }
}

void pushdown(int p) {
    upd(ls, tr[p].axy, tr[p].ax, tr[p].ay, tr[p].a, tr[p].cx, tr[p].cy);
    upd(rs, tr[p].axy, tr[p].ax, tr[p].ay, tr[p].a, tr[p].cx, tr[p].cy);
    tr[p].axy = tr[p].ax = tr[p].ay = tr[p].a = tr[p].cx = tr[p].cy = 0;
}
void update(int p, int l, int r, ull axy, ull ax, ull ay, ull a, int cx, int cy) {
    if (l <= tr[p].l && tr[p].r <= r) {
        upd(p, axy, ax, ay, a, cx, cy);
        return;
    }
    pushdown(p);
    int mid = (tr[p].l + tr[p].r) >> 1;
    if (l <= mid) update(ls, l, r, axy, ax, ay, a, cx, cy);
    if (r > mid) update(rs, l, r, axy, ax, ay, a, cx, cy);
    pushup(p);
}

ull query(int p, int l, int r) {
    if (l <= tr[p].l && tr[p].r <= r) {
        return tr[p].v;
    }
    pushdown(p);
    int mid = (tr[p].l + tr[p].r) >> 1;
    ull res = 0;
    if (l <= mid) res += query(ls, l, r);
    if (r > mid) res += query(rs, l, r);
    return res;
}
struct qry {
    int l, id;
};

void build(int p, int l, int r) {
    tr[p] = {l, r, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
}
vector<qry> qs[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    cin >> q;
    int l, r;
    for (int i = 1; i <= q; i++) {
        cin >> l >> r;
        qs[r].push_back({l, i});
    }
    stack<int> s1, s2;
    build(1, 1, n);
    for (int r = 1; r <= n; r++) {
        while (s1.size() && a[s1.top()] < a[r]) s1.pop();
        while (s2.size() && b[s2.top()] < b[r]) s2.pop();
        update(1, (s1.empty() ? 1 : s1.top() + 1), r, 0, 0, 0, 0, a[r], 0);
        update(1, (s2.empty() ? 1 : s2.top() + 1), r, 0, 0, 0, 0, 0, b[r]);
        s1.push(r), s2.push(r); 
        update(1, 1, r, 1, 0, 0, 0, 0, 0);
        for (const auto& i : qs[r])
            ans[i.id] = query(1, i.l, r);
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << endl;
    return 0;
}