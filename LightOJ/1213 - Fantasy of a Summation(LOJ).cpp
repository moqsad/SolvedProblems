#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

long long mod, n;

long long bigmod(long long power)
{
    if(power == 0)
        return 1;

    long long ret = bigmod(power / 2);

    ret = (ret * ret) % mod;

    if(power % 2 == 1)
        ret = (ret * n) % mod;

    return ret;
}

int main()
{
    long long t, cnt, i, a, k, total;
    scanf("%lld", &t);
    for(cnt  = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld %lld", &n, &k, &mod);
        total = 0;
        for(i = 0; i < n; ++i)
        {
            scanf("%lld", &a);
            total += a;
        }
        total = (total * bigmod(k - 1)) % mod;
        total = (total * k) % mod;
        printf("Case %lld: %lld\n", cnt, total);
    }
    return 0;
}
