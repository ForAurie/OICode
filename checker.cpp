#include <bits/stdc++.h>
using namespace std;
int main() {
	for (int i = 1; i <= 50; i++)
		cout << "rk" << i << ": " << round(25.0 / i) << endl;
	const int N = 1919;
	const int M = 1741;
	mt19937 gen(2026 + N);
	uniform_int_distribution<int> dis(51, M);
	for (int i = 1; i <= 3; i++) {
		cout << "rk" << dis(gen) << ": " << 20 << endl;
	} // 是的，一个人可能会被随到多次，随到几次就奖励几次！
	return 0;
} 