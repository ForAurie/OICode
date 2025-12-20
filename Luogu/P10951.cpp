#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int e[N], ne[N], h[N], tot;
int x, n, m, t, w[N], st;
double l, r, mid, ans = -1, len[N], d[N];
bool flag, vis[N];
void add(int x, int y)
{
    e[++tot] = y, ne[tot] = h[x], h[x] = tot;
} // 添加函数
int f(char ch)
{
    switch (ch)
    {
    case 'S':
        t = 0;
        return 1000;
    case 'G':
        t = 1;
        return 500;
    case 'D':
        t = 2;
        return 300;
    case 'T':
        t = 3;
        return 200;
    case 'K':
        t = 4;
        return 150;
    }
    return -1;
} // 打表
bool dfs(int x)
{
    vis[x] = 1;
    for (int i = h[x]; i; i = ne[i])
    {
        int y = e[i];
        double z = len[i];
        if (d[y] > d[x] + z)
        {
            d[y] = d[x] + z;
            if (vis[y] || dfs(y))
                return 1;
        }
    }
    vis[x] = 0;
    return 0;
}
bool check(double x)
{
    for (int i = 1; i <= m; ++i)
        len[i] = x - w[i];
    memset(vis, 0, sizeof vis);
    memset(d, 0x3f, sizeof d);
    for (int i = 1; i < N; ++i)
        if (dfs(i))
            return 1;
    return 0;
}
int main()
{
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        char s[114];
        scanf("%s", s);
        x = 0, flag = 0, n = strlen(s);
        for (int j = 0; j < n; j++)
        {
            if ('0' <= s[j] && s[j] <= '9')
                x = x * 10 + s[j] - '0'; // 数位分离
            else if (s[j] == '-')
            {
                if (!flag)
                    st = x + t * 10000; // 映射
                flag = 1;
                x = 0;
            }
            else
                w[i] += f(s[j]);
        }
        int ed = x + t * 10000;
        add(st, ed);
    }
    l = 0, r = 0x3f3f3f3f;
    while (r - l > 1e-8)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    if (l == 0)
    {
        cout << -1;
        return 0;
    } // 别忘了没有输出-1
    printf("%.0f\n", l);
    return 0;
}