#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

int par[50050];
char a[20], b[20];

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
map <string, int> mm;

int main()
{
    int i, j, m, n, c, x, sum, t, cnt;
    data info;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &m, &n);
        road.clear();
        mm.clear();
        j = 0;
        for(i = 1; i <= m; ++i)
            par[i] = i;
        for(i = 0; i < n; ++i)
        {
            scanf("%s %s %d", a, b, &c);
            if(mm.find(a) == mm.end())
                mm[a] = ++j;
            if(mm.find(b) == mm.end())
                mm[b] = ++j;
            info.u = mm[a];
            info.v = mm[b];
            info.w = c;
            road.push_back(info);
        }
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
        printf("%d\n", sum);
        if(cnt < t)
            printf("\n");
    }
    return 0;
}

