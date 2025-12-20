#include <bits/stdc++.h>

using namespace std;
constexpr int N = 5e5 + 10, V = 5e5, mod = 1e9 + 7;
int pre[N];
int fp(long long x, int n) {
    long long r = 1;
    while (n) {
        if (n & 1) (r *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return r;
}
int inv(int x) { return fp(x, mod - 2); }
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), sz;
    vector<bool> mk(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (mk[i]) continue;
        int cnt = 0;
        while (!mk[i]) {
            mk[i] = true; cnt++; // id[i] = sz.size();
            i = a[i];
        }
        sz.push_back(cnt);
    }
    unordered_map<int, int> mp;
    for (const auto& i : sz) mp[i]++;
    sort(sz.begin(), sz.end());
    sz.erase(unique(sz.begin(), sz.end()), sz.end());
    int sum = 1;
    vector<vector<int>> cnt(n + 1);
    for (const auto &i : sz) {
        int x = i, ct = mp[i];
        unordered_map<int, int> t;
        while (x > 1) {
            t[pre[x]]++;
            x /= pre[x];
        }
        for (auto &p : t) {
            for (int j = 1; j <= 3 && j <= ct; j++)
                cnt[p.first].push_back(p.second);
            sort(cnt[p.first].begin(), cnt[p.first].end(), greater<int>());
            while (cnt[p.first].size() > 3) cnt[p.first].pop_back();
        }
    }
    for (int i = 2; i <= n; i++)
        sum = (long long) sum * fp(i, cnt[i].front()) % mod;
    int ans = 0;
    for (const int& i : sz) {
        for (const int& j : sz) {
            if (i == j && mp[i] < 2) continue;
            int x = i, y = j;
            unordered_map<int, int> mx, my;
            while (x > 1) {
                mx[pre[x]]++;
                x /= pre[x];
            }
            while (y > 1) {
                my[pre[y]]++;
                y /= pre[y];
            }
            int nowv = sum;
            vector<pair<int, int>> del;
            for (const auto& p : mx) {
                auto it = lower_bound(cnt[p.first].begin(), cnt[p.first].end(), p.second, greater<int>());
                if (it == cnt[p.first].end() || *it != p.second) continue;
                if (*it == cnt[p.first].front()) {
                    nowv = (long long) nowv * fp(inv(p.first), p.second) % mod;
                    if (cnt[p.first].size() > 1) nowv = (long long) nowv * fp(p.first, cnt[p.first][1]) % mod;
                }
                del.push_back(make_pair(p.first, *it));
                cnt[p.first].erase(it);
            }
            for (const auto& p : my) {
                auto it = lower_bound(cnt[p.first].begin(), cnt[p.first].end(), p.second, greater<int>());
                if (it == cnt[p.first].end() || *it != p.second) continue;
                if (*it == cnt[p.first].front()) {
                    nowv = (long long) nowv * fp(inv(p.first), p.second) % mod;
                    if (cnt[p.first].size() > 1) nowv = (long long) nowv * fp(p.first, cnt[p.first][1]) % mod;
                }
                del.push_back(make_pair(p.first, *it));
                cnt[p.first].erase(it);
            }
            if (i == j) (ans += (long long) mp[i] * i % mod * (mp[i] - 1) * i % mod * nowv) %= mod;
            else (ans += (long long) mp[i] * i % mod * mp[j] * j  % mod * nowv % mod) %= mod;
            for (const auto& p : del)
                cnt[p.first].push_back(p.second);
            
        }
    }
}

int main() {
    vector<int> ps;
    for (int i = 2; i < V; i++) {
        if (pre[i] == 0) {
            ps.push_back(i);
            pre[i] = i;
        }
        for (const auto& p : ps) {
            if ((long long) p * i > V) break;
            pre[p * i] = p;
            if (i % p == 0) break;
        }
    }
    int t;
    cin >> t;
    while (t--) solve();
}