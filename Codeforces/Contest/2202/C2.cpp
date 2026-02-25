#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    stack<int> s;
    long long ans = 0, sum = 0;
    for (int i = n; i >= 1; i--) {
        while (s.size() && a[s.top()] == a[i] + 1) {
            sum -= n - s.top() + 1;
            s.pop();
        }
        sum += n - i + 1;
        s.push(i);
        ans += sum;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}