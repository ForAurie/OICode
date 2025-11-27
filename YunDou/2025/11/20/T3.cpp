#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1e5 + 10;
int n, m, d[N], f[N], sz[N], es[N], cnt[N], cnt1[N];
int find(int x) { return f[x] == x ? x : (f[x] = find(f[x])); }
int main() {
    freopen("double3.in", "r", stdin);
    freopen("double.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) f[i] = i, sz[i] = 1;
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        d[x]++, d[y]++;
        x = find(x), y = find(y);
        if (x != y) f[x] = y, sz[y] += sz[x], es[y] += es[x];
        es[y]++;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] & 1) ans++, cnt[find(i)]++, cnt1[find(i)]++;
    }
    for (int i = 1; i <= n; i++) cnt1[i] >>= 1, cnt[i] += cnt1[i];
    ans >>= 1;
    vector<int> t1, t2;
    for (int i = 1; i <= n; i++) {
        x = find(i);
        if (!cnt[x]) t2.push_back(x);
        else if (es[x] & 1) t1.push_back(x);
    }
    sort(t1.begin(), t1.end());
    t1.erase(unique(t1.begin(), t1.end()), t1.end());
    sort(t2.begin(), t2.end());
    t2.erase(unique(t2.begin(), t2.end()), t2.end());
    for (int i : t2)
        ans += (es[i] & 1);
    // cout << t2.size() << endl; 
    cout << ans + (t1.size() & 1) << endl;
}