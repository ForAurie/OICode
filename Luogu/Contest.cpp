#include <bits/stdc++.h>

using namespace std;

void fp(int l, int r) { if (l <= r) cout << "1 " << l << ' ' << r << endl; }
int ask(int l, int r) {
    if (l > r) return 0;
    cout << "2 " << l << ' ' << r << endl;
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    fp(1, n);
    int r = ask(1, n);
    int x, y;
    if (r == n - 1) {
        int l = 1, r = n, mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (ask(1, mid) == mid - 1) r = mid;
            else l = mid + 1;
        }
        x = l;
        fp(1, n);
        l = 1, r = n;
        while (l < r) {
            mid = (l + r) >> 1;
            int res = ask(1, mid);
            if (res == 2) res -= (x <= mid);
            if (res == 1) r = mid;
            else l = mid + 1;
        }
        // if (ask(1, x - 1)) l = 1, r = x - 1;
        // else l = x + 1, r = n;
        // int st = l;
        // while (l < r) {
        //     mid = (l + r) >> 1;
        //     if (ask(st, mid) == 1) r = mid;
        //     else l = mid + 1;
        // }
        // y = l;
    } else if (r == n - 2) {
        int l = 2, r = n, mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (ask(1, mid) == mid - 2) r = mid;
            else l = mid + 1;
        }
        x = l;
        l = 1, r = n;
        while (l < r) {
            mid = (l + r) >> 1;
            if (ask(1, mid) <= mid - 1) r = mid;
            else l = mid + 1;
        }
        y = l;
    } else {
        fp(1, n);
        int l = 2, r = n, mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (ask(1, mid) == 2) r = mid;
            else l = mid + 1;
        }
        x = l;
        l = 1, r = n;
        while (l < r) {
            mid = (l + r) >> 1;
            if (ask(1, mid) >= 1) r = mid;
            else l = mid + 1;
        }
        y = l;
    }
    cout << "3 " << x << ' ' << y << endl;
}
// 1 0 1
// 1 1 0
// 1 0 
int main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}