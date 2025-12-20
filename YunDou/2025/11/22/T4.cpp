#include <bits/stdc++.h>

using namespace std;
constexpr int N = 2e3 + 10;
int n, m, a[N][N], mx = -0x3f3f3f3f, mn = 0x3f3f3f3f;
/*
4 4
1 12 6 11
11 10 2 14
10 1 9 20
4 17 19 10

0 1 0 1
1 - 0 1
- 0 0 1
0 1 1 -

0 ? 0 ?
? ? 0 1
? 0 ? 1
0 1 1 ?


*/
bool check(int x) {
    // < mx - x
    // > mn + x;
    // mx - x <= ? <= mn + x;
    // mn + x <= ? <= mx - x;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mn + x < a[i][j] && a[i][j] < mx - x) {
                return false;
            }
        }
    }
    bool flag = true;
    int v = 0;
    for (int i = 1; i <= n; i++) {
        int fir = 0x3f3f3f3f, las = 0;
        for (int j = 1; j <= m; j++) {
            if (fir > 1e9 && a[i][j] < mx - x) fir = j;
            if (a[i][j] > mn + x) las = j;
        }
        swap(fir, las);
        if (fir > las || v >= las) {
            flag = false;
            break;
        }
        v = max(v, fir);
    }
    if (flag) return true;
    flag = true;
    v = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        int fir = 0x3f3f3f3f, las = 0;
        for (int j = 1; j <= m; j++) {
            if (fir > 1e9 && a[i][j] < mx - x) fir = j;
            if (a[i][j] > mn + x) las = j;
        }
        swap(fir, las);
        if (fir > las || v < fir) {
            flag = false;
            break;
        }
        v = min(v, las - 1);
    }
    /////////////////////////////////////////
    if (flag) return true;
    flag = true;
    v = 0;
    for (int i = 1; i <= n; i++) {
        int fir = 0x3f3f3f3f, las = 0;
        for (int j = 1; j <= m; j++) {
            if (fir > 1e9 && a[i][j] > mn + x) fir = j;
            if (a[i][j] < mx - x) las = j;
        }
        swap(fir, las);
        if (fir > las || v >= las) {
            flag = false;
            break;
        }
        v = max(v, fir);
    }
    if (flag) return true;
    flag = true;
    v = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        int fir = 0x3f3f3f3f, las = 0;
        for (int j = 1; j <= m; j++) {
            if (fir > 1e9 && a[i][j] > mn + x) fir = j;
            if (a[i][j] < mx - x) las = j;
        }
        swap(fir, las);
        if (fir > las || v < fir) {
            flag = false;
            break;
        }
        v = min(v, las - 1);
    }
    return flag;
}
int main() {
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            mx = max(mx, a[i][j]);
            mn = min(mn, a[i][j]);
        }
    }
    int l = 0, r = 1e9, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}