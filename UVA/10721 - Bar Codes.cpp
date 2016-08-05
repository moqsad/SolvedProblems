#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

long long n, k, m, dp[55][55][5][55];

long long func(long long i, long long bar, long long which, long long jotobar)
{
    if(jotobar > m || bar > k)
        return 0;

    if(i == n)
    {
        if(bar == k)
            return 1;
        else
            return 0;
    }

    if(dp[i][bar][which][jotobar] != -1)
        return dp[i][bar][which][jotobar];

    long long x, y, p , q;

    if(which == 1)
    {
        x = jotobar + 1;
        y = 1;
        p = bar;
        q = bar + 1;
    }

    else
    {
        x = 1;
        y = jotobar + 1;
        p = bar + 1;
        q = bar;
    }

    return dp[i][bar][which][jotobar] = func(i + 1, p, 1, x) + func(i + 1, q, 0, y);
}

int main()
{
    while(scanf("%lld %lld %lld", &n, &k, &m) == 3)
    {
        memset(dp, -1, sizeof(dp));
        printf("%lld\n", func(1, 1, 1, 1));
    }
    return 0;
}
