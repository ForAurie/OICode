#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 10;
int n, k, a[N];
long long b[N];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) b[i] = b[i - 1] + a[i];
    function<long long(int, int)> query = [&](int l, int r) -> long long { return b[r] - (l > 0 ? b[l - 1] : 0); };
    long long ans = b[n];
    int l, r, mid;
    for (int i = 1; i <= n; i++) {
        l = 1, r = min(i - 1, n - i);
        // cout << l << ' ' << r << '\n';
        if (l > r) continue;
        while (l < r) {
            mid = (l + r + 1) >> 1;
            const int ll = min(k * (mid - 1ll), (long long) i - 1);
            const int rr = min((long long) k * mid, (long long) i - 1);
            if ((long long) (rr - ll) * a[i] - b[rr] + b[ll] >= a[i + mid] - a[i]) l = mid;
            else r = mid - 1;
        }
        int p = min((long long) k * l, (long long) i - 1);
        // cout << 1 << ':' << p << ',' << p + 1 << ':' << i << ',' << i + 1 << ':' << i + l << ','  << i + l + 1 << ':' << n << ' ' << l << '\n';
        // cout << (long long) p * a[i] << ',' << query(p + 1, i) << ',' << (long long) a[i] * l << ',' << query(i + l + 1, n) << '\n';
        ans = max(ans, (long long) p * a[i] + query(p + 1, i) + (long long) a[i] * l + query(i + l + 1, n));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}