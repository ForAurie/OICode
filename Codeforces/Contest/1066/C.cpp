#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, q, c, l, r;
    vector<array<int, 3>> qs;
    cin >> n >> k >> q;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= q; i++) {
        cin >> c >> l >> r;
        qs.push_back({c, l, r});
        if (c == 1) {
            for (int i = l; i <= r; i++) {
                a[i] = 1;
            }
        } else {
            for (int i = l; i <= r; i++) {
                b[i] = 1;
            }
        }
    }
    vector<int> ans(n + 1, -1);
    sort(qs.begin(), qs.end(), [](auto &x, auto &y) {
        return x[1] < y[1];
    });
    for (auto [c, l, r] : qs) {
        if (c == 1) {
            int cnt = 0;
            for (int i = l; i <= r; i++)
                cnt += (ans[i] == k);
            if (cnt == 0) {
                for (int i = l; i <= r; i++) {
                    if (a[i] && b[i]) continue;
                    if (ans[i] == -1) {
                        ans[i] = k;
                        break;
                    }
                }
            }
        } else {
            vector<int> mk(k);
            for (int i = l; i <= r; i++) {
                if (ans[i] == -1 || a[i] >= k) continue;
                mk[ans[i]] = 1;
            }
            stack<int> st;
            for (int i = 0; i < k; i++) {
                if (mk[i] == 0) st.push(i);
            }
            for (int i = l; i <= r; i++) {
                if (a[i] && b[i]) continue;
                if (st.empty()) break;
                if (ans[i] == -1) {
                    ans[i] = st.top();
                    st.pop();
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << (ans[i] == -1 ? k + 1 : ans[i]) << " ";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}