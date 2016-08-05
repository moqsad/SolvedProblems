#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

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

int par[1010];
double a[1010], b[1010];

int func(int r)
{
    if(par[r] == r)
        return r;
    else
        return par[r] = func(par[r]);
}

int func2(double a)
{
    double x;
    x = floor(a) + .5;
    if(x < a)
        return ((int)a + 1);
    else
        return (int)a;
}

int main()
{
    int i, j, k, cnt, t, n, r, x;
    double p, q;
    data info;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &r);
        road.clear();
        for(i = 0; i < n; ++i)
        {
            par[i] = i;
            scanf("%lf %lf", &a[i], &b[i]);
        }
        x = n - 1;
        for(i = 0; i < x; ++i)
        {
            for(j = i + 1; j < n; ++j)
            {
                info.u = i;
                info.v = j;
                p = a[i] - a[j];
                q = b[i] - b[j];
                info.w = sqrt(p * p + q * q);
                //printf("%lf", info.w);
                road.push_back(info);
            }
        }
        sort(road.begin(), road.end(), comp);
        x = road.size();
        p = 0;
        q = 0;
        j = 0;
        k = 0;
        --n;
        int g, h;
        for(i = 0; i < x; ++i)
        {
            //printf("%d %d\n", road[i].u, road[i].v);
            g = func(road[i].u);
            h = func(road[i].v);
            if(g != h)
            {
                par[g] = h;
                if(road[i].w > r)
                {
                    p += road[i].w;
                    ++j;
                }
                else
                    q += road[i].w;
                if(++k == n)
                    break;
            }
        }
        printf("Case #%d: %d %d %d\n", cnt, ++j, func2(q), func2(p));
    }
    return 0;
}
