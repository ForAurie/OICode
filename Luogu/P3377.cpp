#include <bits/stdc++.h>
using namespace std;

template<typename T>
class LeftistTree {
private:
    T val;
    unique_ptr<LeftistTree> ls, rs;
    size_t h;

public:
    explicit LeftistTree(T val)
        : val(std::move(val)), ls(nullptr), rs(nullptr), h(1) {}

    LeftistTree(LeftistTree&& other) noexcept
        : val(std::move(other.val)),
          ls(std::move(other.ls)),
          rs(std::move(other.rs)),
          h(other.h) {}

    LeftistTree& operator=(LeftistTree&& other) noexcept {
        if (this != &other) {
            val = std::move(other.val);
            ls = std::move(other.ls);
            rs = std::move(other.rs);
            h = other.h;
        }
        return *this;
    }

    // 禁用拷贝
    LeftistTree(const LeftistTree&) = delete;
    LeftistTree& operator=(const LeftistTree&) = delete;

    static unique_ptr<LeftistTree> merge(unique_ptr<LeftistTree> a, unique_ptr<LeftistTree> b) {
        if (!a) return b;
        if (!b) return a;
        if (b->val < a->val)
            swap(a, b);
        a->rs = merge(std::move(a->rs), std::move(b));
        int hl = a->ls ? a->ls->h : 0;
        int hr = a->rs ? a->rs->h : 0;
        if (hl < hr) swap(a->ls, a->rs);
        a->h = (a->rs ? a->rs->h : 0) + 1;
        return a;
    }

    static unique_ptr<LeftistTree> pop(unique_ptr<LeftistTree> root) {
        if (!root) return nullptr;
        return merge(std::move(root->ls), std::move(root->rs));
    }

    const T& top() const { return val; }
};

constexpr int N = 1e5 + 10;
int f[N], mk[N];

int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<unique_ptr<LeftistTree<pair<int, int>>>> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a[i] = make_unique<LeftistTree<pair<int, int>>>(make_pair(x, i));
        f[i] = i;
    }

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            if (mk[x] || mk[y]) continue;
            x = find(x);
            y = find(y);
            if (x == y) continue;
            a[x] = LeftistTree<pair<int, int>>::merge(std::move(a[x]), std::move(a[y]));
            f[y] = x;
        } else if (op == 2) {
            int x;
            cin >> x;
            if (mk[x]) {
                cout << -1 << '\n';
                continue;
            }
            x = find(x);
            if (!a[x]) {
                cout << -1 << '\n';
                continue;
            }
            cout << a[x]->top().first << '\n';
            mk[a[x]->top().second] = 1;
            a[x] = LeftistTree<pair<int, int>>::pop(std::move(a[x]));
        }
    }
    return 0;
}
