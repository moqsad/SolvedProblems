#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int par[200500];

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

int comp(data p, data q)
{
    return p.w < q.w;
}

vector <data> road;

int main()
{
    int i, j, m, n, a, b, c, x, sum, total;
    data info;
    while(scanf("%d %d", &m, &n) == 2)
    {
        if(m == 0 && n == 0)
            break;
        road.clear();
        total = 0;

        for(i = 0; i < n; ++i)
        {
            par[i] = i;
            scanf("%d %d %d", &a, &b, &c);
            total += c;
            info.u = a;
            info.v = b;
            info.w = c;
            road.push_back(info);
        }
        par[i] = i;
        sort(road.begin(), road.end(), comp);
        sum = 0;
        j = 1;
        x = road.size();
        int p, q;
        for(i = 0; i < x; ++i)
        {
            p = func(road[i].u);
            q = func(road[i].v);
            if(p != q)
            {
                par[p] = q;
                sum += road[i].w;
                ++j;
                if(j == m)
                    break;
            }
        }
        printf("%d\n", total - sum);
    }
    return 0;
}
