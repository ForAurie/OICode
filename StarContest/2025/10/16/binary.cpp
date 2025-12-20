<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;
inline void out1(int x) { while (x--) cout << '1'; }
inline void out0(int x) { while (x--) cout << '0'; }
void solve() {
    int n, m;
    cin >> n >> m;
    if (n & 1) {
        if (n == 1 || m <= 1) {
            cout << "-1\n-1";
            return;
        }
        // n >= 3; m >= 2;
        out1(n - 2), out0(1), out1(1), out0(1), out1(1), out0(m - 2);
    } else out1(n), out0(m);
    cout << '\n';
    int res = 1;
    for (int i = 1; i <= m; i++) res <<= 1, res %= 3;
    for (int i = 1; i < n; i++) res <<= 1, res %= 3, res++, res %= 3;
    if (res == 0) {
        out1(1), out0(m), out1(n - 1);
        return;
    }
    res = 1;
    for (int i = 1; i < m; i++) res <<= 1, res %= 3;
    res <<= 1, res %= 3, res++, res %= 3;
    res <<= 1, res %= 3;
    for (int i = 1; i <= n - 2; i++) res <<= 1, res %= 3, res++, res %= 3;
    if (res == 0) {
        out1(1), out0(m - 1), out1(1), out0(1), out1(n - 2);
    } else {
        out1(1), out0(m - 2), out1(1), out0(1), out1(1), out0(1), out1(n - 3);
    }
    // 1 > 1
    // 10000000111111111 随意
    // 10000001011111111 0 >= 1
    // 100000101011111111 0 > 1 1 > 2
}

int main() {
    // cout << (0b1000001111) % 3 << endl;
    // for (int i = 1; i <= 20; i++) cout << (1 << i) % 3 << endl;
    freopen("binary.in", "r", stdin);
    freopen("binary.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve(), cout << '\n';
=======
#include <bits/stdc++.h>

using namespace std;
inline void out1(int x) { while (x--) cout << '1'; }
inline void out0(int x) { while (x--) cout << '0'; }
void solve() {
    int n, m;
    cin >> n >> m;
    if (n & 1) {
        if (n == 1 || m <= 1) {
            cout << "-1\n-1";
            return;
        }
        // n >= 3; m >= 2;
        out1(n - 2), out0(1), out1(1), out0(1), out1(1), out0(m - 2);
    } else out1(n), out0(m);
    cout << '\n';
    int res = 1;
    for (int i = 1; i <= m; i++) res <<= 1, res %= 3;
    for (int i = 1; i < n; i++) res <<= 1, res %= 3, res++, res %= 3;
    if (res == 0) {
        out1(1), out0(m), out1(n - 1);
        return;
    }
    res = 1;
    for (int i = 1; i < m; i++) res <<= 1, res %= 3;
    res <<= 1, res %= 3, res++, res %= 3;
    res <<= 1, res %= 3;
    for (int i = 1; i <= n - 2; i++) res <<= 1, res %= 3, res++, res %= 3;
    if (res == 0) {
        out1(1), out0(m - 1), out1(1), out0(1), out1(n - 2);
    } else {
        out1(1), out0(m - 2), out1(1), out0(1), out1(1), out0(1), out1(n - 3);
    }
    // 1 > 1
    // 10000000111111111 随意
    // 10000001011111111 0 >= 1
    // 100000101011111111 0 > 1 1 > 2
}

int main() {
    // cout << (0b1000001111) % 3 << endl;
    // for (int i = 1; i <= 20; i++) cout << (1 << i) % 3 << endl;
    freopen("binary.in", "r", stdin);
    freopen("binary.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve(), cout << '\n';
>>>>>>> origin/main
}