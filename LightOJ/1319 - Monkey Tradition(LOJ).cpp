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

long long mod, p[15], r[15];

long long big_mod(long long num, long long power)
{
    if(power == 0)
        return 1;

    long long ret = big_mod(num, power / 2);

    ret = (ret * ret) % mod;

    if(power % 2 == 1)
        ret = (ret * num) % mod;

    return ret;
}

int main()
{
    long long t, cnt, sum, boromod, n, i;

    scanf("%lld", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld", &n);

        sum = 0;
        boromod = 1;

        for(i = 0; i < n; ++i)
        {
            scanf("%lld %lld", &p[i], &r[i]);
            boromod *= p[i];
        }

        for(i = 0; i < n; ++i)
        {
            mod = p[i];
            sum += (boromod / p[i]) * big_mod(boromod / p[i], p[i] - 2) * r[i];
        }

        printf("Case %lld: %lld\n", cnt, sum % boromod);
    }

    return 0;
}


