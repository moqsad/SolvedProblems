#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

long long p, dp[75][75][75];

long long func(long long index, long long baki)
{
    if(baki < 0)
        return 0;

    if(index == 0)
    {
       if(baki == 0)
        return 1;
       else
        return 0;
    }

    if(dp[p][index][baki] != -1)
        return dp[p][index][baki];

    long long x = 0, i;
    for(i = p; i <= baki; ++i)
        x += func(index - 1, baki - i);
    return dp[p][index][baki] = x;
}

int main()
{
    long long t, cnt, n, total;
    scanf("%lld", &t);
    memset(dp, -1, sizeof(dp));
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld %lld", &n, &total, &p);
        printf("%lld\n", func(n, total));
    }
    return 0;
}
