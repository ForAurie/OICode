<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;

void solve1() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    for (const int& i : a) {
        if (i == 1) {
            cout << 0 << endl;
            return;
        } else if (i == n) {
            cout << 1 << endl;
            return;
        }
    }
}

int ask(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    int res;
    cin >> res;
    return res;
}

void solve2() {
    int n, t;
    cin >> n >> t;
    if (t == 0) {
        int l = 2, r = n, mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (ask(1, mid) == n - 1) r = mid;
            else l = mid + 1;
        }
        cout << "! " << l << endl;
    } else {
        int l = 1, r = n - 1, mid;
        while (l < r) {
            mid = (l + r + 1) >> 1;
            if (ask(mid, n) == n - 1) l = mid;
            else r = mid - 1;
        }
        cout << "! " << l << endl;
    }
}
int main() {
    string type;
    int t;
    cin >> type >> t;
    if (type == "first") {
        while (t--) solve1();
    } else {
        while (t--) solve2();
    }
    return 0;
=======
#include <bits/stdc++.h>

using namespace std;

void solve1() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    for (const int& i : a) {
        if (i == 1) {
            cout << 0 << endl;
            return;
        } else if (i == n) {
            cout << 1 << endl;
            return;
        }
    }
}

int ask(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    int res;
    cin >> res;
    return res;
}

void solve2() {
    int n, t;
    cin >> n >> t;
    if (t == 0) {
        int l = 2, r = n, mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (ask(1, mid) == n - 1) r = mid;
            else l = mid + 1;
        }
        cout << "! " << l << endl;
    } else {
        int l = 1, r = n - 1, mid;
        while (l < r) {
            mid = (l + r + 1) >> 1;
            if (ask(mid, n) == n - 1) l = mid;
            else r = mid - 1;
        }
        cout << "! " << l << endl;
    }
}
int main() {
    string type;
    int t;
    cin >> type >> t;
    if (type == "first") {
        while (t--) solve1();
    } else {
        while (t--) solve2();
    }
    return 0;
>>>>>>> origin/main
}