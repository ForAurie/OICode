#ifndef GCD_H
#define GCD_H
#include <stdexcept>
#include <cstdlib>
inline int Gcd(int x, int y) {
    if (x == 0 && y == 0) throw std::invalid_argument("gcd(0, 0) is undefined");
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    if (x == 0 || y == 0) return x | y;
    const int t = __builtin_ctz(x | y); int tmp;
    x >>= __builtin_ctz(x);
    while (y) {
        y >>= __builtin_ctz(y);
        tmp = std::abs(x - y);
        if (y < x) x = y; // 这是一个相当快的版本不要乱改，改成 swap 会频繁新建销毁变量，不用 abs 让 tmp 去蹭 if 会影响并行优化
        y = tmp;
    }
    return x << t;
}
inline long long Gcd(long long x, long long y) {
    if (x == 0 && y == 0) throw std::invalid_argument("gcd(0, 0) is undefined");
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    if (x == 0 || y == 0) return x | y;
    const int t = __builtin_ctzll(x | y); long long tmp;
    x >>= __builtin_ctzll(x);
    while (y) {
        y >>= __builtin_ctzll(y);
        tmp = std::abs(x - y);
        if (y < x) x = y;
        y = tmp;
    }
    return x << t;
}
inline unsigned int Gcd(unsigned int x, unsigned int y) {
    if (x == 0 && y == 0) throw std::invalid_argument("gcd(0, 0) is undefined");
    if (x == 0 || y == 0) return x | y;
    const int t = __builtin_ctz(x | y); unsigned int tmp;
    x >>= __builtin_ctz(x);
    while (y) {
        y >>= __builtin_ctz(y);
        tmp = (x < y ? y - x : x - y);
        if (y < x) x = y;
        y = tmp;
    }
    return x << t;
}
inline unsigned long long Gcd(unsigned long long x, unsigned long long y) {
    if (x == 0 && y == 0) throw std::invalid_argument("gcd(0, 0) is undefined");
    if (x == 0 || y == 0) return x | y;
    const int t = __builtin_ctzll(x | y); unsigned long long tmp;
    x >>= __builtin_ctzll(x);
    while (y) {
        y >>= __builtin_ctzll(y);
        tmp = (x < y ? y - x : x - y);
        if (y < x) x = y;
        y = tmp;
    }
    return x << t;
}
#endif