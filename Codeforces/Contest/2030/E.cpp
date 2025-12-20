// #include <bits/stdc++.h>
// using namespace std;
// constexpr int N = 2e5 + 10, mod = 998244353;
// int pre[N], ipre[N];
// inline int C(int n, int m) {
//     if (m > n) return 0;
//     return (long long) pre[n] * ipre[n - m] % mod * ipre[m] % mod;
// }
// using ll = long long;
// void solve() {
//     int n, x;
//     cin >> n;
//     map<int, int> mp;
//     for (int i = 1; i <= n; i++) {
//         cin >> x;
//         mp[x]++;
//     }
//     int last = -1, i = 0, lastcnt = -1;
//     vector<vector<int>> dp(n + 1), ct(n + 1);
//     dp[0].resize(n + 1), ct[0].resize(n + 1);
//     ct[0][n] = 1;
//     for (const auto& _ : mp) {
//         const int v = _.first, cnt = _.second;
//         if (v != last + 1) break;
//         lastcnt = cnt;
//         dp[i + 1].resize(cnt + 1), ct[i + 1].resize(cnt + 1);
//         for (int k = 0; k <= cnt; k++) {
//             for (int j = 0; j < (int) ct[i].size(); j++) {
//                 (dp[i + 1][min(j, k)] += (dp[i][j] + (ll) min(j, k) * ct[i][j] % mod) * C(cnt, k) % mod) %= mod;
//                 (ct[i + 1][min(j, k)] += (ll) C(cnt, k) * ct[i][j] % mod) %= mod;
//             }
//         }
//         ++i;
//         last = v;
//     }
//     int ans = 0;
//     for (int j = 0; j <= lastcnt; j++) (ans += dp[i][j]) %= mod;
//     cout << ans << '\n';
// }
// int fp(long long x, int n) {
//     long long r = 1;
//     while (n) {
//         if (n & 1) (r *= x) %= mod;
//         (x *= x) %= mod;
//         n >>= 1;
//     }
//     return r;
// }
// int main() {
//     ios::sync_with_stdio(0), cin.tie(0);
//     pre[0] = 1;
//     for (int i = 1; i < N; i++) pre[i] = (long long) pre[i - 1] * i % mod;
//     for (int i = 0; i < N; i++) ipre[i] = fp(pre[i], mod - 2);
//     // cout << C(6, 3) << endl;
//     int t;
//     cin >> t;
//     while (t--) solve();
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 10, mod = 998244353;
int pre[N], ipre[N];
inline int C(int n, int m) {
    if (m > n) return 0;
    return (long long) pre[n] * ipre[n - m] % mod * ipre[m] % mod;
}
using ll = long long;
int fp(long long x, int n) {
    long long r = 1;
    while (n) {
        if (n & 1) (r *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return r;
}
void solve() {
    int n, x;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        mp[x]++;
    }
    int last = -1, i = 0, lastcnt = -1;
    vector<vector<int>> dp(n + 1), ct(n + 1);
    dp[0].resize(n + 1), ct[0].resize(n + 1);
    ct[0][n] = 1;
    vector<int> sufdp, sufcnt;
    for (const auto& _ : mp) {
        const int v = _.first, cnt = _.second;
        if (v != last + 1) break;
        lastcnt = cnt;
        n -= cnt;
        dp[i + 1].resize(cnt + 1), ct[i + 1].resize(cnt + 1);
        sufdp = dp[i];
        sufcnt = ct[i];
        for (int i = (int) sufdp.size() - 2; i >= 0; i--) (sufdp[i] += sufdp[i + 1]) %= mod;
        for (int i = (int) sufcnt.size() - 2; i >= 0; i--) (sufcnt[i] += sufcnt[i + 1]) %= mod;
        for (int k = 0; k <= cnt && k < (int) ct[i].size(); k++) {
            (dp[i + 1][k] += C(cnt, k) * (sufdp[k] + (ll) k * sufcnt[k] % mod) % mod) %= mod;
            (ct[i + 1][k] += (ll) C(cnt, k) * sufcnt[k] % mod) %= mod;
        }
        sufcnt.resize(cnt + 1);
        for (int i = 0; i <= cnt; i++) sufcnt[i] = C(cnt, i);
        for (int i = cnt - 1; i >= 0; i--) (sufcnt[i] += sufcnt[i + 1]) %= mod;
        for (int j = 0; j < (int) ct[i].size() && j < cnt; j++) {
            (dp[i + 1][j] += (dp[i][j] + (ll) j * ct[i][j] % mod) * sufcnt[j + 1] % mod) %= mod;
            (ct[i + 1][j] += (ll) sufcnt[j + 1] * ct[i][j] % mod) %= mod;
        }
        ++i;
        last = v;
    }
    int ans = 0;
    for (int j = 0; j <= lastcnt; j++) (ans += dp[i][j]) %= mod;
    cout << (ll) ans * fp(2, n) % mod << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    pre[0] = 1;
    for (int i = 1; i < N; i++) pre[i] = (long long) pre[i - 1] * i % mod;
    for (int i = 0; i < N; i++) ipre[i] = fp(pre[i], mod - 2);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}