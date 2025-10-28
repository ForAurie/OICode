#include <cstdio>
#include <cstddef>
#include <cctype>
#include <type_traits>
#include <string>
template<size_t BUF_SIZE = (1 << 20) * 4>
class FastIO {
private:
    char outdata[BUF_SIZE], indata[BUF_SIZE];
    size_t n = 0, outidx = 0, inidx = 0;
    FILE* inFile;
    FILE* outFile;
    int floatPrecision = 6;
    bool useScientific = true;
public:
    FastIO(FILE* in = stdin, FILE* out = stdout) : inFile(in), outFile(out) {}

    inline void setPrecision(int p) { floatPrecision = p; }
    inline void setScientific(bool enable) { useScientific = enable; }

    inline void putchar(char c) {
        outdata[outidx++] = c;
        if (outidx == BUF_SIZE) {
            std::fwrite(outdata, 1, BUF_SIZE, outFile);
            outidx = 0;
        }
    }
    inline void flush() { if (outidx) std::fwrite(outdata, 1, outidx, outFile), outidx = 0; }
    inline char getchar() {
        if (inidx >= n) {
            n = std::fread(indata, 1, BUF_SIZE, inFile);
            inidx = 0;
            if (n == 0) return -1;
        }
        return indata[inidx++];
    }
    template<typename T, typename std::enable_if<std::is_integral<T>::value, int>::type = 0>
    inline FastIO& operator<<(T x) {
        static char s[40];
        if (x < 0) putchar('-'), x = -x;
        int n = 0;
        do s[n++] = x % 10 | 0x30, x /= 10;
        while (x);
        while (n--) putchar(s[n]);
        return *this;
    }
    template<typename T, typename std::enable_if<std::is_integral<T>::value, int>::type = 0>
    inline FastIO& operator>>(T& x) {
        x = 0;
        char ch = getchar();
        bool flag = false;
        while (!std::isdigit(ch)) {
            if (ch == '-') flag = true;
            ch = getchar();
        }
        while (std::isdigit(ch)) {
            x = (x << 3) + (x << 1) + (ch ^ 0x30);
            ch = getchar();
        }
        if (flag) x = -x;
        return *this;
    }
    template<typename T, typename std::enable_if<std::is_floating_point<T>::value, int>::type = 0>
    inline FastIO& operator>>(T& x) {
        x = 0;
        bool neg = false;
        char ch = getchar();
        while (!std::isdigit(ch) && ch != '.') {
            if (ch == '-') neg = true;
            ch = getchar();
        }
        while (std::isdigit(ch)) {
            x = x * 10 + (ch ^ 0x30);
            ch = getchar();
        }
        if (ch == '.') {
            ch = getchar();
            T div = static_cast<T>(1);
            while (isdigit(ch)) {
                div /= 10;
                x += (ch ^ 0x30) * div;
                ch = getchar();
            }
        }
        if (neg) x = -x;
        if (ch == 'E' || ch == 'e') {
            ch = getchar();
            neg = false;
            if (ch == '+') {
                ch = getchar();
            } else if (ch == '-') {
                neg = true;
                ch = getchar();
            }
            int exp = 0;
            while (isdigit(ch)) {
                exp = (exp << 3) + (exp << 1) + (ch ^ 0x30);
                ch = getchar();
            }
            T base = 10;
            if (neg) {
                while (exp) {
                    if (exp & 1) x /= base;
                    base *= base;
                    exp >>= 1;
                }
            } else {
                while (exp) {
                    if (exp & 1) x *= base;
                    base *= base;
                    exp >>= 1;
                }
            }
        }
        return *this;
    }
    // template<typename T, typename std::enable_if<std::is_floating_point<T>::value, int>::type = 0>
    // inline FastIO& operator<<(T x) {
    //     if (std::isnan(x)) return putchar('n'), putchar('a'), putchar('n'), *this;
    //     if (std::isinf(x)) {
    //         if (x < 0) putchar('-');
    //         putchar('i'), putchar('n'), putchar('f');
    //         return *this;
    //     }
    //     if (x < 0) {
    //         putchar('-');
    //         x = -x;
    //     }
    //     int exp10 = 0;
    //     if (useScientific && (x != 0.0) && (x < 1e-4 || x >= 1e6)) {
    //         exp10 = static_cast<int>(std::floor(std::log10(x)));
    //         x /= std::pow(10.0, exp10);
    //     }
    //     T intPart;
    //     T fracPart = std::modf(x, &intPart);
    //     static char buf[1024];
    //     int n = 0;
    //     if (intPart < 1) buf[n++] = '0';
    //     else {
    //         while (intPart >= 1) {
    //             T tmp = std::floor(std::fmod(intPart, 10));
    //             buf[n++] = static_cast<int>(tmp + 1e-4) | 0x30;
    //             intPart = std::floor(intPart / 10);
    //         }
    //     }
    //     while (n--) putchar(buf[n]);
    //     if (floatPrecision > 0) {
    //         putchar('.');
    //         for (int i = 0; i < floatPrecision; ++i) {
    //             fracPart *= 10;
    //             int digit = fracPart + 1e-4;
    //             buf[fracLen++] =  | 0x30;
    //             fracPart -= digit;
    //         }
    //         // // 去除尾随0
    //         // while (fracLen > 0 && fracBuf[fracLen - 1] == '0') fracLen--;
    //         // for (int i = 0; i < fracLen; ++i) putchar(fracBuf[i]);
    //     }
    //     if (exp10 != 0) {
    //         putchar('e');
    //         if (exp10 < 0) putchar('-'), exp10 = -exp10;
    //         static char expBuf[8];
    //         int n = 0;
    //         do expBuf[n++] = exp10 % 10 | 0x30, exp10 /= 10;
    //         while (exp10);
    //         while (n--) putchar(expBuf[n]);
    //     }
    //     return *this;
    // }
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
    ~FastIO() {
        flush();
    }
};
FastIO<(1 << 20) * 4> __IOER__;
#include <bits/stdc++.h>
#define cin __IOER__
#define cout __IOER__
#define getchar __IOER__.getchar
#define putchar __IOER__.putchar
#define fflush(stdout) __IOER__.flush()
#define endl '\n'

namespace atcoder {

namespace internal {
    
#if __cplusplus >= 202002L
    
    using std::bit_ceil;
    
#else
    
// @return same with std::bit::bit_ceil
    unsigned int bit_ceil(unsigned int n) {
        unsigned int x = 1;
        while (x < (unsigned int)(n)) x *= 2;
        return x;
    }
    
#endif
    
// @param n `1 <= n`
// @return same with std::bit::countr_zero
    int countr_zero(unsigned int n) {
#ifdef _MSC_VER
        unsigned long index;
        _BitScanForward(&index, n);
        return index;
#else
        return __builtin_ctz(n);
#endif
    }
    
// @param n `1 <= n`
// @return same with std::bit::countr_zero
    constexpr int countr_zero_constexpr(unsigned int n) {
        int x = 0;
        while (!(n & (1 << x))) x++;
        return x;
    }
    
}  // namespace internal

}
namespace atcoder {

#if __cplusplus >= 201703L

template <class S, auto op, auto e> struct segtree {
    static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>,
        "op must work as S(S, S)");
    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,
        "e must work as S()");
    
#else
    
    template <class S, S (*op)(S, S), S (*e)()> struct segtree {
        
#endif
        
    public:
        segtree() : segtree(0) {}
        explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
        explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
            size = (int)internal::bit_ceil((unsigned int)(_n));
            log = internal::countr_zero((unsigned int)size);
            d = std::vector<S>(2 * size, e());
            for (int i = 0; i < _n; i++) d[size + i] = v[i];
            for (int i = size - 1; i >= 1; i--) {
                update(i);
            }
        }
        
        void set(int p, S x) {
            assert(0 <= p && p < _n);
            p += size;
            d[p] = x;
            for (int i = 1; i <= log; i++) update(p >> i);
        }
        
        S get(int p) const {
            assert(0 <= p && p < _n);
            return d[p + size];
        }
        
        S prod(int l, int r) const {
            assert(0 <= l && l <= r && r <= _n);
            S sml = e(), smr = e();
            l += size;
            r += size;
            
            while (l < r) {
                if (l & 1) sml = op(sml, d[l++]);
                if (r & 1) smr = op(d[--r], smr);
                l >>= 1;
                r >>= 1;
            }
            return op(sml, smr);
        }
        
        S all_prod() const { return d[1]; }
        
        template <bool (*f)(S)> int max_right(int l) const {
            return max_right(l, [](S x) { return f(x); });
        }
        template <class F> int max_right(int l, F f) const {
            assert(0 <= l && l <= _n);
            assert(f(e()));
            if (l == _n) return _n;
            l += size;
            S sm = e();
            do {
                while (l % 2 == 0) l >>= 1;
                if (!f(op(sm, d[l]))) {
                    while (l < size) {
                        l = (2 * l);
                        if (f(op(sm, d[l]))) {
                            sm = op(sm, d[l]);
                            l++;
                        }
                    }
                    return l - size;
                }
                sm = op(sm, d[l]);
                l++;
            } while ((l & -l) != l);
            return _n;
        }
        
        template <bool (*f)(S)> int min_left(int r) const {
            return min_left(r, [](S x) { return f(x); });
        }
        template <class F> int min_left(int r, F f) const {
            assert(0 <= r && r <= _n);
            assert(f(e()));
            if (r == 0) return 0;
            r += size;
            S sm = e();
            do {
                r--;
                while (r > 1 && (r % 2)) r >>= 1;
                if (!f(op(d[r], sm))) {
                    while (r < size) {
                        r = (2 * r + 1);
                        if (f(op(d[r], sm))) {
                            sm = op(d[r], sm);
                            r--;
                        }
                    }
                    return r + 1 - size;
                }
                sm = op(d[r], sm);
            } while ((r & -r) != r);
            return 0;
        }
        
    private:
        int _n, size, log;
        std::vector<S> d;
        
        void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    };
    
}  // namespace atcoder
using namespace std;
inline int max(int x, int y) { return x < y ? y : x; }
constexpr int INF = 0x3f3f3f3f;
class Matrix {
    int a[2][2];
public:
    constexpr Matrix(int A = 0, int B = 0, int C = 0, int D = 0) { a[0][0] = A, a[0][1] = B, a[1][0] = C, a[1][1] = D; }
    inline const int* operator[](int pos) const { return a[pos]; }
    inline int* operator[](int pos) { return a[pos]; }
    inline Matrix operator*(const Matrix& o) const {
        return Matrix(max(a[0][0] + o.a[0][0], a[0][1] + o.a[1][0]), max(a[0][0] + o.a[0][1], a[0][1] + o.a[1][1]), max(a[1][0] + o.a[0][0], a[1][1] + o.a[1][0]), max(a[1][0] + o.a[0][1], a[1][1] + o.a[1][1]));
    }
};
inline pair<int, int> operator* (const pair<int, int>& pr, const Matrix& mt) { return make_pair(max(pr.first + mt[0][0], pr.second + mt[1][0]), max(pr.first + mt[0][1], pr.second + mt[1][1])); }
constexpr Matrix E = Matrix(0, -INF, -INF, 0);
inline Matrix op(const Matrix& a1, const Matrix& a2) { return a2 * a1; }
constexpr Matrix e() { return E; }
constexpr int N = 1e6 + 10;

int n, m, tot, a[N], dp[N][2], sz[N], d[N], fa[N], son[N], dfn[N], top[N], leaf[N], hd[N], nxt[N << 1], ed[N << 1], rk[N], id[N];
inline void add(int x, int y) {
    static int idx = 0;
    ed[++idx] = y;
    nxt[idx] = hd[x];
    hd[x] = idx;
}
inline void dfs1(int u) {
    sz[u] = 1;
    for (int i = hd[u]; i; i = nxt[i]) {
        int v = ed[i];
        if (v == fa[u]) continue;
        fa[v] = u;
        d[v] = d[u] + 1;
        dfs1(v);
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]]) son[u] = v;
    }
}
inline void dfs2(int u, int tp) {
    rk[dfn[u] = ++tot] = u, top[u] = tp;
    if (son[u]) dfs2(son[u], tp), leaf[u] = leaf[son[u]];
    else {
        leaf[u] = u;
        return;
    }
    for (int i = hd[u]; i; i = nxt[i]) {
        int v = ed[i];
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}
inline void dfs(int u) {
    dp[u][1] = a[u];
    for (int i = hd[u]; i; i = nxt[i]) {
        int v = ed[i];
        if (v == fa[u]) continue;
        dfs(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}
vector<atcoder::segtree<Matrix, op, e>> trs;
inline void update(int p, int vl) {
    static pair<int, int> delta;
    delta = make_pair(0, vl - a[p]);
    a[p] = vl;
    while (p) {
        static int tp, f;
        tp = top[p], f = fa[tp];
        static pair<int, int> pre;
        pre = make_pair(0, 0) * trs[id[dfn[tp]]].all_prod();
        static Matrix mt;
        mt = trs[id[dfn[tp]]].get(dfn[p] - dfn[tp]);
        mt[0][0] += delta.first, mt[1][0] += delta.first, mt[0][1] += delta.second;
        trs[id[dfn[tp]]].set(dfn[p] - dfn[tp], mt);
        static pair<int, int> nxt;
        nxt = make_pair(0, 0) * trs[id[dfn[tp]]].all_prod();
        delta = make_pair(max(nxt.first, nxt.second) - max(pre.first, pre.second), nxt.first - pre.first);
        p = f;
    }
}
int main() {
    int lastans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int x, y;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        add(x, y), add(y, x);
    }
    dfs1(1);
    dfs2(1, 1);
    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (leaf[i] != i) continue;
        for (int j = dfn[top[i]]; j <= dfn[i]; j++)
            id[j] = trs.size();
        trs.push_back(atcoder::segtree<Matrix, op, e>(dfn[i] - dfn[top[i]] + 1));
        for (int j = dfn[top[i]]; j <= dfn[i]; j++) {
            static int n0, n1;
            n0 = dp[rk[j]][0] - max(dp[son[rk[j]]][0], dp[son[rk[j]]][1]), n1 = dp[rk[j]][1] - dp[son[rk[j]]][0];
            trs.back().set(j - dfn[top[i]], Matrix(n0, n1, n0, -INF));
        }
    }
    while (m--) {
        cin >> x >> y;
        x ^= lastans;
        update(x, y);
        pair<int, int> res = make_pair(0, 0) * trs[id[dfn[1]]].all_prod();
        cout << (lastans = max(res.first, res.second)) << '\n';
    }
    return 0;
}
