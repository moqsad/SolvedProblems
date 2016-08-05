#include <cstdio>

int main()
{
    long long cnt, t, sum, total, n, m, a, i, j, k, x, y;
    scanf("%lld", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%lld %lld", &n, &m);
        scanf("%lld", &k);
        scanf("%lld", &a);
        x = a % n;
        for(i = 1; i<k; ++i)
        {
            scanf("%lld", &a);
            y = a % n;
            x = (x * y) % n;
        }
        sum = x;
        for(j = 1; j < m; ++j)
        {
            scanf("%lld", &k);
            scanf("%lld", &a);
            x = a % n;
            for(i = 1; i<k; ++i)
            {
                scanf("%lld", &a);
                y = a % n;
                x = (x * y) % n;
            }
            total = x;
            sum = (sum + total) % n;
        }
        printf("%lld\n", sum);
    }
    return 0;
}
