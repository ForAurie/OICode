#include <bits/stdc++.h>
using ll = long long;
using namespace std;
constexpr int N = 1e5 + 10, mod = 1e9 + 7;
int n, a[N], b[N], vl[N];
vector<int> mk[N], as, bs;
int fp(ll x, int n) {
    ll r = 1;
    while (n) {
        if (n & 1) (r *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return r;
}
struct node {
    int l, r, v, tag = 1;
} tr[N << 2];
#define ls p << 1
#define rs p << 1 | 1
inline void pushup(int p) { tr[p].v = (tr[ls].v + tr[rs].v) % mod; }
void build(int p, int l, int r) {
    tr[p] = {l, r, 0, 1};
    if (l == r) { tr[p].v = vl[l]; return; }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(p);
}
inline void pushdown(int p) {
    if (tr[p].tag ^ 1) {
        tr[ls].v = (ll) tr[ls].v * tr[p].tag % mod;
        tr[rs].v = (ll) tr[rs].v * tr[p].tag % mod;
        tr[ls].tag = (ll) tr[ls].tag * tr[p].tag % mod;
        tr[rs].tag = (ll) tr[rs].tag * tr[p].tag % mod;
        tr[p].tag = 1;
    }
}
void update(int p, int l, int r, int v) {
    if (l <= tr[p].l && tr[p].r <= r) {
        tr[p].tag = (ll) tr[p].tag * v % mod;
        tr[p].v = (ll) tr[p].v * v % mod;
        return;
    }
    pushdown(p);
    int mid = (tr[p].l + tr[p].r) >> 1;
    if (l <= mid) update(ls, l, r, v);
    if (r > mid) update(rs, l, r, v);
    pushup(p);
}

int idas(int x) { return lower_bound(as.begin(), as.end(), x) - as.begin() + 1; }
int valas(int x) { return as[x - 1]; }

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i], as.push_back(a[i]), bs.push_back(b[i]);
    sort(as.begin(), as.end());
    as.erase(unique(as.begin(), as.end()), as.end());
    sort(bs.begin(), bs.end());
    bs.erase(unique(bs.begin(), bs.end()), bs.end());
    for (int i = 1; i <= n; i++) {
        ;
    }
    return 0;
}