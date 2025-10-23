#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, x;
    cin >> n >> k;
    vector<int> cnt(n + 1);
    while (n--) {
        cin >> x;
        ++cnt[x];
    }
    int ans = 0;
    for (int i = 0; i < k; i++)
        ans += !cnt[i];
    cout << max(ans, cnt[k]) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}