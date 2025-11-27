#include <bits/stdc++.h>
using namespace std;

struct ball {
    int a, b, c, pos, mvc;
};

int n, m;
vector<ball> balls;
int mn;
bool check1() {
    for (int i = 0; i < m; i++) {
        if (balls[i].pos != balls[i].b) {
            return false;
        }
    }
    return true;
}
bool check2(int x) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (balls[i].pos == x) {
            cnt++;
        }
    }
    return cnt >= 2;
}

void dfs(int mvs, vector<int>& boxc) {
    if (mvs >= mn) {
        return;
    }
    if (check1()) {
        mn = min(mn, mvs);
        return;
    }
    for (int i = 0; i < m; i++) {
        if (balls[i].mvc >= balls[i].c) {
            continue;
        }
        int from = balls[i].pos;
        if (!check2(from)) {
            continue;
        }
        for (int to = 1; to <= n; to++) {
            if (to == from) continue;
            int old_pos = balls[i].pos;
            int old_from_count = boxc[from];
            int old_to_count = boxc[to];
            balls[i].pos = to;
            balls[i].mvc++;
            boxc[from]--;
            boxc[to]++;
            dfs(mvs + 1, boxc);
            balls[i].pos = old_pos;
            balls[i].mvc--;
            boxc[from] = old_from_count;
            boxc[to] = old_to_count;
        }
    }
}

int solve() {
    mn = 0x3f3f3f3f;
    if (check1()) {
        return 0;
    }
    vector<int> boxc(n + 1, 0);
    for (int i = 0; i < m; i++) {
        boxc[balls[i].a]++;
    }
    dfs(0, boxc);
    return mn == 0x3f3f3f3f ? -1 : mn;
}

int main() {
    freopen("ball.in", "r", stdin);
    freopen("ball.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        balls.resize(m);
        for (int i = 0; i < m; i++) {
            cin >> balls[i].a >> balls[i].b >> balls[i].c;
            balls[i].pos = balls[i].a;
            balls[i].mvc = 0;
        }
        int res = solve();
        cout << res << '\n';
    }
    
    return 0;
}
