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

using namespace std;

struct point {
    int x, y, xy;
    bool operator<(const point& o) const { return xy < o.xy; }
};
struct opt {
    int x, y, xy, id;
    bool operator<(const opt& o) const { return xy < o.xy; }
};
constexpr int N = 1e6 + 10;
int n, ans[N], c[N], q;
void add(int x) { while (x < N) c[x]++, x += x & -x; }
int query(int x) {
    int res = 0;
    while (x) { res += c[x]; x &= x - 1; }
    return res;
}
int main() {
    freopen("triangular.in", "r", stdin);
    freopen("triangular.out", "w", stdout);
    // ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    vector<point> ps;
    int x, y, d;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        ps.push_back({x, y, x + y});
    }
    vector<opt> qs;
    for (int i = 1; i <= q; i++) {
        cin >> x >> y >> d;
        qs.push_back({x, y, x + y + d, i});
    }
    sort(ps.begin(), ps.end());
    sort(qs.begin(), qs.end());
    int idx = 0;
    for (auto& i : qs) {
        while (idx < (int) ps.size() && ps[idx].xy <= i.xy) add(ps[idx++].x);
        ans[i.id] = idx - query(i.x - 1);
    }
    memset(c, 0, sizeof c);
    idx = 0;
    for (auto& i : qs) {
        while (idx < (int) ps.size() && ps[idx].xy <= i.xy) add(ps[idx++].y);
        ans[i.id] -= query(i.y - 1);
    }
    memset(c, 0, sizeof c);
    sort(ps.begin(), ps.end(), [](const point& a, const point& b) { return a.x < b.x; });
    sort(qs.begin(), qs.end(), [](const opt& a, const opt& b) { return a.x < b.x; });
    idx = 0;
    for (auto& i : qs) {
        while (idx < (int) ps.size() && ps[idx].x < i.x) add(ps[idx++].y);
        ans[i.id] += query(i.y - 1);
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
    cerr << (double) clock() / CLOCKS_PER_SEC;
    return 0;
}