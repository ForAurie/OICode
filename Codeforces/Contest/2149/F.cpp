#include <bits/stdc++.h>

using namespace std;

int calc(int x) {
    int l = 0, r = x, mid;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if ((mid * (mid + 1ll) >> 1) < x) l = mid;
        else r = mid - 1;
    }
    return l;
}

void solve() {
    int h, d;
    long long ans = 0;
    cin >> h >> d;
    int l = 1, r = d, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        const long long c = mid * (mid + 1) / 2;
        if ((h / c) * mid >= d) l = mid;
        else r = mid - 1;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}