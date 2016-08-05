#include <stdio.h>
int main()
{
    int n, count, i, j, x, a, p, c, k, arr[200];
    while(scanf("%d %d", &n, &a) == 2)
    {
        j = 0;
        for(count = 1; count <= n; ++count)
        {
            p = 1;
            x = sqrt(count) + 1;
            for(i = 2; i <= x; ++i)
            {
                if(count % i == 0)
                {
                    p = 0;
                    break;
                }
            }
            if(count == 2)
                p = 1;
            if(p == 1)
            {
                arr[j] = count;
                ++j;
            }
        }
        if(j % 2 == 1)
            c = 2 * a - 1;
        else
            c = 2 * a;
        printf("%d %d:", n, a);
        if(c >= j)
            for(i = 0; i < j; ++i)
                printf(" %d", arr[i]);
        else
        {
            k = (j - c) / 2;
            i = 1;
            while(i <= c)
            {
                printf(" %d", arr[k]);
                ++k;
                ++i;
            }
        }
        printf("\n\n");
    }
    return 0;
}
