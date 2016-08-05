#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int par[1000210];
double a[1000210], b[1000210], arr[1000210];

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

vector <data> road;

bool comp(data p, data q)
{
    return p.w < q.w;
}

int main()
{
    int i, j, x, k, y, n, m, l, cnt, t;
    data info;
    double p, q;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%d", &k);
        i = 0;
        while(scanf("%d", &x) == 1)
        {
            if(x == - 1)
                break;
            scanf("%d", &y);
            a[i] = x;
            b[i] = y;
            par[i] = i;
            ++i;
        }
        x = i - 1;
        y = i;
        for(i = 0; i < x; ++i)
            for(j = i + 1; j < y; ++j)
            {
                p = a[i] - a[j];
                q = b[i] - b[j];
                info.u = i;
                info.v = j;
                info.w = sqrt(p * p + q * q);
                road.push_back(info);
            }
        sort(road.begin(), road.end(), comp);
        n = road.size();
        j = 0;
        m = x;
        for(i = 0; i < n; ++i)
        {
            x = func(road[i].u);
            y = func(road[i].v);
            if(x != y)
            {
                par[x] = y;
                arr[j] = road[i].w;
                //printf("%lf\n", arr[j]);
                ++j;
                if(j == m)
                {
                    break;
                }
            }
        }
        if(k > m)
            printf("0\n");
        else
            printf("%d\n", (int)ceil(arr[m - k]));
            road.clear();
    }
    return 0;
}
