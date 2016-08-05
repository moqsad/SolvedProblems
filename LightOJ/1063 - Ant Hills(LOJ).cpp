#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

vector <int> edge[10005];

int par[10005], dist[10005], low[10005], ans;

void dfs(int node, int d)
{
    dist[node] = low[node] = ++d;

    int i, child = 0, p = 0, y, x = edge[node].size();

    for(i = 0; i < x; ++i)
    {
        y = edge[node][i];
        if(!par[y])
        {
            par[y] = node;

            dfs(y, d);

            low[node] = min(low[node], low[y]);
//            printf("%d %d______%d %d\n", node, low[node], y, low[y]);

            if(node == 1)
            {
                if(++child > 1)
                    p = 1;
            }

            else if(low[y] >= dist[node])
                p = 1;
        }

        else if(y != par[node])
            low[node] = min(low[node], dist[y]);
    }

    if(p == 1)
        ++ans;
}

int main()
{
    int t, cnt, a, b, i, n, m;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &m);
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &a, &b);
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        par[1] = 100000000;
        ans = 0;
        dfs(1, 0);
        printf("Case %d: %d\n", cnt, ans);

        for(i = 1; i <= n; ++i)
        {
            par[i] = 0;
            edge[i].clear();
        }
    }
    return 0;
}
