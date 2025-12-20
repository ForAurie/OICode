<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e7 + 10, V = 1e7;
typedef long long ll;
bitset<N> np;
vector<int> ps;
void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (const auto& i : ps) {
        const int x = b / i - a / i;
        const int y = d / i - c / i;
        if (x > y) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    freopen("divide.in", "r", stdin);
    freopen("divide.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i = 2; i <= V; i++) {
        if (!np[i]) ps.push_back(i);
        for (const auto& j : ps) {
            if ((ll) i * j > V) break;
            np[i * j] = 1;
            if (i % j == 0) break;
        }
    }
    // cout << ps.size() << endl;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
=======
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e7 + 10, V = 1e7;
typedef long long ll;
bitset<N> np;
vector<int> ps;
void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (const auto& i : ps) {
        const int x = b / i - a / i;
        const int y = d / i - c / i;
        if (x > y) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    freopen("divide.in", "r", stdin);
    freopen("divide.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i = 2; i <= V; i++) {
        if (!np[i]) ps.push_back(i);
        for (const auto& j : ps) {
            if ((ll) i * j > V) break;
            np[i * j] = 1;
            if (i % j == 0) break;
        }
    }
    // cout << ps.size() << endl;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
>>>>>>> origin/main
}