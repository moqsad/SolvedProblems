#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int a, cnt, i, n, sum[505], j, p, q, det, k, x[500], y[500];
    while(scanf("%d", &n) == 1)
    {
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        j = 1;
        y[0] = 1;
        for(cnt = 0; cnt <= n; ++cnt)
        {
            i = j;
            p = 0;
            for(j = 0; j < i; ++j)
            {
                q = (x[j] + y[j] + p);
                sum[j] = q % 10;
                p = q / 10;
            }
            det = 0;
            if(p != 0)
            {
                det = 1;
                sum[j] = p;
                ++j;
            }
            if(det == 0)
                for(i = 0; i < j; ++i)
                    x[i] = y[i];
            else
            {
                k = j - 1;
                for(i = 0; i < k; ++i)
                    x[i] = y[i];
            }
            for(i = 0; i < j; ++i)
                y[i] = sum[i];

        }
        k = j - 1;
        for(i = k; i >= 0; --i)
            printf("%d", sum[i]);
        printf("\n");
    }
    return 0;
}
