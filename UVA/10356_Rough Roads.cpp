#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int d[5][510];

struct data
{
    int dist, city, level;
    bool operator < (const data & p) const
    {
        return dist >  p.dist;
    }
};

vector <int> edge[510], cost[510];

void dijkstra(int n)
{
    int i, j, x, y;
    data u, v;
    priority_queue <data> q;
    for(i = 0; i < n; ++i)
    {
        d[1][i] = 100000000;
        d[2][i] = 100000000;
    }
    u.city = 0;
    u.dist = 0;
    u.level = 2;
    q.push(u);
    d[2][0] = 0;
    while(!q.empty())
    {
        u = q.top();
        q.pop();
        y = u.city;
        x = edge[y].size();
        for(i = 0; i < x; ++i)
        {
            v.city = edge[y][i];
            if(u.level == 1)
                v.level = 2;
            else
                v.level = 1;
            v.dist = cost[y][i] + d[u.level][y];
            if(v.dist < d[v.level][v.city])
            {
                q.push(v);
                d[v.level][v.city] = v.dist;
            }
        }
    }
}

int main()
{
    int n, m, a, b, c, i, j, cnt = 0;
    while(scanf("%d %d", &n, &m) == 2)
    {
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            edge[a].push_back(b);
            edge[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);
        }
        dijkstra(n);
        for(i = 0; i < n; ++i)
        {
            edge[i].clear();
            cost[i].clear();
        }
        printf("Set #%d\n", ++cnt);
        --n;
        if(d[2][n] < 100000000)
            printf("%d\n", d[2][n]);
        else
            printf("?\n");
    }
    return 0;
}
