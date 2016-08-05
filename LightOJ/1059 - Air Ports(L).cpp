#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int par[10100];

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
    int t, n, m, a, x, y, z, i, j, k, cnt, sum;
    data info;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d %d", &n, &m, &a);
        for(i = 1; i <= n; ++i)
            par[i] = i;
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d %d", &info.u, &info.v, &info.w);
            v.push_back(info);
        }
        sort(v.begin(), v.end(), comp);
        j = 0;
        --n;
        sum = a;
        k = 1;
        z = v.size();
        for(i = 0; i < z; ++i)
        {
            x = func(v[i].u);
            y = func(v[i].v);
            if(x != y)
            {
                par[x] = y;
                if(v[i].w >= a)
                {
                    ++k;
                    sum += a;
                    ++j;
                    break;
                }
                else
                {
                    sum += v[i].w;
                    ++j;
                }
                if(j == n)
                    break;
            }
        }
        k += n - j;
        sum = sum + (n - j) * a;
        printf("Case %d: %d %d\n", cnt, sum, k);
        v.clear();
    }
    return 0;
}
