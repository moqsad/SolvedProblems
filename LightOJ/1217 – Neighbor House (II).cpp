#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

int arr[1001], dp[1001], n, nimu;

int func(int index)
{
    if(index >= n)
        return 0;

    else if(n - index == 1)
    {
        if(nimu == 1)
            return arr[index];
        else
            return 0;
    }

    if(dp[index] != -1)
        return dp[index];

    return dp[index] = max(arr[index] + func(index + 2), func(index + 1));
}

int main()
{
    int t, cnt, i, sum, sum2;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        for(i = 1; i <= n; ++i)
            scanf("%d", &arr[i]);

        memset(dp, -1, sizeof(dp));
        nimu = 1;
        sum = func(1);

        memset(dp, -1, sizeof(dp));
        nimu = 0;
        sum2 =  arr[n] + func(2);

        printf("Case %d: %d\n", cnt, max(sum, sum2));
    }
    return 0;
}

/*
3
2 12 5
*/
