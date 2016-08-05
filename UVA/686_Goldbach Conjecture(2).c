#include <stdio.h>
#include <math.h>
int main()
{
    int a, arr[4000], cnt, i, j, k, m, n, p;
    while(1)
    {
        scanf("%d", &a);
        if(a == 0)
            break;
        arr[0] = 2;
        j = 1;
        for(i = 3; i <= a; ++i)
        {
            p = 1;
            for(cnt = 2; cnt <= sqrt(i) + 1; ++cnt)
            {
                if(i % cnt == 0)
                {
                    p = 0;
                    break;
                }
            }
            if(p == 1)
            {
                arr[j] = i;
                ++j;
            }
        }
        n = 0;
        for(k = 0; k < j; ++k)
        {
            for(m = k; m < j; ++m)
            {
                if(arr[k] + arr[m] == a)
                {
                    ++n;
                    break;
                }
            }
        }
        printf("%d\n", n);
    }
    return 0;
}
