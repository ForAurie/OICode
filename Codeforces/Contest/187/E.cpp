#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 2e5 + 10;
int n, a[N];
vector<int> xs;
ll id(ll x) { return lower_bound(xs.begin(), xs.end(), x) - xs.begin() + 1; }
ll val(ll x) { return xs[x - 1]; }
ll cr[N], cl[N];
ll queryr(int x) {
    ll res = 0;
    while (x) {
        res += cr[x];
        x -= x & -x;
    }
    return res;
}
void addTr(ll x, ll v) {
    while (x < N) {
        cr[x] += v;
        x += x & -x;
    }
}
ll queryl(ll x) {
    ll res = 0;
    while (x) {
        res += cl[x];
        x -= x & -x;
    }
    return res;
}
void addTl(ll x, ll v) {
    while (x < N) {
        cl[x] += v;
        x += x & -x;
    }
}
void addr(ll x, ll v) {
    addTr(1, v);
    addTr(x + 1, -v);
}
void addl(ll x, ll v) {
    addTl(x + 1, v);
}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
__gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>,
                 __gnu_pbds::rb_tree_tag,
                 __gnu_pbds::tree_order_statistics_node_update>
    tr;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], xs.push_back(a[i]);
    sort(xs.begin(), xs.end());
    
    for (int i = 1; i <= n; i++) {
        // cout << id(a[i]) << endl;
        int idd = id(a[i]);
        tr.insert(idd);
        addl(idd, a[i]);
        addr(idd, a[i]);
        if (i < 3) continue;
        int l = 0, r = i - 1, mid;
        ll ans = 0x3f3f3f3f3f3f3f3f;
        while (l <= r) {
            mid = (l + r) >> 1;
            auto idx = tr.find_by_order(mid);
            ll wr, wl;
            if ((*idx) == i - 1) wr = 0;
            else wr = queryr(*idx) - val(*next(idx)) * (i - 1 - mid);
            if ((*idx) == 0) wl = 0;
            else wl = queryl(*idx) - val(*prev(idx)) * mid;
            ans = min(ans, max(wl, wr));
            if (wl == wr) break;
            if (wl > wr) r = mid - 1;
            else l = mid + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}