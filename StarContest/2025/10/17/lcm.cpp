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
    int l, r, v, tag;
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
    if (tr[p].tag != 1) {
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

inline int idas(int x) { return lower_bound(as.begin(), as.end(), x) - as.begin() + 1; }
inline int valas(int x) { return as[x - 1]; }
inline int idbs(int x) { return lower_bound(bs.begin(), bs.end(), x) - bs.begin() + 1; }
inline int valbs(int x) { return bs[x - 1]; }

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i], as.push_back(a[i]), bs.push_back(b[i]);
    sort(as.begin(), as.end());
    as.erase(unique(as.begin(), as.end()), as.end());
    sort(bs.begin(), bs.end());
    bs.erase(unique(bs.begin(), bs.end()), bs.end());
    const int m = bs.size();
    for (int i = 1; i <= n; i++) mk[a[i]].push_back(idbs(b[i]));
    int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    for (int i = 0; i < m; i++)
        vl[i + 1] = fp(3, bs[i]);
    build(1, 1, m);
    for (int i = 0; i <= (int) as.size() || i <= 10; i++) {
        for (int j : mk[i])
            update(1, j, m, 2);
        (sum1 += (ll) tr[1].v * fp(2, i) % mod) %= mod;
    }
    // cout << ans << endl;
    build(1, 1, m);
    for (int i = 0; i < (int) as.size() || i < 10; i++) {
        for (int j : mk[i])
            update(1, j, m, 2);
        (sum2 += (ll) tr[1].v * fp(2, i + 1) % mod) %= mod;
    }
    // cout << 
    for (int i = 1; i <= m; i++) vl[i] = vl[i] * 3ll % mod;
    build(1, 1, m - 1);
    for (int i = 0; i <= (int) as.size() || i <= 10; i++) {
        for (int j : mk[i])
            update(1, j, m - 1, 2);
        (sum3 += (ll) tr[1].v * fp(2, i) % mod) %= mod;
    }
    build(1, 1, m - 1);
    for (int i = 0; i < (int) as.size() || i < 10; i++) {
        for (int j : mk[i])
            update(1, j, m - 1, 2);
        (sum4 += (ll) tr[1].v * fp(2, i + 1) % mod) %= mod;
    }
    cout << sum1 << ' ' << sum2 << ' ' << sum3 << ' ' << sum4 << endl;
    sum1 -= sum2;
    sum1 -= sum3;
    sum1 += sum4;
    cout << (sum1 + mod) % mod << endl;
    return 0;
}

