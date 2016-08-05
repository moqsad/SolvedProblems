#include <cstdio>
#include <cmath>

int main()
{
    int t, cnt, x, y, a, b, n, ans;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%d %d", &a, &b);
        x = b - a;
        y = x / 2;
        n = (- 1 + sqrt(1 + 8 * y)) / 2;
        ans = 2 * n;
        x = x - n * (n + 1);
        if(x > 0)
        {
            if(x <= n + 1)
                ans += 1;
            else
                ans += 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}
