#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int par[2000];

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
    //return p.w <= q.w;
    if (p.w <= q.w) return(true);
    else if (p.w == q.w && p.u < q.u) return(true);
    else if (p.w == q.w && p.u == q.u && p.v < q.v) return(true);
    return(false);
}

int main()
{
    int cnt, i, j, t, n, x, y, z, a;
    data info;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        road.clear();
        scanf("%d", &n);
        for(i = 1; i <= n; ++i)
        {
            par[i] = i;
            for(j = 1; j < n; ++j)
            {
                scanf("%d,", &a);
                if(a != 0)
                {
                    info.u = i;
                    info.v = j;
                    info.w = a;
                    road.push_back(info);
                }
            }
            scanf("%d", &a);
            if(a != 0)
            {
                info.u = i;
                info.v = j;
                info.w = a;
                road.push_back(info);
            }
        }
        sort(road.begin(), road.end(), comp);
        x = n - 1;
        a = road.size();
        j = 0;
        printf("Case %d:\n", cnt);
        for(i = 0; i < a; ++i)
        {
            y = func(road[i].u);
            z = func(road[i].v);
            if(y != z)
            {
                par[y] = z;
                ++j;
                printf("%c-%c %d\n", road[i].u + 64, road[i].v + 64, road[i].w);
                if(j == x)
                    break;
            }
        }
    }
    return 0;
}
