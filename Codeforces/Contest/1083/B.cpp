#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, res = 1;
    cin >> n;
    const int top = n;
    for (long long i = 2; i * i <= top; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            // cout << i << ' ' << cnt << '\n';
            cnt--;
            cnt /= top;
            cnt++;
            while (cnt--) res *= i;
        }
    }
    if (n != 1) res *= n;
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}