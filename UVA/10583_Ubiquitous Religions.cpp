#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int par[50500];

int func(int r)
{
    if(par[r] == r)
        return r;
    else
        return par[r] = func(par[r]);
}

int main()
{
    int x, y, a, b, i, cnt = 0, n, m, total;
    while(scanf("%d %d", &n, &m) == 2)
    {
        if(n == 0 && m == 0)
            break;
        for(i = 1; i <= n; ++i)
            par[i] = i;
        total = 0;
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &a, &b);
            x = func(a);
            y = func(b);
            par[x] = y;
        }
        for(i = 1; i <= n; ++i)
        {
            x = func(i);
            if(par[i] == i)
                ++total;
        }
        printf("Case %d: %d\n", ++cnt, total);
    }
    return 0;
}
