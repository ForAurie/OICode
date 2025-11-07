#include <bits/stdc++.h>
using namespace std;
constexpr int N = (1 << 20) + 10, V = (1 << 20);
int hd[N], nxtt[14698352], val[14698352], mk[26], bl0[N], bl1[N];
string s;
int pre[27][N];
void solve() {
    cin >> s;
    const int n = s.length();
    s = ' ' + s;
    vector<int> nxt(s.length());
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && s[j + 1] != s[i]) j = nxt[j];
        if (s[j + 1] == s[i]) j++;
        nxt[i] = j;
    }
    for (int i = 1; i <= n; i++) s[i] -= 'a';
    int flag = n;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i + 1]) {
            flag = i;
            break;
        }
    }
    if (flag == n) {
        long long ans = 0;
        for (int i = 2; i < n; i++) {
            if ((n - i) & 1) ans += bl1[i];
            else ans += bl0[i];
        }
        cout << ans << '\n';
        return;
    }
    memset(mk, 0, sizeof mk);
    for (int i = 0; i < 27; i++) for (int j = 1; j <= n; j++) pre[i][j] = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (((++mk[(int) s[i]]) & 1) == 1) cnt++;
        else cnt--;
        pre[cnt][i]++;
    }
    for (int i = 0; i < 27; i++)
        for (int j = 1; j <= n; j++) pre[i][j] += pre[i][j - 1];
    for (int i = 1; i < 27; i++)
        for (int j = 1; j <= n; j++) pre[i][j] += pre[i - 1][j];
    memset(mk, 0, sizeof mk);
    cnt = 0;
    long long ans = 0;
    for (int i = n; i > 1; i--) {
        if (((++mk[(int) s[i]]) & 1) == 1) cnt++;
        else cnt--;
        if (i <= flag + 1) {
            if (cnt) ans += bl1[i - 1];
            else ans += bl0[i - 1];
            continue;
        }
        const int p = i - 1;
        const int len = p - nxt[p];
        if (p % len != 0 || len == p) {
            ans += pre[cnt][p - 1];
        } else {
            for (int j = hd[p]; j; j = nxtt[j])
                if (val[j] % len == 0) ans += pre[cnt][val[j] - 1];
        }
    }
    cout << ans << '\n';
}
int idx;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i = 1; i <= V; i++)
        for (int j = i; j <= V; j += i)
            bl1[j] += i - 1,
            bl0[j] += (i - 1) >> 1,
            val[++idx] = i,
            nxtt[idx] = hd[j],
            hd[j] = idx;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}