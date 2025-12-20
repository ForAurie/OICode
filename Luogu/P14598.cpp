#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
int a[N], n, q;
int tmp1[2][2], tmp2[2][2];
struct node {
    int a[2][2] = {{0, 0}, {0, 0}};
    node operator+(const node& o) const {
        node res;
        memcpy(tmp1, a, sizeof tmp1);
        memcpy(tmp2, o.a, sizeof tmp2);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                const int k = j ^ 1;
                for (int l = 0; l < 2; l++) {
                    const int tmp = min(tmp1[i][j], tmp2[k][l]);
                    res.a[i][l] += tmp;
                    tmp1[i][j] -= tmp, tmp2[k][l] -= tmp;
                }
            }
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                res.a[i][j] += tmp1[i][j] + tmp2[i][j];
            }
        }
        return res;
    }
} tr[N << 2];
#define ls p << 1
#define rs p << 1 | 1
void build(int p, int l, int r) {
    if (l == r) {
        tr[p].a[a[l]][a[l]] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    tr[p] = tr[ls] + tr[rs];
}
node query(int p, int l, int r, int nl = 1, int nr = n) {
    if (l <= nl && nr <= r) {
        return tr[p];
    }
    int mid = (nl + nr) >> 1;
    bool flag = false;
    node res;
    if (l <= mid) {
        flag = true;
        res = query(ls, l, r, nl, mid);
    }
    if (r > mid) {
        if (flag) res = res + query(rs, l, r, mid + 1, nr);
        else res = query(rs, l, r, mid + 1, nr);
    }
    return res;
} 
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int l, r;
    char ch;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> ch;
        if (ch == 'C') a[i] = 1;
        else a[i] = 0;
    }
    build(1, 1, n);
    while (q--) {
        cin >> l >> r;
        auto res = query(1, l, r);
        int ans = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                ans += res.a[i][j];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}