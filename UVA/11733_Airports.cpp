#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int par[100010];

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

vector <data> road;

int main()
{
    int t, cnt, n, m, a, x, y, z, i, j, total, sum;
    data info;
    scanf("%d\n", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        road.clear();
        scanf("%d %d %d", &n, &m, &a);
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
        total = 0;
        j = 0;
        sum = 0;
        for(i = 0; i < m; ++i)
        {
            x = func(road[i].u);
            y = func(road[i].v);
            if(x != y)
            {
                par[x] = y;
                if(road[i].w >= a)
                {
                    ++total;
                }
                else
                {
                    sum += road[i].w;
                }
                ++j;
            }
        }
        total += n - j;
        sum += total * a;
        printf("Case #%d: %d %d\n", cnt, sum, total);
    }
    return 0;
}
