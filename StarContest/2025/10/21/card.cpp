<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 10, mod = 998244353;
int n, a[N], b[N], hd[N], nxt[N << 1], ed[N << 1], idx = 1, num, d[N], val[N << 1], cnt = 1, ans = 0;
map<pair<int, int>, int> mp;
void add(int u, int v, int vv) {
    ed[++idx] = v;
    nxt[idx] = hd[u];
    hd[u] = idx;
    val[idx] = vv;
    d[v]++;
    mp[make_pair(u, v)] = vv;
}
set<pair<int, int>> st;
bitset<N> mk;
vector<int> col[N];
void bfs(int s) {
    ++num;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int u = q.front(); q.pop();
        if (mk[u]) continue;
        mk[u] = 1;
        col[num].push_back(u);
        for (int i = hd[u]; i; i = nxt[i]) {
            int v = ed[i];
            if (mk[v]) continue;
            q.push(v);
        }
    }
}
stack<int> s;
vector<int> tmp;
bitset<N> in;
bool flag;
void dfs(int u, int e) {
    if (flag) return;
    in[u] = 1, s.push(u);
    for (int i = hd[u]; i; i = nxt[i]) {
        int v = ed[i];
        if (e == i) continue;
        if (in[v]) {
            while (s.top() != v) {
                tmp.push_back(s.top());
                s.pop();
            }
            tmp.push_back(v);
            flag = true;
            return;
        }
        dfs(v, i ^ 1);
        if (flag) return;
    }
    in[u] = 0, s.pop();
}

bitset<N> nvis;
void dfs1(int u, int fa) {
    for (int i = hd[u]; i; i = nxt[i]) {
        int v = ed[i];
        if (v == fa || nvis[v]) continue;
        ans += val[i];
        dfs1(v, u);
    }
}

int dp[N];

void dfs2(int u, int fa) {
    for (int i = hd[u]; i; i = nxt[i]) {
        int v = ed[i];
        if (v == fa) continue;
        dfs2(v, u);
        dp[u] += dp[v] + val[i];
    }
}
int dp1[N];
void dfs3(int u, int fa) {
    dp1[u] = dp[u];
    for (int i = hd[u]; i; i = nxt[i]) {
        int v = ed[i];
        if (v == fa) continue;
        dp[u] -= dp[v] + val[i];
        dp[v] += dp[u] + val[i ^ 1];
        dfs3(v, u);
        dp[v] -= dp[u] + val[i ^ 1];
        dp[u] += dp[v] + val[i];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i], add(a[i], b[i], 1), add(b[i], a[i], 0), st.insert(make_pair(b[i], a[i]));
    for (int i = 1; i <= n * 2; i++) {
        if (mk[i]) continue;
        bfs(i);
    }
    for (int i = 1; i <= num; i++) {
        if (col[i].size() == 1) continue;
        int sum = 0;
        for (auto u : col[i]) sum += d[u];
        sum >>= 1;
        if (sum > (int) col[i].size()) {
            cout << "-1 -1\n";
            return 0;
        } else if (sum == (int) col[i].size()) {
            tmp.clear();
            flag = false;
            while (s.size()) s.pop();
            dfs(col[i][0], -1);
            int sum1 = mp[make_pair(tmp.back(), tmp[0])];
            for (int j = 0; j + 1 < (int) tmp.size(); j++)
                sum1 += mp[make_pair(tmp[j], tmp[j + 1])];
            int sum2 = mp[make_pair(tmp[0], tmp.back())];
            for (int j = 0; j + 1 < (int) tmp.size(); j++)
                sum2 += mp[make_pair(tmp[j + 1], tmp[j])];
            if (tmp.size() != 2 && tmp.size() != 1) {
                if (sum1 == sum2) {
                    cnt <<= 1;
                    cnt %= mod;
                }
                ans += min(sum1, sum2);
            } else if (tmp.size() == 2) {
                if (st.count(make_pair(tmp[0], tmp[1])) && st.count(make_pair(tmp[1], tmp[0]))) {
                    ;
                } else {
                    cnt <<= 1;
                    cnt %= mod;
                    ans++;
                }
            }
            for (int j : tmp) nvis[j] = 1;
            for (int j : tmp) dfs1(j, j);
        } else {
            dfs2(col[i][0], -1);
            dfs3(col[i][0], -1);
            int minn = 0x3f3f3f3f;
            for (auto u : col[i])
                minn = min(minn, dp1[u]);
            int ct = 0;
            for (auto u : col[i]) {
                if (dp1[u] == minn) ct++;
            }
            ans += minn;
            cnt = 1LL * cnt * ct % mod;
        }
    }
    cout << ans << ' ' << cnt << '\n';
    return 0;
=======
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 10, mod = 998244353;
int n, a[N], b[N], hd[N], nxt[N << 1], ed[N << 1], idx = 1, num, d[N], val[N << 1], cnt = 1, ans = 0;
map<pair<int, int>, int> mp;
void add(int u, int v, int vv) {
    ed[++idx] = v;
    nxt[idx] = hd[u];
    hd[u] = idx;
    val[idx] = vv;
    d[v]++;
    mp[make_pair(u, v)] = vv;
}
set<pair<int, int>> st;
bitset<N> mk;
vector<int> col[N];
void bfs(int s) {
    ++num;
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int u = q.front(); q.pop();
        if (mk[u]) continue;
        mk[u] = 1;
        col[num].push_back(u);
        for (int i = hd[u]; i; i = nxt[i]) {
            int v = ed[i];
            if (mk[v]) continue;
            q.push(v);
        }
    }
}
stack<int> s;
vector<int> tmp;
bitset<N> in;
bool flag;
void dfs(int u, int e) {
    if (flag) return;
    in[u] = 1, s.push(u);
    for (int i = hd[u]; i; i = nxt[i]) {
        int v = ed[i];
        if (e == i) continue;
        if (in[v]) {
            while (s.top() != v) {
                tmp.push_back(s.top());
                s.pop();
            }
            tmp.push_back(v);
            flag = true;
            return;
        }
        dfs(v, i ^ 1);
        if (flag) return;
    }
    in[u] = 0, s.pop();
}

bitset<N> nvis;
void dfs1(int u, int fa) {
    for (int i = hd[u]; i; i = nxt[i]) {
        int v = ed[i];
        if (v == fa || nvis[v]) continue;
        ans += val[i];
        dfs1(v, u);
    }
}

int dp[N];

void dfs2(int u, int fa) {
    for (int i = hd[u]; i; i = nxt[i]) {
        int v = ed[i];
        if (v == fa) continue;
        dfs2(v, u);
        dp[u] += dp[v] + val[i];
    }
}
int dp1[N];
void dfs3(int u, int fa) {
    dp1[u] = dp[u];
    for (int i = hd[u]; i; i = nxt[i]) {
        int v = ed[i];
        if (v == fa) continue;
        dp[u] -= dp[v] + val[i];
        dp[v] += dp[u] + val[i ^ 1];
        dfs3(v, u);
        dp[v] -= dp[u] + val[i ^ 1];
        dp[u] += dp[v] + val[i];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i], add(a[i], b[i], 1), add(b[i], a[i], 0), st.insert(make_pair(b[i], a[i]));
    for (int i = 1; i <= n * 2; i++) {
        if (mk[i]) continue;
        bfs(i);
    }
    for (int i = 1; i <= num; i++) {
        if (col[i].size() == 1) continue;
        int sum = 0;
        for (auto u : col[i]) sum += d[u];
        sum >>= 1;
        if (sum > (int) col[i].size()) {
            cout << "-1 -1\n";
            return 0;
        } else if (sum == (int) col[i].size()) {
            tmp.clear();
            flag = false;
            while (s.size()) s.pop();
            dfs(col[i][0], -1);
            int sum1 = mp[make_pair(tmp.back(), tmp[0])];
            for (int j = 0; j + 1 < (int) tmp.size(); j++)
                sum1 += mp[make_pair(tmp[j], tmp[j + 1])];
            int sum2 = mp[make_pair(tmp[0], tmp.back())];
            for (int j = 0; j + 1 < (int) tmp.size(); j++)
                sum2 += mp[make_pair(tmp[j + 1], tmp[j])];
            if (tmp.size() != 2 && tmp.size() != 1) {
                if (sum1 == sum2) {
                    cnt <<= 1;
                    cnt %= mod;
                }
                ans += min(sum1, sum2);
            } else if (tmp.size() == 2) {
                if (st.count(make_pair(tmp[0], tmp[1])) && st.count(make_pair(tmp[1], tmp[0]))) {
                    ;
                } else {
                    cnt <<= 1;
                    cnt %= mod;
                    ans++;
                }
            }
            for (int j : tmp) nvis[j] = 1;
            for (int j : tmp) dfs1(j, j);
        } else {
            dfs2(col[i][0], -1);
            dfs3(col[i][0], -1);
            int minn = 0x3f3f3f3f;
            for (auto u : col[i])
                minn = min(minn, dp1[u]);
            int ct = 0;
            for (auto u : col[i]) {
                if (dp1[u] == minn) ct++;
            }
            ans += minn;
            cnt = 1LL * cnt * ct % mod;
        }
    }
    cout << ans << ' ' << cnt << '\n';
    return 0;
>>>>>>> origin/main
}