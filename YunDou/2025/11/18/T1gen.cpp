#include <bits/stdc++.h>

using namespace std;

int main() {
    mt19937 gen;
    gen.seed(chrono::system_clock::now().time_since_epoch().count());
    cout << 100 << '\n';
    std::uniform_int_distribution<int> dis1(0, 1000);
    std::uniform_int_distribution<int> dis2(0, 1000000);
    for (int i = 1; i <= 100; i++) {
        int l = 0;
        int r = dis1(gen);
        const int d = dis2(gen);
        l += d;
        r += d;
        cout << l << ' ' << r << '\n';
    }
}