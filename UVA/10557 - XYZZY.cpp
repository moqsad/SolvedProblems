#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

struct data
{
    int u, v;
};



vector <data> vv;
vector <int> g[105];
int cost[105], d[105], cycle[105], visit[105], n, found;

void dfs(int node)
{
//    printf("%d*****\n", node);
    if(cycle[node] == 1)
    {
        found = 1;
        return ;
    }

    int x, y, i;
    visit[node] = 1;
    x = g[node].size();
    for(i = 0; i < x; ++i)
    {
        y = g[node][i];
        if(!visit[y])
        {
            dfs(y);
            if(found == 1)
                return ;
        }
    }
}

void bell(void)
{
    int i, x, cnt, y, p;

    for(i = 1; i <= n; ++i)
        d[i] = -1000000000;

    memset(cycle, 0, sizeof(cycle));

    x = vv.size();

    d[1] = 100;

    for(cnt = 1; cnt <= n; ++cnt)
    {
        p = 0;
        for(i = 0; i < x; ++i)
        {
            if(d[vv[i].u] > 0)
            {
                y = d[vv[i].u] + cost[vv[i].v];
                if(y > 0 && y > d[vv[i].v])
                {
                    p = 1;
                    d[vv[i].v] = y;
                    if(n == cnt)
                    {
                        cycle[vv[i].v] = 1;
                    }
                }
            }
        }
        if(p == 0)
            break;
    }

//    for(i = 1; i <= n; ++i)
//        printf("_______%d\n", cycle[i]);

    if(d[n] > 0)
        printf("winnable\n");
    else
    {
        if(p == 0)
            printf("hopeless\n");
        else
        {
            found = 0;
            memset(visit, 0, sizeof(visit));
            dfs(n);
            if(found == 1)
                printf("winnable\n");
            else
                printf("hopeless\n");
        }
    }
}

int main()
{
    int i, j, x;
    data info;
    while(scanf("%d", &n) == 1)
    {
        if(n == -1)
            break;

        for(i = 1; i <= n; ++i)
        {
            scanf("%d", &cost[i]);
            scanf("%d", &x);
            info.u = i;
            for(j = 1; j <= x; ++j)
            {
                scanf("%d", &info.v);
                vv.push_back(info);
                g[info.v].push_back(i);
            }
        }

        bell();

        for(i = 1; i <= n; ++i)
            g[i].clear();
        vv.clear();
    }
    return 0;
}
/*
5
0 1 2
100 1 3
100 2 1 4
-56757 1 5
0 0
*/
