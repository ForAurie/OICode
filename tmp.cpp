    // iterator types
    // struct const_iterator;
    // struct iterator {
    //     using value_type = T;
    //     using reference = T&;
    //     using pointer = T*;
    //     using difference_type = std::ptrdiff_t;
    //     using iterator_category = std::bidirectional_iterator_tag;

    //     Splay* tree;
    //     node_type* node;
    //     size_t rep;

    //     iterator(Splay* t=nullptr, node_type* n=nullptr, size_t r=0): tree(t), node(n), rep(r) {}

    //     reference operator*() const { return node->val; }
    //     pointer operator->() const { return &node->val; }

    //     bool operator==(const iterator& o) const { return tree==o.tree && node==o.node && rep==o.rep; }
    //     bool operator!=(const iterator& o) const { return !(*this==o); }

    //     iterator& operator++() {
    //         if (!tree || !node) return *this;
    //         if (rep + 1 < node->cnt) { ++rep; return *this; }
    //         node = tree->successor(node);
    //         rep = 0;
    //         return *this;
    //     }
    //     iterator operator++(int) { iterator t = *this; ++*this; return t; }

    //     iterator& operator--() {
    //         if (!tree) return *this;
    //         if (!node) { node = tree->rightmost(tree->root); rep = node ? node->cnt - 1 : 0; return *this; }
    //         if (rep > 0) { --rep; return *this; }
    //         node = tree->predecessor(node);
    //         rep = node ? node->cnt - 1 : 0;
    //         return *this;
    //     }
    //     iterator operator--(int) { iterator t = *this; --*this; return t; }

    //     operator const_iterator() const { return const_iterator(tree, node, rep); }
    // };

    // struct const_iterator {
    //     using value_type = T;
    //     using reference = const T&;
    //     using pointer = const T*;
    //     using difference_type = std::ptrdiff_t;
    //     using iterator_category = std::bidirectional_iterator_tag;

    //     const Splay* tree;
    //     node_type* node;
    //     size_t rep;

    //     const_iterator(const Splay* t=nullptr, node_type* n=nullptr, size_t r=0): tree(t), node(n), rep(r) {}
    //     const T& operator*() const { return node->val; }
    //     const T* operator->() const { return &node->val; }
    //     bool operator==(const const_iterator& o) const { return tree==o.tree && node==o.node && rep==o.rep; }
    //     bool operator!=(const const_iterator& o) const { return !(*this==o); }
    //     const_iterator& operator++() {
    //         if (!tree || !node) return *this;
    //         if (rep + 1 < node->cnt) { ++rep; return *this; }
    //         node = tree->successor(node);
    //         rep = 0; return *this;
    //     }
    //     const_iterator operator++(int) { const_iterator t=*this; ++*this; return t; }
    //     const_iterator& operator--() {
    //         if (!tree) return *this;
    //         if (!node) { node = tree->rightmost(tree->root); rep = node ? node->cnt - 1 : 0; return *this; }
    //         if (rep > 0) { --rep; return *this; }
    //         node = tree->predecessor(node);
    //         rep = node ? node->cnt - 1 : 0; return *this;
    //     }
    //     const_iterator operator--(int) { const_iterator t=*this; --*this; return t; }
    // };

    // iterator begin() { node_type* u = leftmost(root); return u ? iterator(this,u,0) : end(); }
    // iterator end() { return iterator(this, nullptr, 0); }
    // const_iterator begin() const { node_type* u = leftmost(root); return u ? const_iterator(this,u,0) : cend(); }
    // const_iterator end() const { return const_iterator(this, nullptr, 0); }
    // const_iterator cbegin() const { return begin(); }
    // const_iterator cend() const { return end(); }

    // using reverse_iterator = std::reverse_iterator<iterator>;
    // reverse_iterator rbegin() { return reverse_iterator(end()); }
    // reverse_iterator rend() { return reverse_iterator(begin()); }