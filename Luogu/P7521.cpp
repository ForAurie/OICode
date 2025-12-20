#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 10;
int a[N], n;
int calc(int id) {
    vector<int> t;
    for (int i = 1; i <= n; i++) {
        if (id != i) t.push_back(a[i] % a[id]);
    }
    sort(t.begin(), t.end());
    int res = (t.back() + t[t.size() - 2]) % a[id];
    for (int i = 0, idx = t.size() - 1; i < t.size(); i++) {
        while (~idx && t[idx] >= a[id] - t[i]) --idx;
        if (~idx) {
            res = max(res, t[idx] + t[i]);
            // if (idx != i) res = max(res, t[idx] + t[i]);
            // else if (idx > 0) res = max(res, t[idx - 1] + t[i]);
        }
    }
    return res;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = -0x3f3f3f3f;
    for (int i = n; i >= 1; i--) {
        if (ans >= a[i]) break;
        if (i == n || a[i] != a[i + 1]) {
            ans = max(ans, calc(i));
        }
    }
    cout << ans << endl;
    return 0;
}