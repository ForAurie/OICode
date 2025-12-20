#include <bits/stdc++.h>
#define lg2ll(x) (63 - __builtin_clzll(x))
using namespace std;

bool check(long long x, long long y, int d) {
    const long long xx = x & ((1ll << d) - 1);
    x >>= d;
    long long need = y - x;
    if (need < 0 || need > 1) return false;
    return (xx > 0) >= need;
}

void out(long long x) {
    while (x) {
        cerr << (x & 1);
        x >>= 1;
    }
}
/*
1110010110001000011000011101000010000100010111010001011111
11
*/
int id = 0;
void solve() {
    long long x, y;
    cin >> x >> y;
    // if (++id == 371) out(x), cerr<< ' ', out(y), cerr << endl;
    if (y == 0) {
        cout << "YES\n";
        return;
    }
    if (x < y || x == 0) {
        cout << "NO\n";
        return;
    }
    const int d = lg2ll(x) - lg2ll(y);
    if (check(x, y, d) || check(x, y, d + 1)) cout << "YES\n";
    else cout << "NO\n";
}
int main() {
    freopen("todo.in", "r", stdin);
    freopen("todo.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}