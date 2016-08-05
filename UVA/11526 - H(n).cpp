#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    long long cnt, t, n, i, ans, x, y, z;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld", &n);
        if(n > 0)
        {
            z = sqrt(n);
            ans = n;
            x = n;
            for(i = 2; i <= z; ++i)
            {
                y = n / i;
                ans += y + (x - y) * (i - 1);
                x = y;
            }
            if(y != z)
                ans += (x - i + 1) * (i - 1);
            printf("%lld\n", ans);
        }
        else
            printf("0\n");
    }
    return 0;
}
