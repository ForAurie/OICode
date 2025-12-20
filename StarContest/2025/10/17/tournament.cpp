<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1e5 + 10;
int n, k, a[N];
int main() {
    freopen("tournament.in", "r", stdin);
    freopen("tournament.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int mn = n, ans = 0;
    for (int i = n; i >= 1; i--) {
        auto p = upper_bound(a + 1, a + 1 + n, a[i] + k) - a - 1;
        if (p >= mn) ans++, mn = i;
    }
    cout << ans << endl;
    return 0;
=======
#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1e5 + 10;
int n, k, a[N];
int main() {
    freopen("tournament.in", "r", stdin);
    freopen("tournament.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int mn = n, ans = 0;
    for (int i = n; i >= 1; i--) {
        auto p = upper_bound(a + 1, a + 1 + n, a[i] + k) - a - 1;
        if (p >= mn) ans++, mn = i;
    }
    cout << ans << endl;
    return 0;
>>>>>>> origin/main
}