#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

int par[110];
double a[110], b[110];

struct data
{
    int u, v;
    double w;
};

vector <data> con;

bool comp(data p, data q)
{
    return p.w < q.w;
}

int func(int r)
{
    if(r == par[r])
        return r;
    else
        return par[r] = func(par[r]);
}

int main()
{
    int i, j, cnt, t, n, x, g, h;
    double p, q, ans;
    data info;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        con.clear();
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
        {
            par[i] = i;

            scanf("%lf %lf", &a[i], &b[i]);
        }
        x = n - 1;
        for(i = 0; i < x; ++i)
        {
            for(j = i + 1; j < n; ++j)
            {
                info.u = i;
                info.v = j;
                p = a[i] - a[j];
                q = b[i] - b[j];
                info.w = sqrt(p * p + q * q);
                con.push_back(info);
            }
        }
        sort(con.begin(), con.end(), comp);
        ans = 0;
        x = 1;
        j = con.size();
        for(i = 0; i < j; ++i)
        {
            g = func(con[i].u);
            h = func(con[i].v);
            if(g != h)
            {
                par[g] = h;
                ans += con[i].w;
                ++x;
                if(x == n)
                    break;
            }
        }
        printf("%.2lf\n", ans);
        if(cnt != t)
            printf("\n");
    }
    return 0;
}
