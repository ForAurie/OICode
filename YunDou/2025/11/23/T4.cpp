#include <bits/stdc++.h>

using namespace std;
constexpr int N = 3e5 + 10;
struct node {
    int v, id;
    bool operator<(const node &o) const {
        return v > o.v || (v == o.v && id < o.id);
    }
} a[N];

int c[N], n;
void add(int x) {
    while (x < N) {
        c[x]++;
        x += x & -x;
    }
}
int queryT(int x) {
    int res = 0;
    while (x) {
        res += c[x];
        x -= x & -x;
    }
    return res;
}
int query(int l, int r) {
    if (l > r) return 0;
    return queryT(r) - queryT(l - 1);
}
long long dp[N];
int main() {
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].v;
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n);
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    int cnt = 0, last = -1;
    for (int i = 0; i < n; i++) {
        if (last == a[i + 1].v) cnt++;
        else cnt = 0;
        dp[i + 1] = dp[i] + min(query(1, a[i + 1].id) - cnt, query(a[i + 1].id + 1, n));
        add(a[i + 1].id);
        last = a[i + 1].v;
    }
    cout << dp[n] << endl;
    return 0; 
}