#include <bits/stdc++.h>

using namespace std;

inline int calc(int l, int r, int ll, int rr) {
    return max(0, min(r, rr) - max(l, ll) + 1);
}
constexpr int N = 2e5 + 10;
int mk[N], a[N];

void solve() {
    int n, k, l, r;
    cin >> n >> k >> l >> r;
    vector<int> as;
    for (int i = 1; i <= n; i++) cin >> a[i], as.push_back(a[i]);
    sort(as.begin(), as.end());
    as.erase(unique(as.begin(), as.end()), as.end());
    function<int(int)> id = [&as = as](int v) { return lower_bound(as.begin(), as.end(), v) - as.begin() + 1; };
    for (int i = 1; i <= n; i++) a[i] = id(a[i]);
    vector<int> c(n + 1);
    function<void(int, int)> addT = [&c](int x, int v) { while (x < (int) c.size()) c[x] += v, x += x & -x; };
    function<int(int)> query = [&c](int x) { int res = 0; while(x) { res += c[x]; x ^= x & -x; } return res; };
    function<void(int, int)> add = [&](int l, int r) { addT(l, 1), addT(r + 1, -1); };
    int st = 1, ed = 1;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        add(mk[a[i]] + 1, i);
        // cout << "add " << mk[a[i]] + 1 << " to " << i << end 
        // cout << endl;
        while (st <= i && query(st) > k) st++;
        while (ed <= i && query(ed) >= k) ed++;
        if (ed == i && query(ed) == k) ed++;
        // cout << i << ' ' << st << ' ' << ed;
        if (query(st) == k)
            // cout << " true" << endl,
            ans += calc(st, ed - 1, i - r + 1, i - l + 1);
        // else cout << " false" << endl;
        mk[a[i]] = i;
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++) mk[a[i]] = 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}