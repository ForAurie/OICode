<<<<<<< HEAD
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
using namespace std;
constexpr long long mod[2][46] = {
    {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648, 4294967296, 8589934592, 17179869184, 34359738368, 68719476736, 137438953472, 274877906944, 549755813888, 1099511627776, 2199023255552, 4398046511104, 8796093022208, 17592186044416, 35184372088832, 70368744177664},
    {5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625, 1220703125, 6103515625, 30517578125, 152587890625, 762939453125, 3814697265625, 19073486328125, 95367431640625, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
constexpr int top[2] = {46, 20};
int main() {
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    int n, q, x;
    cin >> n >> q;
    vector<vector<unordered_map<long long, int>>> mp(2);
    mp[0].resize(46);
    mp[1].resize(20);
    unordered_set<int> mk;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        mk.insert(x);
        for (int t = 0; t < 2; t++) {
            for (int p = 0; p < top[t]; p++) {
                mp[t][p][(x % mod[t][p] + mod[t][p]) % mod[t][p]]++;
            }
        }
    }
    long long v = 0;
    while (q--) {
        cin >> x;
        v -= x;
        if (abs(v) <= 1e9 && mk.count(v)) {
            cout << "1\n";
            continue;
        }
        int ans = 0x3f3f3f3f;
        for (int t = 0; t < 2; t++) {
            int sum = 0;
            for (int p = 0; p < top[t]; p++) {
                auto it = mp[t][p].find((v % mod[t][p] + mod[t][p]) % mod[t][p]);
                if (it != mp[t][p].end()) sum += it->second;
            }
            ans = min(ans, sum);
        }
        cout << ans << '\n';
    }
    cerr << (double) clock() / CLOCKS_PER_SEC << endl;
    return 0;
=======
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
using namespace std;
constexpr long long mod[2][46] = {
    {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824, 2147483648, 4294967296, 8589934592, 17179869184, 34359738368, 68719476736, 137438953472, 274877906944, 549755813888, 1099511627776, 2199023255552, 4398046511104, 8796093022208, 17592186044416, 35184372088832, 70368744177664},
    {5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625, 1220703125, 6103515625, 30517578125, 152587890625, 762939453125, 3814697265625, 19073486328125, 95367431640625, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
constexpr int top[2] = {46, 20};
int main() {
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    int n, q, x;
    cin >> n >> q;
    vector<vector<unordered_map<long long, int>>> mp(2);
    mp[0].resize(46);
    mp[1].resize(20);
    unordered_set<int> mk;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        mk.insert(x);
        for (int t = 0; t < 2; t++) {
            for (int p = 0; p < top[t]; p++) {
                mp[t][p][(x % mod[t][p] + mod[t][p]) % mod[t][p]]++;
            }
        }
    }
    long long v = 0;
    while (q--) {
        cin >> x;
        v -= x;
        if (abs(v) <= 1e9 && mk.count(v)) {
            cout << "1\n";
            continue;
        }
        int ans = 0x3f3f3f3f;
        for (int t = 0; t < 2; t++) {
            int sum = 0;
            for (int p = 0; p < top[t]; p++) {
                auto it = mp[t][p].find((v % mod[t][p] + mod[t][p]) % mod[t][p]);
                if (it != mp[t][p].end()) sum += it->second;
            }
            ans = min(ans, sum);
        }
        cout << ans << '\n';
    }
    cerr << (double) clock() / CLOCKS_PER_SEC << endl;
    return 0;
>>>>>>> origin/main
}