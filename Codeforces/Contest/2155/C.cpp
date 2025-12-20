#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, times = 1;
    cin >> n;
    vector<int> a(n + 1), mk(n + 1, -1), now(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i > 1) {
            if (abs(a[i] - a[i - 1]) > 1) times = 0;
            else if (a[i] - a[i - 1] == 1) mk[i] = mk[i - 1] = 1;
            else if (a[i] - a[i - 1] == -1) mk[i] = mk[i - 1] = 0;
        }
    }
    int ans = 0, last, sum;
    bool flag;
    mk[1] = 1; flag = true;
    last = sum = 0;
    for (int i = 1; i <= n; i++) {
        if (~mk[i]) now[i] = mk[i];
        else now[i] = now[i - 1] ^ 1;
    }
    for (int i = 1; i <= n; i++) sum += (now[i] ^ 1);
    for (int i = 1; i <= n; i++) {
        sum -= (now[i] ^ 1);
        if (a[i] != last + sum + 1) {
            flag = false;
            break;
        }
        last += now[i];
    }
    ans += flag;
    mk[1] = 0; flag = true;
    last = sum = 0;
    for (int i = 1; i <= n; i++) {
        if (~mk[i]) now[i] = mk[i];
        else now[i] = now[i - 1] ^ 1;
    }
    for (int i = 1; i <= n; i++) sum += (now[i] ^ 1);
    for (int i = 1; i <= n; i++) {
        sum -= (now[i] ^ 1);
        if (a[i] != last + sum + 1) {
            flag = false;
            break;
        }
        last += now[i];
    }
    ans += flag;
    cout << ans * times << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}