#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e5 + 10;
int tid, n, m, a[N], nxt[N], fr[N];
set<pair<int, int>> s;
void del(int x) {
	s.erase(make_pair(a[fr[x]] + a[x], fr[x]));
	s.erase(make_pair(a[nxt[x]] + a[x], x));
	s.insert(make_pair(a[fr[x]] + a[nxt[x]], fr[x]));
	nxt[fr[x]] = nxt[x];
	fr[nxt[x]] = fr[x];
}
int main() {
	freopen("necklace.in", "r", stdin);
	freopen("necklace.out", "w", stdout);
        ios::sync_with_stdio(0), cin.tie(0);
	cin >> tid >> n >> m;
	m = n - m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		nxt[i] = (i + 1) % n;
		fr[i] = (i + n - 1) % n;
	}
	for (int i = 0; i < n; i++) s.insert(make_pair(a[i] + a[nxt[i]], i)); 
	while (m--) {
		auto it = s.end();
		--it;
		const int u = it->second;
		if (a[u] > a[nxt[u]]) del(u);
		else del(nxt[u]);
	}
	auto it = s.end();
	--it;
	cout << it->first << endl;
	return 0;
}