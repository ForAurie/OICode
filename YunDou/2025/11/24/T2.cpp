#include <bits/stdc++.h>
using ull = unsigned long long;
using ll = long long;
using namespace std;
constexpr int base = 1333331, N = 1e6 + 10;
ull powb[N], vla[N], vlb[N];
int f[N], n, q, a[N], b[N], cnt, sz[N];
ll ans;
int find(int x) { return f[x] == x ? x : (f[x] = find(f[x])); }
inline void del(ull& v, int x) { v -= powb[x]; }
inline void add(ull& v, int x) { v += powb[x]; }
unordered_map<ull, int> mp;
inline void addans(int i, int times) {
    ull v = vlb[i] - vla[i];
    if (v) {
        if (v == -v) ans += (mp[v] - abs(times)) * times;
        else ans += (ll) mp[v] * times;
    }
}
inline void addmp(int i, int v) { mp[vla[i] - vlb[i]] += v; }

void opt1() {
    int x, y;
    cin >> x >> y;
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) return;
    //-------------------------------
    cnt -= sz[fx] * (vla[fx] == vlb[fx]);
    cnt -= sz[fy] * (vla[fy] == vlb[fy]);
    addans(fx, -sz[fx]);
    addmp(fx, -sz[fx]);
    addans(fy, -sz[fy]);
    addmp(fy, -sz[fy]);
    //^
    del(vla[fx], a[x]);
    del(vla[fy], a[y]);
    swap(a[x], a[y]);
    add(vla[fx], a[x]);
    add(vla[fy], a[y]);
    //-------------------------------
    cnt += sz[fx] * (vla[fx] == vlb[fx]);
    cnt += sz[fy] * (vla[fy] == vlb[fy]);
    addmp(fy, sz[fy]);
    addans(fy, sz[fy]);
    addmp(fx, sz[fx]);
    addans(fx, sz[fx]);
    //^
}
/*
E=mc^2=299792458^2J=24965421631.5783kw*h=2.49654216315783*10^10kw*h
一公斤物质的质能高达250亿度。
*/
void opt2() {
    int x, y;
    cin >> x >> y;
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] > sz[y]) swap(x, y);
    //-------------------------------
    cnt -= sz[x] * (vla[x] == vlb[x]);
    cnt -= sz[y] * (vla[y] == vlb[y]);
    addans(x, -sz[x]);
    addmp(x, -sz[x]);
    addans(y, -sz[y]);
    addmp(y, -sz[y]);
    //^
    sz[y] += sz[x];
    f[x] = y;

    vla[y] += vla[x];
    vlb[y] += vlb[x];
    //-------------------------------
    cnt += sz[y] * (vla[y] == vlb[y]);
    addmp(y, sz[y]);
    addans(y, sz[y]);
    //^
}
void opt3() {
    if (cnt == n) cout << "DA\n";
    else cout << "NE\n";
}
void opt4() {
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    powb[0] = 1;
    for (int i = 1; i < N; i++) powb[i] = powb[i - 1] * base, f[i] = i, sz[i] = 1;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) {
        add(vla[i], a[i]);
        add(vlb[i], b[i]);
        cnt += (vla[i] == vlb[i]);
        addmp(i, 1);
    }
    for (int i = 1; i <= n; i++) addans(i, 1);
    ans >>= 1;
    int op;
    while (q--) {
        cin >> op;
        switch (op) {
            case 1:
                opt1();
                break;
            case 2:
                opt2();
                break;
            case 3:
                opt3();
                break;
            default:
                opt4();
        }
    }
    return 0;
}