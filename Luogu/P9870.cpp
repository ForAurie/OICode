#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, INF = 0x3f3f3f3f;
// void dmin(int& x, const int& y) { if (y < x) x = y; }
// void dmax(int& x, const int& y) { if (x < y) x = y; }
bool chkpre(int x, int y, const vector<int>& a, const vector<int>& b, const vector<int>& amx, const vector<int>& amn, const vector<int> &bmx, const vector<int>& bmn) {
    if (x == 1 || y == 1) return true;
    if (amn[x - 1] < bmn[y - 1]) {
        for (int i = x - 1; i >= 1; i--) {
            if (a[i] == amn[x - 1]) {
                return chkpre(i, y, a, b, amx, amn, bmx, bmn);
            }
        }
    } else if (bmx[y - 1] > amx[x - 1]) {
        for (int i = y - 1; i >= 1; i--) {
            if (b[i] == bmx[y - 1]) {
                return chkpre(x, i, a, b, amx, amn, bmx, bmn);
            }
        }
    }
    return false;
}
bool chksuf(int x, int y, const vector<int>& a, const vector<int>& b, const vector<int>& amx, const vector<int>& amn, const vector<int> &bmx, const vector<int>& bmn) {
    if (x + 1 == a.size() || y + 1 == b.size()) return true;
    if (amn[x + 1] < bmn[y + 1]) {
        for (int i = x + 1; i < a.size(); i++) {
            if (a[i] == amn[x + 1])
                return chksuf(i, y, a, b, amx, amn, bmx, bmn);
        }
    } else if (bmx[y + 1] > amx[x + 1]) {
        for (int i = y + 1; i < b.size(); i++) {
            if (b[i] == bmx[y + 1])
                return chksuf(x, i, a, b, amx, amn, bmx, bmn);
        }
    }
    return false;
}

bool check(const vector<int>& a, const vector<int>& b) {
    if (a[1] >= b[1] || a.back() >= b.back()) return false;
    vector<int> amx(a.size(), -INF), amn(a.size(), INF), bmx(b.size(), -INF), bmn(b.size(), INF);
    for (int i = 1; i < a.size(); i++) {
        amx[i] = max(a[i], amx[i - 1]);
        amn[i] = min(a[i], amn[i - 1]);
    }
    for (int i = 1; i < b.size(); i++) {
        bmx[i] = max(b[i], bmx[i - 1]);
        bmn[i] = min(b[i], bmn[i - 1]);
    }
    if (bmx.back() <= amx.back() || bmn.back() <= amn.back()) return false;
    int x, y;
    for (int i = 1; i < a.size(); i++) {
        if (a[i] == amn.back()) {
            x = i;
            break;
        }
    }
    for (int i = 1; i < b.size(); i++) {
        if (b[i] == bmx.back()) {
            y = i;
            break;
        }
    }
    if (!chkpre(x, y, a, b, amx, amn, bmx, bmn)) return false;
    amn.back() = amx.back() = a.back();
    bmn.back() = bmx.back() = b.back();
    for (int i = a.size() - 2; i >= 0; i--) {
        amx[i] = max(amx[i + 1], a[i]);
        amn[i] = min(amn[i + 1], a[i]);
    }
    for (int i = b.size() - 2; i >= 0; i--) {
        bmx[i] = max(bmx[i + 1], b[i]);
        bmn[i] = min(bmn[i + 1], b[i]);
    }
    return chksuf(x, y, a, b, amx, amn, bmx, bmn);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	int c, n, m, q, cx, cy, p, v;
	cin >> c >> n >> m >> q;
    vector<int> x(n + 1), y(m + 1);
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i <= m; i++) cin >> y[i];
	cout << (check(x, y) || check(y, x) ? '1' : '0');
	while (q--) {
        vector<int> a(x), b(y);
        cin >> cx >> cy;
		while (cx--) { cin >> p >> v; a[p] = v; }
		while (cy--) { cin >> p >> v; b[p] = v; }
		cout<<(check(a, b) || check(b, a) ? '1' : '0');
	}
	return 0;
}
