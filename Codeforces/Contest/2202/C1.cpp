#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    stack<int> s;
    for (int i = n; i >= 1; i--) {
        while (s.size() && a[s.top()] == a[i] + 1) s.pop();
        s.push(i);
    }
    cout << s.size() << '\n';
    // while (s.size()) {
    //     cout << s.top() << ' ';
    //     s.pop();
    // }
    // cout << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}