#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

map <string, long long int> mm;
long long int par[401];

long long int func(long long int r)
{
    if(par[r] == r)
        return r;
    else
        return par[r] = func(par[r]);
}


struct data
{
    long long int u, v, w;
};

vector <data> road;

bool comp(data p, data q)
{
    return p.w < q.w;
}

int main()
{
    long long int n, m, i, j, a, x, y, sum;
    char arr[20];
    data info;
    while(scanf("%lld %lld", &n, &m) == 2)
    {
        if(n == 0 && m == 0)
            break;
        road.clear();
        mm.clear();
        for(i = 0; i < n; ++i)
        {
            par[i] = i;
            scanf("%s", arr);
            mm[arr] = i;
        }
        for(i = 0; i < m; ++i)
        {
            scanf("%s", arr);
            info.u = mm[arr];
            scanf("%s", arr);
            info.v = mm[arr];
            scanf("%lld", &a);
            info.w = a;
            road.push_back(info);
        }
        scanf("%s", arr);
        sort(road.begin(), road.end(), comp);
        j = 0;
        a = n - 1;
        sum = 0;
        for(i = 0; i < m; ++i)
        {
            x = func(road[i].u);
            y = func(road[i].v);
            if(x != y)
            {
                par[x] = y;
                sum += road[i].w;
                ++j;
                if(j == a)
                    break;
            }
        }
        if(j == a)
            printf("%lld\n", sum);
        else
            printf("Impossible\n");
    }
    return 0;
}
