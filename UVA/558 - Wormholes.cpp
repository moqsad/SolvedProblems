#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct data
{
    int u, v, w;
};

vector <data> vv;

int d[1010], n, m;

void func(void)
{
    int i, j, p, x;
    for(i = 0; i < n; ++i)
        d[i] = 1000000000;

    d[0] = 0;
    for(i = 0; i < n; ++i)
    {
        p = 0;
        for(j = 0; j < m; ++j)
        {
            x = d[vv[j].u] + vv[j].w;
            if(x < d[vv[j].v])
            {
                d[vv[j].v] = x;
                p = 1;
            }
//            printf("n : %d______ j : %d____ d : %d____\n", i, vv[j].v, d[vv[j].v]);
        }
        if(p == 0)
            break;
    }

    if(p == 0)
        printf("not possible\n");
    else
        printf("possible\n");
}

int main()
{
    int cnt, t, i, x;
    data info;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &m);
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d %d", &info.u, &info.v, &info.w);
            vv.push_back(info);
        }
        func();
        vv.clear();
    }
    return 0;
}
