#include <bits/stdc++.h>
#ifndef ATCODER_INTERNAL_BITOP_HPP
#define ATCODER_INTERNAL_BITOP_HPP 1
namespace atcoder {
	namespace internal {
		unsigned int bit_ceil(unsigned int n) {
			unsigned int x = 1;
			while (x < (unsigned int)(n)) x *= 2;
			return x;
		}
		int countr_zero(unsigned int n) {
			return __builtin_ctz(n);
		}
		constexpr int countr_zero_constexpr(unsigned int n) {
			int x = 0;
			while (!(n & (1 << x))) x++;
			return x;
		}
	} 
}
#endif
namespace atcoder {
	template <class S, auto op, auto e, class F, auto mapping, auto composition, auto id>
	struct lazy_segtree {
		static_assert(std::is_convertible_v<decltype(op), std::function<S(S, S)>>, "op must work as S(S, S)");
		static_assert(std::is_convertible_v<decltype(e), std::function<S()>>, "e must work as S()");
		static_assert(std::is_convertible_v<decltype(mapping), std::function<S(F, S)>>, "mapping must work as S(F, S)");
		static_assert(std::is_convertible_v<decltype(composition), std::function<F(F, F)>>, "composition must work as F(F, F)");
		static_assert(std::is_convertible_v<decltype(id), std::function<F()>>, "id must work as F()");
	public:
		lazy_segtree() : lazy_segtree(0) {}
		explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
		explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
			size = (int)internal::bit_ceil((unsigned int)(_n));
			log = internal::countr_zero((unsigned int)size);
			d = std::vector<S>(2 * size, e());
			lz = std::vector<F>(size, id());
			for (int i = 0; i < _n; i++) d[size + i] = v[i];
			for (int i = size - 1; i >= 1; i--) {
				update(i);
			}
		}
		void set(int p, S x) {
			assert(0 <= p && p < _n);
			p += size;
			for (int i = log; i >= 1; i--) push(p >> i);
			d[p] = x;
			for (int i = 1; i <= log; i++) update(p >> i);
		}
		S get(int p) {
			assert(0 <= p && p < _n);
			p += size;
			for (int i = log; i >= 1; i--) push(p >> i);
			return d[p];
		}
		S prod(int l, int r) {
			assert(0 <= l && l <= r && r <= _n);
			if (l == r) return e();
			l += size;
			r += size;
			for (int i = log; i >= 1; i--) {
				if (((l >> i) << i) != l) push(l >> i);
				if (((r >> i) << i) != r) push((r - 1) >> i);
			}
			S sml = e(), smr = e();
			while (l < r) {
				if (l & 1) sml = op(sml, d[l++]);
				if (r & 1) smr = op(d[--r], smr);
				l >>= 1;
				r >>= 1;
			}
			return op(sml, smr);
		}
		S all_prod() { return d[1]; }
		void apply(int p, F f) {
			assert(0 <= p && p < _n);
			p += size;
			for (int i = log; i >= 1; i--) push(p >> i);
			d[p] = mapping(f, d[p]);
			for (int i = 1; i <= log; i++) update(p >> i);
		}
		void apply(int l, int r, F f) {
			assert(0 <= l && l <= r && r <= _n);
			if (l == r) return;
			l += size;
			r += size;
			for (int i = log; i >= 1; i--) {
				if (((l >> i) << i) != l) push(l >> i);
				if (((r >> i) << i) != r) push((r - 1) >> i);
			}
			{
				int l2 = l, r2 = r;
				while (l < r) {
					if (l & 1) all_apply(l++, f);
					if (r & 1) all_apply(--r, f);
					l >>= 1;
					r >>= 1;
				}
				l = l2;
				r = r2;
			}
			for (int i = 1; i <= log; i++) {
				if (((l >> i) << i) != l) update(l >> i);
				if (((r >> i) << i) != r) update((r - 1) >> i);
			}
		}
		template <bool (*g)(S)> int max_right(int l) {
			return max_right(l, [](S x) { return g(x); });
		}
		template <class G> int max_right(int l, G g) {
			assert(0 <= l && l <= _n);
			assert(g(e()));
			if (l == _n) return _n;
			l += size;
			for (int i = log; i >= 1; i--) push(l >> i);
			S sm = e();
			do {
				while (l % 2 == 0) l >>= 1;
				if (!g(op(sm, d[l]))) {
					while (l < size) {
						push(l);
						l = (2 * l);
						if (g(op(sm, d[l]))) {
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
		template <bool (*g)(S)> int min_left(int r) {
			return min_left(r, [](S x) { return g(x); });
		}
		template <class G> int min_left(int r, G g) {
			assert(0 <= r && r <= _n);
			assert(g(e()));
			if (r == 0) return 0;
			r += size;
			for (int i = log; i >= 1; i--) push((r - 1) >> i);
			S sm = e();
			do {
				r--;
				while (r > 1 && (r % 2)) r >>= 1;
				if (!g(op(d[r], sm))) {
					while (r < size) {
						push(r);
						r = (2 * r + 1);
						if (g(op(d[r], sm))) {
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
		std::vector<F> lz;
		void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
		void all_apply(int k, F f) {
			d[k] = mapping(f, d[k]);
			if (k < size) lz[k] = composition(f, lz[k]);
		}
		void push(int k) {
			all_apply(2 * k, lz[k]);
			all_apply(2 * k + 1, lz[k]);
			lz[k] = id();
		}
	};
}

using namespace std;
constexpr int mod = 998244353;
// int pow2[N];

int op(int l, int r) {
    return (l + r) % mod;
}

int e() { return 0; }

int mapping(int f, int x) { return (int) ((long long) f * x % mod); }

int composition(int f, int g) { return (int) ((long long) f * g % mod); }

int id() { return 1; }

typedef atcoder::lazy_segtree<int, op, e, int, mapping, composition, id> tree;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(1, 0), suf(1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (pre.empty() || a[i] > pre.back()) pre.push_back(a[i]);
    }
    for (int i = n; i >= 1; i--) {
        if (suf.empty() || a[i] > suf.back()) suf.push_back(a[i]);
    }
    const int top = pre.back(); suf.pop_back();
    vector<vector<int>> anspre(n + 2, vector<int>(2)), anssuf(n + 2, vector<int>(1));
    tree dppre(pre.size()), dpsuf(suf.size());
    dppre.set(0, 1);
    dpsuf.set(0, 1);
    anspre[0][1] = dppre.get(pre.size() - 1);
    anspre[0][0] = dppre.get(pre.size() - 2);
    anssuf[n + 1][0] = dpsuf.get(suf.size() - 1);
    for (int i = 1; i <= n; i++) {
        // for (int j = 0; j < (int) pre.size(); j++) {
        //     if (pre[j] > a[i]) dppre[i][j] = 2 * dppre[i - 1][j] % mod;
        //     else if (pre[j] == a[i]) dppre[i][j] = (2 * dppre[i - 1][j] % mod + dppre[i - 1][j - 1]) % mod;
        //     else dppre[i][j] = dppre[i - 1][j];
        // }
        int p = lower_bound(pre.begin(), pre.end(), a[i]) - pre.begin();
        dppre.apply(p, pre.size(), 2);
        if (p < (int) pre.size() && pre[p] == a[i])
            dppre.set(p, (dppre.get(p) + dppre.get(p - 1)) % mod);
        anspre[i][1] = dppre.get(pre.size() - 1);
        anspre[i][0] = dppre.get(pre.size() - 2);
    }
    for (int i = n; i >= 1; i--) {
        // for (int j = 0; j < (int) suf.size(); j++) {
        //     if (suf[j] > a[i]) dpsuf[i][j] = 2 * dpsuf[i + 1][j] % mod;
        //     else if (suf[j] == a[i]) dpsuf[i][j] = (2 * dpsuf[i + 1][j] % mod + dpsuf[i + 1][j - 1]) % mod;
        //     else dpsuf[i][j] = dpsuf[i + 1][j];
        // }
        int p = lower_bound(suf.begin(), suf.end(), a[i]) - suf.begin();
        dpsuf.apply(p, suf.size(), 2);
        if (p < (int) suf.size() && suf[p] == a[i])
            dpsuf.set(p, (dpsuf.get(p) + dpsuf.get(p - 1)) % mod);
        anssuf[i][0] = dpsuf.get(suf.size() - 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != top) continue;
        (ans += (long long) (anspre[i - 1].back() + anspre[i - 1].front()) * anssuf[i + 1].back() % mod) %= mod;
        // if (a[i] != top) continue;
        // for (int j = i; j <= n; j++) {
        //     if (a[j] != top) continue;
        //     (ans += (long long) dppre[i - 1].back() * dpsuf[j + 1].back() % mod * pow2[max(j - i - 1, 0)] % mod) %= mod;
        // }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    // pow2[0] = 1;
    // for (int i = 1; i < N; i++) pow2[i] = 2 * pow2[i - 1] % mod;
    while (t--) solve();
    return 0;
}