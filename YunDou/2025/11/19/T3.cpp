#ifndef ATCODER_SEGTREE_HPP
#define ATCODER_SEGTREE_HPP

#include <algorithm>
#include <cassert>
#include <functional>
#include <vector>

/* #include "atcoder/internal_bit" */
#ifndef ATCODER_INTERNAL_BITOP_HPP
#define ATCODER_INTERNAL_BITOP_HPP

#ifdef _MSC_VER
#include <intrin.h>
#endif

#if __cplusplus >= 202002L
#include <bit>
#endif

namespace atcoder {

namespace internal {

#if __cplusplus >= 202002L

using std::bit_ceil;

#else

// @return same with std::bit::bit_ceil
unsigned int bit_ceil(unsigned int n) {
    unsigned int x = 1;
    while (x < (unsigned int)(n)) x *= 2;
    return x;
}

#endif

// @param n `1 <= n`
// @return same with std::bit::countr_zero
int countr_zero(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

// @param n `1 <= n`
// @return same with std::bit::countr_zero
constexpr int countr_zero_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

}  // namespace internal

}  // namespace atcoder

#endif  // ATCODER_INTERNAL_BITOP_HPP
/* ------------------------------- */

namespace atcoder {

#if __cplusplus >= 201703L

template <class S, auto op, auto e> struct segtree {
    static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>,
                  "op must work as S(S, S)");
    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,
                  "e must work as S()");

#else

template <class S, S (*op)(S, S), S (*e)()> struct segtree {

#endif

  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        size = (int)internal::bit_ceil((unsigned int)(_n));
        log = internal::countr_zero((unsigned int)size);
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder

#endif  // ATCODER_SEGTREE_HPP


int op(int x, int y) { return x < y ? x : y; }
int e() { return 0x3f3f3f3f; }
typedef atcoder::segtree<int, op, e> tree;

#include <bits/stdc++.h>

using namespace std;
constexpr int N = 2e5 + 10;
int n, q, a[N], ans[N];
vector<int> G[N];

struct opt {
    int op, x, v, id;
    bool operator<(const opt& o) const {
        return x > o.x;
    }
};

int main() {
    freopen("fall.in", "r", stdin);
    freopen("fall.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int op, x, y;
    vector<int> _d(n + 10);
    for (int i = 1; i < n; i++) cin >> x >> y, _d[x]++, _d[y]++, G[x].push_back(y), G[y].push_back(x);
    bool flag = true;
    vector<opt> qs;
    for (int i = 1; i <= q; i++) {
        cin >> op;
        if (op == 1) {
            flag = false;
            cin >> x >> y;
            qs.push_back({op, x, y, i});
        } else {
            cin >> x;
            qs.push_back({op, x, 0, i});
        }
    }
    for (int i = 1; i <= n; i++)
        sort(G[i].begin(), G[i].end(), [&](int x, int y){ return a[x] < a[y]; });
    int cntd1 = 0, cntd2 = 0;
    for (int i = 1; i <= n; i++) {
        cntd1 += (_d[i] == 1);
        cntd2 += (_d[i] == 2);
    }
    const bool flagl = (cntd1 == 2) && (cntd2 == n - 2); // && false;
    if (flag) {
        cerr << 1 << endl;
        vector<int> rnk(n + 10);
        vector<pair<int, int>> mn(n + 10, make_pair(0x3f3f3f3f, 0));
        function<void(int, int)> dfs = [&](int u, int fa) -> void {
            mn[u].second = u;
            for (int v : G[u]) {
                if (v == fa) continue;
                mn[v].first = min(mn[u].first, a[v]);
                dfs(v, u);
            }
            static int idx = 0;
            rnk[u] = ++idx;
        };
        dfs(1, 1);
        sort(mn.begin() + 1, mn.begin() + 1 + n, greater<pair<int, int>>());
        sort(qs.begin(), qs.end());
        int idx = 1;
        pair<int, int> now = make_pair(rnk[1], 1);
        for (const auto& i : qs) {
            while (idx <= n  && mn[idx].first >= i.x)
                now = min(now, make_pair(rnk[mn[idx].second], mn[idx].second)), idx++;
            ans[i.id] = now.second;
        }
        for (int i = 1; i <= q; i++)
            if (ans[i]) cout << ans[i] << '\n';
    } else if (flagl) {
        cerr << 3 << endl;
        tree tr(vector<int>(n + 10, e()));
        vector<int> rnk(n + 10), fi(n + 10);
        int last = 0, now = 1, idx = 0;
        while (true) {
            rnk[now] = ++idx;
            fi[idx] = now;
            if (G[now].size() < 2 && now != 1) break;
            for (int v : G[now]) {
                if (v == last) continue;
                last = now;
                now = v;
                break;
            }
        }
        for (int i = 1; i <= n; i++)
            tr.set(rnk[i], a[i]);
        for (const auto& i : qs) {
            if (i.op == 1) {
                tr.set(rnk[i.x], i.v);
            } else {
                int l = 1, r = n, mid;
                while (l < r) {
                    mid = (l + r + 1) >> 1;
                    if (tr.prod(2, mid + 1) >= i.x) l = mid;
                    else r = mid - 1;
                }
                cout << fi[l] << '\n';
            }
        }
    } else {
        cerr << 2 << endl;
        vector<set<pair<int, int>>> son(n + 10);
        vector<int> fa(n + 10);
        function<void(int)> dfs = [&](int u) -> void {
            son[fa[u]].insert(make_pair(a[u], u));
            for (int v : G[u]) {
                if (v == fa[u]) continue;
                fa[v] = u;
                dfs(v);
            }
        };
        dfs(1);
        for (const auto& i : qs) {
            if (i.op == 1) {
                son[fa[i.x]].erase(make_pair(a[i.x], i.x));
                a[i.x] = i.v;
                son[fa[i.x]].insert(make_pair(a[i.x], i.x));
            } else {
                int now = 1;
                while (true) {
                    auto it = son[now].lower_bound(make_pair(i.x, 0));
                    if (it == son[now].end()) break;
                    now = it->second;
                }
                cout << now << '\n';
            }
        }
    }
    return 0;
}