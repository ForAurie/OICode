#include <bits/stdc++.h>
using ll = int;
using namespace std;
void solve() {
    int n, mxa = 0;
    ll sum = 0;
    cin >> n;
    vector<int> a(n + 1);
    ll top = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i], mxa = max(mxa, a[i]);
    for (int i = 1; i < n; i++) top = max(top, a[i] + a[i + 1]);
    auto check = [&](ll x) -> bool {
        vector<vector<bool>> dp(min(mxa, x) + 1, vector<bool>(sum / 2 + 1)), nxt;
        dp[0][0] = true;
        ll s = 0;
        for (int i = 0; i < n; i++) {
            nxt.assign(min(mxa, x) + 1, vector<bool>(sum / 2 + 1));
            s += a[i];
            bool f = false;
            for (int j = 0; j <= a[i] && j <= x; j++) {
                for (int k = j; k <= sum / 2 && k <= s; k++) {
                    ll t = min({a[i + 1], x - j, k});
                    for (int l = max({0, a[i + 1] - x, ((k + a[i + 1] - sum / 2) + 1) / 2}), p, q; l <= t; l++) {
                        p = a[i + 1] - l;
                        // a[i + 1] - l <= x;
                        // a[i + 1] - x <= l;
                        // if (p > x) continue;
                        q = k - l + (a[i + 1] - l);
                        //  <= l;
                        // if (q > sum / 2) continue;
                        nxt[p][q] = nxt[p][q] | dp[j][k];
                        f |= dp[j][k];
                    }
                }
            }
            if (!f) return false;
            swap(nxt, dp);
        }
        return dp[0][0];
    };
    ll l = 1, r = top, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
}

int main() {
    freopen("tale.in", "r", stdin);
    freopen("tale.out", "w", stdout);
    // freopen("..\\HeTao\\SXD3\\B\\tale4.in", "r", stdin);
    // freopen("..\\HeTao\\SXD3\\B\\tale.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int c, t;
    cin >> c >> t;
    if (c == 20) {
        while (t--) {
            int n;
            cin >> n;
            vector<int> a(n + 1);
            
        }
    }
    while (t--) solve();
}