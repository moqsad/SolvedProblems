#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int par[10100], value[10100], total[10100];

int func(int r)
{
    if(par[r] == r)
        return r;
    else
        return par[r] = func(par[r]);
}

int main()
{
    int cnt, i, t, a, b, x, y, n, m, flag;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; ++i)
        {
            par[i] = i;
            scanf("%d", &value[i]);
            total[i] = 0;
        }
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &a, &b);
            x = func(a);
            y = func(b);
            par[x] = y;
        }
        for(i = 0; i < n; ++i)
        {
            x = func(i);
            total[x] += value[i];
        }
        flag = 1;
        for(i = 0; i < n; ++i)
        {
            if(total[i] != 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag == 0)
            printf("IMPOSSIBLE\n");
        else
            printf("POSSIBLE\n");
    }
    return 0;
}
