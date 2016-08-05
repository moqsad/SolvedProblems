#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

long long n, k, m, dp[52][52][52];

long long func(long long i, long long bar)
{
    if(bar < 0)
        return 0;

    if(i == 0)
    {
        if(bar == 0)
            return 1;
        else
            return 0;
    }

    if(dp[i][bar][m] != -1)
        return dp[i][bar][m];

    long long x, y = 0, j;

    x = min(i, m);

    for(j = 1; j <= x; ++j)
        y += func(i - j, bar - 1);

    return dp[i][bar][m] = y;
}

int main()
{
    long long t, cnt;
    memset(dp, -1, sizeof(dp));
    while(scanf("%lld %lld %lld", &n, &k, &m) == 3)
    {
        printf("%lld\n", func(n, k));
    }
    return 0;
}
