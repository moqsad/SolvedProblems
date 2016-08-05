#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

#define inf 200000000

struct data
{
    int u, v, c;
};

int dist[205], arr[205];

vector <data> edge;

int main()
{
    int t, cnt, n, m, i, j, x, y, d;
    data info;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);

        for(i = 1; i <= n; ++i)
        {
            scanf("%d", &arr[i]);
            dist[i] = inf;
        }

        scanf("%d", &m);

        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &info.u, &info.v);
            info.c = arr[info.v] - arr[info.u];
            info.c = info.c * info.c * info.c;
            edge.push_back(info);
        }

        dist[1] = 0;
        for(i = 1; i < n; ++i)
        {
            for(j = 0; j < m; ++j)
            {
                if(dist[edge[j].v] > edge[j].c + dist[edge[j].u])
                    dist[edge[j].v] = edge[j].c + dist[edge[j].u];
            }
        }

        for(j = 0; j < m; ++j)
        {
            if(dist[edge[j].v] > edge[j].c + dist[edge[j].u])
                dist[edge[j].v] = - inf;
        }


        printf("Case %d:\n", cnt);

        scanf("%d", &x);
        for(i = 0; i < x; ++i)
        {
            scanf("%d", &d);
            if(dist[d] > 2 && dist[d] < 2000000)
                printf("%d\n", dist[d]);
            else
                printf("?\n");
        }

        edge.clear();
    }
    return 0;
}
