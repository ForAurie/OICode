#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 1e9 + 7, N = 1e5 + 10;
int n, f[N];
string s;
inline int got(char ch) {
    if ('a' <= ch && ch <= 'z') return ch - 'a';
    else return ch - 'A' + 26;
}
set<pair<vector<int>, int>> st;
int d[52], mk[52], p;

void init(vector<int>& x) {
    for (int i = p + 1; i < (int) x.size(); i++) {
        if (mk[i]) x[i] -= x[p];
    }
    x[p] = 0;
    // for (int i = 1; i < (int) x.size(); i++) x[i] -= x[0];
    // x[0] = 0;
}

int main() {
    freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; i++) mk[got(s[i])] = 1;
    for (int i = 0; i < 52; i++) {
        if (mk[i]) {
            p = i;
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        vector<int> tmp(52);
        for (int j = 0; j < 52; j++) tmp[j] = -d[j];
        init(tmp);
        st.insert(make_pair(tmp, -i));
        d[got(s[i])]++;
        for (int j = 0; j < 52; j++) {
            tmp[j] = mk[j] - d[j];
        }
        init(tmp);
        auto it = st.lower_bound(make_pair(tmp, -0x3f3f3f3f));
        if (it == st.end() || it->first != tmp) continue;
        else {
            f[i] = f[-(it->second) - 1] + 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) (ans += f[i]) %= mod;
    cout << ans << endl;
    return 0;
}