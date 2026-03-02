#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(n + m + 10);
    vector<int> a(n), b(m);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    for (int i : a)
        for (int j = i; j < cnt.size(); j += i) cnt[j]++;
    int ca = 0, cb = 0, c = 0;
    for (int i : b) {
        if (cnt[i] && cnt[i] != a.size()) c++;
        else if (cnt[i] == a.size()) ca++;
        else cb++;
    }
    if (c & 1) {
        if (cb > ca) cout << "Bob\n";
        else cout << "Alice\n";
    } else {
        if (ca > cb) {
            cout << "Alice\n";
        } else cout << "Bob\n";
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
