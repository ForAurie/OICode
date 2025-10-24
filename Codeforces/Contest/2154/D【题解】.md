## 思路

对于构造类问题，可以从和题目有关的“充分、必要条件”入手。首先要保证删除节点时没有把 cat 所在的节点删掉，记 cat 与点 $1$ 的距离的奇偶数性为 $s$（可以实时维护出来，每执行一次操作 $1$，$s$ 就会改变），点 $p$ 与点 $1$ 的距离为 $dis_p$，若 $s$ 与 $dis_p$ 的奇偶性不同则可以安全的把点 $p$ 删掉。有了这一结论，就可以在三次操作内安全的删除任意想要删掉的节点，在删除之前，先执行一次操作 $1$ 用于把操作 $2$ 隔开（题目要求操作 $2$ 不能相邻），如果此时 $s$ 的奇偶性和 $dis_p$ 相同则再执行一次操作 $1$ 使得其奇偶性不同，然后执行操作 $2$ 删除点 $p$。

如果可以不断的、绝对安全的执行删除操作直到只剩下点 $n$，则最终 cat 一定在点 $n$。总共有 $n$ 个点，每删除一个点最多需要三次操作，总次数不超过 $3n$。但此时有一个问题，如果将点 $p$ 删除可能会使得 cat 与 $n$ 不连通，发现删除叶子节点一定不会使得连通块数量增加，所以不妨钦定 $p$ 为非 $n$ 的叶子节点。显然这样的点一定存在。

::::info[证明]

一棵树至少有两个叶子节点，排除掉 $n$，一定至少存在一个合法的叶子。

::::


## 代码

```cpp
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x, y;
    cin >> n;
    vector<bool> dis(n + 1);
    vector<vector<int>> G(n + 1);
    array<stack<int>, 2> leaf; // 按与 1 距离的奇偶性维护叶子
    vector<int> d(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
        ++d[x], ++d[y];
    }
    function<void(int, int)> dfs = [&](int u, int fa) {
        for (int v : G[u]) {
            if (v == fa) continue;
            dis[v] = dis[u] ^ 1;
            dfs(v, u);
        }
    };
    dfs(1, 1);
    int now = 0;
    for (int i = 1; i < n; i++)
        if (d[i] == 1) leaf[dis[i]].push(i), d[i] = 0;
    vector<int> ans;
    while (leaf[0].size() || leaf[1].size()) {
        ans.push_back(0);
        now ^= 1;
        if (leaf[0].size()) {
            if (now == 0) ans.push_back(0), now ^= 1;
            ans.push_back(leaf[0].top());
            for (int v : G[leaf[0].top()]) {
                if (v == n || d[v] == 0) continue;
                if (--d[v] == 1) leaf[dis[v]].push(v), d[v] = 0;
            }
            leaf[0].pop();
        } else {
            if (now == 1) ans.push_back(0), now ^= 1;
            ans.push_back(leaf[1].top());
            for (int v : G[leaf[1].top()]) {
                if (v == n || d[v] == 0) continue;
                if (--d[v] == 1) leaf[dis[v]].push(v), d[v] = 0;
            }
            leaf[1].pop();
        }
    }
    cout << ans.size() << '\n';
    for (auto i : ans) {
        if (i) cout << "2 " << i << '\n';
        else cout << "1\n";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
```