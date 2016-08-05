#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, w, k, arr[105], dp[105][105];

int func(int index, int use)
{
    if(index > n || use > k)
        return 0;

    if(dp[index][use] != -1)
        return dp[index][use];

    int i, x, j, kk, max_ = 0;
    for(i = index; i <= n; ++i)
    {
        j = 0;
        kk = i;
        x = arr[i] + w;
        while(kk <= n && arr[kk] <= x)
        {
            ++j;
            ++kk;
        }
        j = j + func(kk, use + 1);
        max_ = max(max_, j);
    }
    return dp[index][use] = max_;
}

int main()
{
    int t, cnt, i, a, b;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d %d", &n, &w, &k);
        for(i = 1; i <= n; ++i)
        {
            scanf("%d %d", &a, &b);
            arr[i] = b;
        }
        sort(arr + 1, arr + n + 1);
        memset(dp, -1, sizeof(dp));
        printf("Case %d: %d\n", cnt, func(1, 1));
    }
    return 0;
}
