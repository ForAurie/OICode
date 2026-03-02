#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    int h = d / m + 1;
    if (n % h == 0) cout << n / h << '\n';
    else cout << n / h + 1 << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}