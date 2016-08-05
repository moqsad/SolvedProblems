#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
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
            value[cnt] = 0;
            par[cnt] = cnt;
        }
        for(cnt = 0; cnt < n; ++cnt)
        {
            scanf("%s %s", a, b);
            x = func(m[a]);
            y = func(m[b]);
            par[x] = y;
        }
        for(i = 1; i <= c; ++i)
        {
            x = func(i);
            ++value[x];
            if(value[x] > total)
                total = value[x];
        }
        printf("%d\n", total);
    }
    return 0;
}
