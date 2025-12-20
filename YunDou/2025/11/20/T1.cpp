#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
// constexpr int M = 3, mod[M] = {998244353, 1000000007, 19260817}, base[M] = {131, 163, 233}, N = 1e7 + 10;
// constexpr int M = 4, mod[M] = {998244353, 1000000007, 19260817, 9905411}, base[M] = {131, 163, 233, 313}, N = 1e7 + 10;
constexpr int M = 2, mod[M] = {998244353, 1000000007}, base[M] = {131, 163}, N = 1e7 + 10;
typedef long long ll;
typedef unsigned long long ull;
// unordered_set<int> mp[M];
__gnu_pbds::cc_hash_table<int, bool> mp[M];
int hs[M], powb[M][N], ans;
void calc(const string& s) {
    for (int i = 0; i < M; i++) hs[i] = 0;
    for (auto& ch : s) {
        for (int i = 0; i < M; i++) {
            hs[i] = (ll) hs[i] * base[i] % mod[i];
            (hs[i] += ch) %= mod[i];
        }
    }
    bool flag = true;
    for (auto& ch : s) {
        for (int i = 0; i < M; i++) {
            (hs[i] += (mod[i] - (ll) ch * powb[i][s.length() - 1] % mod[i]) % mod[i]) %= mod[i];
            hs[i] = (ll) hs[i] * base[i] % mod[i];
            (hs[i] += ch) %= mod[i];
            if (mp[i].find(hs[i]) == mp[i].end()) mp[i][hs[i]] = true, flag = false;
        }
    }
    ans += (flag == false);
}

int main() {
    freopen("isomorphism.in", "r", stdin);
    freopen("isomorphism.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    for (int i = 0; i < M; i++) {
        powb[i][0] = 1;
        for (int j = 1; j < N; j++) powb[i][j] = (ll) powb[i][j - 1] * base[i] % mod[i];
    }
    int n, m;
    string s;
    cin >> n >> m;
    while (n--) {
        cin >> s;
        calc(s);
    }
    cout << ans << endl;
    // cerr << (double) clock() / CLOCKS_PER_SEC << endl; 
    return 0;
}