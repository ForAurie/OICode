#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
constexpr int N = 2e5 + 10, D = 65;
int tr1[N * D][2], idx1 = 1, tr2[N * D][2], idx2 = 1, sz1[N * D], sz2[N * D], TOP = 2;
inline void insert(ull x, int tr[N * D][2], int sz[N * D], int& idx, int v) {
    int now = 1;
    for (int i = TOP; ~i; i--) {
        int u = (x >> i) & 1;
        if (!tr[now][u]) tr[now][u] = ++idx;
        now = tr[now][u];
    }
    sz[now] += v;
}
void pre1(int u) {
    for (int i = 0; i < 2; i++) {
        if (tr1[u][i]) {
            pre1(tr1[u][i]);
            sz1[u] += sz1[tr1[u][i]];
        }
    }
}
void pre2(int u) {
    for (int i = 0; i < 2; i++) {
        if (tr2[u][i]) {
            pre2(tr2[u][i]);
            sz2[u] += sz2[tr2[u][i]];
        }
    }
}
map<pair<int, int>, pair<ull, pair<int, int>>> dp;
ull calc(int x, int y, int d) {
    if (d == -1) return 0;
    // if (!sz1[x] || !sz2[y]) assert(false);
    if (dp.count(make_pair(x, y))) return dp[make_pair(x, y)].first;
    auto& res = dp[make_pair(x, y)];
    if (sz1[tr1[x][0]] && sz2[tr2[y][0]] && sz1[tr1[x][1]] && sz2[tr2[y][1]]) {
        auto a = calc(tr1[x][0], tr2[y][0], d - 1);
        auto b = calc(tr1[x][1], tr2[y][1], d - 1);
        if (a < b) res = make_pair(a, make_pair(0, 0));
        else res = make_pair(b, make_pair(1, 1));
        return res.first;
    } else if (sz1[tr1[x][0]] && sz2[tr2[y][0]]) {
        res = make_pair(calc(tr1[x][0], tr2[y][0], d - 1), make_pair(0, 0));
        return res.first;
    } else if (sz1[tr1[x][1]] && sz2[tr2[y][1]]) {
        res = make_pair(calc(tr1[x][1], tr2[y][1], d - 1), make_pair(1, 1));
        return res.first;
    } else {
        int a = (sz1[tr1[x][0]] ? 0 : 1), b = (sz2[tr2[y][0]] ? 0 : 1);
        res = make_pair((1ULL << d) + calc(tr1[x][a], tr2[y][b], d - 1), make_pair(a, b));
        return res.first;
    }
}
void find(int x, int y, int d) {
    sz1[x]--, sz2[y]--;
    for (int i = TOP; ~i; i--) {
        const auto tt = dp[make_pair(x, y)].second;
        dp.erase(make_pair(x, y));
        x = tr1[x][tt.first];
        y = tr2[y][tt.second];
        sz1[x]--, sz2[y]--;
    }
    // sz1[x]--, sz2[y]--;
    // if (d == -1) return;
    // const int a = dp[make_pair(x, y)].second.first;
    // const int b = dp[make_pair(x, y)].second.second;
    // dp.erase(make_pair(x, y));
    // find(tr1[x][a], tr2[y][b], d - 1);
}
template<typename T>
void read(T& x) {
    x = 0;
    char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
}
template<typename T>
void print(T x) {
    static char buf[21];
    int p = 0;
    do {
        buf[p++] = (x % 10) ^ 48;
        x /= 10;
    } while (x);
    while (p--) putchar(buf[p]);
}
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    // clock_t start = clock();
    int n;
    read(n);
    vector<ull> a(n), b(n);
    for (auto& i : a) { read(i); if (i) { TOP = max(TOP, 63 - __builtin_clzll(i)); } }
    for (auto& i : b) { read(i); if (i) { TOP = max(TOP, 63 - __builtin_clzll(i)); } }
    // cerr << TOP << endl;
    for (const auto& i : a) insert(i, tr1, sz1, idx1, 1);
    for (const auto& i : b) insert(i, tr2, sz2, idx2, 1);
    pre1(1);
    pre2(1);
    while (n--) {
       print(calc(1, 1, TOP)); putchar(' ');
        if (n) {
            find(1, 1, TOP);
        }
    }
    // cerr << (double)(clock() - start) / CLOCKS_PER_SEC << "s\n";
    return 0;
}