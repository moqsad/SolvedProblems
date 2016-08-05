#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    unsigned long long t, cnt, n, x, i, prev, pres, ans;
    scanf("%llu", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%llu", &n);

        x = sqrt(n);
        ans = 0;
        prev = n;
        for(i = 2; i <= x; ++i)
        {
            pres = n / i;
            ans += (pres - 1) * i + ((prev * (prev + 1)) / 2 - (pres * (pres + 1)) / 2) * (i - 2);
            prev = pres;
        }

        if(x * x < n)
            ans += ((prev * (prev + 1)) / 2 - (x * (x + 1)) / 2) * (x - 1);

        printf("Case %llu: %llu\n", cnt, ans);
    }
    return 0;
}
