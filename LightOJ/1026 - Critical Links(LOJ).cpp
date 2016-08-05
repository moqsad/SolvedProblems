#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

struct data
{
    int u, v;
};

vector <int> edge[10005];

int par[10005], dist[10005], low[10005], ans;
data bridge[10005];

void dfs(int node, int d)
{
    int i, y, x = edge[node].size();

    low[node] = dist[node] = ++d;

    for(i = 0; i < x; ++i)
    {
        y = edge[node][i];

        if(!dist[y])
        {
            par[y] = node;

            dfs(y, d);

            low[node] = min(low[node], low[y]);
//            printf("%d %d______%d %d\n", node, low[node], y, low[y]);

            if(low[y] > dist[node])
            {
                bridge[ans].u = node;
                bridge[ans].v = y;
                if(node > y)
                    swap(bridge[ans].u, bridge[ans].v);
                ++ans;
            }
        }

        else if(y != par[node])
            low[node] = min(low[node], dist[y]);
    }
}

bool comp(data p, data q)
{
    if(p.u != q.u)
        return p.u < q.u;
    return p.v < q.v;
}

int main()
{
    int t, cnt, n, i, j, k, a, b;
    scanf("%d", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);

        for(i = 0; i < n; ++i)
        {
            scanf("%d (%d)", &a, &k);

            for(j = 0; j < k; ++j)
            {
                scanf("%d", &b);
                edge[a].push_back(b);
            }
        }

        ans = 0;

        for(i = 0; i < n; ++i)
        {
            if(!par[i])
            {
                par[i] = 100000000;
                dfs(i, 0);
            }
        }

        printf("Case %d:\n",cnt);
        printf("%d critical links\n", ans);
        sort(bridge + 0, bridge + ans, comp);
        for(i = 0; i < ans; ++i)
            printf("%d - %d\n", bridge[i].u, bridge[i].v);

        for(i = 0; i < n; ++i)
        {
            edge[i].clear();
            dist[i] = 0;
            par[i] = 0;
        }
    }
    return 0;
}
