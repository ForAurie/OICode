#include <bits/stdc++.h>

using namespace std;

int ask(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    int res;
    cin >> res;
    return res;
}
int n;
int calc(vector<pair<int, int>>& a) {
    if (a.size() <= 2) {
        int mx = 0;
        for (const auto &i : a) mx = max(mx, ask(i.first, i.second));
        return mx;
    }
    int mid = a.size() >> 1;
    int x = ask(1, a[mid].second), y = ask(a[mid].first, n);
    if (x < y) {
        a.erase(a.begin(), a.begin() + mid);
    } else if (y < x) {
        a.erase(a.begin() + mid + 1, a.end());
    } else return x;
    return calc(a);
}
/*
4 3

1 2
2 4
1 3

0 3 1 2
*/
void solve() {
    int q;
    cin >> n >> q;
    vector<pair<int, int>> qs(q);
    for (auto &i : qs) cin >> i.first >> i.second, i.second = -i.second;
    sort(qs.begin(), qs.end());
    qs.erase(unique(qs.begin(), qs.end()), qs.end());
    for (auto &i : qs) i.second = -i.second;
    vector<pair<int, int>> uqs;
    uqs.push_back(qs.front());
    for (int i = 1; i < qs.size(); i++) {
        if (uqs.back().second >= qs[i].second) continue;
        uqs.push_back(qs[i]);
    }
    // for (auto& i : uqs) cout << i.first << ' ' << i.second << endl;
    auto ans = calc(uqs);
    cout << "! " << ans << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}