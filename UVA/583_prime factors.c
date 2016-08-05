#include <stdio.h>
#include <math.h>

long long int arr[47000], prime[5000];
long long int cnt;

int main()
{
    long long int i, j, k, n, x, y, z, p;
    prime[cnt++] = 2;
    for(i = 3; i < 47000; i += 2)
    {
        if(arr[i] == 0)
        {
            prime[cnt++] = i;
            k = i + i;
            for(j = i * i; j < 47000; j += k)
            {
                arr[j] = 1;
            }
        }
    }
    while(scanf("%lld", &n) == 1)
    {
        if(n == 0)
            break;
        if(n == 1 || n == -1)
            printf("%lld = %lld\n", n, n);
        else
        {
            x = n;
            i = 0;
            if(x < 0)
                x = -x;
            y = sqrt(x) + 1;
            z = x;
            if(n < 0)
                printf("%lld = -1", n);
            else
            {
                p = 0;
                printf("%lld =", n);
                if(x % prime[i] == 0)
                {
                    printf(" %lld", prime[i]);
                    x /= prime[i];
                    p = 1;
                }
                else
                    while(x % prime[i] > 0 && prime[i] < y)
                    {
                        ++i;
                        if(x % prime[i] == 0)
                        {
                            printf(" %lld", prime[i]);
                            x /= prime[i];
                            p = 1;
                            break;
                        }
                    }
                if(p == 0)
                {
                    printf(" %lld", x);
                    x = 1;
                }
            }
            while(x > 1 && prime[i] < y)
            {
                if(x % prime[i] == 0)
                {
                    printf(" x %lld", prime[i]);
                    x /= prime[i];
                }
                else
                    ++i;
            }
            if(x > 1)
                printf(" x %lld", x);
            printf("\n");
        }
    }
    return 0;
}
