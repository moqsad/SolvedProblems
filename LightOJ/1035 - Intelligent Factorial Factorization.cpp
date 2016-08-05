#include <stdio.h>
#include <math.h>

int arr2[100000000];
int main()
{
    int arr[110], i, j, cnt, p, q, x, n, k, t, count_;
    scanf("%d", &t);
    for(count_ = 1; count_ <= t; ++count_)
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

        printf("Case %d: %d =", count_, n);
        printf(" %d (%d)", 2, arr[2]);
        for(j = 3; j <= n; ++j)
            if(arr[j] != 0)
                printf(" * %d (%d)", j, arr[j]);
        printf("\n");
    }
    return 0;
}
