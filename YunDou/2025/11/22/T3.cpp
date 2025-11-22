#include <bits/stdc++.h>

using namespace std;
constexpr int N = 5e2 + 10;
int n, dp1[N][N], c[N], a[N], v[N], dp2[4][N][N], dp0[N][N];

inline bool check(int i, int j) {
    if (i == 0) return true;
    if (j > n) return false;
    return c[i] == c[j] || a[i] == a[j];
}
void dmax(int& x, int y) { if (x < y) x = y; }
int id(int x) { return x % 4; }
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> a[i] >> v[i];
    }
    memset(dp1, -0x3f, sizeof dp1);
    memset(dp2, -0x3f, sizeof dp2);
    memset(dp0, -0x3f, sizeof dp0);
    int ans = 0;
    dp0[1][1] = v[1];
    dp2[3][1][2] = v[3];
    for (int i = 1; i <= n; i++) {
        memset(dp1, -0x3f, sizeof dp1);
        int i0 = id(i), i1 = id(i + 1), i2 = id(i + 2), i3 = id(i + 3);
        for (int j = 1; j < i; j++) {
            for (int k = j + 1; k < i; k++) {
                if (check(i, i + 1)) dmax(dp2[i1][j][k], dp2[i0][j][k] + v[i + 1]);
                if (check(i, j)) dmax(dp1[j][k], dp2[i0][j][k] + v[j]);
            }
        }
        for (int j = 1; j < i; j++) {
            for (int k = j + 1; k < i; k++) {
                // 别忘了！！！dp1[i][j][k] i 是最靠后的被点的，j 是上个被点的，k 是 i 前面保留的。
                if (check(j, k)) dmax(dp0[i][k], dp1[j][k] + v[k]);
                if (check(j, i + 2)) dmax(dp2[i2][k][i + 1], dp1[j][k] + v[i + 2]);
            }
        }
        for (int j = 1; j <= i; j++) {
            if (check(j, i + 1)) dmax(dp0[i + 1][i + 1], dp0[i][j] + v[i + 1]);
            if (check(j, i + 3)) dmax(dp2[i3][i + 1][i + 2], dp0[i][j] + v[i + 3]);
        }
        for (int j = 1; j < i; j++) {
            for (int k = j + 1; k < i; k++) {
                dmax(ans, dp1[j][k]);
                dmax(ans, dp2[i0][j][k]);
            }
        }
        for (int j = 1; j <= i; j++) {
            dmax(ans, dp0[i][j]);
        }
        memset(dp2[i0], -0x3f, sizeof dp2[i0]);
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j < i; j++) {
    //         for (int k = j + 1; k < i; k++) {
    //             dmax(ans, dp1[i][j][k]);
    //             dmax(ans, dp2[i][j][k]);
    //         }
    //     }
    //     for (int j = 1; j <= i; j++) {
    //         dmax(ans, dp0[i][j]);
    //     }
    // }
    cout << ans << endl;
    return 0;
}