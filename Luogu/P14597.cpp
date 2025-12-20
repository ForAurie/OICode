#include <bits/stdc++.h>

using namespace std;
constexpr int N = 5e5 + 10;
using ll = long long;
ll a[N];
int n, dp[N];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i], dp[i - 1]);
        int p = lower_bound(a + 1, a + 1 + n, 2 * a[i] - a[dp[i]]) - a;
        if (p <= n) dp[p] = max(dp[p], i);
    }
    stack<ll> s;
    while (n) {
        s.push(a[n] - a[dp[n]]);
        n = dp[n];
    }
    cout << s.size() << endl;
    while (s.size()) {
        cout << s.top() << ' ';
        s.pop();
    }
    return 0;
}