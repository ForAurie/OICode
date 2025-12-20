#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> sum(n * 2 + 10), cnt(n * 2 + 10);
    vector<int> a(n + 10);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 1; i <= 2 * n; i++) sum[i] = sum[i - 1] + cnt[i];
    // sum[x] - sum[i] + cnt[i] - k < x - i
    // sum[x] - x <= sum[i - 1] - i + k;
    vector<pair<ll, int>> tmp1, tmp2;
    for (int i = 1; i <= 2 * n; i++) {
        tmp1.push_back({sum[i] - i, i});
        if (cnt[i] > k) tmp2.push_back({sum[i - 1] - i + k, i});
    }
    sort(tmp1.begin(), tmp1.end());
    sort(tmp2.begin(), tmp2.end());
    set<int> pq;
    int idx = 0;
    ll ans = 0;
    for (const auto& i : tmp2) {
        while (idx < (int) tmp1.size() && tmp1[idx].first <= i.first) {
            pq.insert(tmp1[idx].second);
            idx++;
        }
        auto it = pq.lower_bound(i.second);
        if (it != pq.end()) ans = max(ans, (ll) (*it) - i.second);
        else ans = max(ans, sum[2 * n] - sum[i.second - 1] - k);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}