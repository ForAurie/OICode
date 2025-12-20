#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        a[x]++;
    }
    int ans = n;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= i) ans -= i;
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