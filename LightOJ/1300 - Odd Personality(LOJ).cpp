#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;

vector <int> edge[10005], conn[10005];

int j, member, p, low[10005], dist[10005], par[100005];

void find_bridge(int node,int d)
{
    int y, i, x = edge[node].size();
    dist[node] = low[node] = ++d;
    for(i = 0; i < x; i++)
    {
        y=edge[node][i];

        if(!dist[y])
        {
            par[y] = node;
            find_bridge(y, d);

            low[node] = min(low[node],low[y]);

            if(low[y] <= dist[node])
            {
                conn[node].push_back(y);
                conn[y].push_back(node);
            }
        }

        else if(y != par[node])
        {
            low[node] = min(low[node], low[y]);

            if(dist[node] > dist[y])
            {
                conn[node].push_back(y);
                conn[y].push_back(node);
            }
        }
    }
}

void dfs(int node)
{
    ++member;

    int i, y, x = conn[node].size();

    for(i = 0; i < x; ++i)
    {
        y = conn[node][i];

        if(!dist[y])
        {
            if(dist[node] == 1)
                dist[y] = 2;
            else
                dist[y] = 1;
            dfs(y);
        }

        else
        {
            if(dist[y] == dist[node])
                p = 1;
        }
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

        for(i = 0; i < n; ++i)
        {
            if(!dist[i])
            {
                par[i] = 100000000;
                find_bridge(i, 0);
            }
        }

        memset(dist, 0, sizeof(dist));

        ans = 0;
        for(j = 0; j < n; ++j)
        {
            if(!dist[j])
            {
                dist[j] = 1;
                p = 0;
                member = 0;
                dfs(j);
                if(p == 1)
                    ans += member;
            }
        }

        for(i = 0; i < n; ++i)
        {
            edge[i].clear();
            conn[i].clear();
            dist[i] = 0;
        }

        printf("Case %d: %d\n", cnt, ans);
    }
    return 0;
}
/*
special case : for the condition if(low[y] <= low[node])
10
6 7
0 1
1 2
2 3
3 0
3 4
4 5
5 1
*/
