#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, sum = 0;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i, sum += i;
    if (sum % n != 0) {
        cout << -1 << '\n';
        return 0;
    }
    sum /= n;
    vector<int> dp(1 << n), pre(1 << n);
    for (int S = 1; S < (1 << n); S++) {
        int v = 0;
        for (int i = 0; i < n; i++)
            if ((S >> i) & 1) v += a[i];
        bool flag = (v == sum * __builtin_popcount(S));
        if (flag) dp[S]++;
        for (int i = 0; i < n; i++) {
            if ((S >> i) & 1) continue;
            const int T = S | (1 << i);
            if (dp[S] > dp[T]) {
                dp[T] = dp[S];
                if (flag) pre[T] = S;
                else pre[T] = pre[S];
            }
        }
    }
    int S = (1 << n) - 1;
    cout << n - dp[S] << '\n';
    do {
        const int p = S ^ pre[S];
        vector<int> tmp;
        for (int i = 0; i < n; i++)
            if ((p >> i) & 1) tmp.push_back(i);
        sort(tmp.begin(), tmp.end(), [&](int x, int y) {
            return a[x] > a[y];
        });
        for (int i = 0; i + 1 < (int) tmp.size(); i++) {
            cout << tmp[i] + 1 << ' ' << tmp[i + 1] + 1 << ' ' << a[tmp[i]] - sum << '\n';
            a[tmp[i + 1]] += a[tmp[i]] - sum;
        }
        S = pre[S];
    } while (S);
    return 0;
}