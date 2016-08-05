#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int par[102], n, edge[102][102], cost[102][102], visit[102];

int bfs(int s, int e)
{
    memset(visit, 0, sizeof(visit));
    par[s] = -1;
    visit[s] = 1;
    queue <int> q;
    q.push(s);
    int u, i;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(i = 1; i <= n; ++i)
        {
            if(visit[i] == 0 && edge[u][i] == 1 && cost[u][i] > 0)
            {
                visit[i] = 1;
                q.push(i);
                par[i] = u;
                if(i == e)
                    return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int i, ed, a, b, c, cnt = 0, s, e, min_, x, ans;
    while(scanf("%d", &n) == 1 && n)
    {
        scanf("%d %d %d", &s, &e, &ed);

        memset(edge, 0, sizeof(edge));
        memset(cost, 0, sizeof(cost));

        for(i = 0; i < ed; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            edge[a][b] = 1;
            edge[b][a] = 1;
            cost[a][b] += c;
            cost[b][a] += c;
        }

        ans = 0;
        while(bfs(s, e))
        {
            min_ = 100000000;
            x = e;
            while(par[x] > 0)
            {
                min_ = min(min_, cost[par[x]][x]);
                x = par[x];
            }

            x = e;
            while(par[x] > 0)
            {
                cost[par[x]][x] -= min_;
                cost[x][par[x]] += min_;
                x = par[x];
            }

            ans += min_;
        }
        printf("Network %d\nThe bandwidth is %d.\n\n", ++cnt, ans);
    }
    return 0;
}

