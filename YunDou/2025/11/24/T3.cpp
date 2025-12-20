#include <bits/stdc++.h>
using namespace std;
constexpr int Q = 1e6 + 10, N = 2e3 + 10, V = 1e5 + 1;
int n, q;
bool ans[Q];
struct obj {
    int x, y, c;
    bool operator<(const obj& o) const {
        return x < o.x;
    }
};
struct query {
    int x, y, k, id;
    bool operator<(const query& o) const {
        return x < o.x;
    }
};
vector<int> xs;
int val(int x) {
    if (x == 0) return -0x3f3f3f3f;
    else if (x > (int) xs.size()) return 0x3f3f3f3f;
    return xs[x - 1];
}
int id(int x) {
    return lower_bound(xs.begin(), xs.end(), x) - xs.begin() + 1;
}
bitset<V> dp;
int main() {
    freopen("bag.in", "r", stdin);
    freopen("bag.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    vector<obj> a;
    vector<query> qs;
    int c, x, y, k;
    for (int i = 1; i <= n; i++) {
        cin >> c >> x >> y;
        a.push_back({x, y, c});
        xs.push_back(x);
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    cin >> q;
    int mxk = 0;
    for (int i = 1; i <= q; i++) {
        cin >> k >> x >> y;
        mxk = max(mxk, k);
        qs.push_back({x, y, k, i});
    }
    sort(qs.begin(), qs.end());
    sort(a.begin(), a.end());
    int idx = 0;
    for (int i = 1; i <= (int) xs.size(); i++) {
        auto st = lower_bound(qs.begin(), qs.end(), (query){val(i), 0, 0});
        auto ed = lower_bound(qs.begin(), qs.end(), (query){val(i + 1), 0, 0});
        vector<query> nq;
        for (auto it = st; it != ed; it++) nq.push_back(*it);
        while (idx < (int) a.size() && a[idx].x <= val(i)) idx++;
        if (idx == 0) continue;
        vector<pair<int, int>> tmp;
        for (int j = 0; j < idx; j++) {
            tmp.push_back(make_pair(a[j].y, a[j].c));
        }
        sort(tmp.begin(), tmp.end(), greater<pair<int, int>>());
        auto cmp = [&](const query& x, const query& y) { return x.y > y.y; };
        sort(nq.begin(), nq.end(), cmp);
        int idx1 = 0;
        dp.reset();
        dp[0] = 1;
        for (const auto& j : nq) {
            while (idx1 < (int) tmp.size() && tmp[idx1].first >= j.y) {
                dp |= dp << tmp[idx1].second;
                idx1++;
            }
            ans[j.id] = dp[j.k];
        }
    }
    for (int i = 1; i <= q; i++) {
        if (ans[i]) cout << "Yes\n";
        else cout << "No\n";
    }
    cerr << (double) clock() / CLOCKS_PER_SEC << endl;
    return 0;
}