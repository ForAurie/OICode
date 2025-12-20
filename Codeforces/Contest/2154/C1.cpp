#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 10;
int n, a[N], b[N], mk[N], c[N];
vector<int> ps[N];
void solve() {
    cin >> n;
    int ans = (int) 2e9 + 10;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j : ps[a[i]]) {
            if (mk[j]) ans = 0;
            mk[j]++;
        }
    }
    vector<int> ord(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin() + 1, ord.end(), [&](int x, int y) { return b[x] < b[y]; });
    ans = min(ans, b[ord[1]] + b[ord[2]]);
    for (int i = 1; i <= n; i++) {
        for (int j : ps[a[i]]) mk[j]--;
        for (int j : ps[a[i] + 1])
            if (mk[j]) ans = min(ans, b[i]);
        for (int j : ps[a[i]]) mk[j]++;
    }
    for (int i = 1; i <= n; i++) {
        if (i == ord[1]) continue;
        for (int j : ps[a[i]]) {
            ans = min((long long) ans, (long long)(j - (a[ord[1]] % j)) % j * b[ord[1]]);
        }
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++)
        for (int j : ps[a[i]]) mk[j] = 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    const int V = 200001;
    for (int i = 2; i <= V; i++) {
        if (ps[i].size()) continue;
        for (int j = i; j <= V; j += i)
            ps[j].push_back(i);
    }
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}