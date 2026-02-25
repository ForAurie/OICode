#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k < n || k >= 2 * n) return cout << "NO\n", void();
    cout << "YES\n";
    int x = 2 * n - 1 - k, y = n - x;
    for (int i = n; i >= n - x + 1; i--) cout << i << ' ' << i << ' ';
    if (y <= 3) {
        for (int i = 1; i <= y; i++) cout << i << ' ';
        for (int i = 1; i <= y; i++) cout << i << ' ';
        cout << '\n';
        return;
    }
    deque<int> a, b;
    for (int i = 1; i <= y; i++) a.push_back(i);
    for (int i = 1; i <= y; i++) {
        int x = -1;
        if (a.size()) cout << a.front() << ' ', x = a.front(), a.pop_front();
        else cout << b.front() << ' ', b.pop_front();
        if (b.size()) cout << b.front() << ' ', b.pop_front();
        else cout << a.front() << ' ', b.push_back(a.front()), a.pop_front();
        if (~x) b.push_back(x);
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}