#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int start, finish, n, d[15], par[15], arr[15];

vector <int> edge[15];
vector <int> cost[15];

struct data
{
    int city, dist;
    bool operator < (const data & p) const
    {
        return dist > p.dist;
    }
};

void dijkstra(void)
{
    int i, x, y;
    data u, v;

    for(i = 1; i <= n; ++i)
        d[i] = 2147483645;
    priority_queue <data> Q;
    u.city = start;
    u.dist = 0;
    Q.push(u);
    d[start] = 0;
    while(!Q.empty())
    {
        u = Q.top();
        if(u.city == finish)
            break;
        Q.pop();
        x = edge[u.city].size();
        for(i = 0; i < x; ++i)
        {
            v.city = edge[u.city][i];
            v.dist = cost[u.city][i] + d[u.city];
            if(v.dist < d[v.city])
            {
                d[v.city] = v.dist;
                Q.push(v);
                par[v.city] = u.city;
            }
        }
    }
}

int main()
{
    int i, j, k, b, c, m, cnt = 0;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            break;

        for(i = 1; i <= n; ++i)
        {
            scanf("%d", &m);
            for(j = 0; j <m; ++j)
            {
                scanf("%d %d", &b, &c);
                edge[i].push_back(b);
                cost[i].push_back(c);
            }
        }

        scanf("%d %d", &start, &finish);
        b = finish;
        dijkstra();
        i = 0;
        arr[i++] = finish;
        while(par[finish] != start)
        {
            arr[i++] = par[finish];
            finish = par[finish];
        }
        arr[i++] = start;

        printf("Case %d: Path =", ++cnt);
        for(j = i - 1; j >= 0; --j)
            printf(" %d", arr[j]);
        printf("; %d second delay\n", d[b]);

        for(i = 1; i <= n; ++i)
        {
            edge[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
