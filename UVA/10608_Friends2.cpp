#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;


int par[30010], value[30010];

int func(int r)
{
    if(r == par[r])
        return r;
    else
    {
        par[r] = func(par[r]);
        return par[r];
    }
}

int main()
{
    int t, cnt, i, v, e, x, y, a, b, total;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        total = 1;
        scanf("%d %d", &v, &e);
        for(i = 1; i <= v; ++i)
        {
            par[i] = i;
            value[i] = 1;
        }
        for(i = 0; i < e; ++i)
        {
            scanf("%d %d", &a, &b);
            x = func(a);
            y = func(b);
            if(x != y)
            {
                par[x] = y;
                value[y] += value[x];
            }
        }
        for(i = 1; i <= v; ++i)
        {
            if(i == par[i] && value[i] > total)
                total = value[i];
        }
        printf("%d\n", total);
    }
    return 0;
}

//1
//10 5
//1 2
//2 3
//4 5
//5 7
//3 4

//output: 6

