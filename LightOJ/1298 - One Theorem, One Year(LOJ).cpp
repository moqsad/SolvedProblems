#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>
#include <cstdlib>
#include <cctype>
#include <stack>
#include <iostream>
using namespace std;

bool arr[3600];
long long prime[505], dp[505][505], total, precal[505][505];

#define mod 1000000007

long long bigmod(long long num, long long power)
{
    if(power == 0)
        return 1;

    long long ret = bigmod(num, power / 2);

    ret = (ret * ret) % mod;

    if(power % 2 == 1)
        ret = (ret * num) % mod;

    return ret;
}

void sieve()
{
    long long i, j, k, cnt = 0;

    prime[++cnt] = 2;

    for(i = 3; i < 3600; i += 2)
    {
        if(arr[i] == 0)
        {
            prime[++cnt] = i;

            if(cnt == 500)
                break;

            k = i + i;

            for(j = i * i; j < 3600; j += k)
                arr[j] = 1;
        }
    }
}

long long func(long long k, long long p)
{
    if(k == 0 && p == 0)
        return 1;

    if(k == 0 || p == 0)
        return 0;

    if(dp[k][p] != -1)
        return dp[k][p];

    long long temp, i, ret = 0;

    for(i = 1; i <= k; ++i)
    {
        temp = ((prime[p] - 1) * precal[p][i - 1]) % mod;
        ret = (ret + (temp * func(k - i, p - 1))) % mod;
    }

    func(k, p - 1);

    return dp[k][p] = ret;
}

int main()
{
    long long t, cnt, p, i, j, k;

    memset(dp, -1, sizeof(dp));

    sieve();

    for(i = 1; i <= 500; ++i)
        for(j = 0; j <= 500; ++j)
            precal[i][j] = bigmod(prime[i], j);

    func(500, 500);

    scanf("%lld", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld", &k, &p);
        printf("Case %lld: %lld\n", cnt, dp[k][p]);
    }

    return 0;
}
