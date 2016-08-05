#include <cstdio>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstring>
using namespace std;

int n, visit[20], dp[18][66000], arr[18][18];

int func(int j, int x)
{
    if(j == n)
        return 0;

    if(dp[j][x] != -1)
        return dp[j][x];

    int i, y = 0;

    for(i = 0; i < n; ++i)
    {
        if(visit[i] == 0)
        {
            visit[i] = 1;
            y = max(y, arr[j][i] + func(j + 1, x | 1 << i));
            visit[i] = 0;
        }
    }

    return dp[j][x] = y;
}

int main()
{
    int i, j, cnt, t;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
            for(j = 0; j < n; ++j)
                scanf("%d", &arr[i][j]);
        memset(dp, -1, sizeof(dp));
        printf("Case %d: %d\n", cnt, func(0, 0));
    }
    return 0;
}
