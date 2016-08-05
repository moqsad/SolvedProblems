#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int price[22][5], dp[22][3], n;

int func(int i, int pre)
{
    if(i > n)
        return 0;

    if(dp[i][pre] != -1)
        return dp[i][pre];

    int j, x;

    x = 1000000000;

    for(j = 1; j <= 3; ++j)
    {
        if(j != pre)
            x = min(x, price[i][j] + func(i + 1, j));
    }
    return dp[i][pre] = x;
}

int main()
{
    int t, cnt, i, j;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        for(i = 1; i <= n; ++i)
            for(j = 1; j <= 3; ++j)
                scanf("%d", &price[i][j]);
        memset(dp, -1, sizeof(dp));
        printf("Case %d: %d\n", cnt, func(1, 0));
    }
    return 0;
}
