#include <bits/stdc++.h>
using namespace std;
constexpr int t = 21, configs[t][3] = {
    {10, 1, 20},
    {100, 1, 200},
    {100, 1, 200},
    {100, 1, 200},
    {100, 1, 200},

    {1000, 1, 2000},
    {1000, 1, 2000},
    {1000, 1, 2000},
    {1000, 1, 2000},
    {1000, 1, 2000},

    {1000000, 1, 1},

    {1000000, 4681, 4681},
    {1000000, 37943, 37943},


    {100, 1, 200},
    {100, 1, 200},
    {1000, 1, 2000},
    {1000, 1, 2000},
    {1000000, 1, 2000000},
    {1000000, 1, 2000000},
    {1000000, 1, 2000000},
    {1000000, 1, 2000000},
};
void solve(int id, int n, int l, int r, mt19937& gen) {
    string name = to_string(id);
    if (name.length() == 1)
        name = '0' + name;
    cout << name << endl;
    ofstream out(name + ".in");
    out << n << endl;
    uniform_int_distribution<int> dis(l, r);
    for (int i = 0; i < n; i++)
        out << dis(gen) << ' ';
    out << endl;
    for (int i = 0; i < n; i++)
        out << dis(gen) << ' ';
}
int main() {
    mt19937 gen(time(0));
    for (int i = 0; i < t; i++)
        solve(i + 1, configs[i][0], configs[i][1], configs[i][2], gen);
    return 0;
}