#include <bits/stdc++.h>

using namespace std;
constexpr int N = 5e5 + 10, M = N * 32;
int son[2][M][2], idx[2] = {1, 1}, sz[2][M];
long long d[32][2];
void insert(int x, int t, int v) {
    array<int, 2> now;
    now[0] = now[1] = 1;
    vector<array<int, 2>> ps;
    for (int i = 29; ~i; i--) {
        ps.push_back(now);
        int p = (x >> i) & 1;
        if (!son[0][now[0]][p]) son[0][now[0]][p] = ++idx[0];
        if (!son[1][now[1]][p]) son[1][now[1]][p] = ++idx[1];
        now[0] = son[0][now[0]][p];
        now[1] = son[1][now[1]][p];
    }
    d[0][0] -= (long long) sz[0][son[0][ps[29][0]][0]] * sz[1][son[1][ps[29][1]][1]];
    d[0][1] -= (long long) sz[0][son[0][ps[29][0]][1]] * sz[1][son[1][ps[29][1]][0]];
    sz[t][now[t]] += v;
    d[0][0] += (long long) sz[0][son[0][ps[29][0]][0]] * sz[1][son[1][ps[29][1]][1]];
    d[0][1] += (long long) sz[0][son[0][ps[29][0]][1]] * sz[1][son[1][ps[29][1]][0]];
    for (int i = 29; ~i; i--) {
        if (i > 0)
            d[30 - i][0] -= (long long) sz[0][son[0][ps[i - 1][0]][0]] * sz[1][son[1][ps[i - 1][1]][1]],
            d[30 - i][1] -= (long long) sz[0][son[0][ps[i - 1][0]][1]] * sz[1][son[1][ps[i - 1][1]][0]];
        sz[0][ps[i][0]] = sz[0][son[0][ps[i][0]][0]] + sz[0][son[0][ps[i][0]][1]], sz[1][ps[i][1]] = sz[1][son[1][ps[i][1]][0]] + sz[1][son[1][ps[i][1]][1]];
        if (i > 0)
            d[30 - i][0] += (long long) sz[0][son[0][ps[i - 1][0]][0]] * sz[1][son[1][ps[i - 1][1]][1]],
            d[30 - i][1] += (long long) sz[0][son[0][ps[i - 1][0]][1]] * sz[1][son[1][ps[i - 1][1]][0]];
    }
}

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n;
    cin >> n;
    if (n <= 2) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> a(n);
    long long ans = 0;
    for (int& i : a) cin >> i;
    for (int i = 1; i < n; i++)
        insert(a[i], 1, 1);
    for (int i = 1; i + 1 < n; i++) {
        insert(a[i - 1], 0, 1);
        insert(a[i], 1, -1);
        for (int j = 0; j < 30; j++) ans += d[j][(a[i] >> j) & 1];
    }
    cout << ans << endl;
    return 0;
}
