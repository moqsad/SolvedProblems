#include <cstdio>

int main()
{
    int m, n, t, x, y, i, j, ans, p, total;
    while(scanf("%d %d %d", &m, &n, &t) == 3)
    {
        total = 10000000;

        if(m < n)
        {
            x = m;
            y = n;
        }
        else
        {
            x = n;
            y = m;
        }

        p = 0;
        for(i = 0; i <= t; i += y)
        {
            j = t - i;
            if(j % x == 0 && i % y == 0)
            {
                ans = j / x + i / y;
                p = 1;
                break;
            }
            else
            {
                if(j % x + i % y < total)
                {
                    total = j % x + i % y;
                    ans = j / x + i / y;
                }
            }
        }
        if(p == 1)
            printf("%d\n", ans);
        else
            printf("%d %d\n", ans, total);
    }
    return 0;
}
