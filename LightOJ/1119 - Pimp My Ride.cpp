#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, check, dp[16390], arr[16][16];

int func(int index)
{
    if(index == check)
        return 0;

    if(dp[index] != -1)
        return dp[index];

    int i, j, min_ = 1000000000, x;
    for(i = 0; i < n; ++i)
    {
        if((index & (1 << i)) == 0)
        {
            x = arr[i][i];
            for(j = 0; j < n; ++j)
            {
                if((index & (1 << j)) > 0)
                {
                    x += arr[i][j];
                }
            }
            x += func(index | (1 << i));
            min_ = min(min_, x);
        }
    }

    return dp[index] = min_;
}

int main()
{
    int cnt, t, i, j;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        check = 1;
        for(i = 0; i < n; ++i)
        {
            check *= 2;
            for(j = 0; j < n; ++j)
                scanf("%d", &arr[i][j]);
        }

        check -= 1;

        memset(dp, -1, sizeof(dp));

        printf("Case %d: %d\n", cnt, func(0));
    }
    return 0;
}
