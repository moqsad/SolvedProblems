#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long int a, b, c, par[1001000];

struct data
{
    long long int u, v, w;
};

vector <data> road;

bool comp(data p, data q)
{
    return p.w < q.w;
}

long long int func(long long int r)
{
    if(par[r] == r)
        return r;
    else
        return par[r] = func(par[r]);
}

int main()
{
    long long int n, i, j, k, m, x, y, sum, cnt = 0;
    data info;
    while(scanf("%lld", &n) == 1)
    {
        road.clear();
        sum = 0;
        ++cnt;
        if(cnt > 1)
            printf("\n");

        for(i = 1; i < n; ++i)
        {
            par[i] = i;
            scanf("%lld %lld %lld", &a, &b, &c);
            sum += c;
            info.u = a;
            info.v = b;
            info.w = c;
            road.push_back(info);
        }
        par[i] = i;
        printf("%lld\n", sum);
        scanf("%lld", &k);
        x = n + k;
        for(i = n; i < x; ++i)
        {
            scanf("%lld %lld %lld", &a, &b, &c);
            info.u = a;
            info.v = b;
            info.w = c;
            road.push_back(info);
        }
        scanf("%lld", &m);
        for(i = 0; i < m; ++i)
        {
            scanf("%lld %lld %lld", &a, &b, &c);
        }
        sort(road.begin(), road.end(), comp);
        k = (long long int)road.size();
        j = 0;
        sum = 0;
        --n;
        for(i = 0; i < k; ++i)
        {
            x = func(road[i].u);
            y = func(road[i].v);
            if(x != y)
            {
                par[x] = y;
                ++j;
                sum += road[i].w;
                if(j == n)
                    break;
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}
