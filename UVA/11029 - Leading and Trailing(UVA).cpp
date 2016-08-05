#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

#define mod 1000;

long long n;

long long func(long long power)
{
    if(power == 0)
        return 1;

    long long ret = func(power / 2);

    ret = (ret * ret) % mod;

    if(power % 2 == 1)
        ret = (ret * n) % mod;

    return ret;
}


int main()
{
    long long t, k;
    double x;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld %lld", &n, &k);

        x = (double)k * log10((double)n);

        x = x - floor(x);
//        printf("%llf__\n", x);

        printf("%lld...%03lld\n", (long long)(pow(10.0, x) * 100.0), func(k));
    }
    return 0;
}
