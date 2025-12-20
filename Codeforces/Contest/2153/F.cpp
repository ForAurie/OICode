<<<<<<< HEAD
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
 
void solve() {
    int n, q, tot = 0;
    cin >> n >> q;
    const int B = max((int) ceil(sqrt((long long) n * n / q)), 1);
    vector<int> a(n + 1), id(n + 1), st(n / B + 5);
    for (int i = 1; i <= n; i += B) {
        st[++tot] = i;
        for (int j = i; j < i + B && j <= n; j++)
            id[j] = tot;
    }
    st[tot + 1] = n + 1;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<bool>> mk(n / B + 3, vector<bool>(n + 1));
    vector<vector<long long>> pre(n / B + 3, vector<long long>(n / B + 3));
    auto change = [&](int id, const vector<bool>& fr, vector<bool> &now, long long& v) -> void {
        now[a[id]] = (now[a[id]] ^ 1);
        if (now[a[id]] ^ fr[a[id]]) v += a[id];
        else v -= a[id]; 
    };
    // cout << B << '$' << tot << endl;
    for (int i = 1; i <= tot; i++) {
        int k = st[i];
        vector<bool> tmp(n + 1);
        for (int j = i; j <= tot; j++) {
            pre[i][j] = pre[i][j - 1];
            while (k < st[j + 1]) {
                tmp[a[k]] = (tmp[a[k]] ^ 1);
                if (tmp[a[k]]) pre[i][j] += a[k];
                else pre[i][j] -= a[k];
                k++;
            }
            if (i == 1) mk[j] = tmp;
        }
    }
    long long ans = 0;
    int x, y;
    vector<bool> tmp(n + 1);
    while (q--) {
        cin >> x >> y;
        x = (x - 1 + ans) % n + 1;
        y = (y - 1 + ans) % n + 1;
        if (x > y) swap(x, y);
        if (id[x] == id[y] || id[x] + 1 == id[y]) {
            ans = 0;
            for (int i = x; i <= y; i++) {
                tmp[a[i]] = (tmp[a[i]] ^ 1);
                if (tmp[a[i]]) ans += a[i];
                else ans -= a[i];
            }
            for (int i = x; i <= y; i++) tmp[a[i]] = 0;
        } else {
            ans = pre[id[x] + 1][id[y] - 1];
            auto& now = mk[id[y] - 1];
            const auto& fr = mk[id[x]];
            for (int i = x; i < st[id[x] + 1]; i++) change(i, fr, now, ans);
            for (int i = st[id[y]]; i <= y; i++) change(i, fr, now, ans);
            for (int i = x; i < st[id[x] + 1]; i++) now[a[i]] = (now[a[i]] ^ 1);
            for (int i = st[id[y]]; i <= y; i++) now[a[i]] = (now[a[i]] ^ 1);
        }
        cout << ans << ' ';
    }
    cout << '\n';
    // cout << endl << endl << clock() / CLOCKS_PER_SEC << endl;
}
 
int main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
=======
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
 
void solve() {
    int n, q, tot = 0;
    cin >> n >> q;
    const int B = max((int) ceil(sqrt((long long) n * n / q)), 1);
    vector<int> a(n + 1), id(n + 1), st(n / B + 5);
    for (int i = 1; i <= n; i += B) {
        st[++tot] = i;
        for (int j = i; j < i + B && j <= n; j++)
            id[j] = tot;
    }
    st[tot + 1] = n + 1;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<bool>> mk(n / B + 3, vector<bool>(n + 1));
    vector<vector<long long>> pre(n / B + 3, vector<long long>(n / B + 3));
    auto change = [&](int id, const vector<bool>& fr, vector<bool> &now, long long& v) -> void {
        now[a[id]] = (now[a[id]] ^ 1);
        if (now[a[id]] ^ fr[a[id]]) v += a[id];
        else v -= a[id]; 
    };
    // cout << B << '$' << tot << endl;
    for (int i = 1; i <= tot; i++) {
        int k = st[i];
        vector<bool> tmp(n + 1);
        for (int j = i; j <= tot; j++) {
            pre[i][j] = pre[i][j - 1];
            while (k < st[j + 1]) {
                tmp[a[k]] = (tmp[a[k]] ^ 1);
                if (tmp[a[k]]) pre[i][j] += a[k];
                else pre[i][j] -= a[k];
                k++;
            }
            if (i == 1) mk[j] = tmp;
        }
    }
    long long ans = 0;
    int x, y;
    vector<bool> tmp(n + 1);
    while (q--) {
        cin >> x >> y;
        x = (x - 1 + ans) % n + 1;
        y = (y - 1 + ans) % n + 1;
        if (x > y) swap(x, y);
        if (id[x] == id[y] || id[x] + 1 == id[y]) {
            ans = 0;
            for (int i = x; i <= y; i++) {
                tmp[a[i]] = (tmp[a[i]] ^ 1);
                if (tmp[a[i]]) ans += a[i];
                else ans -= a[i];
            }
            for (int i = x; i <= y; i++) tmp[a[i]] = 0;
        } else {
            ans = pre[id[x] + 1][id[y] - 1];
            auto& now = mk[id[y] - 1];
            const auto& fr = mk[id[x]];
            for (int i = x; i < st[id[x] + 1]; i++) change(i, fr, now, ans);
            for (int i = st[id[y]]; i <= y; i++) change(i, fr, now, ans);
            for (int i = x; i < st[id[x] + 1]; i++) now[a[i]] = (now[a[i]] ^ 1);
            for (int i = st[id[y]]; i <= y; i++) now[a[i]] = (now[a[i]] ^ 1);
        }
        cout << ans << ' ';
    }
    cout << '\n';
    // cout << endl << endl << clock() / CLOCKS_PER_SEC << endl;
}
 
int main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
>>>>>>> origin/main
}