#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; string s;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    cin >> s;
    if (s.front() == '1' || s.back() == '1') {
        cout << "-1\n";
        return;
    }
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1 || a[i] == n) {
            res.push_back(i + 1);
            if (s[i] == '1') {
                cout << "-1\n";
                return;
            }
        }
    }
    cout << 5 << endl;
    cout << 1 << ' ' << res[0] << endl;
    cout << 1 << ' ' << res[1] << endl;
    cout << res[0] << ' ' << n << endl;
    cout << res[1] << ' ' << n << endl;
    cout << res[0] << ' ' << res[1] << endl; 
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}