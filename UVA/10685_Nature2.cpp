#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

map <string, int> m;

int par[5100], value[5100];
char a[40], b[40];

int func(int r)
{
    if(par[r] == r)
        return r;
    else
        return par[r] = func(par[r]);
}

int main()
{
    int c, n, i, cnt, j, x, y, total;
    while(scanf("%d %d", &c, &n) == 2)
    {
        if(c == 0 && n == 0)
            break;
        m.clear();
        total = 0;
        for(cnt = 1; cnt <= c; ++cnt)
        {
            scanf("%s", a);
            m[a] = cnt;
            value[cnt] = 1;
            par[cnt] = cnt;
        }
        for(cnt = 0; cnt < n; ++cnt)
        {
            scanf("%s %s", a, b);
            x = func(m[a]);
            y = func(m[b]);
            if(x != y)
            {
                par[x] = y;
                value[y] += value[x];
            }
        }
        for(i = 1; i <= c; ++i)
        {
            if(par[i] == i)
              total = max(total, value[i]);
        }
        printf("%d\n", total);
    }
    return 0;
}

