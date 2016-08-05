#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

#define inf 1000000000
#define sz 101

int n, price[sz], dist[sz][sz];

vector <int> edge[sz], cost[sz];

struct data
{
    int city, dist, gas;

    bool operator < (const data & p) const
    {
        return dist > p.dist;
    }
};

void dijkstra(int c, int s, int t)
{
    int i, j, x, y;

    priority_queue <data> q;

    for(i = 0; i < n; ++i)
        for(j = 0; j <= c; ++j)
            dist[i][j] = inf;

    data u, v;
    u.gas = 0;
    u.city = s;
    u.dist = 0;

    q.push(u);
    dist[s][0] = 0;

    while(!q.empty())
    {
        u = q.top();

        q.pop();

        y = u.city;
        if(y == t)
            return ;
        x = edge[y].size();

        if(u.gas + 1 <= c && u.dist + price[y] < dist[y][u.gas + 1])
        {
            v.gas = u.gas + 1;
            v.city = y;
            v.dist = u.dist + price[y];
            q.push(v);
            dist[v.city][v.gas] = v.dist;
        }

        for(i = 0; i < x; ++i)
        {
            v.city = edge[y][i];
            if(u.gas >= cost[y][i])
            {
                if(u.dist < dist[v.city][u.gas - cost[y][i]])
                {
                    v.dist = u.dist;
                    v.gas = u.gas - cost[y][i];
                    q.push(v);
                    dist[v.city][v.gas] = v.dist;
                }
            }
        }
    }
}

int main()
{
    int t, cnt, s, tt, a, b, c, m, i, q;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &m);

        for(i = 0; i < n; ++i)
            scanf("%d", &price[i]);

        for(i = 0; i < m; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            edge[a].push_back(b);
            edge[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);
        }

        printf("Case %d:\n", cnt);
        scanf("%d", &q);
        for(i = 0; i < q; ++i)
        {
            scanf("%d %d %d", &c, &s, &tt);
            dijkstra(c, s, tt);
            if(dist[tt][0] < inf)
                printf("%d\n", dist[tt][0]);
            else
                printf("impossible\n");
        }

        for(i = 0; i < n; ++i)
        {
            edge[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
