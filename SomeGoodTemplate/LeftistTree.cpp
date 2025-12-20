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