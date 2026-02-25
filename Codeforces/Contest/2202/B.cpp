#include <bits/stdc++.h>
using namespace std;
void solve() {
    bool aa = false, bb = false, ab = false, naa = false, nbb = false, nab = false;
    int n;
    string s;
    cin >> n >> s;
    if (n & 1) aa = true;
    else ab = true;
    for (char i : s) {
        naa = nbb = nab = false;
        if (i == 'a') {
            nab |= aa;
            nbb |= ab;
        } else if (i == 'b') {
            nab |= bb;
            naa |= ab;
        } else {
            nab |= aa || bb;
            naa |= ab;
            nbb |= ab;
        }
        swap(aa, naa);
        swap(bb, nbb);
        swap(ab, nab);
    }
    if (aa || bb || ab) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}