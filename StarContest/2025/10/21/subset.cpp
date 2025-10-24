#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
void push(vector<long long>& mk) {
    int d = 0;
    for (int i = 1; i < (int) mk.size(); i++)
        if (mk[i]) { ans.push_back(d = i); break; }
    vector<long long> tmp(mk.size());
    for (int i = mk.size() - 1; i >= d; i--) {
        mk[i - d] -= mk[i];
        tmp[i - d] += mk[i];
    }
    while (tmp.size() && tmp.back() == 0) tmp.pop_back();
    swap(mk, tmp);
}

int main() {
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<long long> mk(m + 1);
    for (long long& i : mk) cin >> i;
    while (n--)
        push(mk);
    sort(ans.begin(), ans.end());
    for (auto i : ans) cout << i << ' ';
    return 0;
}