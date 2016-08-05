#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

long long dp[67][67][3], n, s;

long long func(long long index, long long lock, long long pre)
{
    if(index == 0)
    {
        if(lock == 0)
            return 1;
        else
            return 0;
    }

    if(lock < 0)
        return 0;

    if(dp[index][lock][pre] != -1)
        return dp[index][lock][pre];

    long long x = 0;

    if(pre == 1)
        x = 1;

    return dp[index][lock][pre] = func(index - 1, lock - x, 1) + func(index - 1, lock, 0);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    while(scanf("%lld %lld", &n, &s) == 2)
    {
        if(n < 0 && s < 0)
            break;

        printf("%lld\n", func(n, s, 1));
    }
    return 0;
}
