#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    for (int i = 0; i < n; i++) {
        if (a[i] == n) {
            swap(a[i], a[0]);
            break;
        }
    }
    // cout << ":\n";
    for (int i : a) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}