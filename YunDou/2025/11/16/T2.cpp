#include <bits/stdc++.h>

using namespace namespace std;

void solve() {
    int n, l, r;
    cin >> n;
    // nfa nson
    vector<vector<vector<vector<int>>>> dp(n + 1, vector<vector<vector<int>>>(n + 1, vector<vector<int>>(n + 1, vector<int>(2, 0))));
    for (int i = 1; i <= n; i++) {
        cin >> l >> r;
        for (int son = 0; son < 3; son++) {
            if (son < l || son > r) continue;
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= n; k++) {
                    for (int l = 0; l < 2; l++) {
                        if (son == 0) {
                            (dp[i][][k - 1][l] += k * dp[i - 1][j][k][l]) %= mod;
                            (dp[i][][k][1] += dp[i - 1][j][k][l]) %= mod;
                            // (dp[i][j + 1][][l] += dp[i - 1][][][l]) %= mod;
                        } else if (son == 1) {
                            ;
                        } else {
                            ;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tid, t;
    cin >> tid >> t;
    while (t--) solve();
}
