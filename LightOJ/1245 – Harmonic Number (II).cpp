#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    long long t, cnt, i, n, x, pre, pres, ans;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld", &n);
        x = sqrt(n);
        pre = n;
        ans = 0;
        for(i = 2; i <= x; ++i)
        {
            ans += pre;
            pres = n / i;
            ans = ans + (pre - pres) * (i - 1);
            pre = pres;
        }


        if(n % x != x)
        {
            ans += pre;
            ans = ans + (pre - x) * (x);
        }

        else
            ans += x;


        printf("Case %lld: %lld\n", cnt, ans);
    }
    return 0;
}
