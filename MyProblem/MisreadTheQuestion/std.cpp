#include<bits/stdc++.h>
using namespace std;
inline bool check(const pair<int, int>& chk, int n) { return (chk.first == 0 && chk.second == 1) || (chk.first == 1 && chk.second == n); }
inline int ct(int i, int j, const vector<vector<int>>& mp, int n) {
    if (i < 1 || j > n) return 0;
    return (mp[0][i] + mp[1][i] == 1) && (mp[0][j] + mp[1][j] == 1) && (mp[0][i] != mp[0][j]);
}
int chkadd(const pair<int, int>& x, vector<vector<int>>& mp, int n) {
    int res = -ct(x.second - 1, x.second, mp, n) - ct(x.second, x.second + 1, mp, n);
    mp[x.first][x.second] = 1;
    return res + ct(x.second - 1, x.second, mp, n) + ct(x.second, x.second + 1, mp, n);
}
int chkdel(const pair<int, int>& x, vector<vector<int>>& mp, int n) {
    int res = -ct(x.second - 1, x.second, mp, n) - ct(x.second, x.second + 1, mp, n);
    mp[x.first][x.second] = 0;
    return res + ct(x.second - 1, x.second, mp, n) + ct(x.second, x.second + 1, mp, n);
}
// 9
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n + 1)), mp(2, vector<int>(n + 1));
    vector<vector<pair<int, int>>> find(2 * n + 1);
    vector<int> mk(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[0][i], find[a[0][i]].push_back(make_pair(0, i));
    for (int i = 1; i <= n; i++) cin >> a[1][i], find[a[1][i]].push_back(make_pair(1, i));
    int l = 1, cmk = 0, cnt = 0, flag = 0;
    long long ans = 0;
    for (int r = 1; r <= 2 * n; r++) {
        for (const auto &i : find[r]) {
            cnt += chkadd(i, mp, n);
            if (++mk[i.second] == 1) cmk++;
            flag += check(i, n);
        }
        while (l <= r && (flag == 2 && cmk == n && cnt == 0)) {
            for (const auto& i : find[l]) {
                cnt += chkdel(i, mp, n);
                if (--mk[i.second] == 0) cmk--;
                flag -= check(i, n);
            }
            l++;
        }
        ans += l - 1;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    solve();
    return 0;
}