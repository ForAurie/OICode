<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& i : a) cin >> i;
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i + 1 < (int) a.size(); ++++i)
        ans = max(ans, a[i + 1] - a[i]);
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
=======
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& i : a) cin >> i;
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i + 1 < (int) a.size(); ++++i)
        ans = max(ans, a[i + 1] - a[i]);
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
>>>>>>> origin/main
}