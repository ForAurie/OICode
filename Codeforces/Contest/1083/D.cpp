#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e5 + 10;
pair<int, int> f[24][N];
pair<int, int> mx(int l, int r) {
    const int llg = __lg(r - l + 1);
    return max(f[llg][l], f[llg][r - (1 << llg) + 1]);
}

int calc(int l, int r) {
    if (r - l + 1 <= 2) return 0;
    auto p = mx(l, r);
    return min(calc(l, p.second - 1) + r - p.second, calc(p.second + 1, r) + p.second - l);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> f[0][i].first;
        f[0][i].second = i;
    }
    for (int l = 1; l <= __lg(n); l++)
        for (int i = 1; i + (1 << l) <= n + 1; i++)
            f[l][i] = max(f[l - 1][i], f[l - 1][i + (1 << (l - 1))]);
    int ans = calc(1, n);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}