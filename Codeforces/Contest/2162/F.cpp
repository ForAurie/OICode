<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;
int l[5090], r[5090], m;

bool check01(int x) {
    for (int j = 1; j <= m; j++)
        if (((l[j] <= x && x <= r[j]) & (l[j] <= x + 1 && x + 1 <= r[j])) != (l[j] <= x && x <= r[j])) return false;
    return true;
}

bool check10(int x) {
    for (int j = 1; j <= m; j++)
        if (((l[j] <= x && x <= r[j]) & (l[j] <= x + 1 && x + 1 <= r[j])) != (l[j] <= x + 1 && x + 1 <= r[j])) return false;
    return true;
}

void solve() {
    int n, ll = -0x3f3f3f3f, rr = 0x3f3f3f3f;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> l[i] >> r[i], ll = max(ll, l[i]), rr = min(rr, r[i]);
    if (ll <= rr) {
        int d = 0;
        for (int i = 1; i <= n; i++) {
            if (i == ll) cout << 0 << ' ', d = 1;
            else cout << i - d << ' ';
        }
        cout << endl;
        return;
    }
    
    for (int i = 1; i < n; i++) {
        if (check01(i)) {
            for (int j = 1; j < i; j++) cout << j + 1 << ' ';
            cout << 0 << ' ' << 1 << ' ';
            for (int j = i + 2; j <= n; j++) {
                cout << j - 1 << ' ';
            }
            cout << endl;
            return;
        } else if (check10(i)) {
            for (int j = 1; j < i; j++) cout << j + 1 << ' ';
            cout << 1 << ' ' << 0 << ' ';
            for (int j = i + 2; j <= n; j++) {
                cout << j - 1 << ' ';
            }
            cout << endl;
            return;
        }
    }
    // } else {
        cout << 0 << ' ' << 2 << ' ' << 1 << ' ';
        for (int i = 3; i < n; i++) {
            cout << i << ' ';
        }
    // }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
=======
#include <bits/stdc++.h>

using namespace std;
int l[5090], r[5090], m;

bool check01(int x) {
    for (int j = 1; j <= m; j++)
        if (((l[j] <= x && x <= r[j]) & (l[j] <= x + 1 && x + 1 <= r[j])) != (l[j] <= x && x <= r[j])) return false;
    return true;
}

bool check10(int x) {
    for (int j = 1; j <= m; j++)
        if (((l[j] <= x && x <= r[j]) & (l[j] <= x + 1 && x + 1 <= r[j])) != (l[j] <= x + 1 && x + 1 <= r[j])) return false;
    return true;
}

void solve() {
    int n, ll = -0x3f3f3f3f, rr = 0x3f3f3f3f;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> l[i] >> r[i], ll = max(ll, l[i]), rr = min(rr, r[i]);
    if (ll <= rr) {
        int d = 0;
        for (int i = 1; i <= n; i++) {
            if (i == ll) cout << 0 << ' ', d = 1;
            else cout << i - d << ' ';
        }
        cout << endl;
        return;
    }
    
    for (int i = 1; i < n; i++) {
        if (check01(i)) {
            for (int j = 1; j < i; j++) cout << j + 1 << ' ';
            cout << 0 << ' ' << 1 << ' ';
            for (int j = i + 2; j <= n; j++) {
                cout << j - 1 << ' ';
            }
            cout << endl;
            return;
        } else if (check10(i)) {
            for (int j = 1; j < i; j++) cout << j + 1 << ' ';
            cout << 1 << ' ' << 0 << ' ';
            for (int j = i + 2; j <= n; j++) {
                cout << j - 1 << ' ';
            }
            cout << endl;
            return;
        }
    }
    // } else {
        cout << 0 << ' ' << 2 << ' ' << 1 << ' ';
        for (int i = 3; i < n; i++) {
            cout << i << ' ';
        }
    // }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
>>>>>>> origin/main
}