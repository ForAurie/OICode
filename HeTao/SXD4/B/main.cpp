#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 20, mod = 998244353;
int n, a[1 << N], w[N + 1], f[N + 1][1 << N], tmp[N + 1];
void FMT(int a[]) {
    for (int i = 0; i < n; i++) {
        for (int S = 0; S < (1 << n); S++) {
            if ((S >> i) & 1) (a[S] += a[S ^ (1 << i)]) %= mod;
        }
    }
}
void IFMT(int a[]) {
    for (int i = 0; i < n; i++) {
        for (int S = 0; S < (1 << n); S++) {
            if ((S >> i) & 1) (a[S] -= a[S ^ (1 << i)]) %= mod;
        }
    }
}
int res[N + 1], inv[N + 1];
void exp(int a[]) {
    memset(res, 0, sizeof res);
    res[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            (res[i] += (ll) res[i - j] * a[j] % mod * j % mod) %= mod;
        }
        res[i] = (ll) res[i] * inv[i] % mod;
    }
    for (int i = 0; i <= n; i++) a[i] = res[i];
}
int fp(ll x, int n) {
    ll r = 1;
    while (n) {
        if (n & 1) (r *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return r;
}
int main() {
    for (int i = 1; i <= N; i++) inv[i] = fp(i, mod - 2);
    freopen("sop.in", "r", stdin);
    freopen("sop.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < (1 << n); i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int S = 0; S < (1 << n); S++) {
            if ((S >> i) & 1) continue;
            (a[S] += a[S | (1 << i)]) %= mod;
        }
    }
    int jc = 1;
    for (int i = 1; i <= n; i++) {
        w[i] = ((i & 1) ? 1 : -1) * jc;
        jc = (ll) jc * i % mod;
    }
    for (int i = 1; i < (1 << n); i++) a[i] = (ll) a[i] * w[__builtin_popcount(i)] % mod;
    a[0] = 1;
    for (int i = 0; i < (1 << n); i++)
        f[__builtin_popcount(i)][i] = a[i];
    for (int i = 0; i <= n; i++) FMT(f[i]);    
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j <= n; j++) {
            tmp[j] = f[j][i];
        }
        exp(tmp);
        for (int j = 0; j <= n; j++) {
            f[j][i] = tmp[j];
        }
    }
    for (int i = 0; i <= n; i++) IFMT(f[i]);
    cout << (f[n][(1 << n) - 1] + mod) % mod << endl;
    return 0;
}