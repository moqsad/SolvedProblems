#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int par[110], s, d, total, arr[110][110], visit[110], value[110][110], det, n;

struct data
{
    int u, v, w;
};

bool comp(data p, data q)
{
    return p.w < q.w;
}

int func(int r)
{
    if(par[r] == r)
        return r;
    else
        return par[r] = func(par[r]);
}

void dfs(int x)
{
    int i;
    for(i = 1; i <= n; ++i)
    {
        if(arr[x][i] == 1 && visit[i] == 0)
        {
            visit[i] = 1;

            if(i == d)
            {
                if(value[x][i] > total)
                {
                    total = value[x][i];
                }
                det = 1;
                return;
            }

            dfs(i);

            if(det == 1)
            {
                if(value[x][i] > total)
                {
                    total = value[x][i];
                }
                return;
            }
        }
    }
    return;
}

vector <data> road;

int main()
{
    int t, cnt = 0, m, q, x, y, z, i, j;
    data info;
    while(scanf("%d %d %d", &n, &m, &q) == 3)
    {
        if(n == 0 && m == 0 && q == 0)
            break;
        if(cnt > 0)
            printf("\n");
        memset(arr, 0, sizeof(arr));
        road.clear();
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d %d", &x, &y, &z);
            info.u = x;
            info.v = y;
            info.w = z;
            road.push_back(info);
        }
        for(i = 1; i <= n; ++i)
            par[i] = i;
        sort(road.begin(), road.end(), comp);
        int g, h;
        for(i = 0; i < m; ++i)
        {
            g = road[i].u;
            h = road[i].v;
            x = func(g);
            y = func(h);
            if(x != y)
            {
                arr[g][h] = arr[h][g] = 1;
                value[g][h] = value[h][g] = road[i].w;
                par[x] = y;
            }
        }
        printf("Case #%d\n", ++cnt);
        for(i = 0; i < q; ++i)
        {
            scanf("%d %d", &s, &d);
            x = func(s);
            y = func(d);
            if(x == y)
            {
                det = 0;
                total = 0;
                memset(visit, 0, sizeof(visit));
                visit[s] = 1;
                dfs(s);
                printf("%d\n", total);
            }
            else
                printf("no path\n");
        }
    }
    return 0;
}
