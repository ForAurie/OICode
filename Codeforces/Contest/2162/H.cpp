#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, l, r;
    cin >> n >> m;
    vector<int> a, c;
    vector<pair<int, int>> b;
    for (int i = 1; i <= n; i++) cin >> l, a.push_back(l);
    for (int i = 1; i <= m; i++) cin >> l >> r, b.push_back(make_pair(l, r));
    sort(b.begin(), b.end()); 
    l = 1, r = 0;
    for (const auto& i : b) {
        if (i.first <= r) r = i.second;
        else c.push_back(r - l + 1), l = i.first, r = i.second;
    }
    c.push_back(r - l + 1);
    c.erase(c.begin());
    vector<bool> dp(n + 1);
    dp[0] = true;
    int sum = 0;
    for (const auto& i : c) {
        sum += i;
        for (int j = n; ~j; j--)
            dp[j] = dp[j] || dp[j - i];
    }
    sort(a.begin(), a.end());
    int idx = 0;
    for (int x = 1; x <= n; x++) {
        while (idx < (int) a.size() && a[idx] <= n) idx++;
        bool flag = false;
        for (int i = 0; i <= idx; i++) {
            if (dp[i] && sum - i <= n - idx) {
                flag = true;
                break;
            }
        }
        if (flag) cout << 1;
        else cout << 0;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}