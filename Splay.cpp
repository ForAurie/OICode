#include <bits/stdc++.h>

template<typename T>
struct Node {
    T value;
    size_t count, size;
    Node<T> *fa, *son[2];
    Node() : value(), count(0), size(0), fa(nullptr), son{nullptr, nullptr} {}
    Node(
        const T& value,
        size_t count = 0,
        size_t size = 0,
        Node<T>* fa = nullptr,
        Node<T>* ls = nullptr,
        Node<T>* rs = nullptr
    ): 
        value(value),
        count(count),
        size(size),
        fa(fa),
        son{ls, rs}
    {}
};

template<typename T, typename Compare = std::less<T>>
class Splay {
private:
    Node<T>* root;
    Compare cmp;
    static size_t get_sz(Node<T>* u) { return u ? u->size : 0; }
    inline void pushup(Node<T>* u) { u->size = get_sz(u->son[0]) + get_sz(u->son[1]) + u->count; } // 不会为空
    void rotate(Node<T>* u) { // u->fa 必须有效
        Node<T>* f = u->fa;
        Node<T>* ff = f->fa;
        const bool r = (f->son[1] == u);
        f->son[r] = u->son[!r];
        if (u->son[!r]) u->son[!r]->fa = f;
        u->son[!r] = f;
        f->fa = u;
        u->fa = ff;
        if (ff) ff->son[ff->son[1] == f] = u;
        pushup(f);
        pushup(u);
    }
    inline void splay(Node<T>* u, Node<T>* to = nullptr) {
        // if (!u) return; // 不会为空
        for (Node<T>* f; (f = u->fa) != to; rotate(u))
            if (f->fa != to) rotate(((f->son[1] == u) ^ (f->fa->son[1] == f)) ? u : f);
        pushup(u);
        if (!to) root = u;
    }
    void erase(Node<T>* u) {
        if (!u) return;
        splay(u);
        if (u->count > 1) { u->count--; pushup(u); return; } // 根可以直接 pushup
        Node<T>* L = u->son[0]; Node<T>* R = u->son[1];
        if (!L) {
            if (R) R->fa = nullptr;
            root = R;
            delete u; return;
        }
        L->fa = nullptr;
        while (L->son[1]) L = L->son[1];
        splay(L);
        L->son[1] = R;
        if (R) R->fa = L;   
        pushup(root = L); // 根可以直接 pushup
        delete u;
    }
    Node<T>* find(const T& v) {
        if (!root) return nullptr;
        Node<T>* u = root; bool s;
        while ((s = cmp(u->value, v), (s || cmp(v, u->value))) && u->son[s]) u = u->son[s]; 
        splay(u);
        return u;
    }
    Node<T>* get_by_rank(size_t rk) {
        if (rk >= get_sz(root)) return nullptr; // get_sz 已经有非空判断了
        Node<T>* u = root;
        while (true) {
            size_t left = get_sz(u->son[0]);
            if (rk < left) u = u->son[0];
            else if (rk < left + u->count) { splay(u); return u; } 
            else rk -= left + u->count, u = u->son[1];
        }
    }
    Node<T>* prev_upper_bound(const T& v) {
        if (!root) return nullptr;
        find(v);
        if (cmp(root->value, v)) return root;
        Node<T>* u = root->son[0];
        if (!u) return nullptr;
        while (u->son[1]) u = u->son[1];
        splay(u);
        return u;
    }
    Node<T>* prev_upper_bound(Node<T>* u) {
        if (!u) return nullptr;
        splay(u);
        u = u->son[0];
        if (!u) return nullptr;
        while (u->son[1]) u = u->son[1];
        splay(u);
        return u;
    }
    Node<T>* upper_bound(const T& v) {
        if (!root) return nullptr;
        find(v);
        if (cmp(v, root->value)) return root;
        Node<T>* u = root->son[1];
        if (!u) return nullptr;
        while (u->son[0]) u = u->son[0];
        splay(u);
        return u;
    }
    Node<T>* upper_bound(Node<T>* u) {
        if (!u) return nullptr;
        splay(u);
        u = u->son[1];
        if (!u) return nullptr;
        while (u->son[0]) u = u->son[0];
        splay(u);
        return u;
    }
    Node<T>* lower_bound(const T& v) {
        if (!root) return nullptr;
        find(v);
        if (!cmp(root->value, v)) return root;
        Node<T>* u = root->son[1];
        if (!u) return nullptr;
        while (u->son[0]) u = u->son[0];
        splay(u);
        return u;
    }
    Node<T>* prev_lower_bound(const T& v) {
        if (!root) return nullptr;
        find(v);
        if (!cmp(v, root->value)) return root;
        Node<T>* u = root->son[0];
        if (!u) return nullptr;
        while (u->son[1]) u = u->son[1];
        splay(u);
        return u;
    }
    size_t rank_of(Node<T>* u) {
        if (!u) return get_sz(root);
        splay(u);
        return get_sz(u.son[0]);
    }
    size_t rank_of_value(const T& v) {
        if (!root) return 0;
        find(v);
        if (cmp(root->value, v)) return root->count + get_sz(root->son[0]);
        else return get_sz(root->son[0]);
    }
public:
    class iterator {
        private:
            Node<T>* ptr;
        public:
            iterator(Node<T>* p) : ptr(p) {}
            // T& operator*() { return ptr->value; }
            const T& operator*() const { return ptr->value; }
            iterator& operator++() {
                ptr = upper_bound(ptr);
                return *this;
            }
            iterator operator++(int) {
                iterator temp = *this;
                ++(*this);
                return temp;
            }
            iterator& operator--() {
                ptr = prev_upper_bound(ptr);
                return *this;
            }
            iterator operator--(int) {
                iterator temp = *this;
                --(*this);
                return temp;
            }
            iterator operator+(size_t k) const {
                return iterator(get_by_rank(rank_of(ptr) + k));
            }
            iterator operator-(size_t k) const {
                return iterator(get_by_rank(rank_of(ptr) - k));
            }
            size_t operator-(const iterator& other) const {
                return rank_of(ptr) - rank_of(other.ptr);
            }
            iterator& operator+=(size_t k) {
                ptr = get_by_rank(rank_of(ptr) + k);
                return *this;
            }
            iterator& operator-=(size_t k) {
                ptr = get_by_rank(rank_of(ptr) - k);
                return *this;
            }
            bool operator!=(const iterator& other) const { return ptr != other.ptr; }
            bool operator==(const iterator& other) const { return ptr == other.ptr; }
            bool is_valid() const { return ptr != nullptr; }
    };
    Splay(): root(nullptr), cmp(Compare()) {}
    ~Splay() { clear(root); }
    void clear(Node<T>* u) { if (!u) { return; } clear(u->son[0]); clear(u->son[1]); delete u; }
    inline size_t size() const { return get_sz(root); }
    bool empty() const { return root == nullptr; }
    void insert(const T& v) {
        if (!root) { root = new Node<T>(v, 1, 1); return; }
        Node<T>* u = root; bool s;
        while ((s = cmp(u->value, v), (s || cmp(v, u->value))) && u->son[s]) u = u->son[s];
        if (cmp(u->value, v) || cmp(v, u->value)) splay(u->son[cmp(u->value, v)] = new Node<T>(v, 1, 1, u));
        else u->count++, splay(u);
    }
    void erase(const T& v) {
        Node<T>* u = find(v);
        if (!u) return;
        if (u->count > 1) { u->count--; pushup(u); return; } // 根可以直接 pushup
        // splay(u); find(v) 已经 splay 过了
        Node<T>* L = u->son[0]; Node<T>* R = u->son[1];
        if (!L) {
            if (R) R->fa = nullptr;
            root = R;
            delete u; return;
        }
        L->fa = nullptr;
        while (L->son[1]) L = L->son[1];
        splay(L);
        L->son[1] = R;
        if (R) R->fa = L;
        pushup(root = L); // 根可以直接 pushup
        delete u;
    }
    iterator begin() {
        if (!root) return iterator(nullptr);
        Node<T>* u = root;
        while (u->son[0]) u = u->son[0];
        splay(u);
        return iterator(u);
    }
    iterator end() {
        return iterator(nullptr);
    }
    void erase(iterator it) {
        erase(it.ptr);
    }
    iterator get_by_rank(size_t rk) {
        return iterator(this->get_by_rank(rk));
    }
    iterator prev_upper_bound(const T& v) {
        return iterator(this->prev_upper_bound(v));
    }
    iterator upper_bound(const T& v) {
        return iterator(this->upper_bound(v));
    }
    iterator lower_bound(const T& v) {
        return iterator(this->lower_bound(v));
    }
    iterator prev_lower_bound(const T& v) {
        return iterator(this->prev_lower_bound(v));
    }
    iterator upper_bound(iterator it) {
        return iterator(upper_bound(it.ptr));
    }
    iterator prev_upper_bound(iterator it) {
        return iterator(prev_upper_bound(it.ptr));
    }
    size_t rank_of(iterator it) {
        return rank_of(it.ptr);
    }
    size_t rank_of(const T& v) {
        return rank_of_value(v);
    }
    iterator find(const T& v) {
        return iterator(find(v));
    }
    size_t count(const T& v) {
        Node<T>* u = find(v);
        return u ? u->count : 0;
    }
};
using namespace std;

Splay<int> ST;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x;
    cin >> n >> m;
    while (n--) {
        cin >> x;
        ST.insert(x);
    }
    int last = 0, ans = 0, op;
    while (m--) {
        cin >> op >> x;
        x ^= last;
        if (op == 1) {
            ST.insert(x);
        } else if (op == 2) {
            ST.erase(x);
        } else if (op == 3) {
            last = ST.rank_of_value(x) + 1;
            ans ^= last;
        } else if (op == 4) {
            last =  ST.get_by_rank(x - 1)->value;
            ans ^= last;
        } else if (op == 5) {
            last = ST.prev_upper_bound(x)->value;
            ans ^= last;
        } else if (op == 6) {
            last = ST.upper_bound(x)->value;
            ans ^= last;
        }
    }
    cout << ans << endl;
    return 0;
}