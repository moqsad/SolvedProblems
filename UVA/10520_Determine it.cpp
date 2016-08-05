#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

long long dp[22][22];

int main()
{
    long long n, a_n_1, i, j;
    while(scanf("%lld %lld", &n, &a_n_1) == 2)
    {
        for(i = n; i > 0; --i)
            for(j = 1; j <= n; ++j)
            {
                if(i >= j)
                {
                    if(i == n)
                    {
                        dp[i][j] = dp[i][j - 1] + dp[n][j - 1];
                        if(j == 1)
                            dp[i][j] = a_n_1;
                    }
                    else
                        dp[i][j] = dp[i + 1][1] + dp[i + 1][j] + dp[i][j - 1] + dp[n][j - 1];
                }

                else
                {
                    dp[i][j] = dp[i][j - 1] + dp[j][j];
                }
            }
        printf("%lld\n", dp[1][n]);
    }
    return 0;
}
