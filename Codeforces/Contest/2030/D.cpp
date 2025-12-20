#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, q, x;
    cin >> n >> q;
    vector<int> find(n), no(n), cnt(n);
    int flag = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        x--;
        find[x] = i;
    }
    for (int i = 0; i < n; i++) {
        int st = find[i], ed = i;
        if (st > ed) swap(st, ed);
        no[st]++, no[ed]--;
    }
    for (int i = 1; i < n; i++)
        no[i] += no[i - 1];
    string s;
    cin >> s;
    auto add = [&](int x) -> void {
        if (s[x] == 'L' && x > 0) cnt[x - 1]++;
        else if (s[x] == 'R' && x + 1 < n) cnt[x]++;
    };
    auto del = [&](int x) -> void {
        if (s[x] == 'L' && x > 0) cnt[x - 1]--;
        else if (s[x] == 'R' && x + 1 < n) cnt[x]--;
    };
    for (int i = 0; i < n; i++)
        add(i);
    for (int i = 0; i + 1 < n; i++)
        if (no[i] && cnt[i] == 0) flag++;
    auto calc = [&](int x) -> int {
        return (x > 0 && (no[x - 1] && cnt[x - 1] == 0)) + (x + 1 < n && (no[x] && cnt[x] == 0));
    };
    while (q--) {
        cin >> x;
        x--;
        int d = -calc(x);
        del(x);
        if (s[x] == 'L') s[x] = 'R';
        else s[x] = 'L';
        add(x);
        d += calc(x);
        flag += d;
        if (flag == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}
// S125111214520444930V
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}