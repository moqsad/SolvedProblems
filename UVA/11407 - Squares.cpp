#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define inf 10000000

int dp[10010];

int func(int baki)
{

    if(baki == 0)
        return 0;

    if(baki < 0)
        return inf;

    if(dp[baki] != -1)
        return dp[baki];

    int i, x;
    x = sqrt(baki) + 2;

    dp[baki] = inf;

    for(i = 1; i < x; ++i)
        dp[baki] = min(dp[baki], 1 + func(baki - i * i));

    return dp[baki];
}

int main()
{
    int t, cnt, n;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        printf("%d\n", func(n));
    }
    return 0;
}
