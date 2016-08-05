#include "bits/stdc++.h"
using namespace std;

map<int, int>mm;

int main()
{
    int n, m, arr[10000], cnt, a, b, x, y, p, q, z;
    while(scanf("%d", &n) == 1)
    {
        mm.clear();
        for(cnt = 0; cnt < n; ++cnt)
        {
            scanf("%d", &arr[cnt]);
            mm[arr[cnt]] = 1;
        }
        scanf("%d", &m);
        z = 0;
        x = 100000000;
        if(m % 2 == 1)
            for(cnt = 0; cnt < n; ++cnt)
            {
                a = m - arr[cnt];
                if(mm.find(a) != mm.end())
                {
                    b = arr[cnt];
                    y = a - b;
                    if(y < 0)
                        y = -y;
                    if(x > y)
                    {
                        p = a;
                        q = b;
                        x = y;
                    }
                }
            }
        else
        {
            for(cnt = 0; cnt < n; ++cnt)
            {
                if(arr[cnt] == m / 2)
                {
                    ++z;
                    if(z == 1)
                        continue;
                }
                a = m - arr[cnt];
                if(mm.find(a) != mm.end())
                {
                    b = arr[cnt];
                    y = a - b;
                    if(y < 0)
                        y = -y;
                    if(x > y)
                    {
                        p = a;
                        q = b;
                        x = y;
                    }
                }
            }
        }
        x = p < q ? p : q;
        y = p > q ? p : q;
        printf("Peter should buy books whose prices are %d and %d.\n\n", x, y);
    }
    return 0;
}
