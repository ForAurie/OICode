#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 10;
int n, a[N];
struct node {
    int l, r;
    double sn, cs;
    long long tag;
    node(int l = 0, int r = 0) : l(l), r(r), sn(0), cs(0), tag(0) {}
} tr[N << 2];
#define ls p << 1
#define rs p << 1 | 1

inline void pushup(int p) { tr[p].sn = tr[ls].sn + tr[rs].sn, tr[p].cs = tr[ls].cs + tr[rs].cs; }

void build(int p, int l, int r) {
    tr[p] = node(l, r);
    if (l == r) {
        tr[p].sn = sin(a[l]);
        tr[p].cs = cos(a[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(p);
}
inline void pushdown(int p) {
    if (tr[p].tag) {
        const double sn = sin(tr[p].tag), cs = cos(tr[p].tag);
        double tsn = tr[ls].sn;
        tr[ls].sn = tr[ls].sn * cs + tr[ls].cs * sn;
        tr[ls].cs = -tsn * sn + cs * tr[ls].cs;
        tsn = tr[rs].sn;
        tr[rs].sn = tr[rs].sn * cs + tr[rs].cs * sn;
        tr[rs].cs = -tsn * sn + cs * tr[rs].cs;
        tr[ls].tag += tr[p].tag;
        tr[rs].tag += tr[p].tag;
        tr[p].tag = 0;
    }
}
void add(int p, int l, int r, int v, double sn, double cs) {
    if (l <= tr[p].l && tr[p].r <= r) {
        const double tsn = tr[p].sn;
        tr[p].sn = tr[p].sn * cs + tr[p].cs * sn;
        tr[p].cs = -tsn * sn + tr[p].cs * cs;
        tr[p].tag += v;
        return;
    }
    pushdown(p);
    int mid = (tr[p].l + tr[p].r) >> 1;
    if (l <= mid) add(ls, l, r, v, sn, cs);
    if (r > mid) add(rs, l, r, v, sn, cs);
    pushup(p);
}
double query(int p, int l, int r) {
    if (l <= tr[p].l && tr[p].r <= r)
        return tr[p].sn;
    pushdown(p);
    double res(0);
    int mid = (tr[p].l + tr[p].r) >> 1;
    if (l <= mid) res += query(ls, l, r);
    if (r > mid) res += query(rs, l, r);
    return res;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    build(1, 1, n);
    int q, op, l, r, v;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d%d", &op, &l, &r);
        if (op == 1) {
            scanf("%d", &v);
            add(1, l, r, v, sin(v), cos(v));
        } else {
            printf("%.1f\n", query(1, l, r));
        }
    }
    return 0;
}