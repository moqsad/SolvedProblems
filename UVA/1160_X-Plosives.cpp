#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <iostream>
using namespace std;

map <int, int> mm;

int par[100010];
char arr[40], a[20], b[20];

int func(int r)
{
    if(par[r] == r)
        return r;
    else
        return par[r] = func(par[r]);
}

int main()
{
    int i = 0, k = 0, x, y, m, n;

    while(scanf("%d", &x) == 1)
    {
        if(x == -1)
        {
            printf("%d\n", k);
            mm.clear();
            k = 0;
        }
        else
        {
            scanf("%d", &y);
            if(mm.find(x) == mm.end())
            {
                mm[x] = ++i;
                par[i] = i;
            }
            if(mm.find(y) == mm.end())
            {
                mm[y] = ++i;
                par[i] = i;
            }
            m = func(mm[x]);
            n = func(mm[y]);
            if(m != n)
            {
                par[m] = n;
            }
            else
            {
                ++k;
            }
        }
    }
return 0;
}
