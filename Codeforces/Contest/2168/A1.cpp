#include <bits/stdc++.h>

using namespace std;

int main() {
    string type;
    cin >> type;
    if (type == "first") {
        int n, x;
        cin >> n;
        while (n--) {
            cin >> x;
            cout << (char) (x + 'a' - 1);
        }
    } else {
        string s;
        cin >> s;
        cout << s.size() << endl;
        for (const auto& i : s) {
            cout << (int) (i - 'a' + 1) << ' ';
        }
    }
    return 0;
}