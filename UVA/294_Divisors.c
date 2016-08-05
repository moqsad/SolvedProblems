#include <stdio.h>
#include <math.h>
long long int arr[32000];
int main()
{
    long long int t, m, n, count, i, p, x, y, j, a, b, u, v;
    scanf("%lld", &t);
    for(count = 1; count <= t; ++count)
    {
        scanf("%lld %lld", &m, &n);
        a = 0;
        b = 0;
        if(n == 1)
        {
            printf("Between 1 and 1, 1 has a maximum of 1 divisors.\n");
        }
        else if(n == 2)
        {
            printf("Between %lld and %lld, 2 has a maximum of 2 divisors.\n", m, n);
        }
        else
        {
            for(i = m; i <= n; ++i)
            {
                u = 1;
                x = i;
                y = sqrt(i) + 1;
                for(j = 2; j <= y; ++j)
                {
                    p = 1;
                    if(x % j == 0)
                    {
                        p = 0;
                        while(x % j == 0)
                        {
                            ++arr[j];
                            x /= j;
                        }
                    }
                }
                if(x != 1)
                {
                    u = 2;
                }
                for(j = 2; j <= y; ++j)
                {
                    if(arr[j] > 0)
                        u *= (arr[j] + 1);
                    arr[j] = 0;
                }
                if(u > a)
                {
                    a = u;
                    b = i;
                }
            }
            printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n", m, n, b, a);
        }
    }
    return 0;
}
