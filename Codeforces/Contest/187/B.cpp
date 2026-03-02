#include <bits/stdc++.h>

using namespace std;
using ll = long long;
// int len(ll x) {
//     int cnt = 0;
//     while (x) {
//         x /= 10;
//         cnt++;
//     }
//     return cnt;
// }
int calc(ll x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}
void solve() {
    ll x;
    int ans = 0x3f3f3f3f;
    cin >> x;
    vector<int> tmp;
    while (x) tmp.push_back(x % 10), x /= 10;
    auto a = tmp;
    sort(a.begin(), a.end());
    int sum = 0;
    for (int i : a) sum += i;
    if (calc(sum) == sum) {
        cout << 0 << '\n';
        return;
    }
    for (int i = 0; i < a.size(); i++) {
        int cnt = 9 - a[i];
        // cout << cnt << '\n';
        while (cnt--) {
            sum++;
            if (calc(sum) == sum) {
                ans = min(ans, i + 1);
                goto ed;
            }
        }
    }
    ed:;
    sum = 0;
    for (int i : tmp) sum += i;
    tmp.back()--;
    a = tmp;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        // cout << a[i] << '\n';
        while (a[i]--) {
            sum--;
            if (calc(sum) == sum) {
                ans = min(ans, i + 1);
                goto ed1;
            }
        }
    }
    ed1:;
    cout << ans << '\n';
    // tmp.back()--;
    // int sum = 0;
    // for (int i : tmp) sum += i;
    // int ans = 0x3f3f3f3f;
    // sort(tmp.begin(), tmp.end());
    // for (int i = 1; i <= 18 * 9; i++) {
    //     if (calc(i) != i) continue;
    //     if (i == sum) ans = 0;
    //     if (sum > i) {
    //         int idx = tmp.size();

    //     }
    // }
    // cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}