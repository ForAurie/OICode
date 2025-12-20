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
typedef long long ll;
using namespace std;
constexpr int N = 5e5 + 10;
int n, a[N], fi[N], k, nxt[N], fr[N];
set<int> s;
int main() {
    // freopen("ex_kth2.in", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], fi[a[i]] = i;
    ll ans = 0;
    for (int i = n; i >= 1; i--) {
        
        auto u = s.lower_bound(fi[i]);
        if (u != s.end()) {
            nxt[fi[i]] = *u;
            fr[*u] = fi[i];
        }
        if (u != s.begin()) {
            --u;
            nxt[*u] = fi[i];
            fr[fi[i]] = *u;
        }
        s.insert(fi[i]);
        vector<int> t1, t2;
        auto it = nxt[fi[i]];
        
        while (it && (int) t2.size() < k) t2.push_back(it), it = nxt[it];
        
        it = fr[fi[i]];
        
        while (it && (int) t1.size() < k) t1.push_back(it), it = fr[it];

        t1.push_back(0);
        reverse(t1.begin(), t1.end());
        t1.push_back(fi[i]);
        for (const auto&j : t2) t1.push_back(j);
        t1.push_back(n + 1);
        for (int j = 0; j < (int) t1.size() && t1[j] < fi[i]; j++) {
            if (j + k + 1 < (int) t1.size() && t1[j + k] >= fi[i]) {
                ans += (ll) i * (t1[j + 1] - t1[j]) * (t1[j + k + 1] - t1[j + k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

/*
单增

不能有这些：
2 2
2 3
2 4

3 3
3 4
3 6

4 4


// 3 -> 2, 4, 6
// 4 -> 2, 3
// 2 -> 3, 4
// 6 -> 3

// 5 7 8 9

// 6 -> 0, 2

// ~6 -> 0, 2, 3, 4

// 2 <> 2, 3, 4
// 3 <> 3, 4, 6
// 4 <> 4
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
typedef long long ll;
using namespace std;
constexpr int N = 5e5 + 10;
int n, a[N], fi[N], k, nxt[N], fr[N];
set<int> s;
int main() {
    // freopen("ex_kth2.in", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], fi[a[i]] = i;
    ll ans = 0;
    for (int i = n; i >= 1; i--) {
        
        auto u = s.lower_bound(fi[i]);
        if (u != s.end()) {
            nxt[fi[i]] = *u;
            fr[*u] = fi[i];
        }
        if (u != s.begin()) {
            --u;
            nxt[*u] = fi[i];
            fr[fi[i]] = *u;
        }
        s.insert(fi[i]);
        vector<int> t1, t2;
        auto it = nxt[fi[i]];
        
        while (it && (int) t2.size() < k) t2.push_back(it), it = nxt[it];
        
        it = fr[fi[i]];
        
        while (it && (int) t1.size() < k) t1.push_back(it), it = fr[it];

        t1.push_back(0);
        reverse(t1.begin(), t1.end());
        t1.push_back(fi[i]);
        for (const auto&j : t2) t1.push_back(j);
        t1.push_back(n + 1);
        for (int j = 0; j < (int) t1.size() && t1[j] < fi[i]; j++) {
            if (j + k + 1 < (int) t1.size() && t1[j + k] >= fi[i]) {
                ans += (ll) i * (t1[j + 1] - t1[j]) * (t1[j + k + 1] - t1[j + k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

/*
单增

不能有这些：
2 2
2 3
2 4

3 3
3 4
3 6

4 4


// 3 -> 2, 4, 6
// 4 -> 2, 3
// 2 -> 3, 4
// 6 -> 3

// 5 7 8 9

// 6 -> 0, 2

// ~6 -> 0, 2, 3, 4

// 2 <> 2, 3, 4
// 3 <> 3, 4, 6
// 4 <> 4
>>>>>>> origin/main
*/