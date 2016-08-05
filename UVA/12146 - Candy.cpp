#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int n, m, now, arr[100005], arr2[100005], dp[100005];

int func(int index)
{
    if(index >= now)
        return 0;

    if(dp[index] != -1)
    return dp[index];

    return dp[index] = max(func(index + 1), arr[index] + func(index + 2));
}

int main()
{
    int i, j;
    while(scanf("%d %d", &n, &m) == 2)
    {
        if(n == 0 && m == 0)
            break;

        now = m;
        for(i = 0; i < n; ++i)
        {
            memset(dp, -1, sizeof(int) * m);
            for(j = 0; j < m; ++j)
            scanf("%d", &arr[j]);
            arr2[i] = func(0);
        }

        memset(dp, -1, sizeof(int) * n);
        now = n;
        for(i = 0; i < n; ++i)
            arr[i] = arr2[i];
        printf("%d\n", func(0));
    }
    return 0;
}
