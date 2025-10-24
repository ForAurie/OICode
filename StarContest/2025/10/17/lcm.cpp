#include <cstdio>
#include <cstddef>
#include <cctype>
#include <type_traits>
#include <string>
#define BUF_SIZE ((1 << 20) * 4)
class FastIO {
private:
    char outdat[BUF_SIZE], indat[BUF_SIZE];
    size_t n = 0, outidx = 0, inidx = 0;
    public:
    inline void putchar(char c) {
        outdat[outidx++] = c;
        if (outidx == BUF_SIZE) {
            std::fwrite(outdat, 1, BUF_SIZE, stdout);
            outidx = 0;
        }
    }
    inline void flush() { if (outidx) std::fwrite(outdat, 1, outidx, stdout), outidx = 0; }
    inline char getchar() {
        if (inidx >= n) {
            n = std::fread(indat, 1, BUF_SIZE, stdin);
            inidx = 0;
            if (n == 0) return -1;
        }
        return indat[inidx++];
    }
    template<typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type>
    inline FastIO& operator<<(T x) {
        static char s[24];
        if (x < 0) putchar('-'), x = -x;
        int n = 0;
        do s[n++] = x % 10 | 0x30, x /= 10;
        while (x);
        while (n--) putchar(s[n]);
        return *this;
    }
    template<typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type>
    inline FastIO& operator>>(T& x) {
        x = 0;
        char ch = getchar();
        bool flag = false;
        while (!std::isdigit(ch)) {
            if (ch == '-') flag = true;
            ch = getchar();
        }
        while (std::isdigit(ch)) {
            x = (x << 3) + (x << 1) + (ch & 15);
            ch = getchar();
        }
        if (flag) x = -x;
        return *this;
    }
    inline FastIO& operator<<(char ch) { putchar(ch); return *this; }
    inline FastIO& operator>>(char& ch) {
        ch = getchar();
        while(!std::isgraph(ch)) ch = getchar();
        return *this;
    }
    inline FastIO& operator<<(const std::string& s) {
        for (const auto& i : s) putchar(i);
        return *this;
    }
    inline FastIO& operator>>(std::string& s) {
        char ch = getchar();
        while(!std::isgraph(ch)) ch = getchar();
        s.clear();
        do s.push_back(ch), ch = getchar();
        while (std::isgraph(ch));
        return *this;
    }
    ~FastIO() { flush(); }
} __IOER__;
#undef BUF_SIZE
#include <bits/stdc++.h>
#define cin __IOER__
#define cout __IOER__
#define getchar __IOER__.getchar
#define putchar __IOER__.putchar
#define fflush(stdout) __IOER__.flush()
#define endl '\n'
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
    int l, r, v, tag, tmp, add;
} tr[N << 2];
#define ls p << 1
#define rs p << 1 | 1
inline void pushup(int p) { tr[p].v = (tr[ls].v + tr[rs].v) % mod; }
void build(int p, int l, int r) {
    tr[p] = {l, r, 0, 1, 0, 0};
    if (l == r) { tr[p].tmp = vl[l]; tr[p].v = 0; return; }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(p);
    tr[p].tmp = (tr[ls].tmp + tr[rs].tmp) % mod;
}
inline void pushdown(int p) {
    if (tr[p].tag != 1) {
        tr[ls].v = (ll) tr[ls].v * tr[p].tag % mod;
        tr[rs].v = (ll) tr[rs].v * tr[p].tag % mod;
        tr[ls].tag = (ll) tr[ls].tag * tr[p].tag % mod;
        tr[rs].tag = (ll) tr[rs].tag * tr[p].tag % mod;
        tr[ls].add = (ll) tr[ls].add * tr[p].tag % mod;
        tr[rs].add = (ll) tr[rs].add * tr[p].tag % mod;
        tr[p].tag = 1;
    }
    if (tr[p].add) {
        (tr[ls].add += tr[p].add) %= mod;
        (tr[rs].add += tr[p].add) %= mod;
        (tr[ls].v += (ll) tr[ls].tmp * tr[p].add % mod) %= mod;
        (tr[rs].v += (ll) tr[rs].tmp * tr[p].add % mod) %= mod;
        tr[p].add = 0;
    }
}
void times(int p, int l, int r) {
    if (l <= tr[p].l && tr[p].r <= r) {
        tr[p].tag = tr[p].tag * 2ll % mod;
        tr[p].v = tr[p].v * 2ll % mod;
        tr[p].add = tr[p].add * 2ll % mod;
        return;
    }
    pushdown(p);
    int mid = (tr[p].l + tr[p].r) >> 1;
    if (l <= mid) times(ls, l, r);
    if (r > mid) times(rs, l, r);
    pushup(p);
}
void add(int p, int l, int r) {
    if (l <= tr[p].l && tr[p].r <= r) {
        (++tr[p].add) %= mod;
        (tr[p].v += tr[p].tmp) %= mod;
        return;
    }
    pushdown(p);
    int mid = (tr[p].l + tr[p].r) >> 1;
    if (l <= mid) add(ls, l, r);
    if (r > mid) add(rs, l, r);
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
    for (int i = 1; i <= n; i++) mk[idas(a[i])].push_back(idbs(b[i]));
    int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    for (int i = 0; i < m; i++)
        vl[i + 1] = fp(3, bs[i]);
    build(1, 1, m);
    for (int i = 1; i <= (int) as.size(); i++) {
        for (int j : mk[i])
            times(1, j, m),
            add(1, j, m);
        (sum1 += (ll) tr[1].v * fp(2, valas(i)) % mod) %= mod;
    }
    build(1, 1, m);
    for (int i = 1; i <= (int) as.size(); i++) {
        for (int j : mk[i - 1])
            times(1, j, m),
            add(1, j, m);
        (sum2 += (ll) tr[1].v * fp(2, valas(i)) % mod) %= mod;
    }
    for (int i = 1; i <= m; i++) vl[i] = vl[i + 1] % mod;
    build(1, 1, m - 1);
    for (int i = 1; i <= (int) as.size(); i++) {
        for (int j : mk[i])
            if (j != m)
                times(1, j, m - 1),
                add(1, j, m - 1);
        (sum3 += (ll) tr[1].v * fp(2, valas(i)) % mod) %= mod;
    }
    build(1, 1, m - 1);
    for (int i = 1; i <= (int) as.size(); i++) {
        for (int j : mk[i - 1])
            if (j != m)
                times(1, j, m - 1),
                add(1, j, m - 1);
        (sum4 += (ll) tr[1].v * fp(2, valas(i)) % mod) %= mod;
    }
    sum1 -= sum2;
    sum1 -= sum3;
    sum1 += sum4;
    cout << (sum1 + mod) % mod << endl;
    return 0;
}
