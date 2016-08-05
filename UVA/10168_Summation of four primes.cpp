#include "bits/stdc++.h"
using namespace std;
long long int num[10000050], prime[7000000];

int main()
{
    long long int i, j, k, cnt = 0, n, p, x, r, y;
    prime[cnt++] = 2;
    for(i = 3; i < 3170; i += 2)
    {
        if(num[i] == 0)
        {
            prime[cnt++] = i;
            k = 2 * i;
            for(j = i * i; j < 3170; j += k)
            {
                num[j] = 1;
            }
        }
    }
    while(scanf("%lld", &n) == 1)
    {
        if(n > 7)
        {
            r = 0;
            if(n % 2 == 0)
            {
                r = 1;
                n -= 4;
            }
            else
            {
                n -= 5;
            }
            x = n / 2 + 1;
            for(i = 2; i < x; ++i)
            {
                p = 0;
                cnt = 0;
                j = sqrt(i) + 1;
                while(prime[cnt] <= j)
                {
                    if(i % prime[cnt] == 0)
                        break;
                    ++cnt;
                }
                if(prime[cnt] >= j)
                    p = 1;
                if(p == 1)
                {
                    p = 0;
                    cnt = 0;
                    y = n - i;
                    j = sqrt(y) + 1;
                    while(prime[cnt] <= j)
                    {
                        if(y % prime[cnt] == 0)
                            break;
                        ++cnt;
                    }
                    if(prime[cnt] >= j)
                    {
                        p = 1;
                        if(r == 1)
                            printf("2 2 %lld %lld\n", i, y);
                        else
                            printf("2 3 %lld %lld\n", i, n - i);
                        break;
                    }
                }
            }
            if(p == 0)
                printf("Impossible.\n");
        }
        else
            printf("Impossible.\n");

    }
    return 0;
}
