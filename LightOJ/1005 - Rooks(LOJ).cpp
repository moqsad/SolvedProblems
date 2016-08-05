#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

long long n, k, x, dp[35][35];

long long func(long long i, long long value, long long pos)
{
    if(value < x)
        return 1;

    if(dp[i][value] != -1)
        return dp[i][value];

    if(i > n || pos > x)
        return 0;

    return dp[i][value] = value * func(i + 1, value - 1, 1) + func(i + 1, value, pos + 1);
}

int main()
{
    long long t, cnt;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld", &n, &k);
        if(k <= n)
        {
            x = n - k + 1;
            memset(dp, -1, sizeof(dp));
            printf("Case %lld: %lld\n", cnt, func(1, n, 1));
        }
        else
            printf("Case %lld: 0\n", cnt);
    }
    return 0;
}

