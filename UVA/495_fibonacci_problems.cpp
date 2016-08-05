#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int  nir[5060], sum[5060][5050], x[5060], y[5060];

int main()
{
    int a, cnt, i, n, j, p, q, det, k;
    j = 1;
    y[0] = 1;
    x[0] = 0;
    for(cnt = 1; cnt < 5050; ++cnt)
    {
        i = j;
        p = 0;
        for(j = 0; j < i; ++j)
        {
            q = (x[j] + y[j] + p);
            sum[cnt][j] = q % 10;
            p = q / 10;
        }
        det = 0;
        if(p > 0)
        {
            det = 1;
            sum[cnt][j] = p;
            ++j;
        }
        nir[cnt] = j;
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
            y[i] = sum[cnt][i];
    }
    while(scanf("%d", &n) == 1)
    {
        if(n > 1)
        {
            k = n - 1;
            printf("The Fibonacci number for %d is ", n);
            for(i = nir[k] - 1; i >= 0; --i)
                printf("%d", sum[k][i]);
            printf("\n");
        }
        else if(n == 0)
            printf("The Fibonacci number for 0 is 0\n");
        else
            printf("The Fibonacci number for 1 is 1\n");
    }
    return 0;
}
