#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 10;
int n, m, x, y, sz[N], f[N], es[N];
int find(int x) { return x == f[x] ? x : (f[x] = find(f[x])); }
int main() {
    freopen("coo.in", "r", stdin);
    freopen("coo.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) f[i] = i, sz[i] = 1;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        x = find(x), y = find(y);
        if (x != y) f[x] = y, sz[y] += sz[x], es[y] += es[x];
        es[y]++;
    }
    vector<int> xs;
    for (int i = 1; i <= n; i++)
        xs.push_back(find(i));
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    int ans = 0;
    for (int i : xs)
        ans += sz[i] - ((es[i] - sz[i]) & 1);
    cout << ans << endl;
    return 0;
}