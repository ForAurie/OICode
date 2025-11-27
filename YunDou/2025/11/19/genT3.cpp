#include <bits/stdc++.h>

using namespace std;
constexpr int n = 5000;
int main() {
    freopen("fall.in", "w", stdout);
    srand(time(0));
    vector<int> a(n - 1);
    
    for (int i = 0; i < a.size(); i++) a[i] = i + 2;
    random_shuffle(a.begin(), a.end());
    a.insert(a.begin(), 1);
    cout << n << ' ' << n << endl;
    mt19937 gen(time(0));
    std::uniform_int_distribution<int> dis(1, 1e9);
    for (int i = 1; i <= n; i++) {
        cout << dis(gen) << ' ';
    }
    cout << endl;
    std::uniform_int_distribution<int> dis12(1, 2);
    std::uniform_int_distribution<int> dis1n(1, n);
    for (int i = 0; i + 1 < a.size(); i++) cout << a[i] << ' ' << a[i + 1] << endl;
    for (int i = 1; i <= n; i++) {
        int op = dis12(gen);
        cout << op << ' ';
        if (op == 1) {
            cout << dis1n(gen) << ' ' << dis(gen) << endl;
        } else {
            cout << dis(gen) << endl;
        }
    }
    return 0;
}