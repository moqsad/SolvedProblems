#include <stdio.h>
#include <math.h>

long long int arr[10000001];
long long int prime[700000];
long long int cnt;

int main()
{
    long long int i, j, k, n, x, y, z, p;
    prime[cnt++] = 2;
    for(i = 3; i < 10000001; i += 2)
    {
        if(arr[i] == 0)
        {
            prime[cnt++] = i;
            k = i + i;
            for(j = i * i; j < 10000001; j += k)
            {
                arr[j] = 1;
            }
        }
    }
    while(scanf("%lld", &n) == 1)
    {
        if(n == 0)
            break;
        if(n < 0)
            n = - n;
        if(n == 2 || n == 3)
            printf("-1\n");
        else
        {
            i = 0;
            k = 0;
            x = sqrt(n) + 1;
            while(prime[i] < x)
            {
                if(n % prime[i] == 0)
                {
                    ++k;
                    if(k == 1)
                    z = prime[i];
                    n /= prime[i];
                    if(n == 2 || n == 3)
                        break;
                    x = sqrt(n) + 1;
                }
                else
                {
                    ++i;
                }
                if(i == cnt)
                    break;
            }
            if(k > 0 && z < n)
                printf("%lld\n", n);
            else
                printf("-1\n");
        }
    }
    return 0;
}
