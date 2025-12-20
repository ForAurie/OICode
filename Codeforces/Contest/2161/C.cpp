#include <bits/stdc++.h>

using namespace std;
void solve() {
    int n, x;
    long long sum = 0;
    cin >> n >> x;
    deque<int> q(n);
    for (int& i : q) cin >> i;
    sort(q.begin(), q.end());
    vector<int> ans;
    long long v = 0;
    while (q.size()) {
        if ((sum + q.back()) / x > sum / x) {
            ans.push_back(q.back());
            sum += q.back();
            v += q.back();
            q.pop_back();
        } else {
            ans.push_back(q.front());
            sum += q.front();
            q.pop_front();
        }
    }
    cout << v << endl;
    for (const int& i : ans) cout << i << ' ';
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}