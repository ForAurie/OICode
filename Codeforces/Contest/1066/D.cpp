#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<ll> a(n + 10), pre(n + 10), suf(n + 10);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.begin() + n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + a[i];
    }
    ll ans = 0x3f3f3f3f3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        if (l <= a[i] && a[i] <= r) ans = min(ans, (i - 1ll) * a[i] - pre[i - 1] + suf[i + 1] - (n - i) * a[i]);
    }
    ll tmp1 = 0, tmp2 = 0;
    for (int i = 1; i <= n; i++) {
        tmp1 += abs(l - a[i]);
        tmp2 += abs(r - a[i]);
    }
    // cout << ans << ' ' << tmp1 << ' ' << tmp2 << endl;
    ans = min({ans, tmp1, tmp2});
    cout << ans << "\n";
}
// 1 3 5 7 9
// 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}