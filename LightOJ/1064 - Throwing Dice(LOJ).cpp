#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

long long n, x, dp[27][155];

long long func(long long depth, long long total)
{
//    printf("%lld %lld\n", depth, total);
    if(depth == n)
    {
        if(total >= x)
            return 1;
        else
            return 0;
    }

    if(dp[depth][total] != -1)
        return dp[depth][total];

    long long i, ans = 0, y;

    for(i = 1; i <= 6; ++i)
    {
        ans += func(depth + 1, total + i);
    }

    return dp[depth][total] = ans;
}

int main()
{
    long long t, cnt, a, b, c, d, e, f, i, p, q;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld",&n, &x);

        memset(dp, -1, sizeof(dp));
        a = func(0, 0);

        q = p = b = 1;
        for(i = 1; i <= n; ++i)
        {
            p *= 2;
            q *= 3;
            b *= 6;
        }

        c = a;
        d = 1;
        e = 1;
        if(c > 0)
            while(c % 2 == 0 || c % 3 == 0)
            {
                if(c % 2 == 0)
                {
                    d *= 2;
                    c /= 2;
                }

                else
                {
                    e *= 3;
                    c /= 3;
                }
            }

//        printf("%lld %lld___\n", e, d);
        d = min(d, p) * min(e, q);
        a /= d;
        b /= d;
        if(a == 0)
            printf("Case %lld: 0\n", cnt);
        else if(a == b)
            printf("Case %lld: 1\n", cnt);
        else
            printf("Case %lld: %lld/%lld\n", cnt, a, b);
    }
    return 0;
}
