#include <bits/stdc++.h>
using namespace std;
bool solve(int i, int c, string &s, string &t) {
    auto s0 = s.find('0'), s1 = s.find('1'), t0 = t.find('0'), t1 = t.find('1');
    if (s0 == string::npos && t0 == string::npos) return false;
    if (s1 == string::npos && t1 == string::npos) return false;
    if (c == 0) {
        if (s0 != string::npos && t1 != string::npos) cout << t1 + i << ' ' << s0 + i << '\n';
        else cout << i << ' ' << i << '\n';
    } else {
        if (t0 != string::npos && s1 != string::npos) cout << t0 + i << ' ' << s1 + i << '\n';
        else cout << i << ' ' << i << '\n';
    }
    return true;
}
void solve1() {
    int n, c; cin >> n >> c;
    vector<string> a(n + 10);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = " " + a[i];
    }
    for (int i = 1; i < n; i++) {
        string s, t;
        for (int j = i; j <= n; j++)
            s.push_back(a[i][j]), t.push_back(a[j][i]);
        if (solve(i, c, s, t)) return;
    }
    cout << n << ' ' << n << endl;
}
void solve2() {
    int n; string s1, s2;
    cin >> n >> s1 >> s2;
    if (s1 == s2) {
        int cnt1 = 0, bg = 0, ed = -1;
        for (int i = 0; i < n; i++) {
            if (s1[i] == '1') {
                if (!bg) bg = i + 1;
                ed = i + 1;
                cnt1++;
            }
        }
        cout << (ed - bg + 1 == cnt1) << '\n';
    } else cout << (s1 < s2) << '\n';
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string tid; int t;
    cin >> tid >> t;
    if (tid == "first") while (t--) solve1();
    else while (t--) solve2();
    return 0;
}