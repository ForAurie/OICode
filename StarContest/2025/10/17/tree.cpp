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
constexpr int N = 2e5 + 10;
typedef long long ll;
int c[N], n, hd[N], nxt[N << 1], ed[N << 1], idx, cnt[N], sz[N], rt[N];
ll ans;
void add(int x, int y) {
    ed[++idx] = y;
    nxt[idx] = hd[x];
    hd[x] = idx;
}
stack<int> mk[N];
void dfs(int u, int fa) {
    sz[u] = 1;
    for (int i = hd[u]; i; i = nxt[i]) {
        int v = ed[i];
        if (v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
    cnt[u] = sz[u];
}
void dfs1(int u, int fa) {
    if (mk[c[u]].top() != 1) {
        cnt[mk[c[u]].top()] -= sz[u];
    } else rt[c[u]] -= sz[u];
    for (int i = hd[u]; i; i = nxt[i]) {
        int v = ed[i];
        if (v == fa) continue;
        mk[c[u]].push(v);
        dfs1(v, u);
        mk[c[u]].pop();
    }
}
int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    // ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    ans = n;
    ans *= (n - 1);
    ans >>= 1;
    ans *= n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    int x, y;
    for (int i = 1; i < n; i++) cin >> x >> y, add(x, y), add(y, x);
    dfs(1, 1);
    for (int i = 1; i <= n; i++) mk[i].push(1), rt[i] = n;
    dfs1(1, 1);
    for (int i = 2; i <= n; i++)
        ans -= cnt[i] * (cnt[i] - 1ll) / 2;
    for (int i = 1; i <= n; i++)
        ans -= rt[i] * (rt[i] - 1ll) / 2;
    cout << ans << endl;
    return 0;
}