#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n;
    int cnt0 = 0, cnt = 0;
    while (n--) {
        cin >> x;
        cnt0 += (x == 0);
        cnt += (x == -1);
    }
    cout << cnt0 + (cnt & 1) * 2 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}