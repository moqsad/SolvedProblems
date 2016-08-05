#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct data
{
    int city, dist;
    bool operator < (const data & p) const
    {
        return dist > p.dist;
    }
};

int d[110], n;
vector <int> edge[110], cost[110];

void dijkstra(int start)
{
    int i, x;
    for(i = 1; i <= n; ++i)
        d[i] = 1000000000;

    priority_queue <data> q;

    data u, v;
    d[start] = 0;
    u.city = start;
    u.dist = 0;
    q.push(u);

    while(!q.empty())
    {
        u = q.top();
        q.pop();
        x = edge[u.city].size();
        for(i = 0; i < x; ++i)
        {
            v.city = edge[u.city][i];
            v.dist = d[u.city] + cost[u.city][i];
            if(v.dist < d[v.city])
            {
                d[v.city] = v.dist;
                q.push(v);
            }
        }
//        printf("______\n");
    }
}

int main()
{
    int cnt, t, i, j, m, x, min_, a, b, c;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &m);
        for(i = 0;  i  < m; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            edge[a].push_back(b);
            edge[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);
        }

        min_ = 1000000000;
        for(i = 1; i <= n; ++i)
        {
            dijkstra(i);
            if(d[1] == d[2] && d[2] == d[3] && d[3] == d[4] && d[4] == d[5])
            {
                x = 0;

                for(j = 1; j <= n; ++j)
                    if(d[j] < 1000000000)
                    {
                        if(d[j] > x)
                            x = d[j];
                    }
                    else
                        break;

                if(j > n && min_ > x)
                    min_ = x;
            }
        }

        if(min_ < 1000000000)
            printf("Map %d: %d\n", cnt, min_);
        else
            printf("Map %d: -1\n", cnt);

        for(i = 1; i <= n; ++i)
        {
            edge[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
