#include <bits/stdc++.h>

using namespace std;

constexpr int N = 3e5 + 10;

vector<int> a[N];

void solve() {
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++) a[i].clear();
    for (int i = 1; i <= n; i++) cin >> x, a[x].push_back(i);
    for (int i = 1; i <= n; i++) reverse(a[i].begin(), a[i].end());
    vector<vector<int>> dp(n + 1);
    vector<int> mx(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0, idx = 0; j < a[i].size(); j++) {
            while (idx < a[i - 1].size() && a[i - 1][idx] > a[i][j]) idx++;
            dp[i].push_back(max({mx[max(i - 2, 0)] + 1, mx[i] + 1, 1}));
            if (idx) dp[i].back() = max(dp[i].back(), dp[i - 1][idx - 1] + 1);
            mx[i] = max(mx[i], dp[i].back());
        }
        mx[i] = max(mx[i - 1], mx[i]);
    }
    cout << n - mx[n] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}