#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct data
{
    int u, v, w;
};

bool one(data p, data q)
{
    return p.w < q.w;
}

bool two(data p, data q)
{
    return p.w > q.w;
}

vector <data> v;

int par[110];

int func(int r)
{
    if(par[r] == r)
        return r;
    else
        return par[r] = func(par[r]);
}

int main()
{
    int i, j, cnt, t, n, x, y, z, sum;
    data info;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);

        for(i = 0; i <= n; ++i)
            par[i] = i;

        while(scanf("%d %d %d", &info.u, &info.v, &info.w) == 3)
        {
            if(info.u == 0 && info.v == 0 && info.w == 0)
                break;
            v.push_back(info);
        }

        sort(v.begin(), v.end(), one);
        j = 0;
        sum = 0;
        z = v.size();

        for(i = 0; i < z; ++i)
        {
            x = func(v[i].u);
            y = func(v[i].v);
            if(x != y)
            {
                par[x] = y;
                ++j;
                sum += v[i].w;
                if(j == n)
                    break;
            }
        }

        for(i = 0; i <= n; ++i)
            par[i] = i;
        j = 0;
        sort(v.begin(), v.end(), two);
        for(i = 0; i < z; ++i)
        {
            x = func(v[i].u);
            y = func(v[i].v);
            if(x != y)
            {
                par[x] = y;
                ++j;
                sum += v[i].w;
                if(j == n)
                    break;
            }
        }

        if(sum % 2 == 0)
            printf("Case %d: %d\n", cnt, sum / 2);
        else
            printf("Case %d: %d/2\n", cnt, sum);
        v.clear();
    }
    return 0;
}
