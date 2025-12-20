<<<<<<< HEAD
#include <bits/stdc++.h>
// #define int long long
using namespace std;
constexpr int N = 1e6 + 10, mod = 998244353;
int n, hd[N], nxt[N], ed[N], idx, d[N], k, dm[N], pre[N];
void add(int a, int b) {
    ed[++idx] = b, nxt[idx] = hd[a], hd[a] = idx;
}
vector<int> a[N];
void dfs(int u) {
    dm[u] = d[u];
    for (int i = hd[u]; i; i = nxt[i]) {
        int v = ed[i];
        d[v] = d[u] + 1;
        dfs(v);
        dm[u] = max(dm[u], dm[v] + 1);
    }
    a[d[u]].push_back(dm[u]);
}
int fp(long long x, int n) {
    long long res = 1;
    while (n) {
        if (n & 1) (res *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return res;
}
int A(int n, int m) {
    if (m > n) return 0;
    return (long long) pre[n] * fp(pre[n - m], mod - 2) % mod;
}
int C(int n, int m) {
    if (m > n) return 0;
    return (long long) pre[n] * fp((long long) pre[n - m] * pre[m] % mod, mod - 2) % mod;
}
int main() {
    cin >> n >> k;
    pre[0] = 1;
    for (int i = 1; i <= n; i++) pre[i] = (long long)pre[i - 1] * i % mod;
    int x;
    for (int i = 2; i <= n; i++) {
        cin >> x;
        add(x, i);
    }
    d[1] = 1;
    dfs(1);
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        sort(a[i].begin(), a[i].end());
        int sum, cnt, last = -1;
        for (int j = 0; j < (int) a[i].size(); j++) {
            if (j + 1 == (int) a[i].size() || a[i][j] != a[i][j + 1]) {
                cnt = j - last;
                sum = a[i].size() - last - 1;
                last = j;
            } else continue;
            if (sum <= k) break;
            if (cnt < 2) continue;
            (
                ans += cnt * ((long long) A(sum - 1, k - 1) - A(sum - cnt, k - 1)) % mod
            ) %= mod;
            if (k - 1 == (int) sum - cnt) (ans += (long long) cnt * pre[k - 1] % mod) %= mod;
        }
    }
    cout << (ans + mod) % mod << endl;
    return 0;
}
=======
#include <bits/stdc++.h>
// #define int long long
using namespace std;
constexpr int N = 1e6 + 10, mod = 998244353;
int n, hd[N], nxt[N], ed[N], idx, d[N], k, dm[N], pre[N];
void add(int a, int b) {
    ed[++idx] = b, nxt[idx] = hd[a], hd[a] = idx;
}
vector<int> a[N];
void dfs(int u) {
    dm[u] = d[u];
    for (int i = hd[u]; i; i = nxt[i]) {
        int v = ed[i];
        d[v] = d[u] + 1;
        dfs(v);
        dm[u] = max(dm[u], dm[v] + 1);
    }
    a[d[u]].push_back(dm[u]);
}
int fp(long long x, int n) {
    long long res = 1;
    while (n) {
        if (n & 1) (res *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return res;
}
int A(int n, int m) {
    if (m > n) return 0;
    return (long long) pre[n] * fp(pre[n - m], mod - 2) % mod;
}
int C(int n, int m) {
    if (m > n) return 0;
    return (long long) pre[n] * fp((long long) pre[n - m] * pre[m] % mod, mod - 2) % mod;
}
int main() {
    cin >> n >> k;
    pre[0] = 1;
    for (int i = 1; i <= n; i++) pre[i] = (long long)pre[i - 1] * i % mod;
    int x;
    for (int i = 2; i <= n; i++) {
        cin >> x;
        add(x, i);
    }
    d[1] = 1;
    dfs(1);
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        sort(a[i].begin(), a[i].end());
        int sum, cnt, last = -1;
        for (int j = 0; j < (int) a[i].size(); j++) {
            if (j + 1 == (int) a[i].size() || a[i][j] != a[i][j + 1]) {
                cnt = j - last;
                sum = a[i].size() - last - 1;
                last = j;
            } else continue;
            if (sum <= k) break;
            if (cnt < 2) continue;
            (
                ans += cnt * ((long long) A(sum - 1, k - 1) - A(sum - cnt, k - 1)) % mod
            ) %= mod;
            if (k - 1 == (int) sum - cnt) (ans += (long long) cnt * pre[k - 1] % mod) %= mod;
        }
    }
    cout << (ans + mod) % mod << endl;
    return 0;
}
>>>>>>> origin/main
