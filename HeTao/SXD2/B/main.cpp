#include <bits/stdc++.h>
using namespace std;
constexpr int N = 310, INF = 0x3f3f3f3f;
void dmin(int &x, int y) {
    if (y < x) x = y;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> xs;
    for (int i = 1; i <= n; i++)
        cin >> a[i], xs.push_back(a[i]);
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    const int V = n * (n + 2);
    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(V, vector<int>(2, INF))); 
    auto nxt = dp;
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin() + 1;
        a[i] *= (n + 1);
    }
    for (int i = 1; i < V; i++) dp[1][i][0] = dp[1][i][1] = (i != a[1]);
    for (int i = 2; i <= n; i++) {
        nxt.assign(m + 1, vector<vector<int>>(V, vector<int>(2, INF)));
        for (int j = 1; j < m; j++) {
            for (int k = 1; k < V; k++) {
                for (int l = 1; l < k; l++) {
                    dmin(nxt[j + 1][l][0], dp[j][k][0] + (l != a[i]));
                    dmin(nxt[2][l][0], dp[j][k][1] + (l != a[i]));
                }
                dmin(nxt[j + 1][k][0], dp[j][k][0] + (k != a[i]));
                dmin(nxt[j + 1][k][1], dp[j][k][1] + (k != a[i]));
                for (int l = k + 1; l < V; l++) {
                    dmin(nxt[2][l][1], dp[j][k][0] + (l != a[i]));
                    dmin(nxt[j + 1][l][1], dp[j][k][1] + (l != a[i]));
                }
            }
        }
        swap(dp, nxt);
    }
    // cout << endl;
    int ans = INF;
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < V; j++) {
            dmin(ans, dp[i][j][0]);
            dmin(ans, dp[i][j][1]);
        }
    }
    cout << ans << "\n";
}
int main() {
    freopen("lis.in", "r", stdin);
    freopen("lis.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int c, t;
    cin >> c >> t;
    while (t--) solve();
    return 0;
}