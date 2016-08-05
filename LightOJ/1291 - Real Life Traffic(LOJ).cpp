#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;

vector <int> conn[10005], edge[10005];

struct data
{
    int u, v;
};

data bridge[10005];

int low[10005], dist[10005], par[10005], j, k;

void find_bridge(int node, int d)
{
    dist[node] = low[node] = ++d;

    int i, y, x = edge[node].size();

    for(i = 0; i < x; ++i)
    {
        y = edge[node][i];

        if(!dist[y])
        {
            par[y] = node;

            find_bridge(y, d);

            low[node] = min(low[node], low[y]);

            if(low[y] <= dist[node])
            {
                conn[node].push_back(y);
                conn[y].push_back(node);
            }

            else
            {
                bridge[k].u = node;
                bridge[k].v = y;
                ++k;
            }
        }

        else if(y != par[node])
        {
            if(dist[node] > dist[y])
            {
                conn[node].push_back(y);
                conn[y].push_back(node);
            }
            low[node] = min(dist[y], low[node]);
        }
    }
}

void dfs(int node)
{
//    printf("%d______\n", node);
    dist[node] = 1;
    par[node] = j;

    int i, y, x = conn[node].size();

    for(i = 0; i < x; ++i)
    {
        y = conn[node][i];

        if(!dist[y])
            dfs(y);
    }
}

int main()
{
    int t, cnt, n, m, i, a, b, ans;

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

        par[0] = 100000000;
        k = 0;
        find_bridge(0, 0);

        memset(dist, 0, sizeof(dist));

        for(j = 0; j < n; ++j)
        {
            if(!dist[j])
                dfs(j);
        }

        memset(dist, 0, sizeof(dist));

        ans = 0;

        for(i = 0; i < k; ++i)
        {
            ++dist[par[bridge[i].u]];
            ++dist[par[bridge[i].v]];
        }

        for(i = 0; i < n; ++i)
        {
//            printf("%d : %d\n", i, dist[i]);
            if(dist[i] == 1)
                ++ans;
            conn[i].clear();
            edge[i].clear();
            dist[i] = 0;
        }

        if(ans % 2)
            ans = ans / 2 + 1;
        else
            ans /= 2;

        printf("Case %d: %d\n", cnt, ans);
    }
    return 0;
}
/*
8 10
3 1
1 7
7 4
4 6
1 5
5 0
3 2
7 6
4 1
4 3
*/
