#include <bits/stdc++.h>

using namespace std;
constexpr int N = 5e5 + 10;
int n, q, a[N], l, r;

int calc(const vector<int>& tmp) {
    unordered_set<int> s;
    for (int i : tmp) s.insert(i);
    if (s.size() == tmp.size()) return 0;
    vector<int> t0, t1;
    for (int i = 0; i < tmp.size(); i++) {
        if (i & 1) t1.push_back(tmp[i]);
        else t0.push_back(tmp[i]);
    }
    return calc(t0) + calc(t1) + 1;
}
map<pair<int, int>, int> temp;
int main() {
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    bool flag1 = true;
    for (int i = 1; i <= n; i++) cin >> a[i], flag1 = flag1 && (a[i] == 1);
    cin >> q;
    if (flag1) {
        vector<int> ans(n + 1);
        ans[1] = 0;
        for (int i = 2; i <= n; i++)
            ans[i] = ans[i / 2] + ans[(i + 1) / 2] + 1;
        while (q--) {
            cin >> l >> r;
            cout << ans[r - l + 1] << '\n';
        }
        return 0;
    }
    while (q--) {
        cin >> l >> r;
        if (temp.count(make_pair(l, r))) {
            cout << temp[make_pair(l, r)] << '\n';
            continue;
        }
        vector<int> tmp;
        for (int i = l; i <= r; i++) tmp.push_back(a[i]);
        int ans = calc(tmp);
        temp[make_pair(l, r)] = ans;
        cout << ans << '\n';
    }
    return 0;
}