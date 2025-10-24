#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int n, m;
int h[N], e[N], ne[N], idx;
int f[N], din[N], dout[N];
bool vis[N], flag, mevis[N];
vector<int> me;
queue<int> q;
void Clear(void)
{
    memset(h, 0, sizeof(h));
    memset(e, 0, sizeof(e));
    memset(ne, 0, sizeof(ne));
    idx = 0;
    memset(f, 0, sizeof(f));
    memset(din, 0, sizeof(din));
    memset(dout, 0, sizeof(dout));
    memset(vis, 0, sizeof(vis));
    flag = 0;
    memset(mevis, 0, sizeof(mevis));
    me.clear();
    while (!q.empty())
        q.pop();
}
int read()
{
    int x;
    scanf("%d", &x);
    return x;
}
void add(int u, int v)
{
    e[++idx] = v;
    ne[idx] = h[u];
    h[u] = idx;
    return;
}
bool topsort()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (din[i] == 0)
        {
            cnt++;

            q.push(i);
            f[i] = 1;
        }
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = h[u]; i != 0; i = ne[i])
        {
            int v = e[i];
            f[v] = max(f[v], f[u] + 1);
            din[v]--;
            if (din[v] == 0)
            {
                cnt++;
                q.push(v);
            }
        }
    }
    return cnt == n;
}
int main()
{
    freopen("xcx.in","r",stdin);
    freopen("xcx.out", "w", stdout);
    int T;
    T = read();
    while (T--)
    {
        Clear();
        n = read(), m = read();
        for (int i = 1; i <= m; i++)
        {
            int x = read(), y = read();
            if (x == y && !vis[x])
            {
                vis[x] = true;
                me.push_back(x);
            }
            else
            {
                add(x, y);
                dout[x]++, din[y]++;
            }
        }
        sort(me.begin(), me.end());
        me.erase(unique(me.begin(), me.end()), me.end());
        if (me.size() >= 2 || (me.size() == 1 && dout[me[0]] >= 1))
        {
            puts("Poor cx");
            continue;
        }
        if (!topsort())
        {
            puts("Poor cx");
            continue;
        }
        int ans = 0, macnt = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans, f[i]);
        for (int i = 1; i <= n; i++)
            if (f[i] == ans)
                macnt++;
        if (me.size() == 1)
        {
            if (f[me[0]] == ans && macnt == 1)
                printf("Let's play\n%d\n", ans - 1);
            else
                printf("Let's play\n%d\n", ans);
        }
        else
        {
            if (macnt == 1)
                printf("Let's play\n%d\n", ans - 1);
            else
                puts("Poor cx");
        }
    }
    return 0;
}