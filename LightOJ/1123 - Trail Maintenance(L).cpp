#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int par[210], cycle[210];

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

void union_(int x, int y)
{
    if(cycle[x] > cycle[y])
        par[y] = x;
    else
        par[x] = y;
    if(cycle[x] == cycle[y])
        ++cycle[y];
}

bool comp(data p, data q)
{
    return p.w < q.w;
}

vector <data> v, w;

int main()
{
    int t, vnt, x, y, z, p, i, j, k, sum, n, m, cnt;
    data info;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        printf("Case %d:\n", cnt);
        scanf("%d %d", &n, &m);
        z = n - 1;

        for(k = 1; k <= n; ++k)
        {
            par[k] = k;
            cycle[k] = 0;
        }

        for(i = 1; i <= m; ++i)
        {
            scanf("%d %d %d", &info.u, &info.v, &info.w);
            v.push_back(info);
            if(i < z)
                printf("-1\n");
            else
            {
                j = 0;
                sum = 0;
                sort(v.begin(), v.end(), comp);
                p = v.size();
                for(k = 0; k < p; ++k)
                {
                    x = func(v[k].u);
                    y = func(v[k].v);
                    if(x != y)
                    {
                        union_(x, y);
//                        par[x] = y;
                        sum += v[k].w;
                        w.push_back(v[k]);
//                        printf("%d_______%d______%d\n", v[k].u, v[k].v, v[k].w);
//                        printf("%d_______%d______%d\n", w[j].u, w[j].v, w[j].w);
                        ++j;
                        if(j == n - 1)
                            break;
                    }
                }

                for(k = 1; k <= n; ++k)
                {
                    par[k] = k;
                    cycle[k] = 0;
                }

                if(j == n - 1)
                    printf("%d\n", sum);
                else
                    printf("-1\n");
                v = w;
//                for(k = 0; k < v.size(); ++k)
//                    printf("%d %d %d________________________\n", v[k].u, v[k].v, v[k].w);
                w.clear();
            }
        }
        v.clear();
    }
    return 0;
}

