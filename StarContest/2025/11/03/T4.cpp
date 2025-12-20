<<<<<<< HEAD
#include <bits/stdc++.h>
#define double long double
using namespace std;
typedef long long ll;
constexpr int N = 2e5 + 10;
int n, q, L[N], R[N];
bool ans[N];
struct query {
    int y, c, id;
    bool operator<(const query& o) const {
        return c < o.c;
    }
};
struct line {
    double k, b;
    int id;
    line(double k = 0, double b = 0, int id = 0) : k(k), b(b), id(id) {}
    inline bool alive() const { return id; }
    inline double calc(double x) const { return k * x + b; }
};
inline int Max(const line& a, const line& b, int x) {
    if (!a.alive() && !b.alive()) return 0;
    if (!a.alive()) return b.id;
    if (!b.alive()) return a.id;
    return a.calc(x) < b.calc(x) ? b.id : a.id;
}
inline int Min(const line& a, const line& b, int x) {
    if (!a.alive() && !b.alive()) return 0;
    if (!a.alive()) return b.id;
    if (!b.alive()) return a.id;
    return a.calc(x) < b.calc(x) ? a.id : b.id;
}
struct node {
    int l, r;
    line v;
}  tr1[N << 2], tr2[N << 2];
#define ls p << 1
#define rs p << 1 | 1
void pushdownMax(int p, line x) {
    if (Max(tr1[p].v, x, (tr1[p].l + tr1[p].r) >> 1) == x.id) swap(x, tr1[p].v);
    if (tr1[p].l == tr1[p].r) return;
    if (Max(tr1[p].v, x, tr1[p].l) == x.id) pushdownMax(ls, x);
    if (Max(tr1[p].v, x, tr1[p].r) == x.id) pushdownMax(rs, x);
}
void pushdownMin(int p, line x) {
    if (Min(tr2[p].v, x, (tr2[p].l + tr2[p].r) >> 1) == x.id) swap(x, tr2[p].v);
    if (tr2[p].l == tr2[p].r) return;
    if (Min(tr2[p].v, x, tr2[p].l) == x.id) pushdownMin(ls, x);
    if (Min(tr2[p].v, x, tr2[p].r) == x.id) pushdownMin(rs, x);
}
void buildMax(int p, int l, int r) {
    tr1[p].l = l, tr1[p].r = r;
    if (l == r) return;
    int mid = (tr1[p].l + tr1[p].r) >> 1;
    buildMax(ls, l, mid);
    buildMax(rs, mid + 1, r);
}
void buildMin(int p, int l, int r) {
    tr2[p].l = l, tr2[p].r = r;
    if (l == r) return;
    int mid = (tr2[p].l + tr2[p].r) >> 1;
    buildMin(ls, l, mid);
    buildMin(rs, mid + 1, r);
}
double queryMax(int x) {
    int p = 1;
    double res = -1e10;
    while (tr1[p].l ^ tr1[p].r) {
        int mid = (tr1[p].l + tr1[p].r) >> 1;
        if (tr1[p].v.alive()) res = max(res, tr1[p].v.calc(x));
        if (x <= mid) p = ls;
        else p = rs;
    }
    if (tr1[p].v.alive()) res = max(res, tr1[p].v.calc(x));
    return res;
}
double queryMin(int x) {
    int p = 1;
    double res = 1e10;
    while (tr2[p].l ^ tr2[p].r) {
        int mid = (tr2[p].l + tr2[p].r) >> 1;
        if (tr2[p].v.alive()) res = min(res, tr2[p].v.calc(x));
        if (x <= mid) p = ls;
        else p = rs;
    }
    if (tr2[p].v.alive()) res = min(res, tr2[p].v.calc(x));
    return res;
}
int main() {
    freopen("barrier.in", "r", stdin);
    freopen("barrier.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> L[i] >> R[i];
    vector<query> qs;
    int y, c;
    for (int i = 1; i <= q; i++) {
        cin >> y >> c;
        qs.push_back({y, c, i});
    }
    buildMax(1, 1, 2e5);
    buildMin(1, 1, 2e5);
    sort(qs.begin(), qs.end());
    int idx = 1, cnt = 0;
    for (const auto& i : qs) {
        while (idx <= n && idx <= i.c) pushdownMax(1, line(-1.0 / idx, (double)L[idx] / idx, ++cnt)), pushdownMin(1, line(-1.0 / idx, (double) R[idx] / idx, ++cnt)), idx++;
        ans[i.id] = (queryMax(i.y) <= queryMin(i.y) + 1e-7);
    }
    for (int i = 1; i <= q; i++) {
        if (ans[i]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
=======
#include <bits/stdc++.h>
#define double long double
using namespace std;
typedef long long ll;
constexpr int N = 2e5 + 10;
int n, q, L[N], R[N];
bool ans[N];
struct query {
    int y, c, id;
    bool operator<(const query& o) const {
        return c < o.c;
    }
};
struct line {
    double k, b;
    int id;
    line(double k = 0, double b = 0, int id = 0) : k(k), b(b), id(id) {}
    inline bool alive() const { return id; }
    inline double calc(double x) const { return k * x + b; }
};
inline int Max(const line& a, const line& b, int x) {
    if (!a.alive() && !b.alive()) return 0;
    if (!a.alive()) return b.id;
    if (!b.alive()) return a.id;
    return a.calc(x) < b.calc(x) ? b.id : a.id;
}
inline int Min(const line& a, const line& b, int x) {
    if (!a.alive() && !b.alive()) return 0;
    if (!a.alive()) return b.id;
    if (!b.alive()) return a.id;
    return a.calc(x) < b.calc(x) ? a.id : b.id;
}
struct node {
    int l, r;
    line v;
}  tr1[N << 2], tr2[N << 2];
#define ls p << 1
#define rs p << 1 | 1
void pushdownMax(int p, line x) {
    if (Max(tr1[p].v, x, (tr1[p].l + tr1[p].r) >> 1) == x.id) swap(x, tr1[p].v);
    if (tr1[p].l == tr1[p].r) return;
    if (Max(tr1[p].v, x, tr1[p].l) == x.id) pushdownMax(ls, x);
    if (Max(tr1[p].v, x, tr1[p].r) == x.id) pushdownMax(rs, x);
}
void pushdownMin(int p, line x) {
    if (Min(tr2[p].v, x, (tr2[p].l + tr2[p].r) >> 1) == x.id) swap(x, tr2[p].v);
    if (tr2[p].l == tr2[p].r) return;
    if (Min(tr2[p].v, x, tr2[p].l) == x.id) pushdownMin(ls, x);
    if (Min(tr2[p].v, x, tr2[p].r) == x.id) pushdownMin(rs, x);
}
void buildMax(int p, int l, int r) {
    tr1[p].l = l, tr1[p].r = r;
    if (l == r) return;
    int mid = (tr1[p].l + tr1[p].r) >> 1;
    buildMax(ls, l, mid);
    buildMax(rs, mid + 1, r);
}
void buildMin(int p, int l, int r) {
    tr2[p].l = l, tr2[p].r = r;
    if (l == r) return;
    int mid = (tr2[p].l + tr2[p].r) >> 1;
    buildMin(ls, l, mid);
    buildMin(rs, mid + 1, r);
}
double queryMax(int x) {
    int p = 1;
    double res = -1e10;
    while (tr1[p].l ^ tr1[p].r) {
        int mid = (tr1[p].l + tr1[p].r) >> 1;
        if (tr1[p].v.alive()) res = max(res, tr1[p].v.calc(x));
        if (x <= mid) p = ls;
        else p = rs;
    }
    if (tr1[p].v.alive()) res = max(res, tr1[p].v.calc(x));
    return res;
}
double queryMin(int x) {
    int p = 1;
    double res = 1e10;
    while (tr2[p].l ^ tr2[p].r) {
        int mid = (tr2[p].l + tr2[p].r) >> 1;
        if (tr2[p].v.alive()) res = min(res, tr2[p].v.calc(x));
        if (x <= mid) p = ls;
        else p = rs;
    }
    if (tr2[p].v.alive()) res = min(res, tr2[p].v.calc(x));
    return res;
}
int main() {
    freopen("barrier.in", "r", stdin);
    freopen("barrier.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> L[i] >> R[i];
    vector<query> qs;
    int y, c;
    for (int i = 1; i <= q; i++) {
        cin >> y >> c;
        qs.push_back({y, c, i});
    }
    buildMax(1, 1, 2e5);
    buildMin(1, 1, 2e5);
    sort(qs.begin(), qs.end());
    int idx = 1, cnt = 0;
    for (const auto& i : qs) {
        while (idx <= n && idx <= i.c) pushdownMax(1, line(-1.0 / idx, (double)L[idx] / idx, ++cnt)), pushdownMin(1, line(-1.0 / idx, (double) R[idx] / idx, ++cnt)), idx++;
        ans[i.id] = (queryMax(i.y) <= queryMin(i.y) + 1e-7);
    }
    for (int i = 1; i <= q; i++) {
        if (ans[i]) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
>>>>>>> origin/main
}