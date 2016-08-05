#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int par[800];

int func(int r)
{
    if(par[r] == r)
        return r;
    else
        return par[r] = func(par[r]);
}

struct data
{
    int u, v;
    double w;
};

bool comp(data p, data q)
{
    return p.w < q.w;
}

vector <data> road;

int main()
{
    int cnt, t, i, j, x, y, n, m, c, d, k;
    double a[800], b[800], p, q;
    data info;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        road.clear();
        scanf("%d", &n);
        for(i = 1; i <= n; ++i)
        {
            par[i] = i;
            scanf("%lf %lf", &a[i], &b[i]);
        }
        scanf("%d", &m);
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &c, &d);
            x = func(c);
            y = func(d);
            par[x] = y;
        }
        for(i = 1; i < n; ++i)
            for(j = i + 1; j <= n; ++j)
            {
                p = a[i] - a[j];
                q = b[i] - b[j];
                info.u = i;
                info.v = j;
                info.w = sqrt(p * p + q * q);
                road.push_back(info);
            }

        sort(road.begin(), road.end(), comp);
        c = road.size();
        k = 0;
        for(i = 0; i < c; ++i)
        {
            x = func(road[i].u);
            y = func(road[i].v);
            if(x != y)
            {
                k = 1;
                par[x] = y;
                printf("%d %d\n", road[i].u, road[i].v);
            }
        }
        if(k == 0)
            printf("No new highways need\n");
        if(cnt < t)
            printf("\n");
    }
    return 0;
}
