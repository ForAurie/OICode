#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        int x, y;
        cin >> x >> y;
        if (y * 2 < x || x * 2 < y) {
            cout << -1 << endl;
            return;
        }
        {
            int l1 = 1, l2 = -1;
            while (x || y) {
                if ((l1 == 1 && l2 == 1) || x == 0) {
                    cout << 2 << ' ';
                    l2 = l1;
                    l1 = 2;
                    y--;
                    continue;
                }
                if (y > (x - 1) * 2 + 1) {
                    cout << 2 << ' ';
                    l2 = l1;
                    l1 = 2;
                    y--;
                } else {
                    cout << 1 << ' ';
                    l2 = l1;
                    l1 = 1;
                    x--;
                }
            }
            cout << endl;
        }
        return;
    } else {
        int p = 0;
        for (int i = 1; i <= n; i++) cin >> p;
        for (int i = 1; i <= n; i++) {
            cout << i << ' ' ;
        }
        cout << endl;
    }
}
int main() {
    freopen("permutation.in", "r", stdin);
    freopen("permutation.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}