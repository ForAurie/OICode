<<<<<<< HEAD
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
            string tmp;
            while (x) {
                tmp.push_back(x % 26 + 'a');
                x /= 26;
            }
            while (tmp.size() < 7) tmp.push_back('a');
            reverse(tmp.begin(), tmp.end());
            cout << tmp;
        }
    } else {
        string s;
        cin >> s;
        cout << s.length() / 7 << endl;
        for (int i = 0; i < s.length(); i += 7) {
            int x = 0;
            for (int j = i; j < i + 7; j++) {
                x = x * 26 + (s[j] - 'a');
            }
            cout << x << ' ';
        }
    }
    return 0;
=======
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
            string tmp;
            while (x) {
                tmp.push_back(x % 26 + 'a');
                x /= 26;
            }
            while (tmp.size() < 7) tmp.push_back('a');
            reverse(tmp.begin(), tmp.end());
            cout << tmp;
        }
    } else {
        string s;
        cin >> s;
        cout << s.length() / 7 << endl;
        for (int i = 0; i < s.length(); i += 7) {
            int x = 0;
            for (int j = i; j < i + 7; j++) {
                x = x * 26 + (s[j] - 'a');
            }
            cout << x << ' ';
        }
    }
    return 0;
>>>>>>> origin/main
}