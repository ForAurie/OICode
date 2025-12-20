#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N = 1e6 + 10;
int n, a[N], f[N];
ll k;
ll calc(const vector<int>& v, int l, int r) {
    ll res = 0;
    for (const int& i : v) res += i;
    for (int i = l; i <= r; i++) if (f[i] <= (int) v.size()) res += v[f[i] - 1];
    return res;
}
signed main() {
    freopen("study.in", "r", stdin);
    freopen("study.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> f[i];
    int ans = 0;
    for (int l = 1; l <= n;) {
        if (a[l] * (1 + (f[l] == 1)) > k) {
            cout << "-1" << endl;
            return 0;
        }
        ans++;
        int i, r;
        for (i = 0; ; i++) {
            vector<int> v;
            r = min(l + (1 << i) - 1, n);
            for (int j = l; j <= r; j++) v.push_back(a[j]);
            sort(v.begin(), v.end());
            reverse(v.begin(), v.end());
            if (calc(v, l, r) > k || r == n) break;
        }
        int ll = l, rr = r, mid;
        vector<pair<int, int>> v;
        for (int i = ll; i <= rr; i++) v.push_back(make_pair(a[i], i));
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        while (ll < rr) {
            mid = (ll + rr + 1) >> 1;
            vector<int> vn;
            for (const auto& i : v) {
                if (i.second > mid) continue;
                vn.push_back(i.first);
            }
            if (calc(vn, l, mid) <= k) ll = mid;
            else rr = mid - 1;
        }
        l = ll + 1;
    }
    cout << ans << endl;
    return 0;
}