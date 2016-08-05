#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

char arr[70];
long long dp[65][65];

long long func(long long s, long long e)
{
    if(s > e)
        return 0;

    long long ans = 0, i;

    if(dp[s][e] != -1)
    return dp[s][e];

    for(i = s + 1; i <= e; ++i)
    {
        if(arr[s] == arr[i])
            ans = ans + 1 + func(s + 1, i - 1);
    }

    for(i = e - 1; i > s; --i)
    {
        if(arr[e] == arr[i])
            ans = ans + 1 + func(i + 1, e - 1);
    }

    ans += func(s + 1, e - 1);

    if(s < e)
        ans += 2;
    else
        ans += 1;

    return dp[s][e] = ans;
}

int main()
{
    long long t, cnt;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%s", arr);
        memset(dp, -1, sizeof(dp));
        printf("Case %lld: %lld\n", cnt, func(0, strlen(arr) - 1));
    }
    return 0;
}

