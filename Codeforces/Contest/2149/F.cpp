#include <bits/stdc++.h>

using namespace std;

long long calc(int m, int h, int d) {
    int len = d / (m + 1), r = d % (m + 1);
    return r * ((len + 1ll) * (len + 2) >> 1) + (m + 1 - r) * ((len + 1ll) * len >> 1);
}

void solve() {
    int h, d;
    cin >> h >> d;
    int l = 0, r = d, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (calc(mid, h, d) <= h + mid - 1) r = mid;
        else l = mid + 1;
    }
    cout << l + d << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}