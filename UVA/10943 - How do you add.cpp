#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int dp[110][110], x;

int func(int index, int baki)
{
    if(baki < 0)
        return 0;

    if(index == 0)
    {
        if(baki == 0)
            return 1;
        else
            return 0;
    }

    if(dp[index][baki] != -1)
        return dp[index][baki];

    dp[index][baki] = 0;

    int i;

    for(i = 0; i <= x; ++i)
        dp[index][baki] = (dp[index][baki] + func(index - 1, baki - i)) % 1000000;

    return dp[index][baki];
}

int main()
{
    int n, k;
    while(scanf("%d %d", &n, &k) == 2)
    {
        if(n == 0 && k == 0)
            break;

        memset(dp, -1, sizeof(dp));
        x = n;
        printf("%d\n", func(k, n));
    }
    return 0;
}

