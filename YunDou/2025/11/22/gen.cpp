#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5;

int main() {
    freopen("magic.in", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand((unsigned)time(nullptr));
    cout << N << endl;
    for (int i = 1; i <= N; i++) {
        if (rand() % 2) cout << (char) (rand() % 26 + 'a');
        else cout << (char) (rand() % 26 + 'A');
    }
}