#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>
#include <cstdlib>
#include <cctype>
#include <stack>
#include <iostream>
using namespace std;

#define mod 1000000007

long long f_inverse[1000010], f[1000010], arr[1010];

long long inverse(long long data, long long power)
{
    if(power == 0)
        return 1;

    long long ret = inverse(data, power / 2);

    ret = (ret * ret) % mod;

    if(power % 2)
        ret = (ret * data) % mod;

    return ret;
}

void fact()
{
    f_inverse[0] = 1;
    f[0] = 1;
    for(long long i = 1; i <= 1000005; ++i)
    {
        f[i] = (f[i - 1] * i) % mod;
        f_inverse[i] = inverse(f[i], mod - 2);
    }
}

long long nCr(long long n, long long r)
{
    return (((f[n] * f_inverse[r]) % mod) * f_inverse[n - r]) % mod;
}

int main()
{
    long long t, cnt, i, ans, total, n;

    fact();

    scanf("%lld", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld", &n);

        for(i = 1; i <= n; ++i)
            scanf("%lld", &arr[i]);

        ans = 1;
        total = arr[1];

        for(i = 2; i <= n; ++i)
        {
            ans = (ans * nCr(total + arr[i] - 1, arr[i] - 1)) % mod;
            //printf("%lld_______________%lld\n", ans, total);
            total += arr[i];
        }

        printf("Case %lld: %lld\n", cnt, ans);
    }

    return 0;
}


