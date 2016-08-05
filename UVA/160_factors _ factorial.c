#include <stdio.h>
#include <math.h>
int main()
{
    int arr[110], i, j, cnt, p, q, x, n, k;
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        for(i = 0; i <= n; ++i)
            arr[i] = 0;
        for(cnt = 2; cnt <= n; ++cnt)
        {
            x = cnt;
            p = 1;
            while(p == 1)
            {
                q = 0;
                if(x == 2)
                {
                    ++arr[2];
                    p = 0;
                }
                else
                {
                    for(i = 2; i < sqrt(x) + 1; ++i)
                    {
                        if(x % i == 0)
                        {
                            ++arr[i];
                            q = 1;
                            break;
                        }
                    }

                    if(q == 0)
                    {
                        p = 0;
                        ++arr[x];
                        break;
                    }

                    x = x / i;
                    if(x <= 1)
                    break;
                }
            }
        }
        k = 0;
        printf("%3d! =", n);
        for(j = 2; j <= n; ++j)
            if(j <= 50 && arr[j] != 0)
                printf("%3d", arr[j]);
            else if(arr[j] != 0)
            {
                ++k;
                if(k == 1)
                printf("\n      %3d", arr[j]);
                else
                printf("%3d", arr[j]);
            }
        printf("\n");
    }
    return 0;
}
