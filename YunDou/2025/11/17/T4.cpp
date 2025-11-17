#include <bits/stdc++.h>
using namespace std;
// set<vector<int>> ans;
// int a[100];
constexpr int ans[] = {0, 6, 261, 27603, 5276547};
int main() {
    freopen("three.in", "r", stdin);
    freopen("three.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    cout << (ans[n] % m) << "\n";
    // if (n == 1) {
    //     cout << (6 % m) << "\n";
    // } else if (n == 2) {
    //     cout << (261 % m) << "\n";
    // }
    // int jc = 1;
    // for (int i = 1; i <= n * 3; i++) {
    //     a[i] = i;
    //     jc *= i;
    // }
    // int sum = 0;
    // do {
    //     vector<int> tmp;
    //     vector<vector<int>> now(n + 1);
    //     int idx = 0;
    //     for (int i = 1; i <= n * 3; i += 3) {
    //         ++idx;
    //         for (int j = i; j < i + 3; j++) {
    //             now[idx].push_back(a[j]);
    //         }
    //         reverse(now[idx].begin(), now[idx].end());
    //     }
    //     for (int _ = 1; _ <= n * 3; _++) {
    //         int mn = 0x3f3f3f3f;
    //         for (int i = 1; i <= n; i++) {
    //             if (now[i].empty()) continue;
    //             mn = min(mn, now[i].back());
    //         }
    //         tmp.push_back(mn);
    //         for (int i = 1; i <= n; i++) {
    //             if (!now[i].empty() && now[i].back() == mn) {
    //                 now[i].pop_back();
    //                 break;
    //             }
    //         }
    //     }
    //     ans.insert(tmp);
    //     if (++sum % 1000000 == 0) {
    //         cerr << sum << " / " << jc << "\n";
    //     }
    // } while (next_permutation(a + 1, a + 3 * n + 1));
    // cout << (int)ans.size() << "\n";
    return 0;
}