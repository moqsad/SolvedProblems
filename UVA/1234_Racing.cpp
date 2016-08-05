#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int par[10010];

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
    int t, i, j, cnt, n, m, x, a, b, c, sum;
    data info;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        road.clear();
        scanf("%d %d", &n, &m);
        for(i = 1; i <= n; ++i)
            par[i] = i;
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            info.u = a;
            info.v = b;
            info.w = c;
            road.push_back(info);
        }
        sort(road.begin(), road.end(), comp);
        j = 0;
        sum = 0;
        c = n - 1;
        x = road.size();
//        printf("%d__________\n", x);
        for(i = 0; i < x; ++i)
        {
            a = func(road[i].u);
            b = func(road[i].v);
            if(a != b)
            {
                ++j;
                par[a] = b;
                if(x == j)
                {
                    break;
                }
            }
            else
                sum += road[i].w;
        }
        printf("%d\n", sum);
    }
    scanf("%d", &a);
    return 0;
}
