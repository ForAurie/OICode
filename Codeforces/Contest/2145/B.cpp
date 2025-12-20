#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, cnth = 0, cntl = 0, cnt = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    for (auto i : s) cnth += (i == '0'), cntl += (i == '1'), cnt += (i == '2');
    for (int i = 1; i <= n; i++) {
        if (i <= cnth || n - i + 1 <= cntl || cnth + cnt + cntl == n) cout << '-';
        else if (i <= cnth + cnt || n - i + 1 <= cntl + cnt) cout << '?';
        else cout << '+';
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}