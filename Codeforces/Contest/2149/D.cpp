#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    s = ' ' + s;
    vector<long long> ans1(n + 2), ans2(n + 2);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'a') {
            const int p = i - cnt;
            ans1[p + 1]++;
            ans2[p - 1]++;
            ++cnt;
        }
    }
    for (int i = 1; i <= n; i++) ans1[i] += ans1[i - 1];
    for (int i = 1; i <= n; i++) ans1[i] += ans1[i - 1];
    for (int i = n; i >= 1; i--) ans2[i] += ans2[i + 1];
    for (int i = n; i >= 1; i--) ans2[i] += ans2[i + 1];
    long long ans = 0x3f3f3f3f3f3f3f3fll;
    for (int i = 1; i + cnt - 1 <= n; i++)
        ans = min(ans, ans1[i] + ans2[i]);
    ans1.clear(), ans2.clear();
    ans1.resize(n + 2), ans2.resize(n + 2);
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'b') {
            const int p = i - cnt;
            ans1[p + 1]++;
            ans2[p - 1]++;
            ++cnt;
        }
    }
    for (int i = 1; i <= n; i++) ans1[i] += ans1[i - 1];
    for (int i = 1; i <= n; i++) ans1[i] += ans1[i - 1];
    for (int i = n; i >= 1; i--) ans2[i] += ans2[i + 1];
    for (int i = n; i >= 1; i--) ans2[i] += ans2[i + 1];
    for (int i = 1; i + cnt - 1 <= n; i++)
        ans = min(ans, ans1[i] + ans2[i]);
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}