#include <bits/stdc++.h>
using namespace std;
inline int ask(int t, int l, int r) {
	cout << t << ' ' << l << ' ' << r << endl;
	int res;
	cin >> res;
	return res;
}
 
//pair<int, int> query(int l, int r, int q1, int q2) {
//	if (q1 == q2) return make_pair(0x3f3f3f3f, -0x3f3f3f3f);
//	else if (q1 + r - l + 1 == q2) return make_pair(l, r);
//	int mid = (l + r) >> 1;
//	auto qq1 = ask(1, l, mid);
//	auto qq2 = ask(2, l, mid);
//	auto x = query(l, mid, qq1, qq2);
//	auto y = query(mid + 1, r, q1 - qq1, q2 - qq2);
//	return make_pair(min(x.first, y.first), max(x.second, y.second));
//}
void solve() {
	int n;
	cin >> n;
	const int len = ask(2, 1, n) - (n + 1) * n / 2;
//	auto ans = query(1, n, (1 + n) * n / 2, ask(2, 1, n));
	int l = 1, r = n, mid;
	while (l < r) {
		mid = (l + r) >> 1;
		if (ask(2, 1, mid) - ask(1, 1, mid) < len) l = mid + 1;
		else r = mid;
	}
	cout << "! " << l - len + 1 << ' ' << r << endl; 
}
// 2 1 3 4
// 2 2 4 5
int main() {
//	cout << log2(2e4) << endl;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
