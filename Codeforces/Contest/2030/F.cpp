#include <bits/stdc++.h>
#include "segtree.hpp"

using namespace std;

int e() { return 0; }

int op(int x, int y) { return x < y ? y : x; }

typedef atcoder::segtree<int, op, e> tree;

void solve() {
    int n, q, x;
    cin >> n >> q;
    tree tr(vector<int>(n + 1));
    vector<int> ans(n + 1), mk(n + 1);
    for (int i = 1, l = 1; i <= n; i++) {
        cin >> x;
        int last = mk[x];
        while (last > l && tr.prod(l, last) > last) l++;
        if (last) tr.set(last, i);
        ans[i] = l; 
        mk[x] = i;
    }
    int l, r;
    while (q--) {
        cin >> l >> r;
        if (l >= ans[r]) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}