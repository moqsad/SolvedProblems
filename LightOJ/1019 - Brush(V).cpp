#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int d[110];

struct data
{
    int city, dist;
    bool operator < (const data & p) const
    {
        return dist > p.dist;
    }
};

vector <int> edge[110], cost[110];

void dijkstra(int n)
{
    int i, x;
    priority_queue <data> q;
    for(i = 1; i <= n; ++i)
        d[i] = 100000000;
    d[1] = 0;
    data u, v;
    u.city = 1;
    u.dist = 0;
    q.push(u);
    while(!q.empty())
    {
        u = q.top();
        if(u.city == n)
            break;
        q.pop();
        x = edge[u.city].size();
        for(i = 0; i < x; ++i)
        {
            v.city = edge[u.city][i];
            v.dist = d[u.city] + cost[u.city][i];
            if(d[v.city] > v.dist)
            {
                d[v.city] = v.dist;
                q.push(v);
            }
        }
    }
}

int main()
{
    int t, cnt, a, b, c, n, m, i;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &m);
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            edge[a].push_back(b);
            edge[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);
        }
        dijkstra(n);
        if(d[n] != 100000000)
            printf("Case %d: %d\n", cnt, d[n]);
        else
            printf("Case %d: Impossible\n", cnt);
        for(i = 1; i <= n; ++i)
        {
            edge[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
