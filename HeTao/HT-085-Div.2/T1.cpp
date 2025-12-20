// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;

// constexpr int N = 5e3 + 10, V = 1e7 + 10;
// int n, a[N], cnt[V], tmp[V], res[V];

// vector<int> lsh;

// inline ll C3(int n) {
//     return n * (n - 1ll) * (n - 2ll) / 6;
// }
// inline ll C2(int n) {
//     return n * (n - 1ll) >> 1;
// }
// vector<pair<int, ll>> qs[N];
// int main() {
//     freopen("a.in", "r", stdin);
//     freopen("a.out", "w", stdout);
//     ios::sync_with_stdio(0); cin.tie(0);
//     cin >> n;
//     for (int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++, lsh.push_back(a[i]);
//     sort(lsh.begin(), lsh.end());
//     lsh.erase(unique(lsh.begin(), lsh.end()), lsh.end());
//     sort(a + 1, a + 1 + n);
//     for (const int d : lsh) {
//         if (cnt[d] < 3) continue;
//         const ll t3 = C3(cnt[d]);
//         for (int j = 1; j <= n; j++) {
//             if (a[j] >= d) continue;
//             qs[j - 1].push_back(make_pair(d - a[j], t3));
//         }
//     }
//     ll ans = 0;
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j < i && a[i] + a[j] < V; j++)
//             tmp[a[i] + a[j]]++;
//         for (const auto& j : qs[i])
//             ans += tmp[j.first] * j.second;
//     }
//     memset(tmp, 0, sizeof tmp);
//     for (int i = 1; i <= n; i++) {
//         for (int l = i + 1; l <= n; l++) {
//             if (a[i] + a[l] < V) res[a[i] + a[l]] += tmp[a[i] + a[l]];
//             for (int j = i + 1; j < l; j++)
//                 tmp[a[j] + a[l]]++;
//         }
//         for (int l = i + 1; l <= n; l++)
//             for (int j = i + 1; j < l; j++)
//                 tmp[a[j] + a[l]]--;
//     }
//     for (const auto& d : lsh)
//         ans += C2(cnt[d]) * res[d];
//     cout << ans << endl;
//     return 0;
// }

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

constexpr int N = 5e3 + 10, V = 1e7 + 10;
int n, a[N], cnt[V], tmp[V];

vector<int> lsh;

inline ll C3(int n) {
    return n * (n - 1ll) * (n - 2ll) / 6;
}
inline ll C2(int n) {
    return n * (n - 1ll) >> 1;
}

inline ll C4(int n) {
    return n * (n - 1ll) * (n - 2ll) * (n - 3ll) / 24;
}
vector<pair<int, ll>> qs[N];

inline ll f(int d, int x) {
    if (x >= (d + 1) / 2) return 0;
    return (ll) cnt[x] * cnt[d - x];
}

int main() {
    freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++, lsh.push_back(a[i]);
    sort(lsh.begin(), lsh.end());
    lsh.erase(unique(lsh.begin(), lsh.end()), lsh.end());
    sort(a + 1, a + 1 + n);
    for (const int d : lsh) {
        if (cnt[d] < 3) continue;
        const ll t3 = C3(cnt[d]);
        for (int j = 1; j <= n; j++) {
            if (a[j] >= d) continue;
            qs[j - 1].push_back(make_pair(d - a[j], t3));
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++)
            if (a[i] + a[j] < V) tmp[a[i] + a[j]]++;
        for (const auto& j : qs[i])
            ans += tmp[j.first] * j.second;
    }
    for (const int d : lsh) {
        ll sum = 0;
        for (int i : lsh)
            sum += f(d, i);
        if (!(d & 1)) {
            ans += C2(cnt[d]) * C4(cnt[d >> 1]);
            ans += C2(cnt[d]) * C2(cnt[d >> 1]) * sum;
        }
        for (int i : lsh) {
            if (i >= (d + 1) / 2) break;
            ans += (f(d, i) * (sum - f(d, i)) / 2) * C2(cnt[d]);
            ans += C2(cnt[i]) * C2(cnt[d - i]) * C2(cnt[d]);
        }
        // cout << d << ' ' << ans << endl;
    }
    cout << ans << endl;
    return 0;
}