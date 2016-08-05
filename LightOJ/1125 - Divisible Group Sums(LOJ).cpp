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

long long n, q, m, d, dp[205][15][25], arr[205];

long long func(long long index, long long nici, long long modvalue)
{
    if(nici == m)
    {
        if(modvalue == 0)
            return 1;
        else
            return 0;
    }

    if(index == n)
        return 0;

    if(dp[index][nici][modvalue] != -1)
        return dp[index][nici][modvalue];

    long long x = modvalue + arr[index];

    if(x < 0)
        x = (d + x % d) % d;
    else
        x = x % d;

    long long ret = func(index + 1, nici + 1, x) + func(index + 1, nici, modvalue);

    dp[index][nici][modvalue] = ret;

    return dp[index][nici][modvalue];
}

int main()
{
    long long t, cnt, i, j, k, l;

    scanf("%lld", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld", &n, &q);

        for(i = 0; i < n; ++i)
            scanf("%lld", &arr[i]);

        printf("Case %lld:\n", cnt);

        for(i = 0; i < q; ++i)
        {
            scanf("%lld %lld", &d, &m);

            for(j = 0; j <= n; ++j)
                for(k = 0; k <= m; ++k)
                    for(l = 0; l <= d; ++l)
                        dp[j][k][l] = -1;

            printf("%lld\n", func(0, 0, 0));
        }
    }

    return 0;
}
