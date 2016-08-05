#include <bits/stdc++.h>
using namespace std;

#define sz 65

long long dp[sz][sz];
char arr[sz];

long long func(long long s, long long e)
{
    if(e - s == 1)
        return 1;

    if(dp[s][e] != -1)
        return dp[s][e];

    long long i, j, ret = e - s;

    for(i = s + 1; i < e; ++i)
        for(j = i + 1; j < e; ++j)
        {
            if(arr[i] == arr[j])
                ret += func(i, j);
        }
    return dp[s][e] = ret;
}

int main()
{
    long long t, ans, x, i, j;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%s", arr);
        x = strlen(arr);
        ans = x;
        memset(dp, -1,  sizeof(dp));
        for(i = 0; i < x; ++i)
            for(j = i + 1; j < x; ++j)
            {
                if(arr[i] == arr[j])
                    ans += func(i, j);
            }
        printf("%lld\n", ans);
    }
    return 0;
}
