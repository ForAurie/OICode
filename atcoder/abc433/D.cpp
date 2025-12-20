#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 10;
inline int lg10(int x) {
    int cnt = 0;
    while (x) {
        cnt++;
        x /= 10;
    }
    return cnt;
}
map<int, int> mp[11];
int a[N], n, m, pow10[11];
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[lg10(a[i])][a[i] % m]++;
    }
    long long ans = 0;
    pow10[0] = 1;
    for (int i = 1; i <= 10; i++)
        pow10[i] = (pow10[i - 1] * 10ll) % m;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 10; j++) {
            int tmp = m - (ll) pow10[j] * a[i] % m;
            tmp %= m;
            ans += mp[j][tmp];
        }
    }
    cout << ans << endl;
    return 0;
}