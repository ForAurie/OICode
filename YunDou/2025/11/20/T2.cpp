#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    const int n = s.length();
    vector<int> a(n + 10), nxt(n + 10), mk(n + 10);
    for (int i = 1; i <= n; i++) {
        a[i] = s[i - 1] ^ 0x30 ^ 1;
        // a[i] += a[i - 1];
    }
    for (int i = n; i >= 1; i--) {
        if (a[i] == 0) nxt[i] = i;
        else nxt[i] = nxt[i + 1];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) mk[a[i - 1] + 1] = i;
        a[i] += a[i - 1];
    }
    function<int(int, int)> find = [&](int st, int len) {
        int p = a[st - 1] + len;
        if (p > n) return 0;
        return mk[p];
        // int l = st, r = n, mid;
        // st--;
        // while (l < r) {
        //     mid = (l + r) >> 1;
        //     if (a[mid] - a[st] >= len) r = mid;
        //     else l = mid + 1;
        // }
        // if (a[l] - a[st] == len) return l;
        // else return 0;
    };
    function<int(int)> calc = [&](int len) {
        int now = 1;
        int cnt = 0;
        while (true) {
            now = find(now, len);
            if (!now) break;
            cnt++;
            now = nxt[now];
            if (!now) break;
        }
        if (cnt <= 1) return 0;
        return cnt * len + cnt - 1;
    };
    int mx = -1, ans = -1;
    for (int i = 1; i * 2 <= n; i++) {
        int tmp = calc(i);
        if (tmp) {
            if (tmp > mx) {
                mx = tmp;
                ans = i;
            }
        }
    }
    cout << mx << " " << ans << "\n";
}

int main() {
    freopen("rabbit.in", "r", stdin);
    freopen("rabbit.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}