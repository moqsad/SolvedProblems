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

struct data
{
    long long  dist, city;

    bool operator < (const data & p) const
    {
        return dist > p.dist;
    }
};

long long  dist1[10005], dist2[10005], n;
vector <long long> edge1[10005], edge2[10005], cost1[10005], cost2[10005];
priority_queue <data> q;

void dijkstra1(long long s)
{
    long long i, x, y;

    for(i = 1; i <= n; ++i)
        dist1[i] = 100000000000000LL;

    dist1[s] = 0;

    data u, v;

    u.city = s;
    u.dist = 0;

    q.push(u);

    while(!q.empty())
    {
        u = q.top();
        q.pop();
        y = u.city;
        x = edge1[y].size();

        for(i = 0; i < x; ++i)
        {
            v.city = edge1[y][i];
            v.dist = dist1[y] + cost1[y][i];

            if(dist1[v.city] > v.dist)
            {
                dist1[v.city] = v.dist;
                q.push(v);
            }
        }
    }
}

void dijkstra2(long long s)
{
    long long i, x, y;

    for(i = 1; i <= n; ++i)
        dist2[i] = (long long)100000000000000;

    dist2[s] = 0;

    data u, v;

    u.city = s;
    u.dist = 0;

    q.push(u);

    while(!q.empty())
    {
        u = q.top();
        q.pop();
        y = u.city;
        x = edge2[y].size();

        for(i = 0; i < x; ++i)
        {
            v.city = edge2[y][i];
            v.dist = dist2[y] + cost2[y][i];

            if(dist2[v.city] > v.dist)
            {
                dist2[v.city] = v.dist;
                q.push(v);
            }
        }
    }
}

int  main()
{
    long long  m, s, t, p, i, j, x, cnt, T, max_, a, b, c;

    scanf("%lld", &T);

    for(cnt = 1; cnt <= T; ++cnt)
    {
        scanf("%lld %lld %lld %lld %lld", &n, &m, &s, &t, &p);

        for(i = 0; i < m; ++i)
        {
            scanf("%lld %lld %lld", &a, &b, &c);
            edge1[a].push_back(b);
            edge2[b].push_back(a);
            cost1[a].push_back(c);
            cost2[b].push_back(c);
        }

        dijkstra1(s);
        dijkstra2(t);

        max_ = -1;

        for(i = 1; i <= n; ++i)
        {
//            printf("%lld %lld_________\n", dist1[i], dist2[i]);
            x = edge1[i].size();

            for(j = 0; j < x; ++j)
            {
                if(dist1[i] + dist2[edge1[i][j]] + cost1[i][j] <= p)
                    max_ = max(cost1[i][j], max_);
            }

            edge1[i].clear();
            edge2[i].clear();
            cost1[i].clear();
            cost2[i].clear();
        }

        printf("Case %lld: %lld\n", cnt, max_);
    }
    return 0;
}
