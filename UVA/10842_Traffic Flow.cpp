#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int par[10020];

int func(int r)
{
    if(par[r] == r)
        return r;
    else
        return par[r] = func(par[r]);
}

struct data
{
    int u, v, w;
};

vector <data> road;

bool comp(data p, data q)
{
    return p.w > q.w;
}

int main()
{
    int t, n, m, cnt, i, j, k, a, b, c, x, y;
    data info;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        road.clear();
        scanf("%d %d", &n, &m);
        for(i = 0; i < m; ++i)
        {
            par[i] = i;
            scanf("%d %d %d", &a, &b, &c);
            info.u = a;
            info.v = b;
            info.w = c;
            road.push_back(info);
        }
        par[i] = i;
        sort(road.begin(), road.end(), comp);
        j = 0;
        --n;
        k = 0;
        for(i = 0; i < m; ++i)
        {
            x = func(road[i].u);
            y = func(road[i].v);
            if(x != y)
            {
                ++j;
                k = road[i].w;
                if(j == n)
                    break;
                par[x] = y;
            }
        }
        printf("Case #%d: %d\n", cnt, k);
    }
    return 0;
}
