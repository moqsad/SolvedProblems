#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct data
{
    int u, v;
    double w;
};

bool comp(data p, data q)
{
    return p.w < q.w;
}

int par[3600];

int func(int r)
{
    if(par[r] == r)
        return r;
    else
        return par[r] = func(par[r]);
}

vector <data> out;

double a[600], b[600], c, d, arr[600];

int main()
{
    int n, s, p, i, j, k, cnt, x;
    data info;
    scanf("%d", &n);
    for(cnt = 0; cnt < n; ++cnt)
    {
        out.clear();
        scanf("%d %d", &s, &p);
        for(i = 0; i < p; ++i)
        {
            par[i] = i;
            scanf("%lf %lf", &a[i], &b[i]);
        }
        x = p - 1;
        for(i = 0; i < x; ++i)
            for(j = i + 1; j < p; ++j)
            {
                info.u = i;
                info.v = j;
                c = a[i] - a[j];
                d = b[i] - b[j];
                info.w = sqrt(c * c + d * d);
                printf("%lf\n", info.w);
                out.push_back(info);
            }
        sort(out.begin(), out.end(), comp);
        k = out.size();
        j = 0;
        x = p - s;
        int g, h;
        for(i = 0; i < k; ++i)
        {
            g = func(out[i].u);
            h = func(out[i].v);
            if(g != h)
            {
                par[g] = h;
                arr[j++] = out[i].w;
                if(j == x)
                    break;
            }
        }
        printf("%.2lf\n", arr[j - 1]);
    }
    return 0;
}
