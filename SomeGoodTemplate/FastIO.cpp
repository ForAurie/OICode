#include <cstdio>
#include <cstddef>
#include <cctype>
#include <type_traits>
#include <string>
#include <iostream>
template<size_t BUF_SIZE>
class FastIO {
private:
    char outdata[BUF_SIZE], indata[BUF_SIZE];
    size_t n, outidx, inidx;
    FILE* inFile;
    FILE* outFile;
public:
    FastIO(FILE* in = stdin, FILE* out = stdout) : n(0), outidx(0), inidx(0), inFile(in), outFile(out) {}
    inline void putchar(char c) {
        outdata[outidx++] = c;
        if (outidx == BUF_SIZE) { std::fwrite(outdata, 1, BUF_SIZE, outFile); outidx = 0; }
    }
    inline void flush() {
        if (outidx) {
            std::fwrite(outdata, 1, outidx, outFile); outidx = 0;
            std::fflush(outFile);
        }
    }
    inline char getchar() {
        if (inidx >= n) {
            n = std::fread(indata, 1, BUF_SIZE, inFile); inidx = 0;
            if (n == 0) return EOF;
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
        x = 0; char ch = getchar(); bool neg = false;
        while (!std::isdigit(ch)) {
            if (ch == '-') neg = true;
            ch = getchar();
        }
        while (std::isdigit(ch)) {
            x = (x << 3) + (x << 1) + (ch ^ 0x30);
            ch = getchar();
        }
        if (neg) x = -x;
        return *this;
    }
    template<typename T, typename std::enable_if<std::is_floating_point<T>::value, int>::type = 0>
    inline FastIO& operator>>(T& x) {
        x = 0; bool neg = false; char ch = getchar();
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
    // inline FastIO& operator<<(const std::ostream& (*pf)(std::ostream&)) {
    //     if (pf == std::endl) { putchar('\n'); flush(); }
    //     return *this;
    // }
    ~FastIO() { flush(); }
};
#include <bits/stdc++.h>
FastIO<(1 << 20) * 4> __IOER__;
#define cin __IOER__
#define cout __IOER__
#define getchar __IOER__.getchar
#define putchar __IOER__.putchar