#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define mod 10056

int dp[1005][1005], ans[1005];

int combination(int n, int k)
{
    if(n == k || k == 0)
        return 1;

    if(dp[n][k] != -1)
        return dp[n][k];

    return dp[n][k] = (combination(n - 1, k - 1) + combination(n - 1, k)) % mod;
}

int main()
{
    int i, j, cnt, n, t, sum;

    memset(dp, -1, sizeof(dp));

    ans[0] = 1;
    for(i = 1; i <= 1000; ++i)
    {
//    printf("%d++++++++++\n", i);
        sum = 0;
        for(j = 1; j <= i; ++j)
            sum += (combination(i, j) * ans[i - j]) % mod;
        ans[i] = sum % mod;
    }
    scanf("%d", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        printf("Case %d: %d\n", cnt, ans[n]);
    }

    return 0;
}
