#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int dp[55][55], arr[55];

int func(int start, int finish)
{
    if(start + 1 == finish)
        return 0;

    if(dp[start][finish] != -1)
        return dp[start][finish];

    int i, temp;

    temp = arr[finish] - arr[start];

    dp[start][finish] = 1000000000;

    for(i = start + 1; i < finish; ++i)
    {
        dp[start][finish] = min(dp[start][finish], func(start, i) + func(i, finish) + temp);
    }
    return dp[start][finish];
}

int main()
{
    int i, n, total;
    while(scanf("%d", &total) == 1 && total)
    {
        scanf("%d", &n);
        for(i = 1; i <= n; ++i)
        {
            scanf("%d", &arr[i]);
        }
        arr[++n] = total;
        memset(dp, -1, sizeof(dp));
        printf("The minimum cutting is %d.\n", func(0, n));
    }
    return 0;
}
