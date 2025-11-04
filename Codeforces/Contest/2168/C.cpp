#include <bits/stdc++.h>

using namespace std;

void solve1() {
    int n, x = 0, cnt = 0;
    cin >> n; n--;
    vector<int> res;
    for (int i = 0; i < 15; i++) {
        if ((n >> i) & 1) res.push_back(i + 1), x ^= i + 1, cnt ^= 1;
    }
    for (int i = 0; i < 4; i++) {
        if ((x >> i) & 1) res.push_back(i + 16);
    }
    if (cnt) res.push_back(20);
    cout << res.size() << endl;
    for (auto i : res) cout << i << ' ';
    cout << endl;
}

int calc(const vector<int>& a) {
    int res = 0;
    for (const int& i : a)
        res |= (1 << (i - 1));
    return res;
}

void solve2() {
    int n, x = 0, cnt = 0;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    if (a.size() && a.back() == 20) cnt = 1, a.pop_back();
    while (a.size() && a.back() > 15) {
        x |= (1 << (a.back() - 16));
        a.pop_back();
    }
    if (((int) a.size() & 1) == cnt) {
        int tmp = calc(a) + 1;
        cout << tmp << endl;
    } else {
        int xx = 0;
        for (const int& i : a) xx ^= i;
        if (xx == x) {
            int tmp = calc(a) + 1;
            cout << tmp << endl;
        } else {
            xx ^= x;
            int ans = calc(a);
            ans ^= (1 << (xx - 1));
            cout << ans + 1 << endl;
        }
    }
}
int main() {
    string type;
    int t;
    cin >> type >> t;
    if (type == "first") while (t--) solve1();
    else while (t--) solve2();
}