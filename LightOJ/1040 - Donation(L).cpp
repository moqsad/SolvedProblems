#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int par[110];

struct data
{
    int u, v, w;
};

int func(int r)
{
    if(par[r] == r)
        return r;
    else
        return par[r] = func(par[r]);
}

bool comp(data p, data q)
{
    return p.w < q.w;
}

vector <data> v;

int main()
{
    int i, j, cnt, t, n, x, y, z, c, total, sum;
    data info;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        total = 0;
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
        {
            par[i] = i;
            for(j = 0; j < n; ++j)
            {
                scanf("%d", &c);

                if(c > 0)
                {
                    info.u = i;
                    info.v = j;
                    info.w = c;
                    v.push_back(info);
                    total += c;
                }
            }
        }

        sort(v.begin(), v.end(), comp);
        sum = 0;
        j = 0;
        --n;
        z = v.size();
        for(i = 0; i < z; ++i)
        {
            x = func(v[i].u);
            y = func(v[i].v);
            if(x != y)
            {
                par[x] = y;
                sum += v[i].w;
                ++j;
                if(j == n)
                    break;
            }
        }
        if(j == n)
            printf("Case %d: %d\n", cnt, total - sum);
        else
            printf("Case %d: -1\n", cnt);
        v.clear();
    }
    return 0;
}
