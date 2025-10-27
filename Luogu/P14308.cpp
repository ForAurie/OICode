#include <bits/stdc++.h>

using namespace std;

bool check(long long x, long long y, long long lx, long long ly, long long rx, long long ry) { return lx <= x && x <= rx && ly <= y && y <= ry; }

long long len(long long lx, long long ly, long long rx, long long ry) { return rx - lx; }

void solve() {
    long long plx = -1, ply = -1, prx = 0, pry = 0;
    long long lx = 0, ly = -1, rx = 2, ry = 1, x, y;
    cin >> x >> y;
    if (check(x, y, -1, 0, 0, 1)) {
        cout << 1 << endl;
    } else if (check(x, y, plx, ply, prx, pry)) {
        cout << 1 << endl;
    } else {
        for (int i = 3;; i++) {
            if (check(x, y, lx, ly, rx, ry)) {
                cout << len(lx, ly, rx, ry) << endl;
                break;
            }
            const long long l = len(lx, ly, rx, ry) + len(plx, ply, prx, pry);
            long long tmp;
            switch(i % 4) {
            case 0:
                tmp = ply;
                plx = lx, ply = ly, prx = rx, pry = ry;
                rx = lx;
                lx -= l;
                ly = tmp;
            break;
            case 1:
                tmp = prx;
                plx = lx, ply = ly, prx = rx, pry = ry;
                ry = ly;
                ly -= l;
                rx = tmp;
            break;
            case 2:
                tmp = pry;
                plx = lx, ply = ly, prx = rx, pry = ry;
                lx = rx;
                rx += l;
                ry = tmp;
            break;
            default:
                tmp = plx;
                plx = lx, ply = ly, prx = rx, pry = ry;
                ly = ry;
                ry += l;
                lx = tmp;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}