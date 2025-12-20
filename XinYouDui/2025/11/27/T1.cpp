#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 10, mod = 998244353;
int ans[N], n;
using ll = long long;
ll fp(ll x, int n) {
    ll r = 1;
    while (n) {
        if (n & 1) (r *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return r;
}
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> n;
    int ans = 1, n2 = fp(2, n), times = 1;
    for (int i = 0; i < n; i++) {
        ans = (ll) ans * (n2 - times) % mod;
        (times <<= 1) %= mod;
        ans = ans * fp(i + 1, mod - 2) % mod;
    }
    cout << ans << endl;
    return 0;
}