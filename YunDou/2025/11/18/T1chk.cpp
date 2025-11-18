#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

void solve() {
    ull l, r;
    cin >> l >> r;
    ull ans = r;
    for (ull i = l; i <= r; i++) {
        for (ull j = l; j <= r; j++) {
            ans = max(ans, i | j);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}