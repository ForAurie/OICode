struct FHQ {
    int ch[MAXN][2], val[MAXN], mn[MAXN], mn_pos[MAXN], sz[MAXN], tag[MAXN], prio[MAXN], root, tot;
    FHQ() { root = tot = 0; }
    int newnode(int v) {
        ++tot;
        val[tot] = mn[tot] = v;
        mn_pos[tot] = 0;
        sz[tot] = 1;
        tag[tot] = 0;
        prio[tot] = rand();
        ch[tot][0] = ch[tot][1] = 0;
        return tot;
    }

    void push_up(int x) {
        sz[x] = 1;
        mn[x] = val[x];
        mn_pos[x] = 0;
        int left = ch[x][0];
        int right = ch[x][1];

        if (left) {
            sz[x] += sz[left];
        }
        if (right) {
            sz[x] += sz[right];
        }
        int base = left ? sz[left] : 0;
        if (left) {
            mn[x] = mn[left];
            mn_pos[x] = mn_pos[left];
        }
        if (val[x] < mn[x] || 
           (val[x] == mn[x] && base < mn_pos[x])) {
            mn[x] = val[x];
            mn_pos[x] = base;
        }
        if (right) {
            int right_pos = base + 1 + mn_pos[right];
            if (mn[right] < mn[x] ||
               (mn[right] == mn[x] && right_pos < mn_pos[x])) {
                mn[x] = mn[right];
                mn_pos[x] = right_pos;
            }
        }
    }
    void push_down(int x) {
        if (tag[x]) {
            for (int i = 0; i < 2; i++) {
                int c = ch[x][i];
                if (c) {
                    val[c] += tag[x];
                    mn[c] += tag[x];
                    tag[c] += tag[x];
                }
            }
            tag[x] = 0;
        }
    }
    void split(int now, int k, int &x, int &y) {
        if (!now) {
            x = y = 0;
            return;
        }
        push_down(now);
        if (sz[ch[now][0]] >= k) {
            y = now;
            split(ch[now][0], k, x, ch[now][0]);
            push_up(y);
        } else {
            x = now;
            split(ch[now][1], k - sz[ch[now][0]] - 1, ch[now][1], y);
            push_up(x);
        }
    }
    int merge(int x, int y) {
        if (!x || !y) return x + y;
        if (prio[x] < prio[y]) {
            push_down(x);
            ch[x][1] = merge(ch[x][1], y);
            push_up(x);
            return x;
        } else {
            push_down(y);
            ch[y][0] = merge(x, ch[y][0]);
            push_up(y);
            return y;
        }
    }
    void insert(int pos, int v) {
        int a, b;
        split(root, pos, a, b);
        int node = newnode(v);
        root = merge(merge(a, node), b);
    }
    void prefix_add(int pos, int delta) {
        int a, b;
        split(root, pos + 1, a, b);
        if (a) {
            val[a] += delta;
            mn[a] += delta;
            tag[a] += delta;
        }
        root = merge(a, b);
    }
    pair<int,int> suffix_min(int pos) {
        int a, b;
        split(root, pos, a, b);
        pair<int,int> ans;
        if (!b) {
            ans = {INT_MAX, -1};
        } else {
            ans = {mn[b], mn_pos[b] + pos};
        }
        root = merge(a, b);
        return ans;
    }
} fhq;