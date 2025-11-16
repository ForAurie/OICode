#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 10;
typedef long long ll;
template <typename T>
void dmax(T& a, T b) {
    if (a < b) a = b;
}
void solve() {
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    s = " " + s;
    t = " " + t;
    for (auto& i : s) i -= 'a';
    for (auto& i : t) i -= 'a';
    vector<int> a(n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], ans += a[i];
    vector<int> L(26, 0x3f3f3f3f), R(26, -0x3f3f3f3f);
    for (int i = 1; i <= m; i++) {
        if (L[t[i]] == 0x3f3f3f3f) L[t[i]] = i;
        R[t[i]] = i;
    }

    // vector<vector<ll>> dp(m + 2, vector<ll>(n + 2, -0x3f3f3f3f3f3f3f3f));
    // dp[0][0] = 0;
    // for (int i = 0; i <= m; i++) {
    //     for (int j = 0; j <= n; j++) {    
    //         if (L[s[j + 1]] <= i && R[s[j + 1]] > i) {
    //             if (s[j + 1] == t[i + 1]) dmax(dp[i + 1][j + 1], dp[i][j] + a[j + 1]);
    //         } else {
    //             if (s[j + 1] != t[i + 1]) dmax(dp[i][j + 1], dp[i][j]);
    //             else dmax(dp[i][j + 1], dp[i][j]), dmax(dp[i + 1][j + 1], dp[i][j] + a[j + 1]);
    //         }
    //     }
    // }
    // ll mx = -0x3f3f3f3f3f3f3f3f;
    // for (int i = 0; i <= n; i++) mx = max(mx, dp[m][i]);
    
    // vector<vector<ll>> dp(2, vector<ll>(m + 2, -0x3f3f3f3f3f3f3f3f));
    // dp[0][0] = 0;
    // ll mx = -0x3f3f3f3f3f3f3f3f;
    // for (int i = 0; i <= n; i++) {
    //     const int cur = i & 1, nxt = cur ^ 1;
    //     dp[nxt].assign(m + 2, -0x3f3f3f3f3f3f3f3f);
    //     for (int j = 0; j <= m; j++) {
    //         if (L[s[i + 1]] <= j && R[s[i + 1]] > j) {
    //             if (s[i + 1] == t[j + 1]) dmax(dp[nxt][j + 1], dp[cur][j] + a[i + 1]);
    //         } else {
    //             if (s[i + 1] != t[j + 1]) dmax(dp[nxt][j], dp[cur][j]);
    //             else dmax(dp[nxt][j], dp[cur][j]), dmax(dp[nxt][j + 1], dp[cur][j] + a[i + 1]);
    //         }
    //     }
    //     dmax(mx, dp[nxt][m]);
    // }
    unordered_map<int, ll> dp[2];
    dp[0][0] = 0;
    ll mx = -0x3f3f3f3f3f3f3f3f;
    for (int i = 0; i <= n; i++) {
        const int cur = i & 1, nxt = cur ^ 1;
        dp[nxt].clear();
        for (const auto& [j, val] : dp[cur]) {
            if (L[s[i + 1]] <= j && R[s[i + 1]] > j) {
                if (s[i + 1] == t[j + 1]) dmax(dp[nxt][j + 1], val + a[i + 1]);
            } else {
                if (s[i + 1] != t[j + 1]) dmax(dp[nxt][j], val);
                else dmax(dp[nxt][j], val), dmax(dp[nxt][j + 1], val + a[i + 1]);
            }
        }
        if (dp[nxt].count(m)) dmax(mx, dp[nxt][m]);
    }
    if (mx < 0) cout << -1 << "\n";
    else cout << ans - mx << "\n";
}
int main() {
    freopen("letter.in", "r", stdin);
    freopen("letter.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tid, t;
    cin >> tid >> t;
    while (t--) solve();
}