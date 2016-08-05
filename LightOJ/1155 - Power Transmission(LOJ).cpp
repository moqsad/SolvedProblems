#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
using namespace std;

#define inf 900000000

int n, visit[205], edge[205][205], par[205];

int bfs(void)
{
    int u, i;
    memset(visit, 0, sizeof(visit));
    queue <int> q;
    q.push(0);
    visit[0] = 1;
    par[0] = -1;

    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(i = 0; i <= n; ++i)
        {
            if(visit[i] == 0 && edge[u][i] > 0)
            {
                par[i] = u;
                if(i == n)
                    return 1;
                q.push(i);
                visit[i] = 1;
            }
        }
    }
    return 0;
}

int main()
{
    int t, cnt, i, a, b, c, d, min_, ans, ed, x;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        ans = 0;
        memset(edge, 0, sizeof(edge));
        scanf("%d", &n);

        for(i = 1; i <= n; ++i)
            scanf("%d", &edge[i][i + n]);

        scanf("%d", &ed);
        for(i = 0; i < ed; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            edge[a + n][b] = c;
        }

        scanf("%d %d", &b, &d);
        for(i = 0; i < b; ++i)
        {
            scanf("%d", &a);
            edge[0][a] = inf;
        }

        x = 2 * n + 1;
        for(i = 0; i < d; ++i)
        {
            scanf("%d", &a);
            edge[a + n][x] = inf;
        }

        n = x;
        while(bfs())
        {
            min_ = inf;
            x = n;
            while(par[x] >= 0)
            {
                min_ = min(min_, edge[par[x]][x]);
                x = par[x];
            }

            x = n;

            while(par[x] >= 0)
            {
                edge[par[x]][x] -= min_;
                edge[x][par[x]] += min_;
                x = par[x];
            }

            ans += min_;
        }
        printf("Case %d: %d\n", cnt, ans);
    }
    return 0;
}
