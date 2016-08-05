#include <stdio.h>
int main()
{
    int m, n, x, y, cnt, t;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &m, &n);
        if(m == 0 && n == 0)
            break;
        x = m * n;
        if(m == 1 || n == 1)
            printf("Case %d: %d\n", cnt, x);
        else if(x <= 8)
            printf("Case %d: 4\n", cnt);
        else if(m == 2 || n == 2)
        {
            y = x % 8;
            if(y == 6)
                y = 4;
            printf("Case %d: %d\n", cnt, (x / 8) * 4 + y);
        }
        else if(x % 2 == 0)
            printf("Case %d: %d\n", cnt, x / 2);
        else
            printf("Case %d: %d\n", cnt, x / 2 + 1);
    }
    return 0;
}
