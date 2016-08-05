#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

map <int, int> have;

int a[50010], b[50010], c[50010];

int main()
{
    int t, cnt, i, j, k, x, y, z, total, n;
    for(i = 0; i < 225; ++i)
    {
        x = i * i;
        for(j = i; j < 225; ++j)
        {
            y = j * j;
            for(k = j; k < 225; ++k)
            {
                z = k * k;
                total = x + y + z;
                if(total < 50005)
                {
                    if(have.find(total) == have.end())
                    {
                        have[total] = 1;
                        a[total] = i;
                        b[total] = j;
                        c[total] = k;
                    }
                }
                else
                    break;
            }
        }
    }

    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%d", &n);
        if(have.find(n) != have.end())
        {
            printf("%d %d %d\n", a[n], b[n], c[n]);
        }
        else
            printf("-1\n");
    }
    return 0;
}
