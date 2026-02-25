#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 0x3f3f3f3f;
inline void dmin(int& x, int y) { if (x > y) x = y; }
int dp[2][1 << 12][1 << 12];
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (auto& i : a) {
        for (auto& j : i) {
            static char ch;
            cin >> ch;
            if (ch == '.') j = 1;
            else if (ch == '?') j = -1;
        }
    }
    if (n < m) {
        vector<vector<int>> tmp(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                tmp[j][i] = a[i][j];
        swap(a, tmp);
        swap(n, m);
    }
    auto calc = [&](int A, int U) -> int {
        int S = 0, tmp = 0;
        for (int i = 0; i < m; i++) {
            if ((U >> i) & 1) tmp |= (1 << i);
            else {
                if (tmp & A) S |= tmp;
                tmp = 0;
            }
        }
        if (tmp & A) S |= tmp;
        return S;
    };
    // 0 0 需要向上 1 | 0
    // 1 0 无       1 | 0
    // 1 1 向下     0
    for (int S = 0; S < (1 << m); S++) {
        for (int T = S; ; T = (T - 1) & S) {
            dp[0][S][T] = INF;
            if (T == 0) break;
        }
    }
    const int Um = (1 << m) - 1;
    dp[0][Um][0] = 0;
    for (int i = 0; i < n; i++) {
        int now = i & 1, nxt = now ^ 1;
        for (int S = 0; S < (1 << m); S++) {
            for (int T = S; ; T = (T - 1) & S) {
                dp[nxt][S][T] = INF;
                if (T == 0) break;
            }
        }
        int M = 0, E = 0;
        // M 空 和 问号
        // E 空
        for (int j = 0; j < m; j++) {
            M <<= 1; E <<= 1;
            M |= (a[i][j] != 0);
            E |= (a[i][j] == 1);
        }
        
        for (int S = 0; S < (1 << m); S++) {
            int rS = (~S) & Um;
            if ((rS & M) != rS) continue;
            // cout << i << ' ' << S << endl;
            for (int T = S; ; T = (T - 1) & S) {
                if (dp[now][S][T] >= INF) {
                    if (T == 0) break; 
                    continue;
                }
                // (~S) 必须放
                // T 必须不放
                // (S ^ T) & M 需要枚举的
                const int U = M & (~T);
                for (int TP = U; ; TP = (TP - 1) & U) {
                    const int TL = T | calc(TP, M);
                    int need = (E & (~TL)) | (rS & (~TP));
                    int Down = M & (TP | T);
                    dmin(dp[nxt][(~need) & Um][Down], dp[now][S][T] + __builtin_popcount(TP));
                    if (TP == 0) break;
                }
                if (T == 0) break;
            }
        }
        // if (i == 11 || i == 12) {
        //     // cout << dp[now][0b10][0b00] << ' ';
        //     int ans = INF;
        //     for (int S = 0; S < (1 << m); S++)
        //         dmin(ans, dp[nxt][(1 << m) - 1][S]);
        //     cout << ans << endl;
        // }
    }
    int ans = INF;
    for (int S = 0; S < (1 << m); S++)
        dmin(ans, dp[n & 1][(1 << m) - 1][S]);
    cout << ans << '\n';
}

int main() {
    // freopen("..\\HeTao\\SXD2\\A\\laser3.in", "r", stdin);
    // freopen("laser.out", "w", stdout);
    // freopen("laser.in", "r", stdin);
    // freopen("laser.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int c, t;
    cin >> c >> t;
    while (t--) solve();
    // cerr << "time: " << clock() << endl;
    return 0;
}