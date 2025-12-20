#include <bits/stdc++.h>

using namespace std;
int B;
struct query {
    int l, r, id;
    query(int l = 0, int r = 0, int id = 0) : l(l), r(r), id(id) {}
    bool operator<(const query& o) const {
        const int x = l / B, y = o.l / B;
        return x < y || (x == y && ((x & 1) ? r > o.r : r < o.r));
    }
};

void solve() {
    int n, q, l, r;
    cin >> n >> q;
    B = n / sqrt(q);
    if (B == 0) B++;
    vector<int> a(n + 1), as;
    for (int i = 1; i <= n; i++) cin >> a[i], as.push_back(a[i]);
    sort(as.begin(), as.end());
    as.erase(unique(as.begin(), as.end()), as.end());
    function<int(int)> id = [&as = as] (int x) { return lower_bound(as.cbegin(), as.cend(), x) - as.cbegin() + 1; };
    function<int(int)> val = [&as = as] (int x) { return as[x - 1]; };
    for (int& i : a) i = id(i);
    vector<query> qs;
    vector<vector<int>> ans(q);
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        qs.emplace_back(l, r, i);
    }
    sort(qs.begin(), qs.end());
    vector<int> v(n + 1);
    function<void(int)> add = [&](int x) -> void {
        x = a[x];
        ++v[x];
    };
    function<void(int)> del = [&](int x) -> void {
        x = a[x];
        --v[x];
    };
    l = 1, r = 0;
    mt19937 gen(time(0));
    for (const auto& i : qs) {
        while (l > i.l) add(--l);
        while (r < i.r) add(++r);
        while (l < i.l) del(l++);
        while (r > i.r) del(r--);
        const int len = (r - l + 1) / 3;
        int cnt = 50, p;
        while (cnt--) {
            p = l + (gen() % (r - l + 1) + (r - l + 1)) % (r - l + 1);
            if (v[a[p]] > len) ans[i.id].push_back(a[p]);
        }
    }
    for (auto& i : ans) {
        if (i.empty()) cout << -1 << '\n';
        else {
            for (int& j : i) j = val(j);
            sort(i.begin(), i.end());
            i.erase(unique(i.begin(), i.end()), i.end());
            for (int j = 0; j < (int) i.size(); j++)
                cout << i[j] << " \n"[j + 1 == (int) i.size()];
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}