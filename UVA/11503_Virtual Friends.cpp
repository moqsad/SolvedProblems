#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;

map <string, int> m;

char a[30], b[30];
int par[210000], value[210000];

int func(int r)
{
    if(par[r] == r)
        return r;
    else
        return par[r] = func(par[r]);
}

int main()
{
    int t, cnt, i, j, n, x, y;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        i = 0;
        m.clear();
        scanf("%d", &n);
        for(j = 0; j < n; ++j)
        {
            scanf("%s %s", a, b);
            if(m.find(a) == m.end())
            {
                m[a] = ++i;
                value[i] = 1;
                par[i] = i;
            }
            if(m.find(b) == m.end())
            {
                m[b] = ++i;
                value[i] = 1;
                par[i] = i;
            }
            x = func(m[a]);
            y = func(m[b]);
            if(x != y)
            {
                par[x] = y;
                value[y] += value[x];
            }
            printf("%d\n", value[y]);
        }
    }
    return 0;
}
