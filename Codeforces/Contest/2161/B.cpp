#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto& i : a) cin >> i;
    int mxi = -1, mxj = -1, mni = n, mnj = n, mx1 = -0x3f3f3f3f, mn1 = 0x3f3f3f3f, mx2 = -0x3f3f3f3f, mn2 = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '#') {
                mxi = max(mxi, i);
                mni = min(mni, i);
                mxj = max(mxj, j);
                mnj = min(mnj, j);
                mx1 = max(mx1, i + j);
                mn1 = min(mn1, i + j);
                mx2 = max(mx2, i - j);
                mn2 = min(mn2, i - j);
            }
        }
    }
    if (mxi == -1 || (mxi - mni < 2 && mxj - mnj < 2) || (mx1 - mn1 <= 1) || (mx2 - mn2 <= 1)) {
        cout << "YES\n";
    } else cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}