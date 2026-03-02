#include <bits/stdc++.h>
using namespace std;
void init(vector<int>& a) {
    vector<int> res;
    set<int> s;
    for (int i : a) {
        if (s.count(i)) continue;
        res.push_back(i);
        s.insert(i);
    }
    swap(res, a);
}
void out(vector<int>& x) { for (int i : x) cout << i << ' '; }
bool mk[1000010];
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (auto& i : a) {
        static int m;
        cin >> m;
        i.resize(m);
        for (int& j : i) cin >> j;
        reverse(i.begin(), i.end());
        init(i);
    }
    while (a.size()) {
        int p = 0;
        for (int i = 1; i < a.size(); i++)
            if (a[i] < a[p]) p = i;
        out(a[p]);
        auto tmp = a[p];
        a.erase(a.begin() + p);
        for (int i : tmp) mk[i] = 1;
        vector<vector<int>> x;
        for (auto& i : a) {
            vector<int> t;
            for (int j : i) {
                if (mk[j]) continue;
                t.push_back(j);
            }
            x.push_back(t);
        }
        swap(x, a);
        for (int i : tmp) mk[i] = 0;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}