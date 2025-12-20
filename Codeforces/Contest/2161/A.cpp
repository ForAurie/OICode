#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, r, d, n;
    cin >> r >> x >> d >> n;
    string s;
    cin >> s;
    int ans = 0;
    for (auto i : s) {
        if (i == '1' || r < x) {
            ans++;
            r = max(0, r - d);
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}