#include <bits/stdc++.h>
using namespace std;
constexpr int N = 20;
int n, m;
using T = unsigned int;
T a[1 << N];
inline void __OR(T f[1 << N]) {
	for (int o = 2, k = 1; o <= m; o <<= 1, k <<= 1)
		for (int i = 0; i < m; i += o)
			for (int j = 0; j < k; j++)
				f[i + j + k] += f[i + j];
}
inline void __AND(T f[1 << N]) {
	for (int o = 2, k = 1; o <= m; o <<= 1, k <<= 1)
		for (int i = 0; i < m; i += o)
			for (int j = 0; j < k; j++)
				f[i + j] += f[i + j + k];
}
inline void __IOR(T f[1 << N]) {
	for (int o = 2, k = 1; o <= m; o <<= 1, k <<= 1)
		for (int i = 0; i < m; i += o)
			for (int j = 0; j < k; j++)
				f[i + j + k] -= f[i + j];
}
inline void __IAND(T f[1 << N]) {
	for (int o = 2, k = 1; o <= m; o <<= 1, k <<= 1)
		for (int i = 0; i < m; i += o)
			for (int j = 0; j < k; j++)
				f[i + j] -= f[i + j + k];
}
inline void OR(T f[1 << N]) {
    int cnt = 0;
    for (int i = 0; i < m; i++) cnt += f[i];
    if ((long long) cnt * cnt + 1000 <= n * m) {
        vector<int> id;
        for (int i = 0; i < m; i++) if (f[i]) id.push_back(i);
        for (int i : id)
            for (int j : id)
                f[i | j] = 1;
        return;
    }
    __OR(f);
    for (int i = 0; i < m; i++) f[i] *= f[i];
    __IOR(f);
    for (int i = 0; i < m; i++) f[i] = (bool) f[i];
}
inline void AND(T f[1 << N]) {
    int cnt = 0;
    for (int i = 0; i < m; i++) cnt += f[i];
    if ((long long) cnt * cnt + 1000 <= n * m) {
        vector<int> id;
        for (int i = 0; i < m; i++) if (f[i]) id.push_back(i);
        for (int i : id)
            for (int j : id)
                f[i & j] = 1;
        return;
    }
    __AND(f);
    for (int i = 0; i < m; i++) f[i] *= f[i];
    __IAND(f);
    for (int i = 0; i < m; i++) f[i] = (bool) f[i];
}
T tmp[1 << N];
int main() {
    freopen("topo.in", "r", stdin);
    freopen("topo.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        tmp[x] = a[x] = 1;
    }
    m = (1 << n);
    while (true) {
        OR(a);
        AND(a);
        bool flag = true;
        for (int j = 0; j < m; j++) {
            if (tmp[j] != a[j]) flag = false;
            tmp[j] = a[j];
        }
        if (flag) break;
    }
    for (int i = 0; i < m; i++) cout << a[i];
    cerr << (double) clock() / CLOCKS_PER_SEC << endl;
    return 0;
}