#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ll calc(ll x, ll U) {
//     ll res = 0;
//     for (int i = 62; ~i; i--) {
//         if ((U >> i) & 1) {
//             if (res + (1 << i) <= x) res += (1 << i);
//         }
//     }
//     return res;
// }

void solve() {
    ll s, m;
    cin >> s >> m;
    const ll t = 1 << __builtin_ctz(m);
    if (s % t != 0) {
        cout << "-1\n";
        return;
    }
    auto check = [&](ll x) -> bool {
        vector<ll> ct(70);
        for (int i = 0; i <= 62; i++)
            if ((s >> i) & 1) ct[i]++;
        for (int i = 62; i > 0; i--) {
            if (ct[i] > 1e18) return false;
            if (!((m >> i) & 1)) ct[i - 1] += ct[i] * 2;
            else if (ct[i] > x) ct[i - 1] += (ct[i] - x) * 2;
        }
        if (m % 2 == 0) return ct[0] == 0;
        return ct[0] <= x;
    };
    ll l = 1, r = s / t, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
}
// 1101
//   11

// 8421
// 1101
// 0101
// 1000
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}