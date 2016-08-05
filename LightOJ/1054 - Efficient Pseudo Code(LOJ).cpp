#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

#define mod 1000000007

long long prime[5000];

bool arr[46350];

void sieve(void)
{
    long long cnt = 0, i, j, k;
    prime[cnt++] = 2;
    for(i = 3; i < 46350; i += 2)
    {
        if(!arr[i])
        {
            prime[cnt++] = i;
            k = i + i;
            for(j = i * i; j < 46350; j += k)
                arr[j] = 1;
        }
    }
}

long long func(long long data, long long power)
{
    if(power == 0)
        return 1;
    else if(power == 1)
        return data;

    long long mid = power / 2, r, x;

    x = func(data, mid);

    r = (x * x) % mod;

    if(power % 2 == 1)
        r = (r * data) % mod;

    return r;
}

int main()
{
    sieve();
    long long t, cnt, n, m, i, j, x, ans;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld", &n, &m);

        if(n == 1000000007)
            printf("Case %lld: %lld\n", cnt, 1LL);

        else
        {
            x = sqrt(n) + 2;

            ans = 1;
            i = 0;
            while(prime[i] < x)
            {
                if(n % prime[i] == 0)
                {
                    j = 0;
                    while(n % prime[i] == 0)
                    {
                        ++j;
                        n /= prime[i];
                    }
                    ans = (ans * (func(prime[i], j * m + 1) - 1)) % mod;
                    ans = (ans * func(prime[i] - 1, mod - 2)) % mod;
                }
                ++i;
            }

            if(n > 1)
            {
                ans = (ans * (func(n, m + 1) - 1)) % mod;
                ans = (ans * func(n - 1, mod - 2)) % mod;
            }

            printf("Case %lld: %lld\n", cnt, ans);
        }
    }
    return 0;
}
