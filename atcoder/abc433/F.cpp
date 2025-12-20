#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 998244353;
int tmp1[10], tmp2[10];
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    const int n = s.length();
    s = ' ' + s;
    for (int i = 1; i <= n; i++) tmp2[s[i] - '0']++;
    for (int i = 1; i <= n; i++) {
        int x = s[i] - '0';
        tmp1[x]++;
        tmp2[x]--;
        if (x == 9) continue;
        int y = s[i] - '0' + 1;
        for (int j = 0; j < tmp1[x]; j++) {
            ans += C(tmp1[x] - 1, j) * C(tmp2[y], j + 1);
        }
    }
    return 0;
}