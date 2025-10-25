#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1e5 + 10;

struct node {
    int a, b;
    bool operator<(const node& o) const {
        return a > o.a || (a == o.a && b < o.b);
    }
} a[N];
bool mk[N];
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i].a;
    for (int i = 1; i <= n; i++) cin >> a[i].b;
    sort(a + 1, a + 1 + n);
    if (k == 0) {
        for (int i = 1; i < n; i++) a[i] = a[i + 1];
        n--;
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; ++i) {
        q.push(a[i].b);
        if ((int) q.size() > (i + 1) / 2) q.pop();
    }
    long long ans = 0;
    while (q.size()) {
        ans += q.top();
        q.pop();
    }
    cout << ans << "\n";
    // return 0;
    // vector<vector<long long>> dp(n + 5, vector<long long>(n + 5, -0x3f3f3f3f3f3f3f3f));
    // dp[0][0] = 0;
    // for (int i = 1; i <= n; i++) {
    //     const int cn = i - i / 2;
    //     for (int j = 0; j <= cn; j++) {
    //         dp[i][j] = dp[i - 1][j];
    //         if (j) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i].b);
    //     }
    // }
    // cout << dp[n][n - n / 2] << endl;
}

int main() {
    freopen("adventure.in", "r", stdin);
    freopen("adventure.out", "w", stdout);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}