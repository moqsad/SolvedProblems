#include <stdio.h>
int main()
{
    long long int m, n, t, count, i, j, x, y, ans;
    scanf("%lld", &t);
    for(count = 1; count <= t; ++count)
    {
        scanf("%lld %lld", &m, &n);
        x = m - 2;
        y = n - 2;
        ans = 0;
        if(y % 3 == 0)
            ans += y / 3;
        else
            ans += y / 3 + 1;
        if(x % 3 == 0)
            ans *= x / 3;
        else
            ans *= (x / 3 + 1);
            printf("%lld\n", ans);
    }
    return 0;
}
