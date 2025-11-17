#include <bits/stdc++.h>

using namespace std;
constexpr int N = 5e5 + 10;
int C[N], a[N];
void addT(int x, int v) {
    while (x < N) {
        C[x] += v;
        x += x & -x;
    }
}

void update(int l, int r, int v) {
    if (l > r) return;
    addT(l, v);
    addT(r + 1, -v);
}
int query(int x) {
    int res = 0;
    while (x) {
        res += C[x];
        x -= x & -x;
    }
    return res;
}

int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
        update(a[i + 1] + 1, a[i], 1);
    int last = 0, x, y;
    char op;
    while (q--) {
        cin >> op >> x;
        x ^= last;
        if (op == 'Q') {
            cout << (last = (query(x) + (a[n] >= x))) << "\n";
        } else {
            cin >> y;
            y ^= last;
            update(a[x] + 1, a[x - 1], -1);
            if (x < n) update(a[x + 1] + 1, a[x], -1);
            a[x] = y;
            update(a[x] + 1, a[x - 1], 1);
            if (x < n) update(a[x + 1] + 1, a[x], 1);
        }
    }
    return 0;
}