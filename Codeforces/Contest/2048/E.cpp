#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> calc(int n) {
    const int m = 2 * n - 1;
    vector<vector<int>> res(2 * n, vector<int>(m));
    for (int c = 0; c < n; c++) {
        for (int i = 0; i < m; i++) {
            res[(i + c * 2) % (2 * n)][i] = c + 1;
            res[(i + c * 2 + 1) % (2 * n)][i] = c + 1;
        }
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    if (2 * n * n + n * m - n >= 2 * n * m) {
        auto ans = calc(n);
        cout << "YES\n";
        for (int i = 0; i < 2 * n; i++)
            for (int j = 0; j < m; j++)
                cout << ans[i][j] << " \n"[j + 1 == m];
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}