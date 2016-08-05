#include <bits/stdc++.h>
using namespace std;

#define sz

struct data
{
    int u, v;
}bridge[1000005];

#define sz 1005

int low[sz], dist[sz];

vector <int> edge[sz], conn[sz];

void arti(int node, int par)
{
    int i, x = edge[node].size(), y;

    low[node] = dist[node] = ++total;

    for(i = 0; i < x; ++i)
    {
        y = edge[node][i];

        if(!dist[y])
        {
            arti(y, node);

            low[node] = min(low[node], low[y]);

            if(dist[node] > low[y])
            {
                bridge[ans].u = node;
                bridge[ans++].v = y;
            }

            else
            {
                conn[node].push_back(y);
                conn[y].push_back(node);
            }
        }

        else if(y != par)
            low[node] = min(low[node], dist[y]);
    }
}

void dfs(int node)
{
    dist[node] = 1;
    int i, y, x = edge[node].size();

    for(i = 0; i < x; ++i)
    {
        y = edge[node][i];

        if(!dist[y])
        {
            printf("%d %d\n", node, y);
            dfs(y, node);
        }
        else
        {
            if(y != par && dist[y] == 1)
                printf("%d %d\n", node, y);
        }
    }
    dist[node] = 2;
}

int main()
{
    int n, m, i, a, b;
    while(scanf("%d %d", &n, &m) == 2 && (n || m))
    {
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &a, &b);
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        ans = total = 0;

        for(i = 1; i <= n; ++i)
        {
            if(!dist[i])
                arti(i, -1);
        }

        memset(dist, 0, sizeof(dist));

        for(i = 1; i <= n; ++i)
        {
            if(!dist[i])
                dfs(i, -1);
        }

        for(i = 1; i <= n; ++i)
        {
            edge[i].clear();
            conn[i].clear();
            dist[i] = 0;
        }
    }
    return 0;
}
