#include <bits/stdc++.h>
using ll = long long;
using namespace std;
constexpr int N = 1e5 + 10, mod = 1e9 + 7;
int n, a[N], b[N], vl[N];
vector<int> mk[N];
vector<int> as;
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
void update(int p, int l, int r, int v) {
    if (l <= tr[p].l && tr[p].r <= r) {
        tr[p].tag = (ll) tr[p].tag * v % mod;
        tr[p].v = (ll) tr[p].v * v % mod;
        return;
    }
    int mid = (tr[p].l + tr[p].r) >> 1;
    if (l <= mid) update(ls, l, r, v);
    if (r > mid) update(rs, l, r, v);
    pushup(p);
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i], as.push_back(a[i]);
    
    return 0;
}