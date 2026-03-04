#include <bits/stdc++.h>
// #include "FastIO.cpp"
using namespace std;
using ll = long long;
constexpr int N = 2e5 + 10;
ll n, m, a[N], b[N], c[N];

ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

pair<ll, ll> calc(ll a, ll b, ll n) {
    ll x, y;
    ll d = exgcd(a, n, x, y);
    if (b % d) return make_pair<ll, ll>(-1, -1);
    n /= d;
    return make_pair((x * (b / d) % n + n) % n, (ll) n);
}
map<ll, ll> g[40];
int main() {
    // freopen("..\\HeTao\\SXD5\\A\\balloon1.in", "r", stdin);
    freopen("balloon.in", "r", stdin);
    freopen("balloon.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr); 
    cin >> n >> m;
    m = 1ll << m;
    // bool flag = true;
    for (int i = 1; i <= (int) n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i] = (m - (a[i] % m)) % m;
        b[i] %= m;
        // flag = flag && m % b[i] == 0;
    }
    // if (flag) {
        // for (int i = 1; i <= (int) n; i++) {
            // if (a[i] % b[i]) continue;
            // ll t = a[i] / b[i], d = m / b[i];
            // g[63 - __builtin_clzll(d)][t] += c[i];
        // }
        // for (int i = 0; i <= m; i++) {
            
            // ans = max(ans, i % );
        // }
        // return 0;
    // } else {
        for (int i = 1; i <= (int) n; i++) {
            ll t, d;
            auto res = calc(b[i], a[i], m);
            t = res.first, d = res.second;

            if (t == -1) continue;
            g[63 - __builtin_clzll(d)][t] += c[i];
        }
    // }
    ll ans = 0;
    for (int i = 0; i <= 30; i++) {
        for (auto& j : g[i]) {
            ll id = j.first, sum = j.second;
            for (ll k = i - 1; k >= 0; k--) {
                ll pre = id & ((1ll << k) - 1);
                if (g[k].count(pre)) sum += g[k][pre];
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << '\n';
    return 0;
}