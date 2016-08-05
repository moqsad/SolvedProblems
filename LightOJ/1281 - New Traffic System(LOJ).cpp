#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

#define inf 2000000000

struct data
{
    int city, dist, new_;

    bool operator < (const data & p) const
    {
        return dist > p.dist;
    }
};

priority_queue <data> q;
int d, dist[10005][12];

vector <int> edge[10005], cost[10005], edge2[10005], cost2[10005];

void dijkstra()
{
    data u, v;
    int i, y, x;

    u.city = 0;
    u.dist = 0;
    u.new_ = 0;

    dist[0][0] = 0;

    q.push(u);

    while(!q.empty())
    {
//        printf("___________\n");
        u = q.top();

        q.pop();

        y = u.city;
        x = edge[y].size();

        for(i = 0; i < x; ++i)
        {
            v.city = edge[y][i];
            v.dist = dist[y][u.new_] + cost[y][i];
            v.new_ = u.new_;

            if(dist[v.city][v.new_] > v.dist)
            {
                q.push(v);
                dist[v.city][v.new_] = v.dist;
            }
        }

        x = edge2[u.city].size();
        for(i = 0; i < x; ++i)
        {
            v.city = edge2[y][i];
            v.dist = dist[y][u.new_] + cost2[y][i];
            v.new_ = u.new_ + 1;

            if(v.new_ <= d && dist[v.city][v.new_] > v.dist)
            {
                q.push(v);
                dist[v.city][v.new_] = v.dist;
            }
        }
    }
}

int main()
{
    int t, cnt, i, j, n, m, k, min_, a, b, c;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d %d %d", &n, &m, &k, &d);

        for(i = 0; i < m; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);

            edge[a].push_back(b);
            cost[a].push_back(c);
        }

        for(i = 0; i < k; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);

            edge2[a].push_back(b);
            cost2[a].push_back(c);
        }

        for(i = 0; i < n; ++i)
            for(j = 0; j <= d; ++j)
                dist[i][j] = inf;

        dijkstra();

        --n;
        min_ = inf;
        for(i = 0; i <= d; ++i)
            min_ = min(min_, dist[n][i]);

        if(min_ < inf)
            printf("Case %d: %d\n", cnt, min_);
        else
            printf("Case %d: Impossible\n", cnt);

        for(i = 0; i <= n; ++i)
        {
            edge[i].clear();
            edge2[i].clear();
            cost[i].clear();
            cost2[i].clear();
        }
    }
    return 0;
}

/*
2
7 5 4 3
0 1 10
1 2 5
3 4 12
4 5 14
6 4 2
0 6 50
0 2 5
2 3 7
5 6 9

*/
