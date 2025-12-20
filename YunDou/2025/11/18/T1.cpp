#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
void solve() {
    ull l, r;
    cin >> l >> r;
    if (l == r) {
        cout << l << '\n';
        return;
    }
    const int t = 64 - __builtin_clzll(l ^ r);
    cout << (l | ((1ull << t) - 1)) << '\n';
}

int main() {
    freopen("or.in", "r", stdin);
    freopen("or.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}