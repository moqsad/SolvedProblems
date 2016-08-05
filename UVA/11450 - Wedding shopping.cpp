#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int arr[22][22], num[22], m, c, dp[22][210];

int func(int index, int baki)
{
    if(baki < 0)
        return -200000000;

    if(index == c)
        return 0;

    if(dp[index][baki] != -1)
        return dp[index][baki];

    int i;

    dp[index][baki] = -100000000;
    for(i = 0; i < num[index]; ++i)
    {
        dp[index][baki] = max(dp[index][baki], arr[index][i] + func(index + 1, baki - arr[index][i]));
    }
    return dp[index][baki];
}

int main()
{
    int t, cnt, i, j, k, x;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        memset(dp, -1, sizeof(dp));
        scanf("%d %d", &m, &c);
        for(i = 0; i < c; ++i)
        {
            scanf("%d", &num[i]);
            for(j = 0; j < num[i]; ++j)
                scanf("%d", &arr[i][j]);
        }
        x = func(0, m);
        if(x < 0)
            printf("no solution\n");
        else
            printf("%d\n", x);
    }
    return 0;
}
