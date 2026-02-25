#include <bits/stdc++.h>

using namespace std;
constexpr int mod = 998244353;
void solve() {
    int n;
    using ll = long long;
    auto fp = [](ll x, int n) -> int {
        ll res = 1;
        while (n) {
            if (n & 1) (res *= x) %= mod;
            (x *= x) %= mod;
            n >>= 1;
        }
        return res;
    };
    string s;
    cin >> n >> s; s = ' ' + s;
    int ans = 0;
    vector<array<array<int, 2>, 2>> dp(n + 1);
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') sum[i] = sum[i - 1] + 1;
        else sum[i] = sum[i - 1] - 1;
    }
    for (int i = 1; i <= n; i++) sum[i] = (sum[i] >= 2);
    dp[0][0][1] = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') (ans += fp(2, i - 1)) %= mod;
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                (dp[i][j][min(k, sum[i])] += dp[i - 1][j][k]) %= mod;
                if (j == 0 || k == 1) (dp[i][s[i] == '(' ? 1 : 0][sum[i]] += dp[i - 1][j][k]) %= mod;
            }
        }
    }
    cout << (ans + dp[n][0][0] - 1ll + mod) % mod << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}