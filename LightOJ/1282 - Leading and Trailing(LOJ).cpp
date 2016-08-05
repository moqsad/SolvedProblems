#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

#define mod 1000

int bigmod(long long data, int power)
{
    if(power == 0)
        return 1;

    long long ret = bigmod(data, power / 2);

    ret = (ret * ret) % mod;

    if(power % 2 == 1)
        ret = (data * ret) % mod;

    return ret;
}

int main()
{
    int t, cnt, n, k;
    double ans1;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &k);

        ans1 = (double)k * log10((double)n);
        ans1 = ans1 - floor(ans1);

        printf("Case %d: %d %03d\n", cnt, (int)(pow(10, ans1) * 100.0), bigmod(n, k));
    }
    return 0;
}
