#include <bits/stdc++.h>
using namespace std;
constexpr int N = 20, M = 5e3 + 10;
typedef long long ll;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
ll dp[1 << 18][N], dis[N][N], mn[1 << 18];
int n, m, k;
// int tmp[M];
pair<vector<int>, int> a[N];
int fi[1 << 18];
int main() {
    srand(time(0));
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        a[i].first.resize(m + 1);
        a[i].second = i;
        for (int j = 1; j <= m; j++) {
            cin >> a[i].first[j];
        }
    }
    int x, y, v;
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1; i <= k; i++) {
        cin >> x >> y >> v;
        x--, y--;
        dis[x][y] = dis[y][x] = min(dis[x][y], (ll) v);
    }
    for (int k = 0; k <= n; k++) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    for (int i = 0; i <= n; i++) dis[i][i] = 0;
    memset(dp, 0x3f, sizeof dp);
    dp[0][n] = 0;
    for (int S = 0; S < (1 << n); S++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < n; k++) {
                if ((S >> k) & 1) continue;
                dp[S | (1 << k)][k] = min(dp[S | (1 << k)][k], dp[S][j] + dis[j][k]);
            }
        }
    }
    memset(mn, 0x3f, sizeof mn);
    for (int S = 0; S < (1 << n); S++) {
        for (int i = 0; i <= n; i++) {
            mn[S] = min(mn[S], dp[S][i] + dis[i][n]);
        }
    }
    ll ans = INF;
    // sort(a, a + n);
    // vector<int> id(n);
    // for (int i = 0; i < n; i++) id[i] = i;
    // while (true) {
    //     int S = 0;
    //     for (int i = 1; i <= m; i++) tmp[i] = 0x3f3f3f3f;
    //     for (int i = 0; i < n; i++) {
    //         S |= 1 << a[id[i]].second;
    //         for (int j = 1; j <= m; j++) tmp[j] = min(tmp[j], a[id[i]].first[j]);
    //         ll sum = 0;
    //         for (int j = 1; j <= m; j++) sum += tmp[j];
    //         ans = min(ans, sum + mn[S]);
    //     }
    //     random_shuffle(id.begin(), id.end());
    //     if (1.0 * clock() / CLOCKS_PER_SEC > 0.97) break;
    // }
    // for (int S = 0; S < (1 << n); S++) {
    //     if (S == 0) continue;
    //     ll sum = 0;
    //     for (int i = 1; i <= m; i++) sum += tmp[j];
    //     ans = min(ans, mn[S] + sum);
    // }
    vector<vector<int>> pr(20);
    for (int S = 0; S < (1 << n); S++) {
        fi[S] = pr[__builtin_popcount(S)].size();
        pr[__builtin_popcount(S)].push_back(S);
    }
    vector<int> fr(1, 0);
    for (int i = 1; i < n; i++) {
        vector<int> now;
        for (int j = 0; j < pr.size(); j++) {
            now[j] = pre[fi[pr[j] ^ (pr[j] & -pr[j])];
            ;
        }
        swap(fr, now);
    }
    cout << ans << endl;
    return 0;
}