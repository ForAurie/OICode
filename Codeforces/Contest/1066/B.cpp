#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    int cnt4 = 0, cnt8 = 0;
    cin >> s;
    x = abs(x), y = abs(y);
    for (int i : s) {
        cnt4 += (i == '4');
        cnt8 += (i == '8');
    }
    int t  = min({x, y, cnt8});
    x -= t;
    y -= t;
    cnt8 -= t;
    if (x + y <= cnt4 + cnt8) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}