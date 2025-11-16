#include <bits/stdc++.h>
constexpr int N = 1e3 + 10;
using namespace std;
string s[N];
int tid, n, m, q;
bool check(int x1, int y1, int x2, int y2) {
    if (x2 < 1 || x2 > n || y2 < 1 || y2 > m) return false;
    if (s[x1][y1] == 'D') return y2 != y1 + 1;
    else if (s[x1][y1] == 'R') return x2 != x1 + 1;
    else if (s[x1][y1] == 'L') return x2 != x1 - 1;
    else return y2 != y1 - 1;
}
int dfn[N][N], low[N][N], idx, col[N][N], cols, lx[N * N], rx[N * N], ly[N * N], ry[N * N], lxsuf[N * N], rxsuf[N * N], lysuf[N * N], rysuf[N * N], ;
bool in[N][N];
stack<pair<int, int>> stk;
constexpr int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void tarjan(int x, int y) {
    dfn[x][y] = low[x][y] = ++idx;
    in[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + mv[i][0], ny = y + mv[i][1];
        if (!check(x, y, nx, ny)) continue;
        if (!dfn[nx][ny]) {
            tarjan(nx, ny);
            low[x][y] = min(low[x][y], low[nx][ny]);
        } else if (!in[nx][ny]) low[x][y] = min(low[x][y], dfn[nx][ny]);
    }
    if (low[x][y] == dfn[x][y]) {
        pair<int, int> p;
        cols++;
        do {
            p = stk.top(); stk.pop();
            in[p.first][p.second] = false;
            col[p.first][p.second] = cols;
            lx[cols] = min(lx[cols], p.first);
            rx[cols] = max(rx[cols], p.first);
            ly[cols] = min(ly[cols], p.second);
            ry[cols] = max(ry[cols], p.second);
        } while (p.first != x || p.second != y);
    }
}

int main() {
    memset(lx, 0x3f, sizeof lx);
    memset(ly, 0x3f, sizeof ly);
    memset(rx, -0x3f, sizeof rx);
    memset(ry, -0x3f, sizeof ry);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> tid >> n >> m > q;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = ' ' + s[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dfn[i][j]) continue;
            tarjan(i, j);
        }
    }
    return 0;
}