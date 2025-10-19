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
// #define cin __IOER__
// #define cout __IOER__
// #define getchar __IOER__.getchar
// #define putchar __IOER__.putchar
// #define fflush(stdout) __IOER__.flush()

using namespace std;
constexpr int N = 1e6 + 10;
int a[N], b[N], n, ans[N];
string s;
vector<int> v;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], v.push_back(a[i]);
    for (int i = 1; i <= n; i++) cin >> b[i], v.push_back(b[i]);
    nth_element(v.begin(), v.begin() + n - 1, v.end());
    const int mn = v[n - 1];
    nth_element(v.begin(), v.begin() + n, v.end());
    const int mx = v[n];
    int p1 = 0, p2 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == mn || b[i] == mn) p1 = i;
        if (a[i] == mx || b[i] == mx) p2 = i;
    }
    if ((a[p1] == mn) == (a[p2] == mx)) swap(a[p1], b[p1]), ans[p1] ^= 1;
    if (b[p1] == mn) swap(a[p1], b[p1]), swap(a[p2], b[p2]), ans[p1] ^= 1, ans[p2] ^= 1;
    const int k = n / 2;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += (a[i] < mn);
    for (int i = 1; i <= n; i++) {
        if (i == p1 || i == p2) continue;
        if (cnt == k) break;
        if (cnt < k) {
            if (a[i] > mn && b[i] < mn)
                cnt++, ans[i] ^= 1;
        } else {
            if (a[i] < mn && b[i] > mn)
                cnt--, ans[i] ^= 1;
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i];
    return 0;
}