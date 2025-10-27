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