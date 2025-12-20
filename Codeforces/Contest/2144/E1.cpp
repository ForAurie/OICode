#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e3 + 10, mod = 998244353;
int pow2[N];
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(1, 0), suf(1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (pre.empty() || a[i] > pre.back()) pre.push_back(a[i]);
    }
    for (int i = n; i >= 1; i--) {
        if (suf.empty() || a[i] > suf.back()) suf.push_back(a[i]);
    }
    const int top = pre.back(); suf.pop_back();
    vector<vector<int>> dppre(n + 2, vector<int>(pre.size())), dpsuf(n + 2, vector<int>(suf.size()));
    dppre[0][0] = dpsuf[n + 1][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (int) pre.size(); j++) {
            if (pre[j] > a[i]) dppre[i][j] = 2 * dppre[i - 1][j] % mod;
            else if (pre[j] == a[i]) dppre[i][j] = (2 * dppre[i - 1][j] % mod + dppre[i - 1][j - 1]) % mod;
            else dppre[i][j] = dppre[i - 1][j];
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < (int) suf.size(); j++) {
            if (suf[j] > a[i]) dpsuf[i][j] = 2 * dpsuf[i + 1][j] % mod;
            else if (suf[j] == a[i]) dpsuf[i][j] = (2 * dpsuf[i + 1][j] % mod + dpsuf[i + 1][j - 1]) % mod;
            else dpsuf[i][j] = dpsuf[i + 1][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != top) continue;
        (ans += (long long) (dppre[i - 1].back() + dppre[i - 1][pre.size() - 2]) * dpsuf[i + 1].back() % mod) %= mod;
        // if (a[i] != top) continue;
        // for (int j = i; j <= n; j++) {
        //     if (a[j] != top) continue;
        //     (ans += (long long) dppre[i - 1].back() * dpsuf[j + 1].back() % mod * pow2[max(j - i - 1, 0)] % mod) %= mod;
        // }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    pow2[0] = 1;
    for (int i = 1; i < N; i++) pow2[i] = 2 * pow2[i - 1] % mod;
    while (t--) solve();
    return 0;
}