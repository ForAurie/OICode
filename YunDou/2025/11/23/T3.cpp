#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e3 + 10, mod = 1e9 + 7;

int dp[N], n, a[N], sum[N][N];
vector<int> xs;
int main() {
    freopen("sd.in", "r", stdin);
    freopen("sd.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<pair<int, int>> in(n);
    for (auto& i : in) cin >> i.second >> i.first, xs.push_back(i.second);
    sort(in.begin(), in.end(), greater<pair<int, int>>());
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    for (int i = 0; i < n; i++) a[i + 1] = lower_bound(xs.begin(), xs.end(), in[i].second) - xs.begin() + 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dp[j] = 1;
            if (a[j] > a[i]) {
                (dp[j] += sum[j][a[i] - 1]) %= mod;
            } else if (a[j] < a[i]) {
                (dp[j] += sum[j][n] - sum[j][a[i]]) %= mod;
            }
            sum[i][a[j]] = dp[j];
            (ans += dp[j]) %= mod;
        }
        for (int k = 1; k <= n; k++)
            (sum[i][k] +=  sum[i][k - 1]) %= mod;
    }
    (ans += n) %= mod;
    cout << (ans + mod) % mod << endl;
    return 0;
}