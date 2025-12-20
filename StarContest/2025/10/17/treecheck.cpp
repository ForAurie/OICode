#include <bits/stdc++.h>

using namespace std;
int n, x, y, f[210000];
int find(int x) { return f[x] == x ? x : (f[x] = find(f[x])); }
int main() {
    freopen("tree4.in", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x <= 0 || x > n) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        if (x <= n && y <= n && x >= 1 && y >= 1);
        else {
            cout << "NO1" << endl;
            return 0;
        }
        if (find(x) == find(y)) {
            cout << "NO1" << endl;
            return 0;
        }
        f[find(x)] = find(y); 
    }
    cout << "YES" << endl;
    return 0;
}
