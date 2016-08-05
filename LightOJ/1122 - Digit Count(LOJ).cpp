#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;

int n, m, dp[10][10], arr[10];

int func(int pre, int depth)
{
    if(depth == n)
        return 1;
    if(dp[pre][depth] != -1)
        return dp[pre][depth];
    int x = 0, i;
    for(i = 0; i < m; ++i)
        if(abs(pre - arr[i]) < 3)
            x += func(arr[i], depth + 1);
    return dp[pre][depth] = x;
}

int main()
{
    int t, cnt, i, ans;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &m, &n);
        for(i = 0; i < m; ++i)
            scanf("%d", &arr[i]);
        ans = 0;
        memset(dp, -1, sizeof(dp));
        for(i = 0; i < m; ++i)
            ans += func(arr[i], 1);
        printf("Case %d: %d\n", cnt, ans);
    }
    return 0;
}
