#include <bits/stdc++.h>
using namespace std;
constexpr int V = 3e6, N = V + 10, mod = 500009;
int cnt[N], ans[N], mp[N];
int main() {
    freopen("ball.in", "r", stdin);
    freopen("ball.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i = 1; i <= V; i++)
        for (int j = i; j <= V; j += i)
            cnt[j]++;
    // int mn = 0x3f3f3f3f, cnt = 0;
    // for (int i = 1; i <= 2000; i++) {
    //     cnt += !mp[i].empty();
    //     if (mp[i].size() < mod) continue;
    //     mn = min(mn, mp[i][mod - 1]);
    // }
    // cout << mn << ':' << cnt << endl;
    // 2229283:114
    ans[1] = 1;
    for (int i = 2; i <= V; i++)
        ans[i] = (long long) ans[i - 1] * (++mp[cnt[i]]) % mod;
    int n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n <= 3e6) cout << ans[n] << '\n';
        else cout << "0\n";
    }
    return 0;
}