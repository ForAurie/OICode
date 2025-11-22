#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1.1e6;
int k, suma[N], sumb[N], sumc[N], n;
string s;

inline int geta(int st, int l, int r) {
    l += st, r += st;
    if (l > n) return suma[r - n] - suma[l - n - 1];
    else if (r > n) return suma[n] - suma[l - 1] + suma[r - n];
    else return suma[r] - suma[l - 1];
}
inline int getb(int st, int l, int r) {
    l += st, r += st;
    if (l > n) return sumb[r - n] - sumb[l - n - 1];
    else if (r > n) return sumb[n] - sumb[l - 1] + sumb[r - n];
    else return sumb[r] - sumb[l - 1];
}
inline int getc(int st, int l, int r) {
    l += st, r += st;
    if (l > n) return sumc[r - n] - sumc[l - n - 1];
    else if (r > n) return sumc[n] - sumc[l - 1] + sumc[r - n];
    else return sumc[r] - sumc[l - 1];
}
int main() {
    freopen("good.in", "r", stdin);
    freopen("good.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> k >> s;
    s = ' ' + s;
    n = (1 << k)  * (1 << k) ;
    for (int i = 1; i <= n; i++) {
        suma[i] = suma[i - 1] + (s[i] == 'A');
        sumb[i] = sumb[i - 1] + (s[i] == 'B');
        sumc[i] = sumc[i - 1] + (s[i] == 'C');
    }
    int ans = 0x3f3f3f3f;
    for (int st = 0; st < n; st++) {
        int l = 1, r = n, sum = 0, len;
        while (l < r) {
            len = (r - l + 1) >> 2;
            // cout << l << ' ' << r << ' ' << len << endl;
            sum += len - geta(st, l, l + len - 1);
            sum += len - getb(st, l + len, l + 2 * len - 1);
            sum += len - getc(st, l + 2 * len, l + 3 * len - 1);
            l = l + 3 * len;
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}