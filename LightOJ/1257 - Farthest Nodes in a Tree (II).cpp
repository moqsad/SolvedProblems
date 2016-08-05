#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

vector <int> edge[30010], cost[30010];

int vertex, total, cnt, dist1[30010], dist2[30010];

void dfs(int par, int node, int dist)
{
    int i, x = edge[node].size();

    if(cnt == 1)
        dist1[node] = dist;
    else
        dist2[node] = dist;

    if(dist > total)
    {
        total = dist;
        vertex = node;
    }

    for(i = 0; i < x; ++i)
    {
        if(edge[node][i] != par)
            dfs(node, edge[node][i], dist + cost[node][i]);
    }
}

int main()
{
    int t, cnt2, a, b, c, n, i, node1, node2;
    scanf("%d", &t);
    for(cnt2 = 1; cnt2 <= t; ++cnt2)
    {
        scanf("%d", &n);
        for(i = 1; i < n; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            edge[a].push_back(b);
            edge[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);
        }

        printf("Case %d:\n", cnt2);

        cnt = total = 0;
        dfs(-1, 0, 0);
        node1 = vertex;
        cnt = 1;
        total = 0;
        dfs(-1, node1, 0);
        node2 = vertex;
        cnt = 2;
        dfs(-1, node2, 0);

        for(i = 0; i < n; ++i)
        {
            printf("%d\n", (dist1[i] > dist2[i]) ? dist1[i] : dist2[i]);
            edge[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}

/*
6
6
0 1 10
1 2 10
2 3 10
3 4 10
4 5 10
*/
