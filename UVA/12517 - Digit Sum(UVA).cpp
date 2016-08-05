#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

long long dp[12][2][2], arr[12], temp[12], n;

void func(long long index, long long flag)
{
    if(dp[index][flag][0] != 0)
        return ;
    if(index == n)
    {
        dp[index][flag][0] = 1;
        return ;
    }

    long long nflag, i, lim = (flag == 0) ? 9 : arr[index];
    for(i = 0; i <= lim; ++i)
    {
        if(flag == 0 || i < lim)
            nflag = 0;
        else
            nflag = 1;

        func(index + 1, nflag);
        dp[index][flag][0] += dp[index + 1][nflag][0];
        dp[index][flag][1] += dp[index + 1][nflag][1] + dp[index + 1][nflag][0] * i;
    }
    return ;
}

int main()
{
    long long a, b, ans, i, j;
    while(scanf("%lld %lld", &a, &b) == 2)
    {
        if(a == 0 && b == 0)
            break;

        --a;
        n = 0;
        while(a > 0)
        {
            temp[n++] = a % 10;
            a /= 10;
        }
        j = 0;
        for(i = n - 1; i >= 0; --i)
            arr[j++] = temp[i];
        memset(dp, 0, sizeof(dp));
        func(0, 1);
        ans = - dp[0][1][1];

        n = 0;
        while(b > 0)
        {
            temp[n++] = b % 10;
            b /= 10;
        }
        j = 0;
        for(i = n - 1; i >= 0; --i)
            arr[j++] = temp[i];
        memset(dp, 0, sizeof(dp));
        func(0, 1);
        ans += dp[0][1][1];
        printf("%lld\n", ans);
    }
    return 0;
}
