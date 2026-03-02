#include <bits/stdc++.h>
#define lgg(x) (63 - __builtin_clz((unsigned long long)(x)))
using namespace std;
constexpr int N = 3e5 + 10;
bool mk[N];
int n, a[N], tr[2][N * 31][2], sz[2][N * 31], tot[2], ans = 0x3f3f3f3f, ps[2], sume;
set<int> leaf[N];
inline void insert(int x, int id) {
    int now = 0;
    for (int i = 30; ~i; i--) {
        int p = (a[x] >> i) & 1;
        if (!tr[id][now][p]) tr[id][now][p] = ++tot[id];
        now = tr[id][now][p];
        sz[id][now]++;
    }
    static int sid = 0;
    if (!tr[id][now][0]) tr[id][now][0] = ++sid;
    leaf[tr[id][now][0]].insert(x);
}
inline void del(int x, int id) {
    int now = 0;
    for (int i = 30; ~i; i--) {
        now = tr[id][now][(a[x] >> i) & 1];
        sz[id][now]--;
    }
    leaf[tr[id][now][0]].erase(x);
}
inline pair<int, int> query(int x, int id) {
    int now = 0, res = 0;
    for (int i = 30; ~i; i--) {
        int p = (a[x] >> i) & 1;
        if (sz[id][tr[id][now][p]]) now = tr[id][now][p];
        else {
            now = tr[id][now][p ^ 1];
            res |= 1 << i;
        }
    }
    return make_pair(res, sz[id][now]);
}
set<int> empt;
inline set<int>& qry(int x, int id) {
    int now = 0, res = 0;
    for (int i = 30; ~i; i--) {
        int p = (a[x] >> i) & 1;
        // cout << tr[id][now][p] << endl;
        if (sz[id][tr[id][now][p]]) now = tr[id][now][p];
        else {
            now = tr[id][now][p ^ 1];
            res |= 1 << i;
        }
        // cout << i << endl;
    }
    
    if (res != ans) return empt;
    else return leaf[tr[id][now][0]];
}
inline void es(int id) {
    ps[mk[id]]--;
    auto res = query(id, mk[id] ^ 1);
    if (res.first == ans)
        sume -= res.second;
    del(id, mk[id]);
}
inline bool check(int y) {
    if (ps[mk[y]] > 1) {
        auto res = query(y, mk[y] ^ 1);
        if (res.first == ans && res.second == sume) return false;
    }
    return true;
}
set<int> que[2];
int main() {
    freopen("roast.in", "r", stdin);
    freopen("roast.out", "w", stdout);
    // freopen("..\\HeTao\\SXD3\\A\\roast3.in", "r", stdin);
    // freopen("..\\HeTao\\SXD3\\A\\roast.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    bool flag = true;
    for (int i = 1; i < n; i++)
        flag = (flag && (a[i] == a[i + 1]));
    if (flag) {
        for (int i = 1; i <= n; i++) cout << i << " \n"[i == n];
        return 0;
    }
    array<vector<int>, 2> t;
    for (int d = 30; ~d; d--) {
        bool flag = true;
        for (int i = 1; i < n; i++)
            flag = flag && (((a[i] >> d) & 1) == ((a[i + 1] >> d) & 1));
        if (flag) continue;
        for (int i = 1; i <= n; i++) {
            mk[i] = ((a[i] >> d) & 1);
            ps[mk[i]]++;
            t[mk[i]].push_back(i);
        }
        break;
    }
    for (int i = 1; i <= n; i++) insert(i, mk[i]);
    for (int i = 1; i <= n; i++)
        if (mk[i]) {
            auto res = query(i, 0);
            if (res.first < ans) {
                ans = res.first;
                sume = res.second;
            } else if (res.first == ans) {
                sume += res.second;
            }
        }
    int now = 0;
    for (int i = 1; i <= n; i++) {
        if (ps[mk[i]] > 1) {
            auto res = query(i, mk[i] ^ 1);
            if (res.first == ans && res.second == sume) continue;
        }
        now = i;
        break;
    }
    cout << now << ' ';
    for (int i = 1; i <= n; i++) {
        if (i != now) que[mk[i]].insert(i);
    }
    es(now);
    for (int _ = 2; _ <= n; _++) {
        auto obj = qry(now, mk[now] ^ 1);
        auto i1 = que[mk[now]].begin(), i2 = obj.begin();
        while (true) {
            int f = 0;
            if (i1 == que[mk[now]].end()) f = 2;
            else if (i2 == obj.end()) f = 1;
            else if ((*i1) < (*i2)) f = 1;
            else f = 2;
            if (f == 1) {
                if (check(*i1)) {
                    now = *i1;
                    break;
                } else i1++;
            } else {
                if (check(*i2)) {
                    now = *i2;
                    break;
                } else i2++;
            }
        }
        que[mk[now]].erase(now);
        es(now);
        cout << now << " \n"[_ == n];
    }
    // cerr << clock() << endl;
    return 0;
}