#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

unsigned long long arr[17];

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
    unsigned long long r;

    while(b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    unsigned long long t, cnt, i, j, k, n, m, x, limit, ans;

    scanf("%llu", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%llu %llu", &n, &m);

        limit = 1;
        for(i = 0; i < m; ++i)
        {
            scanf("%llu", &arr[i]);
            limit *= 2;
        }

        ans = 0;
        for(i = 1; i < limit; ++i)
        {
            for(j = 0; j < m; ++j)
                if((i & (1 << j)) > 0)
                    break;

            if(arr[j] <= n)
            {
                x = arr[j];
                k = 1;
                for(j = j + 1; j < m; ++j)
                {
                    if((i & (1 << j)) > 0)
                    {
                        x = x * arr[j] / gcd(x, arr[j]);
                        if(x > n)
                            break;
                        ++k;
                    }
                }

                if(j == m)
                {
                    if(k % 2 > 0)
                        ans += n / x;
                    else
                        ans -= n / x;
                }
            }
        }

        printf("Case %llu: %llu\n", cnt, n - ans);
    }
    return 0;
}
