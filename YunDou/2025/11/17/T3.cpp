#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
constexpr int N = 2e5 + 10, D = 63;
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
vector<ull> ans;
int calc(int x, int y, int d, ull v) {
    if (d == -1) {
        ans.push_back(v);
        sz1[x]--, sz2[y]--;
        return 1;
    }
    int sum = 0;
    if (sz1[tr1[x][0]] && sz2[tr2[y][0]] && sz1[tr1[x][1]] && sz2[tr2[y][1]]) {
        sum += calc(tr1[x][0], tr2[y][0], d - 1, v), sum += calc(tr1[x][1], tr2[y][1], d - 1, v);
    } else if (sz1[tr1[x][0]] && sz2[tr2[y][0]]) {
        sum = calc(tr1[x][0], tr2[y][0], d - 1, v);
    } else if (sz1[tr1[x][1]] && sz2[tr2[y][1]]) {
        sum = calc(tr1[x][1], tr2[y][1], d - 1, v);
    } else {
        int a = (sz1[tr1[x][0]] ? tr1[x][0] : tr1[x][1]), b = (sz2[tr2[y][0]] ? tr2[y][0] : tr2[y][1]);
        sum = calc(a, b, d - 1, v | (1ull << d));
    }
    sz1[x] -= sum;
    sz2[y] -= sum;
    return sum;
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
    int n;
    read(n);
    vector<ull> a(n), b(n);
    for (auto& i : a) { read(i); if (i) { TOP = max(TOP, 63 - __builtin_clzll(i)); } }
    for (auto& i : b) { read(i); if (i) { TOP = max(TOP, 63 - __builtin_clzll(i)); } }
    for (const auto& i : a) insert(i, tr1, sz1, idx1, 1);
    for (const auto& i : b) insert(i, tr2, sz2, idx2, 1);
    pre1(1);
    pre2(1);
    while (sz1[1]) { calc(1, 1, TOP, 0); }
    sort(ans.begin(), ans.end());
    for (auto& i : ans) cout << i << " ";
    return 0;
}