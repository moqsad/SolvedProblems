#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int dp[52][52], n, arr[52], arr2[52];

int func(int a, int b)
{
    int x, y = 0;

    if(a == n)
    return 0;

    if(dp[a][b] != -1)
        return dp[a][b];

    if(arr[a] > arr2[b])
        return dp[a][b] = 2 + func(a + 1, b + 1);

    else if(arr[a] < arr2[b])
      return dp[a][b] = func(a + 1, b);

    else
    {
        x = 1  + func(a + 1, b + 1);
        y = func(a + 1, b);
        return dp[a][b] = max(x, y);
    }
}

int main()
{
    int i, cnt, t;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
            scanf("%d", &arr[i]);

        for(i = 0; i < n; ++i)
            scanf("%d", &arr2[i]);

        sort(arr, arr + n);
        sort(arr2, arr2 + n);

        memset(dp, -1, sizeof(dp));

        printf("Case %d: %d\n", cnt, func(0, 0));
    }
    return 0;
}
