#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, d[2100], airport_ace[2100];

vector <int> edge[2100];

struct data
{
    int city, dist;
    bool operator < (const data & p) const
    {
        return dist > p.dist;
    }
};

void dijkstra(int start, int finish)
{
    int i, j, x, y;

    for(i = 1; i <= n; ++i)
        d[i] = 1000000000;

    priority_queue <data> q;

    data u, v;
    u.dist = airport_ace[start];
    u.city = start;
    d[start] = 0;
    q.push(u);

    while(!q.empty())
    {
        u = q.top();
        if(u.city == finish)
            break;
        q.pop();

        x = edge[u.city].size();
        for(i = 0; i < x; ++i)
        {
            v.city = edge[u.city][i];
            v.dist = u.dist + airport_ace[v.city];
            if(v.dist < d[v.city])
            {
                d[v.city] = v.dist;
                q.push(v);
            }
        }
    }
}

int main()
{
    int t, cnt, a, b, m, k, q, i, j;

    scanf("%d", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d %d", &n, &m, &k);

        for(i = 1; i <= n; ++i)
        {
            airport_ace[i] = 1;
        }

        for(i = 1; i <= k; ++i)
        {
            scanf("%d", &a);
            airport_ace[a] = 0;
        }

        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &a, &b);
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        scanf("%d", &q);
        printf("Case %d:\n", cnt);
        for(i = 0; i < q; ++i)
        {
            scanf("%d %d", &a, &b);
            dijkstra(a, b);
            if(d[b] < 1000000000)
                printf("%d\n", d[b]);
            else
                printf("-1\n");
        }

        printf("\n");

        for(i = 1; i <= n; ++i)
        {
            edge[i].clear();
        }
    }
    return 0;
}
