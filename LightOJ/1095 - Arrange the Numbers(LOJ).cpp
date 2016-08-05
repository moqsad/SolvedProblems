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

#define mod 1000000007

long long combi[1005][1005], dp[1005][1005], f[1005];

long long nCr(long long n, long long r)
{
    if(r == 0 || n == r)
        return 1;

    if(combi[n][r] != -1)
        return combi[n][r];

    return combi[n][r] = (nCr(n - 1, r - 1) + nCr(n - 1, r)) % mod;
}

void fact()
{
    long long i;

    f[0] = f[1] = 1;

    for(i = 2; i <= 1000; ++i)
        f[i] = (f[i - 1] * i) % mod;
}

long long func(long long a, long long b)
{
    if(a == 0)
        return f[b];

    if(a < 0)
        return 0;

    if(dp[a][b] != -1)
        return dp[a][b];

    return dp[a][b] = ((a - 1) * func(a - 2, b + 1) + b * func(a - 1, b)) % mod;
}

int main()
{
    long long t, cnt, n, m, k;

    memset(combi, -1, sizeof(combi));
    memset(dp, -1, sizeof(dp));

    fact();

    scanf("%lld", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld %lld", &n, &m, &k);
        printf("Case %lld: %lld\n", cnt, (func(m - k, n - m) * nCr(m, k)) % mod);
    }

    return 0;
}

