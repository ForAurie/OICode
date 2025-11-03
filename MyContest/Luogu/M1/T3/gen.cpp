#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};



inline int randint(int l, int r) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> dist(l, r);
    return dist(gen);
}
inline long long randll(long long l, long long r) {
    static random_device rd;
    static mt19937_64 gen(rd());
    uniform_int_distribution<long long> dist(l, r);
    return dist(gen);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}
