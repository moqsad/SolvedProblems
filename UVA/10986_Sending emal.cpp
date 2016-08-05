#include <bits/stdc++.h>

using namespace std;

#define SZ 20010
int inf = 2140000000;

vector<int> edge[SZ], cost[SZ];
int d[SZ];
int n;

struct data
{
    int city, dist;
    bool operator < ( const data& p ) const
    {
        return dist > p.dist;
    }
};

void dijkstra(int source, int destination)
{
    int i, p;

    for(i=1; i <= n; i++)
        d[i] = inf;

    priority_queue <data> q;

    data u, v;

    u.city = source;
    u.dist = 0;

    q.push( u );
    d[source] = 0;
    while( !q.empty() )
    {
        u = q.top();
        q.pop();

        for(i=0; i<edge[u.city].size(); i++)
        {
            v.city = edge[u.city][i];
            v.dist = cost[u.city][i] + d[u.city];
            if(d[v.city] > v.dist)
            {
                d[v.city] = v.dist;
                q.push( v );
            }
        }
    }

//    return d[destination];
}

int main()
{
    int m, i, j, k, l, cnt, t, start, endd, x;

    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d %d %d", &n, &m, &start, &endd);
        for(i=0; i<m; i++)
        {
            scanf("%d %d %d",&j,&k,&l);

            edge[j].push_back(k);
            edge[k].push_back(j);

            cost[j].push_back(l);
            cost[k].push_back(l);
        }

        dijkstra(start, endd);
        x = d[endd];
        if(x < inf)
            printf("Case #%d: %d\n", cnt, x);
        else
            printf("Case #%d: unreachable\n", cnt);
        for(i=0; i < n; i++)
        {
            edge[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}
/*
5 6 1 5
1 2 2
1 3 5
2 3 1
2 5 7
3 4 3
4 5 2
*/

