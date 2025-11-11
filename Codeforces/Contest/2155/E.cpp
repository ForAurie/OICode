#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k, x, y;
    cin >> n >> m >> k;
    if (n == 1) {
        int sum = 0;
        while (k--) {
            cin >> x >> y;
            if (y == 2) sum ^= 1;
        }
        if (sum) cout << "Mimo\n";
        else cout << "Yuyu\n";
    } else {
        unordered_map<int, bool> mp;
        while (k--) {
            cin >> x >> y;
            if (y > 1) mp[y] ^= 1;
        }
        bool flag = false;
        for (const auto& i : mp)
            flag |= i.second;
        if (flag) cout << "Mimo\n";
        else cout << "Yuyu\n";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}