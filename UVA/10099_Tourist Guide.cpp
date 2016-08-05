#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int par[110], s, d, total, arr[110][110], value[110][110], det, n;

struct data
{
    int u, v, w;
};

bool comp(data p, data q)
{
    return p.w > q.w;
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
        if(arr[x][i] == 1)
        {
            arr[x][i] = arr[i][x] = 0;

            if(i == d)
            {
                if(value[x][i] < total)
                {
                    total = value[x][i];
                }
                det = 1;
                return;
            }

            dfs(i);

            if(det == 1)
            {
                if(value[x][i] < total)
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
    int t, cnt = 0, m, x, y, z, i, j;
    data info;
    while(scanf("%d %d", &n, &m) == 2)
    {
        if(n == 0 && m == 0)
            break;
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
        scanf("%d %d %d", &s, &d, &t);
        for(i = 1; i <= n; ++i)
            par[i] = i;
        sort(road.begin(), road.end(), comp);
        j = 0;
        z = n - 1;
        total = 1000000000;
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
                ++j;
                if(j == z)
                    break;
            }
        }
        det = 0;
        dfs(s);
        --total;
        if(t % total == 0)
            j = t / total;
        else
            j = t / total + 1;
        printf("Scenario #%d\n", ++cnt);
        printf("Minimum Number of Trips = %d\n\n", j);
    }
    return 0;
}

